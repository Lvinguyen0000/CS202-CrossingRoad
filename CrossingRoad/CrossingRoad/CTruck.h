#pragma once
//#include <iostream>
#include "CObstacle.h"
#include"CConsole.h"

using namespace std;
#define RIGHT_IN 0
#define RIGHT_OUT 83
#define LEFT_IN 83
#define LEFT_OUT 6
class CTruck: public CObstacle {
public:
	void Draw();
	void Move();
	void Left();
	void Right();
	bool isOut();
	int getWidth();
	
};

