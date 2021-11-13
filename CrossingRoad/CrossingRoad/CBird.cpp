#include "CBird.h"

CBird::CBird() {
	b = new char* [2];
	for (int i = 0; i < 2; i++)
		b[i] = new char[3];

	b[0][0] = (char)254;
	b[0][1] = ' ';
	b[0][2] = (char)254;
	b[1][0] = ' ';
	b[1][1] = (char)254;
	b[1][2] = ' ';
}

void CBird::Draw() {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cout << b[i][j];
		}
		cout << endl;
	}
}
CBird::~CBird() {
	for (int i = 0; i < 3; i++)
		delete[] b[i];
	delete[] b;
}

void CBird::Move(int x, int y) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			GotoXY(x + j, y + i + 1);
			cout << b[i][j];
		}
		cout << endl;
	}
}



bool CBird::isOut(int x) {
	return (x >= 55);
}
