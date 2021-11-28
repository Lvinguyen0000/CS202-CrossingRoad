#include "CGame.h"

CGame::CGame() {

}

void CGame::drawGame() {
	DisableMouse();
	map.PrintBorder();
	map.ResetMap();

	while (true) {
		map.NextState();

		/*move = -1;

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
		else if (move == 4) cn.Left();*/
	}
	_getch();
}

//void printCol(int index, int height) {
//	for (int y = 0; y <= height; y++) {
//		GotoXY(index, y);
//		cout << '|';
//	}
//}
//
//void printRow(int index, int width) {
//	for (int x = 0; x <= width; x++) {
//		GotoXY(x, index);
//		cout << '-';
//	}
//}
