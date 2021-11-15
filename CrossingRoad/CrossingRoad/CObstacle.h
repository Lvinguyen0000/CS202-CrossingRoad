#pragma once
#include <iostream>
using namespace std;

class CObstacle {
protected:
	int mX, mY;
	bool direction;
	bool light;
	int speed;
public:
	CObstacle(int x = 0, int y = 0, bool direction = 0, bool light = 0, int speed = 0);

	virtual void Move() = 0;
	virtual void Draw() = 0;
};

