#include "CBird.h"

CBird::CBird(int x, int y, bool direction, bool light, int speed) : CObstacle(x, y, direction, light, speed) {
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

void CBird::Draw() {
	string b[2] = {
		"* *",
		" * ",
	};
	for (int i = 0; i < 2; i++) {
		GotoXY(mX, mY + i);
		cout << b[i] << endl;
	}
}

void CBird::Left() {
	int oldX = mX;
	mX--;
	if (mX > 88) return;
	else if (mX >= 2 && mX < 88) {
		this->Draw();
		for (int i = 0; i < 3; i++) {
			GotoXY(oldX + 2, mY + i);
			cout << " ";
		}
	}
	else if (mX < 2) {
		for (int i = 0; i < 3; i++) {
			GotoXY(1, mY + i);
			cout << "     ";
		}
	}
}

void CBird::Right() {
	int oldX = mX;
	mX++;
	if (mX < 1) return;
	else if (mX > 2 && mX < 87) {

		this->Draw();
		for (int i = 0; i < 3; i++) {
			GotoXY(oldX, mY + i);
			cout << " ";
		}
	}
	else if (mX == 87) {
		for (int i = 0; i < 3; i++) {
			GotoXY(86, mY + i);
			cout << "   ";
		}
	}
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
		return (mX > RIGHT_OUT || mX < RIGHT_IN);
	else
		return (mX > LEFT_OUT || mX < LEFT_IN);
}

int CBird::getWidth() {
	return 3;
}