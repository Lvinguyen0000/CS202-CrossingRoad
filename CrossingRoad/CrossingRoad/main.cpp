#include "CGame.h"
#include <mmsystem.h>

static CMap map;
static bool isMute = 0;
static bool isPause = 0;
static bool isLose = 0;
static bool isLoad = 0;
static bool isMenu = 0;
static int choice = -1;


void MenuGame() {
	clrscr();
	DisableMouse();
	map.PrintWall();
	if (!isMute) PlaySound(TEXT("menu.wav"), NULL, SND_FILENAME | SND_ASYNC);
	string choices[4] = { "New Game", "Load Game", "Setting", "Quit" };
	choice = 0;
	bool isChangeConsole = false;
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
		
		map.PrintStart();

		if (_kbhit()) {
			char KEY = toupper(_getch());
			if (KEY == 'w') {
				choice -= 1;
				if (choice < 0) choice = 3;
			}
			else if (KEY == 's') {
				choice += 1;
				if (choice > 3) choice = 0;
			}
			else if (KEY == 0 || KEY == -32) {
				KEY = _getch();
				if (KEY == 72) {
					choice -= 1;
					if (choice < 0) choice = 3;
				}
				else if (KEY == 80) {
					choice += 1;
					if (choice > 3) choice = 0;
				}
			}
			else if (KEY == 13) {
				isChangeConsole = true;
				return;
			}
		}
	}
}


void LoadGame() {
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
	map.PrintWall();
	map.PrintLoadGame();
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
				int oldPos = curPos;
				curPos -= 1;
				if (curPos < 0) curPos = files.size() - 1;
				GotoXY(13, 16 + oldPos);
				cout << "       ";
			}
			else if (KEY == 's')
			{
				int oldPos = curPos;
				curPos += 1;
				if (curPos > files.size() - 1) curPos = 0;
				GotoXY(13, 16 + oldPos);
				cout << "       ";
			}
			else if (KEY == 0 || KEY == -32) {
				KEY = _getch();
				if (KEY == 72) {
					int oldPos = curPos;
					curPos -= 1;
					if (curPos < 0) curPos = files.size() - 1;
					GotoXY(13, 16 + oldPos);
					cout << "       ";
				}
				else if (KEY == 80) {
					int oldPos = curPos;
					curPos += 1;
					if (curPos > files.size() - 1) curPos = 0;
					GotoXY(13, 16 + oldPos);
					cout << "       ";
				}
			}
			else if (KEY == 13)
			{
				map.~CMap();
				if (map.LoadMap(files[curPos])) {
					isLoad = 1;
					return;
				}
			}
			if (KEY == 27)
			{
				return;
			}
		}
	}
}


void SaveGame() {
	clrscr();
	string filename;
	DisableMouse();
	map.PrintWall();
	map.PrintSaveGame();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	GotoXY(4, 12);
	cout << "Input file name to save: ";
	//getline(cin, filename);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	char key;
	while ((key = _getch()) != 27) {
		switch (key) {
		case '\b':
			if (filename.size() != 0) {
				filename.pop_back();
				GotoXY(4, 15);
				cout << "                                                 ";
				GotoXY(4, 15);
				cout << filename;
			}
			break;
		case 13:
			map.SaveMap(filename);
			return;
		default:
			filename.push_back(key);
			GotoXY(50, 15);
			cout << filename;
		}
		if (key == 13) {
			clrscr();
			return;
		}
	}

}

void SettingGame() {
	clrscr();
	DisableMouse();
	map.PrintWall();
	string c1[2] = { "Sound: ON ", "Return to main menu" };
	string c2[2] = { "Sound: OFF", "Return to main menu" };
	int choice = 0;
	bool isChangeConsole = false;

	while (true) {
		for (int i = 0; i < 2; i++) {
			GotoXY(MID_X, MID_Y + i);
			if (i == choice) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}

			if (isMute == false)
				cout << c1[i] << endl;
			else
				cout << c2[i] << endl;
		}

		map.PrintStart();

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
				if (choice == 0) ToggleMute();
				if (!isMute) PlaySound(TEXT("menu.wav"), NULL, SND_FILENAME | SND_ASYNC);
				else if (isMute) PlaySound(NULL, 0, 0);
				if (choice == 1) break;
			}
		}
	}
}

