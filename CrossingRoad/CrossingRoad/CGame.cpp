#include "CGame.h"

CGame::CGame() : width(90), height(30) {

}

void CGame::drawGame() {
	clrscr();
	GotoXY(0, 0);
	for (int i = 0; i <= height; i += 5) {
		printRow(i, this->width);
	}
	printCol(0, this->height);
	printCol(this->width + 1, this->height);

	cn.drawPeople();
	int move; // 1: UP 2: DOWN 3: RIGHT 4:LEFT
	
	//int run = 1;
	
	while (true) {
		//road.drawNextState();
		Sleep(50);

		//if (run < 90) {
		//	cd.Move(run, 10);
		//	ac.Move(run, 6);
		//	truck.Move(run1, 17);
		//	car.Move(run1, 22);
		//	Sleep(10);
		//	run++;
		//}
		//else run = 1; 

		move = -1;

		if (_kbhit()) {
			char KEY = _getch();
			if (KEY == 'w') {
				move = 1;
			}
			else if (KEY == 's') {
				move = 2;
			}
			else if (KEY == 'd') {
				move = 3;
			}
			else if (KEY == 'a') {
				move = 4;
			}
			else if (KEY == 0 || KEY == -32) {
				KEY = _getch();
				if (KEY == 72) move = 1;
				else if (KEY == 80) move = 2;
				else if (KEY == 77) move = 3;
				else if (KEY == 75) move = 4;
			}
		}
		if (move == 1) cn.Up();
		else if (move == 2) cn.Down();
		else if (move == 3) cn.Right();
		else if (move == 4) cn.Left();
	}
	_getch();
}

void printCol(int index, int height) {
	for (int y = 0; y <= height; y++) {
		GotoXY(index, y);
		cout << '|';
	}
}

void printRow(int index, int width) {
	for (int x = 0; x <= width; x++) {
		GotoXY(x, index);
		cout << '-';
	}
}
