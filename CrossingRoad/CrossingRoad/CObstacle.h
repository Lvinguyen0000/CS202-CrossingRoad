#pragma once
#include <iostream>
using namespace std;


class CObstacle {
protected:
	int mX, mY;
	bool direction; //1:left 0:right
	bool light; //1:red 0:green
	int speed; // truyền vào sleep
public:
	CObstacle(int x = 0, int y = 0, bool direction = 0, bool light = 0, int speed = 0);
	virtual void Move() = 0;
	virtual void Draw() = 0;
	virtual int getWidth() = 0;
	int GetX();
	int GetY();
	void SetLight(bool light);
	void SetDir(bool direction);
	void SetSpeed(int speed);
};

