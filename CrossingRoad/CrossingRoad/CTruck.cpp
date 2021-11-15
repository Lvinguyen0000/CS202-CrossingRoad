#include "CTruck.h"
void CTruck::DrawTruck(int x, int y) {
	string truck[3] = {
	" ___|\\_",//8
	"|___|_|",//7
	" *  *",//5
	};
	for (int i = 0; i < 3; i++) {
		GotoXY(x, y + i);
		cout << truck[i];

	}
}
void CTruck::DrawTruckReserve(int x, int y) {
	string truck[3] = {
	" _/|___ ",
	" |_|___|",
	"   *  *",
	};
	for (int i = 0; i < 3; i++) {
		GotoXY(x, y + i);
		cout << truck[i];
	}
}
CTruck::~CTruck() {
	for(int i=0; i< 3; i++) {
		delete[] a[i];
	}
	delete a;
}

void CTruck::Move(int x, int y) {
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

	CVehicle::Move(x, y);
	string del[3] = { " ", " ", " " };
	string end[3] = {"        ","       ","     "};
	if (CVehicle::DIRECTION()) {
		string del[3] = { " ", " ", " " };
		string end[3] = { "        ","       ","     " };
		if (x < 1) return;
		else if (x == 1) {
			GotoXY(x, y);
			DrawTruck(x, y);
			Sleep(10);
		}
		else if (x > 1 && x < 84) {
			int oldX = x - 1, curX = x;
			GotoXY(curX, y);
			DrawTruck(curX, y);
			for (int i = 0; i < 3; i++) {
				GotoXY(oldX, y + i);
				cout << del[i];
			}
			Sleep(10);
		}
		else if (x == 84) {
			for (int i = 0; i < 3; i++) {
				GotoXY(x - 1, y + i);
				cout << end[i];
				GotoXY(90, y + i);
				cout << "|";
			}
		}
		else if (x > 84) return;
	}

}
