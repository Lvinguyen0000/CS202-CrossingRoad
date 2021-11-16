#include "CDinausor.h"

CDinausor::CDinausor() : CObstacle(){}

void CDinausor::Draw() {
	if (direction) {
		string dino[3] = {
			"  /'",
			" []}.",
			"/| |",
		};
		GotoXY(mX, mY);
		for (int i = 0; i < 3; i++) {
			cout << dino[i];
		}
	}
	else {
		string dino[3] = {
			" '\\ ",
			".{[] ",
			" | |\\ ",
		};
		GotoXY(mX, mY);
		for (int i = 0; i < 3; i++) {
			cout << dino[i];
		}
	}
}


void CDinausor::Move() {
	string del[3] = { " "," "," " };
	string end[3] = { "    ","     ","     " };
	if (direction) {
		if (mX == 84) {
			for (int i = 0; i < 3; i++) {
				GotoXY(mX, mY + i);
				cout << end[i];
			}
		}
		else if (mX > 84) return;
		else {
			int oldX = mX, preX = mX + 1;
			GotoXY(preX, mY);
			Draw();
			GotoXY(oldX, mY);
			for (int i = 0; i < 3; i++) {
				GotoXY(oldX, mY + i);
				cout << del[i];
			}
		}
	}
	else {
		if (mX == 1) {
			for (int i = 0; i < 3; i++) {
				GotoXY(mX, mY + i);
				cout << end[i];
			}
		}
		else if (mX < 1) return;
		else if (mX > 84) {
			for (int i = 0; i < 3; i++) {
				GotoXY(91, mY);
				cout << "|";
			}
		}
		else {
			int oldX = mX + 6, preX = mX - 1;
			GotoXY(preX, mY);
			Draw();
			GotoXY(oldX, mY);
			for (int i = 0; i < 3; i++) {
				GotoXY(oldX, mY + i);
				cout << del[i];
			}
		}
	}
}
