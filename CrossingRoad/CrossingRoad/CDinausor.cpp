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
		return(mX > 84 || mX < 2);
	}
	else {
		return (mX < 0 || mX > 84);
	}
}
