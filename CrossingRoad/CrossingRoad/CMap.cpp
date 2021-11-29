#include "CMap.h"


CMap::~CMap() {
	this->player.~CPeople();
	this->roads.erase(roads.begin(), roads.end());
}

void CMap::PrintWall() {
	GotoXY(0, 0);
	TextColor(15);
	printCol(0, this->height);
	printCol(this->width, this->height);
	printRow(0, this->width);
	printRow(this->height, this->width);
}


void CMap::PrintBorder() {
	GotoXY(0, 0);
	TextColor(15);
	for (int i = 0; i <= height; i += 5) {
		printRow(i, this->width);
	}
	printCol(0, this->height);
	printCol(this->width + 1, this->height);
}


void CMap::printCol(int index, int height) {
	for (int y = 0; y <= height; y++) {
		GotoXY(index, y);
		cout << '|';
	}
}

void CMap::printRow(int index, int width) {
	for (int x = 0; x <= width; x++) {
		GotoXY(x, index);
		cout << '-';
	}
}


void CMap::PrintLoadGame() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	GotoXY(4, 1); cout << "**      *******      ****     *******" << endl;
	GotoXY(4, 2); cout << "**     **     **    **  **    **     *" << endl;
	GotoXY(4, 3); cout << "**     **     **   ********   **      * **     ** ******** **    ** **    **" << endl;
	GotoXY(4, 4); cout << "****** **     **  **********  **     *  ** * * ** **       ** *  ** **    **" << endl;
	GotoXY(4, 5); cout << "******  *******  **        ** *******   **  *  ** *******  **  * ** **    **" << endl;
	GotoXY(4, 6); cout << "                                        **     ** **       **   *** **    **" << endl;
	GotoXY(4, 7); cout << "                                        **     ** ******** **    ** ********" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
}

void CMap::PrintDead() {

}

void CMap::PrintFinish() {

}

void CMap::printFile(int x, ofstream& outfile) {
	outfile.write((char*)&x, sizeof(int));
}

int CMap::readFile(ifstream& infile) {
	int x;
	infile.read((char*)&x, sizeof(int));
	return x;
}

void CMap::SaveMap(string file) {
	//"./data/" +
	ofstream outfile(file + ".bin", ios::out | ios::binary);
	printFile(player.GetX(), outfile);
	printFile(player.GetY(), outfile);

	for (int i = 0; i < roads.size(); i++) {
		printFile(roads[i].getDir(), outfile);
		printFile(roads[i].getLight(), outfile);
		printFile(roads[i].getSpeed(), outfile);
		printFile(roads[i].getSize(), outfile);

		for (int j = 0; j < roads[i].getSize(); j++) {
			printFile(roads[i].getType(j), outfile);
			printFile(roads[i].getX(j), outfile);
			printFile(roads[i].getY(j), outfile);
		}
	}
	outfile.close();
}

bool CMap::LoadMap(string file) {
	this->~CMap();
	//"./data/" + 
	ifstream infile(file + ".bin", ios::in | ios::binary);
	if (!infile.is_open()) {
		return false;
	}
	int playerX, playerY;
	playerX = readFile(infile);
	playerY = readFile(infile);
	player.SetXY(playerX, playerY);

	for (int i = 0; i < 4; i++) {
		new(&roads[i]) CRoad(row1Y + 5*i);
		int dir, light, speed;
		dir = readFile(infile);
		light = readFile(infile);
		speed = readFile(infile);
		roads[i].SetDir(bool(dir));
		roads[i].SetLight(bool(light));
		roads[i].SetSpeed(speed);
		int size = readFile(infile);

		for (int j = 0; j < size; j++) {
			CObstacle* temp = nullptr;
			int type, loadedX, loadedY;
			type = readFile(infile);
			loadedX = readFile(infile);
			loadedY = readFile(infile);

			if (type == 1) {
				temp = new CCar(loadedX, loadedY, dir, light, speed);
			}
			else if (type == 2) {
				temp = new CTruck(loadedX, loadedY, dir, light, speed);
			}
			else if (type == 3) {
				temp = new CDinausor(loadedX, loadedY, dir, light, speed);
			}
			else if (type == 4) {
				temp = new CBird(loadedX, loadedY, dir, light, speed);
			}
			roads[i].PushLoaded(temp);
		}
	}
	infile.close();
	return true;
}


void CMap::UseSpeed() {
	Sleep(this->speed);
}


void CMap::CreateObject() {
	new(&player) CPeople();
	player.drawPeople();
	speed = speed5;
	srand(time(0));
	for (int i = 0; i < 4; i++) {
		CRoad rod(row4Y - i * 5);
		rod.SetDir(rand() % 2);
		rod.SetLight(0);
		rod.SetSpeed(speed1);
		roads.push_back(rod);
	}
}

void CMap::NextState() {
	TextColor(15);
	for (int i = 0; i < roads.size(); i++) {
		if ((roads[i].getLight() && (rand() % 75 == 0)) || (!roads[i].getLight() && (rand() % 50 == 0))) {
			roads[i].ToggleLight();
		}
		roads[i].PushObstacle((rand() % 15 == 0), MAX_OBS);
		roads[i].DrawRoad();
	}
}

void CMap::AdjustSpeed(int speed) {
	this->speed = speed;
	for (int i = 0; i < roads.size(); i++) {
		roads[i].SetSpeed(speed);
	}
}


void CMap::PrintStart() {
	int color = rand() % 7 + 9;
	TextColor(color);
	GotoXY(4, 1); cout << " =====  =======   ======   =====  ===== ==== ===       =======" << endl;
	GotoXY(4, 2); cout << "||     ||     |  ||	   |  ||     ||	     ||	||  \\   | ||  " << endl;
	GotoXY(4, 3); cout << "||     ||_____|  ||	   |  ||___  ||___   ||	||   \\  | ||   ====  " << endl;
	GotoXY(4, 4); cout << "||     ||   \\    ||    |       |     |   ||	||    \\ | ||_____||         	" << endl;
	GotoXY(4, 5); cout << " =========== \\    ======   ===== =====  ==== ======   ======      /\\      ====\\\\" << endl;
	GotoXY(4, 6); cout << "                                            ||     | ||    |     // \\    ||	   |" << endl;
	GotoXY(4, 7); cout << "                                            || ====  ||    |    //   \\   ||	   |" << endl;
	GotoXY(4, 8); cout << "                                            ||   \\\\  ||    |   //  ===\\  ||	   |" << endl;
	GotoXY(4, 9); cout << "                                            ||    \\\\  ======  //	   \\  ====//" << endl;
}

void CMap::CPeopleMove(int move) {
	if (move == 1) this->player.Up();
	else if (move == 2) this->player.Down();
	else if (move == 3) this->player.Right();
	else if (move == 4) this->player.Left();
	else return;
}

void CMap::PrintSetup() {
	GotoXY(100, 3); cout << "   MANUAL GUIDE   " << endl;
	GotoXY(100, 4); cout << "[W] [UP] Di len" << endl;
	GotoXY(100, 5); cout << "[S] [DOWN] Di xuong" << endl;
	GotoXY(100, 6); cout << "[A] [LEFT] Sang trai" << endl;
	GotoXY(100, 7); cout << "[D] [RIGHT] Sang phai" << endl;

	GotoXY(100, 11); cout << "[L] Luu game" << endl;
	GotoXY(100, 12); cout << "[P] Pause/ Countinue Game" << endl;
	GotoXY(100, 13); cout << "[K} Mute/ Unmute Game" << endl;
	GotoXY(100, 14); cout << "[M] Tro ve menu" << endl;

}