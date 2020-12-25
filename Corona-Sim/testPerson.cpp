#include "Person.h"
#include "ColorPrint.h"

static void testPersonUnion();
static bool testPersonSpawn();
static bool testPersonMove();
static bool testPersonGetInfected();

/*********************************************************************
 * �������ƣ�testPersonUnion
 * �������ܣ�Person�Ĳ��Լ���
 * ���������None
 * ���ز�����void
 * ��������δ�׳��쳣
 *********************************************************************/
static void testPersonUnion() {
	ColorPrint::colorPass("******************** testPersonUnion Start ******************** \n");

	if (!testPersonSpawn()) {
		ColorPrint::colorError("testcase failed! - testPersonSpawn failed\n");
	}
	if (!testPersonMove()) {
		ColorPrint::colorError("testcase failed! - testPersonMove failed\n");
	}
	if (!testPersonGetInfected()) {
		ColorPrint::colorError("testcase failed! - testPersonGetInfected failed\n");
	}

	ColorPrint::colorPass("******************** testPersonUnion Pass ******************** \n");
}


/*********************************************************************
 * �������ƣ�testPersonSpawn
 * �������ܣ�����Person����Զ�λ�����ɺ���
 * ���������None
 * ���ز�����bool
 * ��������δ�׳��쳣������true
 *********************************************************************/
static bool testPersonSpawn() {
	ColorPrint::colorPass("------------------ testPersonSpawn Start ------------------ \n");
	unsigned int x_length = 100;
	unsigned int y_length = 100;

	Background background(x_length, y_length);

	Person pserson(background);
	vector<unsigned int> location = pserson.getPersonLocationDot();
	printf("pserson spawns in: x=%u y=%u\n", location[0], location[1]);
	
	ColorPrint::colorPass("------------------ testPersonSpawn Pass ------------------ \n");
	return true;
}


/*********************************************************************
 * �������ƣ�testPersonMove
 * �������ܣ�����Person���move����
 * ���������None
 * ���ز�����bool
 * ��������δ�׳��쳣������true
 *********************************************************************/
