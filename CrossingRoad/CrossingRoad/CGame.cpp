#include "CGame.h"


//void CGame::drawGame() {
//	DisableMouse();
//	map.PrintBorder();
//	map.ResetMap();
//
//	while (true) {
//		map.NextState();
//	}
//	_getch();
//}


void CGame::MenuGame() {
	clrscr();
	DisableMouse();
	this->map.PrintWall();
	string choices[4] = { "New Game", "Load Game", "Setting", "Quit" };
	int choice = 0;
	bool isChangeConsole = false;
	while (true) {
		while (true) {
			for (int i = 0; i < 4; i++) {
			GotoXY(MID_X, MID_Y + i);
			if (i == choice) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			cout << choices[i] << endl;
			}

			this->map.PrintStart();

			if (_kbhit()) {
			char KEY = _getch();
			if (KEY == 'w') {
				choice -= 1;
				if (choice < 0) choice = 4;
			}
			else if (KEY == 's') {
				choice += 1;
				if (choice > 3) choice = 0;
			}
			else if (KEY == 0 || KEY == -32) {
				KEY = _getch();
				if (KEY == 72) {
					choice -= 1;
					if (choice < 0) choice = 4;
				}
				else if (KEY == 80) {
					choice += 1;
					if (choice > 3) choice = 0;
				}
			}
			else if (KEY == 13) {
				isChangeConsole = true;
				break;
			}
			}
		}
		if (choice == 0) this->NewGame();
		else if (choice == 1) this->LoadGame();
		else if (choice == 2) this->SettingGame();
		else if (choice == 3) this->Quit();
	}
}


void CGame::NewGame() {
	clrscr();
	this->map.PrintBorder();
	this->map.CreateObject();
	this->map.PrintSetup();
	int move = -1;
	
	while(true){
		if (this->isPause == 0) this->map.NextState();
		
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
			else if (KEY == 'l') {
				move = 5;
			}
			else if (KEY == 'p') {
				move = 6;
			}
			else if (KEY == 'k') {
				move = 7;
			}
			else if (KEY == 'm') {
				move = 8;
			}
			else if (KEY == 0 || KEY == -32) {
				KEY = _getch();
				if (KEY == 72) move = 1;
				else if (KEY == 80) move = 2;
				else if (KEY == 77) move = 3;
				else if (KEY == 75) move = 4;
			}
		}
		this->map.CPeopleMove(move);
		this->map.UseSpeed();
		
		if (move == 5) {
			this->SaveGame();
		}
		else if (move == 6) {
			this->TogglePause();
		}
		else if (move == 7) {
			this->ToggleMute();
		}
		else if (move == 8) {
			this->map.~CMap();
			this->MenuGame();
		}
		move = -1;
	}

}

void CGame::LoadGame() {
	clrscr();
	string filename;
	vector <string> files = getAllFilename("data");
	if (files.size() == 0) {
		GotoXY(30, 15);
		cout << "No saved file to load !!!";
		Sleep(1000);
		clrscr();
		return;
	}
	int curPos = 0;
	clrscr();
	this->map.PrintWall();
	this->map.PrintLoadGame();
	GotoXY(20, 13); cout << "<Press ESC to escape...>";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	GotoXY(20, 15);
	cout << "Choose Filename to load: ";

	for (int i = 0; i < (int)files.size(); ++i) {
		GotoXY(20, 16 + i);
		cout << files[i] << endl;
	}
	while (true) {
		GotoXY(13, 16 + curPos);
		cout << ">>>   ";
		if (_kbhit())
		{
			char KEY = _getch();
			if (KEY == 'w')
			{
				curPos -= 1;
				if (curPos < 0) curPos = files.size() - 1;
			}
			else if (KEY == 's')
			{
				curPos += 1;
				if (curPos > files.size() - 1) curPos = 0;
			}
			else if (KEY == 0 || KEY == -32) {
				KEY = _getch();
				if (KEY == 72) {
					curPos -= 1;
					if (curPos < 0) curPos = files.size() - 1;
				}
				else if (KEY == 80) {
					curPos += 1;
					if (curPos > files.size() - 1) curPos = 0;
				}
			}
			else if (KEY == 13)
			{
				this->map.LoadMap(files[curPos]);
				this->NewGame();
				clrscr();
			}
			if (KEY == 27)
			{
				return;
			}
		}
	}
}


void CGame::SaveGame() {

}

