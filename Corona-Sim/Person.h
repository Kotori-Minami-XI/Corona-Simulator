#ifndef PERSON_H /* Person - v1.0.0.0 */
#define PERSON_H

#include <iostream>
#include <vector>
#include <mutex>
#include <cstdlib>
#include <ctime>
#include "Dot.h"
#include "ColorPrint.h"
#include "Background.h"

class Person
{
public:
	Person(Background& background, bool isInfected = false, unsigned int paceRange = 1) {
		unique_lock<mutex> uk(this->personLock);
		this->isInfected = isInfected;
		this->paceRange = paceRange;
		this->background = &background;
		randomSpawn();
	}

	vector<unsigned int> getPersonLocationDot() {
		unique_lock<mutex> uk(this->personLock);
		return this->personLocationDot->getCord();
	}

	void setPersonLocationDot(unsigned int x, unsigned int y) {
		unique_lock<mutex> uk(this->personLock);
		this->personLocationDot = (*this->background->getDotVector())[x][y];
	}

	void move(bool isRandom = true, unsigned int direct = 0) {
		unique_lock<mutex> uk(this->personLock);
		for (int i = 0; i < this->paceRange; i++) {
			if (isRandom) {
				direct = rand() % 8 + 1;
			}
			else {
				if (direct <= 0 || direct > 9) {
					throw new exception(
						ColorPrint::colorStr("fatal error: direct should be between 0 and 9 when isRandom is true!", RESET, FRONT_RED, BACK_BLACK).c_str());
				}
			}
			switch (direct)
			{
			case 1:
				makeMove(-1, 1);
				break;
			case 2:
				makeMove(0, 1);
				break;
			case 3:
				makeMove(1, 1);
				break;
			case 4:
				makeMove(-1, 0);
				break;
			case 5:
				makeMove(0, 0);
				break;
			case 6:
				makeMove(1, 0);
				break;
			case 7:
				makeMove(-1, -1);
				break;
			case 8:
				makeMove(0, -1);
				break;
			case 9:
				makeMove(1, -1);
				break;
			default:
				ColorPrint::colorError("fatal error: invalid direct value! direct=%u", direct);
				break;
			}
		}
	}

	void setInfected(bool isInfected) {
		this->isInfected = isInfected;
	}

	bool getInfected() {
		return this->isInfected;
	}

private:
	void randomSpawn() {
		this->personLocationDot = 
			(*(this->background->getDotVector()))[rand() % this->background->getXLength()][rand() % this->background->getYLength()];
	}

	void makeMove(int xDiff, int yDiff) {
		vector<unsigned int> cords = this->personLocationDot->getCord();
		unsigned int xCord = cords[0];
		unsigned int yCord = cords[1];
		if (xCord == 0 && xDiff < 0) {
			xCord = 0;
		}
		else if (xCord == this->background->getXLength() - 1 && xDiff > 0) {
			xCord = this->background->getXLength() - 1;
		}
		else {
			xCord += xDiff;
		}

		if (yCord == 0 && yDiff < 0) {
			yCord = 0;
		}
		else if (yCord == this->background->getYLength() - 1 && yDiff > 0) {
			yCord = this->background->getYLength() - 1;
		}
		else {
			yCord += yDiff;
		}

		Dot* dot = (*this->background->getDotVector())[xCord][yCord];
		this->personLocationDot = dot;

		// Person might get infected by dot
		if (dot->isDotComtaminated()) {
			this->setInfected(true);
		}

		// Person might infect the current dot
		if (this->isInfected) {
			dot->contaminateDot();
		}
	}

	Dot* personLocationDot;
	bool isInfected;
	unsigned int paceRange;
	mutex personLock;
	Background* background;
};

#endif /* Person */

