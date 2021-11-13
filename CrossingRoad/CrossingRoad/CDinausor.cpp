#include "CDinausor.h"

CDinausor::CDinausor() {
	a = new char* [3];
	for (int i = 0; i < 3; i++)
	{
		a[i] = new char[4];
	}

	a[0][0] = ' ';
	a[0][1] = ' ';
	a[0][2] = '/';
	a[0][3] = '^';

	a[1][0] = ' ';
	a[1][1] = (char)220;
	a[1][2] = (char)219;
	a[1][3] = (char)221;

	a[2][0] = '/';
	a[2][1] = '|';
	a[2][2] = ' ';
	a[2][3] = '|';
}
CDinausor::~CDinausor(){
	for (int i = 0; i < 3; i++)
	{
		delete[] a[i];
	}
	delete[] a;
}

void CDinausor::Move(int x, int y) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			GotoXY(x + j, y + i + 1);
			if (x + i + 4 >= 90 || x +i - 4 <= 0) {
				cout << ' ';
				for (int k = 11; k < 15; k++) {
					GotoXY(91, k);
					cout << '|';
				}
			}
			else {
				cout << a[i][j];
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
