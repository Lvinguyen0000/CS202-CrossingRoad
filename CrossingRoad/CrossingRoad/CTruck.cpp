#include "CTruck.h"

CTruck::CTruck(int x, int y, bool direction, bool light, int speed) : CObstacle(x, y, direction, light, speed) {
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
void CTruck::Draw() {
	string Truck[3] = {
	" ___|\\_",//7
	"|___|_|",//7
	" *  *",//5
	};
	string ReserveTruck[3] = {
	"_/|___ ",
	"|_|___|",
	"  *  * ",
	};
	if (this->direction == 1) {
		for (int i = 0; i < 3; i++) {
			GotoXY(mX, mY + i);
			cout << ReserveTruck[i] << endl;
		}
	}
	else {
		for (int i = 0; i < 3; i++) {
			GotoXY(mX, mY + i);
			cout << Truck[i] << endl;
		}
	}
}

void CTruck::Right() {
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
	else if (mX >= 84) {
		for (int i = 0; i < 3; i++) {
			GotoXY(83, mY + i);
			cout << "        ";
		}
	}
}
void CTruck::Left() {
	int oldX = mX;
	mX--;
	if (mX > 84) return;
	else if (mX >= 2 && mX < 84) {

		this->Draw();
		for (int i = 0; i < 3; i++) {
			GotoXY(oldX + 6, mY + i);
			cout << " ";
		}
	}
	else if (mX < 2) {
		for (int i = 0; i < 3; i++) {
			GotoXY(1, mY + i);
			cout << "        ";
		}
	}
}


void CTruck::Move() {
	if (this->light == 1) {
		return;
	}
	else {
		if (this->direction == 1) {
			this->Left();
		}
		else this->Right();
		return;
	}
}


int CTruck::getWidth() {
	return 8;
}