void Quit(thread& t) {
	t.detach();
}


void ToggleMute() {
	isMute = !isMute;
}

void TogglePause() {
	isPause = !isPause;
}


vector<string> getAllFilename(const string& name)
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
void GameOver() {
	clrscr();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	GotoXY(4, 1); cout << "  ***   *****   **   **   ****    *****    *       *   ****   ****    " << endl;
	GotoXY(4, 2); cout << "**      *   *   * * * *   *      *     *    *     *    *      *   *   " << endl;
	GotoXY(4, 3); cout << "* ***   *****   *  *  *   ****   *     *     *   *     ****   ****    " << endl;
	GotoXY(4, 4); cout << "*  **   *   *   *     *   *      *     *      * *      *      *   *   " << endl;
	GotoXY(4, 5); cout << " ****   *   *   *     *   ****    *****        *       ****   *     * " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	Sleep(3000);
}

void FinishGame() {
	clrscr();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	GotoXY(4, 1); cout << "*    *   **    *****   ***** " << endl;
	GotoXY(4, 2); cout << "* *  *   **   *        *     " << endl;
	GotoXY(4, 3); cout << "*  * *   **   *        ***** " << endl;
	GotoXY(4, 4); cout << "*   **   **   *        *     " << endl;
	GotoXY(4, 5); cout << "*    *   **    *****   ***** " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	Sleep(3000);
}


void SoundEffect() {
	while (!isMute && !map.GetPeople().CheckIsDead()) {
		PlaySound(TEXT("game2.wav"), NULL, SND_FILENAME | SND_ASYNC);
		Sleep(60000);
	}
}


void Game() {
	clrscr();
	thread Save;
	thread Load;

	map.PrintBorder();
	if (!isLoad) map.CreateObject();
	else {
		map.PrintPeople();
		isLoad = 0;
	}
	map.PrintSetup();
	int move = -1;
	
	thread Sound(SoundEffect);


	while (true) {
		if (isPause == 0) map.NextState();
		if (map.CheckCrash()) {
			if (!isMute) PlaySound(TEXT("death.wav"), NULL, SND_FILENAME | SND_ASYNC);
			map.GetPeople().Kill();
			Quit(Sound);
			break;
		}

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
		map.CPeopleMove(move);
		map.UseSpeed();

		if (move == 5) {
			Save = thread(SaveGame);
			Save.join();
			clrscr();
			map.PrintBorder();
			map.PrintSetup();
			map.PrintPeople();
		}
		else if (move == 6) {
			Load = thread(LoadGame);
			Load.join();
			clrscr();
			map.PrintBorder();
			map.PrintSetup();
			map.PrintPeople();
		}
		else if (move == 7) {
			ToggleMute();
			if (!isMute) PlaySound(TEXT("game2.wav"), NULL, SND_FILENAME | SND_ASYNC);
			else if (isMute) PlaySound(NULL, 0, 0);
		}
		else if (move == 8) {
			isMenu = 1;
			map.~CMap();
			Quit(Sound);
			return;
		}
		move = -1;
	}
	map.~CMap();
	return;
}


int main() {
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);

	MoveWindow(console, r.left, r.top, 960, 630, TRUE);
	FixConsoleWindow();
	DisableMouse();

	thread main;
	thread game;

	while (true) {
		main = thread(MenuGame);
		main.join();
		if (choice == 0) {
			game = thread{ Game };
			game.join();
			if (isMenu) {
				isMenu = 0;
			}
			else if (map.GetPeople().CheckIsDead()) {
				thread lose(GameOver);
				lose.join();
			}
			else {
				thread win(FinishGame);
				win.join();
			}
		}
		else if (choice == 1) {
			thread Load(LoadGame);
			Load.join();
			game = thread{ Game };
			game.join();
			if (isMenu) {
				isMenu = 0;
			}
			else if (map.GetPeople().CheckIsDead()) {
				thread lose(GameOver);
				lose.join();
			}
			else {
				thread win(FinishGame);
				win.join();
			}
		}
		else if (choice == 2)
		{
			thread Setting(SettingGame);
			Setting.join();
		}
		else if (choice == 3) {
			break;
		}
	}
}


 