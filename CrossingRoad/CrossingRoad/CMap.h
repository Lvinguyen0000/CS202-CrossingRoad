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
#include "CConsole.h"

#define speed1 150
#define speed2 100
#define speed3 75
#define speed4 25
#define speed5 10
#define MAX_OBS 5

#define MID_X 34
#define MID_Y 13

class CMap {
private:
	const int width, height;
	CPeople player;
	vector<CRoad> roads;
	int speed;
public:
	CMap() : width(90), height(30) {};
	~CMap();
	void CreateObject();
	void SaveMap(std::string);
	//void DrawObject();
	bool LoadMap(std::string);
	void NextState();
	void UseSpeed();
	void AdjustSpeed(int);
	void CPeopleMove(int move);
	//void ResetMap();


	void PrintWall();
	void PrintBorder();
	void PrintStart();
	void PrintLoadGame();
	void PrintDead();
	void PrintFinish();
	void printCol(int index, int height);
	void printRow(int index, int width);
	void PrintSetup();



	void printFile(int x, ofstream& outfile);
	int readFile(ifstream& infile);
};

