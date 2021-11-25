#include "CTruck.h"

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
			cout << ReserveTruck[i];
		}
	}
	else {
		for (int i = 0; i < 3; i++) {
			GotoXY(mX, mY + i);
			cout << Truck[i];
		}
	}
}
void CTruck::Right() {
	string del = " ";
	string end = "        ";
	int oldX = this->mX, oldY = this->mY;
	if (this->mX == 1) this->Draw();
	else if (this->mX > 1 && this->mX < 84) {
		this->mX += 1;
		GotoXY(mX, mY);
		this->Draw();
		for (int i = 0; i < 3; i++) {
			GotoXY(oldX, mY + i);
			cout << del;
		}
	}
	else if (mX == 84) {
		this->Draw();
		for (int i = 0; i < 3; i++) {
			GotoXY(mX, mY + i);
			cout << end;
			GotoXY(90, mY + i);
			cout << "|";
		}
	}
	else return;
}
void CTruck::Left() {
	if (mX > 84) return;
	else if (mX == 84) this->Draw();
	else if (mX >= 2 && mX < 84) {
		int oldX = mX;
		mX -= 1;
		this->Draw();
		for (int i = 0; i < 3; i++) {
			GotoXY(oldX + 6, mY + i);
			cout << " ";
		}
	}
	else if (mX == 1) {
		for (int i = 0; i < 3; i++) {
			GotoXY(1, mY + i);
			cout << "       ";
		}
	}
}
void CTruck::Move() {
	if (this->light == 1) {
		this->Draw();
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
bool CTruck::isOut() {
	if (this->direction == 1) {
		return(mX > RIGHT_OUT || mX < RIGHT_IN); // 84 2
	}
	else {
		return (mX > LEFT_OUT || mX < LEFT_IN); // 0 84
	}
}

int CTruck::getWidth() {
	return 8;
}

