#include "CTruck.h"

//void CTruck::DrawTruck(int x, int y) {
//	string truck[3] = {
//	" ___|\\_",//7
//	"|___|_|",//7
//	" *  *",//5
//	};
//	for (int i = 0; i < 3; i++) {
//		GotoXY(x, y + i);
//		cout << truck[i];
//
//	}
//}
//void CTruck::DrawTruckReserve(int x, int y) {
//	string truck[3] = {
//	"_/|___",
//	"|_|___|",
//	"  *  * ",
//	};
//	for (int i = 0; i < 3; i++) {
//		GotoXY(x, y + i);
//		cout << truck[i];
//	}
//}
//void CTruck::Move() {
	//for (int i = 0; i < 3; i++) {
	//	for (int j = 0; j < 8; j++) {
	//		GotoXY(x + j, y + i);
	//		if (x + i + 8 >= 90 || x + i - 8 <= 0) {
	//			cout << ' ';
	//			for (int p = 17; p < 20; p++) {
	//				GotoXY(91, p);
	//				cout << '|';
	//			}
	//		}
	//		else { cout << a[i][j]; }
	//	}
	//	if (x != 1) {
	//		for (int i = 0; i < 3; i++) {
	//			GotoXY(x - 1, y + i);
	//			cout << ' ';
	//		}
	//	}
	//}
	//cout << endl;
	//CObstacle::Move();
	//int x = this->mX;
	//int y = this->mY;
	//if (this->direction == true) {
	//	string del[3] = { " ", " ", " " };
	//	string end[3] = { "        ","       ","     " };
	//	if (x < 1) return;
	//	else if (x == 1) {
	//		GotoXY(x, y);
	//		DrawTruck(x, y);
	//		Sleep(10);
	//	}
	//	else if (x > 1 && x < 84) {
	//		int oldX = x - 1, curX = x;
	//		GotoXY(curX, y);
	//		DrawTruck(curX, y);
	//		for (int i = 0; i < 3; i++) {
	//			GotoXY(oldX, y + i);
	//			cout << del[i];
	//		}
	//		Sleep(10);
	//	}
	//	else if (x == 84) {
	//		for (int i = 0; i < 3; i++) {
	//			GotoXY(x - 1, y + i);
	//			cout << end[i];
	//			GotoXY(90, y + i);
	//			cout << "|";
	//		}
	//	}
	//	else if (x > 84) return;
	//}
	//else {
	//	string del[3] = { " ", " ", " " };
	//	string end[3] = { "       ","        ","        " };
	//	if (x >= 84) return;
	//	else if (x == 83) {
	//		GotoXY(x, y);
	//		DrawTruckReserve(x, y);
	//		Sleep(20);
	//	}
	//	else if (x > 0 && x < 83) {
	//		int oldX = x + 1, curX = x;
	//		GotoXY(curX, y);
	//		DrawTruckReserve(curX, y);
	//		for (int i = 0; i < 3; i++) {
	//			GotoXY(x + 7, y + i);
	//			cout << del[i];
	//		}
	//		Sleep(20);
	//	}
	//	else if (x == 0) {
	//		for (int i = 0; i < 3; i++) {
	//			GotoXY(x + 1, y + i);
	//			cout << end[i];
	//		}
	//	}
	//}}
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
		return(mX > 84 || mX < 2);
	}
	else {
		return (mX < 0 || mX > 84);
	}
}



