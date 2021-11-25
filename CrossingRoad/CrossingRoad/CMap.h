#pragma once
#include <iostream>
#include <vector>
#include "CPeople.h"
#include "CRoad.h"

class CMap {
private:
	const int width, height;
	CPeople player;
	vector<CRoad> roads;
	static int score;
public:
	CMap();
	void ResetMap();
	void SaveMap();
	void DrawObject();
	void LoadMap();
	void PrintBorder();
	void PrintLevelUp();
	void PrintDead();
	void PrintFinish();
};

