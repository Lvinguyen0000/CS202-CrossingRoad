#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "CPeople.h"
#include "CRoad.h"
#include "CLevel.h"
#include "CCar.h"
#include "CTruck.h"
#include "CDinausor.h"
#include "CBird.h"

#define speed1 150
#define speed2 100
#define speed3 75
#define speed4 25
#define speed5 10
#define MAX_OBS 5

class CMap {
private:
	const int width, height;
	CPeople player;
	vector<CRoad> roads;
	int speed;
	static int score;
public:
	CMap() : width(90), height(30) {}
	void ResetMap();
	void SaveMap(std::string);
	//void DrawObject();
	bool LoadMap(std::string);
	void NextState();
	void UseSpeed();
	void AdjustSpeed(int);

	void PrintBorder();
	void PrintLevelUp();
	void PrintDead();
	void PrintFinish();
	void printCol(int index, int height);
	void printRow(int index, int width);
	void printFile(int x, ofstream& outfile);
	int readFile(ifstream& infile);
};

