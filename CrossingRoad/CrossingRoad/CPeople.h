#pragma once
#include "CObstacle.h"
#include "CConsole.h"


class CPeople {
private:
	int mX, mY;
	bool mState; //Trang thai song chet 0: Chet 1: Song
public:
	CPeople();
	void drawPeople(int x = 45, int y = 26);
	void Up();
	void Left();
	void Right();
	void Down();
	//bool CheckCrash();
	//bool CheckIsDead();
	int GetX();
	int GetY();
	void SetXY(int, int);
};




