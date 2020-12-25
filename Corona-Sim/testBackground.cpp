#include "Background.h"
#include "ColorPrint.h"

static void testBackgroundUnion();
static bool testBackgroundConstructor();


static void testBackgroundUnion() {
	ColorPrint::colorPass("******************** testBackgroundUnion Start ******************** \n");

	if (!testBackgroundConstructor()) {
		ColorPrint::colorError("testcase failed! - testBackgroundConstructor failed");
	}

	ColorPrint::colorPass("******************** testBackgroundUnion Pass ******************** \n");
}

static bool testBackgroundConstructor() {
	ColorPrint::colorPass("------------------ testBackgroundConstructor Start ------------------ \n");

	unsigned int x_length = 100;
	unsigned int y_length = 100;

	Background background(x_length, y_length);
	vector<vector<Dot*>>* dotVector = background.getDotVector();
	for (unsigned int i = 0; i < x_length; i++) {
		for (unsigned int j = 0; j < y_length; j++) {
			Dot* dot = (*dotVector)[i][j];
			vector<unsigned int> cords = dot->getCord();
			if (cords[0] != i || cords[1] != j) {
				ColorPrint::colorError("fatal error: cordinates for the dot are not correct! i=%u, j=%u, x_cord = %u, y_cord = %u",
					i, j, cords[0], cords[1]);
				return false;
			}
		}
	}
	
	ColorPrint::colorPass("------------------ testBackgroundConstructor Pass ------------------ \n");
	return true;
}


int main1() {
	testBackgroundUnion();
	return 0;
}