void CGame::SettingGame() {
	clrscr();
	DisableMouse();
	this->map.PrintWall();
	string c1[2] = { "Sound: ON ", "Return to main menu" };
	string c2[2] = { "Sound: OFF", "Return to main menu" };
	int choice = 0;
	bool isChangeConsole = false;
	while (true) {
		while (true) {
			for (int i = 0; i < 2; i++) {
				GotoXY(MID_X, MID_Y + i);
				if (i == choice) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				}
				else {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				}

				if (this->isMute == false)
					cout << c1[i] << endl;
				else
					cout << c2[i] << endl;
			}

			this->map.PrintStart();

			if (_kbhit()) {
				char KEY = _getch();
				if (KEY == 'w') {
					choice -= 1;
					if (choice < 0) choice = 1;
				}
				else if (KEY == 's') {
					choice += 1;
					if (choice > 1) choice = 0;
				}
				else if (KEY == 0 || KEY == -32) {
					KEY = _getch();
					if (KEY == 72) {
						choice -= 1;
						if (choice < 0) choice = 1;
					}
					else if (KEY == 80) {
						choice += 1;
						if (choice > 1) choice = 0;
					}
				}
				else if (KEY == 13) {
					isChangeConsole = true;
					break;
				}
			}
		}
		if (choice == 0)
			this->ToggleMute();
		else if (choice == 1) this->MenuGame();
	}
}

void CGame::Quit() {

}


void CGame::ToggleMute() {
	this->isMute = !this->isMute;
}

void CGame::TogglePause() {
	this->isPause = !this->isPause;
}


vector<string> CGame::getAllFilename(const string& name)
{
	vector<string> v;
	string pattern(name);
	pattern.append("\\*");
	std::wstring stemp = std::wstring(pattern.begin(), pattern.end());
	LPCWSTR sw = stemp.c_str();
	WIN32_FIND_DATA data;
	HANDLE hFind;
	if ((hFind = FindFirstFile(sw, &data)) != INVALID_HANDLE_VALUE) {
		do {
			wchar_t* txt = data.cFileName;
			wstring ws(txt);
			string str(ws.begin(), ws.end());
			if (str[0] == '.') continue;
			v.push_back(str);
		} while (FindNextFile(hFind, &data) != 0);
		FindClose(hFind);
	}
	return v;
}
void CGame::GameOver() {
	clrscr();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	GotoXY(4, 1); cout << "  ***   *****   **   **   ****    *****    *       *   ****   ****    " << endl;
	GotoXY(4, 2); cout << "**      *   *   * * * *   *      *     *    *     *    *      *   *   " << endl;
	GotoXY(4, 3); cout << "* ***   *****   *  *  *   ****   *     *     *   *     ****   ****    " << endl;
	GotoXY(4, 4); cout << "*  **   *   *   *     *   *      *     *      * *      *      *   *   " << endl;
	GotoXY(4, 5); cout << " ****   *   *   *     *   ****    *****        *       ****   *     * " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	int choice = 0;
	bool isChangeConsole = false;
	const char* c[2] = { "<Continue>", "<Menu>" };

	while (true) {
		while (isChangeConsole != true) {
			for (int i = 0; i < 2; i++) {
				GotoXY(MID_X, MID_Y + i);
				if (i == choice) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
					cout << c[i] << endl;
				}
				else {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					cout << c[i] << endl;
				}
			}

			if (_kbhit()) {
				char KEY = _getch();
				if (KEY == 'w') {
					choice -= 1;
					if (choice < 0) choice = 1;
				}
				else if (KEY == 's') {
					choice += 1;
					if (choice > 1) choice = 0;
				}
				else if (KEY == 0 || KEY == -32) {
					KEY = _getch();
					if (KEY == 72) {
						choice -= 1;
						if (choice < 0) choice = 1;
					}
					else if (KEY == 80) {
						choice += 1;
						if (choice > 1) choice = 0;
					}
				}
				else if (KEY == 13) {
					isChangeConsole = true;
					break;
				}
			}
		}
		if (choice == 0) this->NewGame();
		else if (choice == 1) this->MenuGame();
	}
}
void CGame::FinishGame() {
	clrscr();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	GotoXY(4, 1); cout << "*    *   **    *****   ***** " << endl;
	GotoXY(4, 2); cout << "* *  *   **   *        *     " << endl;
	GotoXY(4, 3); cout << "*  * *   **   *        ***** " << endl;
	GotoXY(4, 4); cout << "*   **   **   *        *     " << endl;
	GotoXY(4, 5); cout << "*    *   **    *****   ***** " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	int choice = 0;
	bool isChangeConsole = false;
	const char* c[2] = { "<Next level>", "<Menu>" };

	while (true) {
		while (isChangeConsole != true) {
			for (int i = 0; i < 2; i++) {
				GotoXY(MID_X, MID_Y + i);
				if (i == choice) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
					cout << c[i] << endl;
				}
				else {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					cout << c[i] << endl;
				}
			}

			if (_kbhit()) {
				char KEY = _getch();
				if (KEY == 'w') {
					choice -= 1;
					if (choice < 0) choice = 1;
				}
				else if (KEY == 's') {
					choice += 1;
					if (choice > 1) choice = 0;
				}
				else if (KEY == 0 || KEY == -32) {
					KEY = _getch();
					if (KEY == 72) {
						choice -= 1;
						if (choice < 0) choice = 1;
					}
					else if (KEY == 80) {
						choice += 1;
						if (choice > 1) choice = 0;
					}
				}
				else if (KEY == 13) {
					isChangeConsole = true;
					break;
				}
			}
		}
		if (choice == 0) {
			//update game moi voi level ke tiep
		}
		else if (choice == 1) this->MenuGame();
	}
}