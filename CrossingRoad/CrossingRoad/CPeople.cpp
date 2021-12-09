#include "CPeople.h"

CPeople::CPeople() : mX(44), mY(27) {
	mState = 1;
}


void CPeople::drawPeople(int x, int y) {
	if (mState == 0) return;
	string man[3] = {
		" o ",
		"/|\\",
		"/ \\",
	};
	this->mX = x; this->mY = y;
	for (int i = 0; i < 3; i++) {
		GotoXY(x, y + i);
		cout << man[i];
	}
}

void CPeople::Up() {
	if (mState == 0) return;
	if (mY <= 3) return;
	string del[3] = { "   ","   ","   " };
	int oldX = mX, oldY = mY;
	mY -= 5;
	drawPeople(mX, mY);
	GotoXY(oldX, oldY);
	for (int i = 0; i < 3; i++) {
		GotoXY(oldX, oldY + i);
		cout << del[i];
	}
}

void CPeople::Down() {
	if (mState == 0) return;
	if (mY >= 26) return;
	string del[3] = { "   ","   ","   " };
	int oldX = mX, oldY = mY;
	mY += 5;
	drawPeople(mX, mY);
	for (int i = 0; i < 3; i++) {
		GotoXY(oldX, oldY + i);
		cout << del[i];
	}
}

void CPeople::Right() {
	if (mState == 0) return;
	if (mX >= 87) return;
	string del[3] = { "   ","   ","   " };
	int oldX = mX, oldY = mY;
	mX += 3;
	drawPeople(mX, mY);
	GotoXY(oldX, oldY);
	for (int i = 0; i < 3; i++) {
		GotoXY(oldX, oldY + i);
		cout << del[i];
	}
}

void CPeople::Left() {
	if (mState == 0) return;
	if (mX <= 3) return;
	string del[3] = { "   ","   ","   " };
	int oldX = mX, oldY = mY;
	mX -= 3;
	drawPeople(mX, mY);
	GotoXY(oldX, oldY);
	for (int i = 0; i < 3; i++) {
		GotoXY(oldX, oldY + i);
		cout << del[i];
	}

}


int CPeople::GetX() {
	return mX;
}

int CPeople::GetY() {
	return mY;
}

void CPeople::SetXY(int x, int y) {
	mX = x;
	mY = y;
}

bool CPeople::CheckImpact(CObstacle*& c) {
	if (c->GetY() >= this->mY && c->GetY() -5 < this->mY) {
		if (this->mX > c->GetX() && this->mX - c->GetX() < c->getWidth())
			return true;
		else if (this->mX < c->GetX() && c->GetX() - this->mX < 3)
			return true;
	}
	return false;
}

bool CPeople::CheckIsDead() {
	return !mState;
}

bool CPeople::CheckIsFinished() {
	return (this->mY < 4);
}

void CPeople::Kill() {
	this->mState = false;
}