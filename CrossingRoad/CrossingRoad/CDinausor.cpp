#include "CDinausor.h"

void CDinausor::drawDino(int x, int y) {
	string dino[3] = {
		"  /'",
		" []}.",
		"/| |",
	};
	for (int i = 0; i < 3; i++) {
		GotoXY(x, y + i);
		cout << dino[i];
	}
}

void CDinausor::drawDinoreverse(int x, int y) {
	string dino[3] = {
		" '\\ ",
		".{[] ",
		" | |\\ ",
	};
	for (int i = 0; i < 3; i++) {
		GotoXY(x, y + i);
		cout << dino[i];
	}
}


void CDinausor::Move(int x, int y, bool direction) {
	CAnimal::Move(x, y, direction);
	string del[3] = { " "," "," " };
	string end[3] = { "    ","     ","     " };
	if (direction) {
		if (x == 84) {
			for (int i = 0; i < 3; i++) {
				GotoXY(x, y + i);
				cout << end[i];
			}
		}
		else if (x > 84) return;
		else {
			int oldX = x, preX = x + 1;
			drawDino(preX, y);
			GotoXY(oldX, y);
			for (int i = 0; i < 3; i++) {
				GotoXY(oldX, y + i);
				cout << del[i];
			}
		}
	}
	else {
		if (x == 1) {
			for (int i = 0; i < 3; i++) {
				GotoXY(x, y + i);
				cout << end[i];
			}
		}
		else if (x < 1) return;
		else if (x > 84) {
			for (int i = 0; i < 3; i++) {
				GotoXY(91, y);
				cout << "|";
			}
		}
		else {
			int oldX = x + 6, preX = x - 1;
			drawDinoreverse(preX, y);
			GotoXY(oldX, y);
			for (int i = 0; i < 3; i++) {
				GotoXY(oldX, y + i);
				cout << del[i];
			}
		}
	}
}