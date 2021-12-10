#include "CCar.h"

CCar::CCar(int x, int y, bool direction, bool light, int speed) : CObstacle(x, y, direction, light, speed) {
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

void CCar::Draw() {
	string car[3] = {
		"_/```\\__",
		"\\_ __ _/ ",
		"  *  *  "
	};

	string reversedCar[3] = {
		"__/```\\_ ",
		"\\_ __ _/ ",
		"  *   * ",
	};
	if (this->direction == 1) {

		for (int i = 0; i < 3; i++) {
			GotoXY(this->mX, this->mY + i);
			cout << reversedCar[i] << endl;
		}
	}
	else {
		for (int i = 0; i < 3; i++) {
			GotoXY(this->mX, this->mY + i);
			cout << car[i] << endl;
		}
	}
}

void CCar::Move() {
	if (this->light == 1) {
		return;
	}
	else {
		if (this->direction == 1) {
			this->Left();
		}
		else {
			this->Right();
		}
	}
}

void CCar::Left() {
	int oldX = mX;
	mX--;
	if (mX > 82) return;
	else if (mX >= 2 && mX <= 82) {
		this->Draw();
		for (int i = 0; i < 3; i++) {
			GotoXY(oldX + 8, mY + i);
			cout << " ";
		}
	}
	else if (mX < 2) {
		for (int i = 0; i < 3; i++) {
			GotoXY(1, mY + i);
			cout << "         ";
		}
	}
}

void CCar::Right() {

	int oldX = mX;
	mX++;
	if (mX < 1) return;
	else if (mX > 2 && mX < 81) {

		this->Draw();
		for (int i = 0; i < 3; i++) {
			GotoXY(oldX, mY + i);
			cout << " ";
		}
	}
	else if (mX >= 81) {
		for (int i = 0; i < 3; i++) {
			GotoXY(80, mY + i);
			cout << "         ";
		}
	}
}


int CCar::getWidth() {
	return 10;
}