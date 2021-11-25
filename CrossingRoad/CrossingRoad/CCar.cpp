#include "CCar.h"

CCar::CCar(int x, int y, bool direction, bool light, int speed) : CObstacle(x, y, direction, light, speed) {

}

void CCar::Draw() {
	string car[3] = {
		"_/```\\__",
		"\_ __ _/ ",
		"  *  *  "
	};

	string reversedCar[3] = {
		"__/```\\_",
		"\\_ __ _/",
		"  *   * ",
	};
	if (this->direction == 1) {
		GotoXY(this->mX, this->mY);
		for (int i = 0; i < 3; i++) cout << reversedCar[i] << endl;
	}
	else {
		GotoXY(this->mX, this->mY);
		for (int i = 0; i < 3; i++) cout << car[i] << endl;
	}
}

void CCar::Move() {
	if (this->light == 1) {
		this->Draw();
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
	string del = { ' ',' ',' ' };
	int oldX = this->mX; int oldY = this->mY;

	this->mX -= 1;
	if (this->isOut()) return;
	this->Draw();
	for (int i = 0; i < 3; i++) {
		GotoXY(oldX + 9, oldY + i);
		cout << del;
	}
}
	
void CCar::Right() {
	string del = { ' ',' ',' ' };
	int oldX = this->mX; int oldY = this->mY;

	this->mX += 1;
	if (this->isOut()) return;
	this->Draw();
	for (int i = 0; i < 3; i++) {
		GotoXY(oldX , oldY + i);
		cout << del;
	}
	Sleep(this->speed);
}

bool CCar::isOut() {
	if (this->direction == 1) {
		return(mX > RIGHT_OUT || mX < RIGHT_IN);
	}
	else {
		return (mX > LEFT_OUT || mX < LEFT_IN);
	}
}

int CCar::getWidth() {
	return 9;
}