#ifndef DOT_H /* Dot - v1.0.0.0 */
#define DOT_H

#include <iostream>
#include <mutex>
#include <vector>

using namespace std;

class Dot
{
public:
	Dot(unsigned int xCord, unsigned int yCord, unsigned int contaminateRange = 1) {
		unique_lock<mutex> uk(this->dotLock);
		this->xCord = xCord;
		this->yCord = yCord;
		this->contaminateRange = contaminateRange;
		isContaminated = false;
	}

	void contaminateDot() {
		unique_lock<mutex> uk(this->dotLock);
		this->isContaminated = true;
	}

	vector<unsigned int> getCord() {
		vector<unsigned int> cords = { this->xCord, this->yCord };
		return cords;
	}

	bool isDotComtaminated() {
		unique_lock<mutex> uk(this->dotLock);
		return this->isContaminated;
	}

private:
	unsigned int xCord;
	unsigned int yCord;
	unsigned int contaminateRange;
	bool isContaminated;
	mutex dotLock;
};

#endif /* DOT_H */