static bool testPersonMove() {
	ColorPrint::colorPass("------------------ testPersonSpawn Start ------------------ \n");
	unsigned int x_length = 100;
	unsigned int y_length = 100;
	unsigned int expect_x;
	unsigned int expect_y;

	Background background(x_length, y_length);

	Person pserson(background);
	vector<unsigned int> location = pserson.getPersonLocationDot();
	printf("pserson spawns in: x=%u y=%u\n", location[0], location[1]);

	/************* Case 1: diagnal, vertical and horizental move **************/
	pserson.setPersonLocationDot(50, 50);
	expect_x = 50; 
	expect_y = 50;
	location = pserson.getPersonLocationDot();
	printf("pserson is located in: x=%u y=%u\n", location[0], location[1]);
	if (location[0] != expect_x || location[1] != expect_y) {
		ColorPrint::colorError("fatal error: person is not located at correct position! expect: {%u %u} actual: {%u %u}\n",
			expect_x, expect_y, location[0], location[1]);
		return false;
	}

	// Upper left
	pserson.move(false, 1);
	expect_x = 49;
	expect_y = 51;
	location = pserson.getPersonLocationDot();
	printf("pserson is located in: x=%u y=%u\n", location[0], location[1]);
	if (location[0] != expect_x || location[1] != expect_y) {
		ColorPrint::colorError("fatal error: person is not located at correct position! expect: {%u %u} actual: {%u %u}\n",
			expect_x, expect_y, location[0], location[1]);
		return false;
	}

	// Lower right
	pserson.move(false, 9);
	expect_x = 50;
	expect_y = 50;
	location = pserson.getPersonLocationDot();
	printf("pserson is located in: x=%u y=%u\n", location[0], location[1]);
	if (location[0] != expect_x || location[1] != expect_y) {
		ColorPrint::colorError("fatal error: person is not located at correct position! expect: {%u %u} actual: {%u %u}\n",
			expect_x, expect_y, location[0], location[1]);
		return false;
	}

	// Lower left
	pserson.move(false, 7);
	expect_x = 49;
	expect_y = 49;
	location = pserson.getPersonLocationDot();
	printf("pserson is located in: x=%u y=%u\n", location[0], location[1]);
	if (location[0] != expect_x || location[1] != expect_y) {
		ColorPrint::colorError("fatal error: person is not located at correct position! expect: {%u %u} actual: {%u %u}\n",
			expect_x, expect_y, location[0], location[1]);
		return false;
	}

	// Upper right
	pserson.move(false, 3);
	expect_x = 50;
	expect_y = 50;
	location = pserson.getPersonLocationDot();
	printf("pserson is located in: x=%u y=%u\n", location[0], location[1]);
	if (location[0] != expect_x || location[1] != expect_y) {
		ColorPrint::colorError("fatal error: person is not located at correct position! expect: {%u %u} actual: {%u %u}\n",
			expect_x, expect_y, location[0], location[1]);
		return false;
	}

	// Up
	pserson.move(false, 2);
	expect_x = 50;
	expect_y = 51;
	location = pserson.getPersonLocationDot();
	printf("pserson is located in: x=%u y=%u\n", location[0], location[1]);
	if (location[0] != expect_x || location[1] != expect_y) {
		ColorPrint::colorError("fatal error: person is not located at correct position! expect: {%u %u} actual: {%u %u}\n",
			expect_x, expect_y, location[0], location[1]);
		return false;
	}

	// Down
	pserson.move(false, 8);
	expect_x = 50;
	expect_y = 50;
	location = pserson.getPersonLocationDot();
	printf("pserson is located in: x=%u y=%u\n", location[0], location[1]);
	if (location[0] != expect_x || location[1] != expect_y) {
		ColorPrint::colorError("fatal error: person is not located at correct position! expect: {%u %u} actual: {%u %u}\n",
			expect_x, expect_y, location[0], location[1]);
		return false;
	}

	// Left
	pserson.move(false, 4);
	expect_x = 49;
	expect_y = 50;
	location = pserson.getPersonLocationDot();
	printf("pserson is located in: x=%u y=%u\n", location[0], location[1]);
	if (location[0] != expect_x || location[1] != expect_y) {
		ColorPrint::colorError("fatal error: person is not located at correct position! expect: {%u %u} actual: {%u %u}\n",
			expect_x, expect_y, location[0], location[1]);
		return false;
	}

	// Right
	pserson.move(false, 6);
	expect_x = 50;
	expect_y = 50;
	location = pserson.getPersonLocationDot();
	printf("pserson is located in: x=%u y=%u\n", location[0], location[1]);
	if (location[0] != expect_x || location[1] != expect_y) {
		ColorPrint::colorError("fatal error: person is not located at correct position! expect: {%u %u} actual: {%u %u}\n",
			expect_x, expect_y, location[0], location[1]);
		return false;
	}
	printf("------------------ Case 1 Succeed ------------------ \n");

	/************* Case 2: Boundary move (Located in lower left corner) **************/
	pserson.setPersonLocationDot(0, 0);
	expect_x = 0;
	expect_y = 0;
	location = pserson.getPersonLocationDot();
	printf("pserson is located in: x=%u y=%u\n", location[0], location[1]);
	if (location[0] != expect_x || location[1] != expect_y) {
		ColorPrint::colorError("fatal error: person is not located at correct position! expect: {%u %u} actual: {%u %u}\n",
			expect_x, expect_y, location[0], location[1]);
		return false;
	}

	// Down
	pserson.move(false, 8);
	expect_x = 0;
	expect_y = 0;
	location = pserson.getPersonLocationDot();
	printf("pserson is located in: x=%u y=%u\n", location[0], location[1]);
	if (location[0] != expect_x || location[1] != expect_y) {
		ColorPrint::colorError("fatal error: person is not located at correct position! expect: {%u %u} actual: {%u %u}\n",
			expect_x, expect_y, location[0], location[1]);
		return false;
	}

	// Left
	pserson.move(false, 4);
	expect_x = 0;
	expect_y = 0;
	location = pserson.getPersonLocationDot();
	printf("pserson is located in: x=%u y=%u\n", location[0], location[1]);
	if (location[0] != expect_x || location[1] != expect_y) {
		ColorPrint::colorError("fatal error: person is not located at correct position! expect: {%u %u} actual: {%u %u}\n",
			expect_x, expect_y, location[0], location[1]);
		return false;
	}

	// Lower left
	pserson.move(false, 7);
	expect_x = 0;
	expect_y = 0;
	location = pserson.getPersonLocationDot();
	printf("pserson is located in: x=%u y=%u\n", location[0], location[1]);
	if (location[0] != expect_x || location[1] != expect_y) {
		ColorPrint::colorError("fatal error: person is not located at correct position! expect: {%u %u} actual: {%u %u}\n",
			expect_x, expect_y, location[0], location[1]);
		return false;
	}

	// Lower right
	pserson.move(false, 9);
	expect_x = 1;
	expect_y = 0;
	location = pserson.getPersonLocationDot();
	printf("pserson is located in: x=%u y=%u\n", location[0], location[1]);
	if (location[0] != expect_x || location[1] != expect_y) {
		ColorPrint::colorError("fatal error: person is not located at correct position! expect: {%u %u} actual: {%u %u}\n",
			expect_x, expect_y, location[0], location[1]);
		return false;
	}

	// Lower left
	pserson.move(false, 7);
	expect_x = 0;
	expect_y = 0;
	location = pserson.getPersonLocationDot();
	printf("pserson is located in: x=%u y=%u\n", location[0], location[1]);
	if (location[0] != expect_x || location[1] != expect_y) {
		ColorPrint::colorError("fatal error: person is not located at correct position! expect: {%u %u} actual: {%u %u}\n",
			expect_x, expect_y, location[0], location[1]);
		return false;
	}
	printf("------------------ Case 2 Succeed ------------------ \n");

	/************* Case 3: Boundary move (Located in upper right corner) **************/
	pserson.setPersonLocationDot(x_length - 1 , y_length - 1);
	expect_x = x_length - 1;
	expect_y = y_length - 1;
	location = pserson.getPersonLocationDot();
	printf("pserson is located in: x=%u y=%u\n", location[0], location[1]);
	if (location[0] != expect_x || location[1] != expect_y) {
		ColorPrint::colorError("fatal error: person is not located at correct position! expect: {%u %u} actual: {%u %u}\n",
			expect_x, expect_y, location[0], location[1]);
		return false;
	}

	// Up
	pserson.move(false, 2);
	expect_x = x_length - 1;
	expect_y = y_length - 1;
	location = pserson.getPersonLocationDot();
	printf("pserson is located in: x=%u y=%u\n", location[0], location[1]);
	if (location[0] != expect_x || location[1] != expect_y) {
		ColorPrint::colorError("fatal error: person is not located at correct position! expect: {%u %u} actual: {%u %u}\n",
			expect_x, expect_y, location[0], location[1]);
		return false;
	}

	// Right
	pserson.move(false, 6);
	expect_x = x_length - 1;
	expect_y = y_length - 1;
	location = pserson.getPersonLocationDot();
	printf("pserson is located in: x=%u y=%u\n", location[0], location[1]);
	if (location[0] != expect_x || location[1] != expect_y) {
		ColorPrint::colorError("fatal error: person is not located at correct position! expect: {%u %u} actual: {%u %u}\n",
			expect_x, expect_y, location[0], location[1]);
		return false;
	}

	// Upper right
	pserson.move(false, 3);
	expect_x = x_length - 1;
	expect_y = y_length - 1;
	location = pserson.getPersonLocationDot();
	printf("pserson is located in: x=%u y=%u\n", location[0], location[1]);
	if (location[0] != expect_x || location[1] != expect_y) {
		ColorPrint::colorError("fatal error: person is not located at correct position! expect: {%u %u} actual: {%u %u}\n",
			expect_x, expect_y, location[0], location[1]);
		return false;
	}

	// Lower right
	pserson.move(false, 9);
	expect_x = x_length - 1;
	expect_y = y_length - 2;
	location = pserson.getPersonLocationDot();
	printf("pserson is located in: x=%u y=%u\n", location[0], location[1]);
	if (location[0] != expect_x || location[1] != expect_y) {
		ColorPrint::colorError("fatal error: person is not located at correct position! expect: {%u %u} actual: {%u %u}\n",
			expect_x, expect_y, location[0], location[1]);
		return false;
	}

	// Upper right
	pserson.move(false, 3);
	expect_x = x_length - 1;
	expect_y = y_length - 1;
	location = pserson.getPersonLocationDot();
	printf("pserson is located in: x=%u y=%u\n", location[0], location[1]);
	if (location[0] != expect_x || location[1] != expect_y) {
		ColorPrint::colorError("fatal error: person is not located at correct position! expect: {%u %u} actual: {%u %u}\n",
			expect_x, expect_y, location[0], location[1]);
		return false;
	}

	printf("------------------ Case 3 Succeed ------------------ \n");

	ColorPrint::colorPass("------------------ testPersonSpawn Pass ------------------ \n");
	return true;
}


/*********************************************************************
 * �������ƣ�testPersonGetInfected
 * �������ܣ�����Person���Ⱦ�ĳ���
 * ���������None
 * ���ز�����bool
 * ��������δ�׳��쳣������true
 *********************************************************************/
static bool testPersonGetInfected() {
	ColorPrint::colorPass("------------------ testPersonGetInfected Start ------------------ \n");
	unsigned int x_length = 100;
	unsigned int y_length = 100;

	Background background(x_length, y_length);

	Person pserson(background);
	vector<unsigned int> location = pserson.getPersonLocationDot();
	printf("pserson spawns in: x=%u y=%u\n", location[0], location[1]);




	ColorPrint::colorPass("------------------ testPersonGetInfected Pass ------------------ \n");
}


int main() {
	testPersonUnion();
	return 0;
}