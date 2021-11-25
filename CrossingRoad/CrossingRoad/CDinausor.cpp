#include "CDinausor.h"

CDinausor::CDinausor(int x, int y, bool direction, bool light, int speed) : CObstacle(x, y, direction, light, speed) {

}

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
	if (direction) Left();
	else Right();
}

void CDinausor::Left() {
	string end[3] = { "    ","     ","     " };
	string del = { ' ',' ',' ' };
	int oldX = mX, oldY = this->mY;

	mX--;

	if (this->isOut()) {
		for (int i = 0; i < 3; i++) {
			GotoXY(oldX, oldY + i);
			cout << end[i];
		}
		return;
	}

	this->Draw();
	for (int i = 0; i < 3; i++) {
		GotoXY(oldX + 6, oldY + i);
		cout << del;
	}
	Sleep(this->speed);
}

void CDinausor::Right() {
	string end[3] = { "    ","     ","     " };
	string del = { ' ',' ',' ' };
	int oldX = mX, oldY = mY;

	mX++;

	if (this->isOut()) {
		for (int i = 0; i < 3; i++) {
			GotoXY(oldX - 6, oldY + i);
			cout << end[i];
		}
		return;
	}

	this->Draw();
	for (int i = 0; i < 3; i++) {
		GotoXY(oldX, oldY + i);
		cout << del;
	}
	Sleep(this->speed);
}

bool CDinausor::isOut() {
	if (direction) {
		return(mX > RIGHT_OUT || mX < RIGHT_IN);
	}
	else {
		return (mX > LEFT_OUT || mX < LEFT_IN);
	}
}

int CDinausor::getWidth() {
	return 6;
}
