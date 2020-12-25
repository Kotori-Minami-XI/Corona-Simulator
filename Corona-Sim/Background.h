#ifndef BACKGROUND_H /* Background - v1.0.0.0 */
#define BACKGROUND_H

#include <iostream>
#include <vector>
#include <mutex>
#include <cstdlib>
#include <ctime>
#include "Dot.h"
#include "ColorPrint.h"

using namespace std;

class Background
{

public:
	Background(unsigned int xLength, unsigned int yLength) {
		this->backgroundLock.lock();
		this->xLength = xLength;
		this->yLength = yLength;
		initDots(1);
		initRandom();
		this->backgroundLock.unlock();
	}

	vector<vector<Dot*>>* getDotVector() {
		return this->dotVector;
	}

	unsigned int getXLength() {
		return this->xLength;
	}

	unsigned int getYLength() {
		return this->yLength;
	}

	~Background()
	{
		this->backgroundLock.lock();
		delete(this->dotVector);
		this->backgroundLock.unlock();
		//ColorPrint::colorWarning("Background has already deconstructed\n");
	}
private:
	Background(const Background&) = delete;
	Background& operator= (const Background&) = delete;

	void initDots(unsigned int contaminateRange) {
		this->dotVector = new vector<vector<Dot*>>(this->yLength, vector<Dot*>(this->xLength));
		for (unsigned int i = 0; i < this->xLength; i++) {
			for (unsigned int j = 0; j < this->yLength; j++) {
				(*this->dotVector)[i][j] = new Dot(i, j, contaminateRange);
			}
		}
	}

	void initRandom() {
		srand(time(0));
	}

	unsigned int xLength;
	unsigned int yLength;
	mutex backgroundLock;
	vector<vector<Dot*>>* dotVector;
};

#endif /* BACKGROUND_H */


