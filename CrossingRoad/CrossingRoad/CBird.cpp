#include "CBird.h"

CBird::CBird() {
	b = new char* [2];
	for (int i = 0; i < 2; i++)
		b[i] = new char[3];

	b[0][0] = (char)254;
	b[0][1] = ' ';
	b[0][2] = (char)254;
	b[1][0] = ' ';
	b[1][1] = (char)223;
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
			if (isOut(x + i + 3)) {
				cout << ' ';
				for (int k = 6; k < 9; k++) {
					GotoXY(91, k);
					cout << '|';
				}
			}
			else {
				cout << b[i][j];
			}
		}
		cout << endl;
	}
	if (x != 1) {
		for (int i = 1; i < 4; i++) {
			GotoXY(x - 1, y + i);
			cout << ' ';
		}
	}
}



bool CBird::isOut(int x) {
	return (x >= 90);
}
