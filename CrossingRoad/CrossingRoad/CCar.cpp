#include "CCar.h"

CCar::CCar() : CObstacle() {

}

void CCar::Move() {

}
void CCar::Draw() {
	string car[3] = {
		"_/```\\__",
		"\_ __ _/ ",
		"  *  *   "
	};

	string reversedCar[3] = {
		" __/```\\_",
		"\\_ ___ _/",
		"   *   *  ",
	};
	if (this->direction) {
		GotoXY(this->mX, this->mY);
		for (int i = 0; i < 3; i++) cout << car[i] << endl;
	}
}



	//a = new char* [3];
	//for (int i = 0; i < 3; i++) {
	//	a[i] = new char[8];
	//}
	//for (int i = 0; i < 3; i++) {
	//	for (int j = 0; j < 8; j++) {
	//		a[i][j] = ' ';
	//	}
	//}
	//a[0][0] = '_';
	//a[0][1] = '/';
	//a[0][2] = '`';
	//a[0][3] = '`';
	//a[0][4] = '`';
	//a[0][5] = '\\';
	//a[0][6] = '_';
	//a[1][0] = '/';
	//a[1][7] = '\\';
	//a[1][0] = '_';
	//a[2][1] = '*';
	//a[1][2] = '_';
	//a[1][3] = '_';
	//a[1][4] = '_';
	//a[2][5] = '*';
	//a[1][6] = '_';
//}
	