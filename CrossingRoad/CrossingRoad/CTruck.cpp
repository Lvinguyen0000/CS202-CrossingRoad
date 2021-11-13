#include "CTruck.h"
CTruck::CTruck() {
  	a = new char* [3];
	for (int i = 0; i < 3; i++) {
		a[i] = new char[8];
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 8; j++) {
			a[i][j] = ' ';
		}
	}
	a[0][1] = '_';
	a[0][2] = '_';
	a[0][3] = '_';
	a[0][4] = '|';
	a[0][5] = '\\';
	a[1][0] = '|';
	a[1][1] = '_';
	a[1][2] = '_';
	a[1][3] = '_';
	a[1][4] = '|';
	a[1][5] = '_';
	a[1][6] = '|';
	a[2][1] = '*';
	a[2][4] = '*';
}
CTruck::~CTruck() {
	for(int i=0; i< 3; i++) {
		delete[] a[i];
	}
	delete a;
}
void CTruck::Move(int x, int y) {
	if (x > 83 || y > 16) return;
	for (int i = 0; i < 3; i++) {
		GotoXY(x + i, y);
		for (int j = 0; j < 8; j++) {
			GotoXY(x + j, y + i);
			cout << a[i][j];
		}
	}
}
