#pragma once
//#include <iostream>
#include "CObstacle.h"
#include"CConsole.h"

using namespace std;
#define RIGHT_IN 1 //0
#define RIGHT_OUT 83
#define LEFT_IN 83
#define LEFT_OUT 2 //6
class CTruck: public CObstacle {
public:
	CTruck(int x, int y, bool direction, bool light, int speed);
	~CTruck() = default;
	void Draw();
	void Move();
	void Left();
	void Right();
	bool isOut();
	int getWidth();
	
};

