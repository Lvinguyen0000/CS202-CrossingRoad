#include "CBird.h"

CBird::CBird() : CObstacle() {}

void CBird::Draw() {
	b[2] = {
		"* *",
		" * ",
	};

	GotoXY(mX, mY);
	for (int i = 0; i < 2; i++) {
		cout << b[i];
	}
}

CBird::~CBird() {
	delete b;
}

void CBird::Left() {
	string end[3] = { "    ","     ","     " };
	string del = { ' ',' ',' ' };
	int oldX = mX, oldY = this->mY;

	mX--;

	if (this->isOut()) {
		for (int i = 0; i < 2; i++) {
			GotoXY(oldX, oldY + i);
			cout << end[i];
		}
		return;
	}

	this->Draw();
	for (int i = 0; i < 2; i++) {
		GotoXY(oldX + 4, oldY + i);
		cout << del;
	}
	Sleep(this->speed);
}

void CBird::Right() {
	string end[3] = { "    ","     ","     " };
	string del = { ' ',' ',' ' };
	int oldX = mX, oldY = mY;

	mX++;

	if (this->isOut()) {
		for (int i = 0; i < 2; i++) {
			GotoXY(oldX - 4, oldY + i);
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

void CBird::Move() {
	if (direction) {
		Left();
	}
	else
		Right();
}


bool CBird::isOut() {
	if (direction)
		return (mX > 94 || mX < 2);
	else
		return (mX < 0 || mX > 84);
}
