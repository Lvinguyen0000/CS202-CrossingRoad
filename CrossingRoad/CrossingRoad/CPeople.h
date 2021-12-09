#pragma once
#include <deque>
#include "CObstacle.h"
#include "CConsole.h"


class CPeople {
private:
	int mX, mY;
	bool mState; //Trang thai song chet 0: Chet 1: Song
public:
	CPeople();
	~CPeople() = default;
	void drawPeople(int x = 45, int y = 26);
	void Up();
	void Left();
	void Right();
	void Down();
	bool CheckIsFinished();
	bool CheckImpact(CObstacle*& c);
	bool CheckIsDead();
	int GetX();
	int GetY();
	void SetXY(int, int);
	void Kill();
};




