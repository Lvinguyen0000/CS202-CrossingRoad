#include "CDinausor.h"

CDinausor::CDinausor() {
	a = new char* [3];
	for (int i = 0; i < 3; i++)
	{
		a[i] = new char[5];
	}

	a[0][0] = ' ';
	a[0][1] = ' ';
	a[0][2] = ' ';
	a[0][3] = '/';
	a[0][4] = '^';

	a[1][0] = ' ';
	a[1][1] = ' ';
	a[1][2] = (char)220;
	a[1][3] = (char)219;
	a[1][4] = (char)221;

	a[2][0] = ' ';
	a[2][1] = '/';
	a[2][2] = '|';
	a[2][3] = ' ';
	a[2][4] = '|';
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
		for (int j = 0; j < 5; j++) {
			GotoXY(x + j, y + i + 1);
			if (x + i + 5 >= 90 || x +i - 5 <= 0) {
				cout << ' ';
				for (int j = 11; j < 15; j++) {
					GotoXY(91, j);
					cout << '|';
				}
			}
			else {
				cout << a[i][j];
			}
		}
		cout << endl;
	}
}
