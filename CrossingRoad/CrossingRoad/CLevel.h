#pragma once
#include <iostream>

using namespace std;
class CLevel {
private:
	int level;
	int speed;
	int maxObstacle;
	const int maxLevel = 5;
public:
	CLevel();
	CLevel(int level, int maxObstacle);
	int GetLevel();
	bool NewLevel(int lv);
	bool NextLevel();
	int GetSpeed();
};

