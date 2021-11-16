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

void CBird::Move() {
	string del[3] = { " "," "," " };
	string end[3] = { "    ","     ","     " };
	if (direction) {
		if (mX < 84) {
			int oldX = mX, preX = mX + 1;
			GotoXY(preX, mY);
			Draw();
			GotoXY(oldX, mY);
			for (int i = 0; i < 2; i++) {
				GotoXY(oldX, mY + i);
				cout << del[i];
			}
		}
		else if (mX == 84) {
			for (int i = 0; i < 2; i++) {
				GotoXY(mX, mY + i);
				cout << end[i];
			}
		}
		else
			return;
	}
	else {
		if (mX > 84) {
			for (int i = 0; i < 2; i++) {
				GotoXY(91, mY);
				cout << "|";
			}
		}

		else if (mX == 1) {
			for (int i = 0; i < 2; i++) {
				GotoXY(mX, mY + i);
				cout << end[i];
			}
		}
		else if (mX < 1) return;
		
		else {
			int oldX = mX + 4, preX = mX - 1;
			GotoXY(preX, mY);
			Draw();
			GotoXY(oldX, mY);
			for (int i = 0; i < 2; i++) {
				GotoXY(oldX, mY + i);
				cout << del[i];
			}
		}
	}
}


bool CBird::isOut(int x) {
	return (x >= 90);
}
