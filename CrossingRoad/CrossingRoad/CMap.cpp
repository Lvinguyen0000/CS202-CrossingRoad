#include "CMap.h"


void CMap::PrintBorder() {
	clrscr();
	GotoXY(0, 0);
	for (int i = 0; i <= height; i += 5) {
		printRow(i, this->width);
	}
	printCol(0, this->height);
	printCol(this->width + 1, this->height);
}


void CMap::printCol(int index, int height) {
	for (int y = 0; y <= height; y++) {
		GotoXY(index, y);
		cout << '|';
	}
}

void CMap::printRow(int index, int width) {
	for (int x = 0; x <= width; x++) {
		GotoXY(x, index);
		cout << '-';
	}
}