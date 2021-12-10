#include "CDinausor.h"

CDinausor::CDinausor(int x, int y, bool direction, bool light, int speed) : CObstacle(x, y, direction, light, speed) {
	if (x != 0) this->mX = x;
	else {
		if (this->direction == 1) {
			this->mX = LEFT_IN;
		}
		else {
			this->mX = RIGHT_IN;
		}
	}
}

void CDinausor::Draw() {
	if (!direction) {
		string dino[3] = {
			"  /'",
			" []}.",
			"/| |",
		};
		for (int i = 0; i < 3; i++) {
			GotoXY(mX, mY + i);
			cout << dino[i] << endl;
		}
	}
	else {
		string dino[3] = {
			" '\\ ",
			".{[] ",
			" | |\\",
		};
		for (int i = 0; i < 3; i++) {
			GotoXY(mX, mY + i);
			cout << dino[i] << endl;
		}
	}
}


void CDinausor::Move() {
	if (direction) Left();
	else Right();
}

void CDinausor::Left() {
	int oldX = mX;
	mX--;
	if (mX > 85) return;
	else if (mX >= 2 && mX < 85) {
		this->Draw();
		for (int i = 0; i < 3; i++) {
			GotoXY(oldX + 4, mY + i);
			cout << " ";
		}
	}
	else if (mX < 2) {
		for (int i = 0; i < 3; i++) {
			GotoXY(1, mY + i);
			cout << "      ";
		}
	}
}

void CDinausor::Right() {
	int oldX = mX;
	mX++;
	if (mX < 1) return;
	else if (mX > 2 && mX < 84) {

		this->Draw();
		for (int i = 0; i < 3; i++) {
			GotoXY(oldX, mY + i);
			cout << " ";
		}
	}
	else if (mX == 84) {
		for (int i = 0; i < 3; i++) {
			GotoXY(83, mY + i);
			cout << "     ";
		}
	}
}


int CDinausor::getWidth() {
	return 6;
}
