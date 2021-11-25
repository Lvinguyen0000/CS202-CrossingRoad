#pragma once
//#include <iostream>
#include "CObstacle.h"
#include"CConsole.h"

using namespace std;

class CTruck: public CObstacle {
public:
	void Draw();
	void Move();
	void Left();
	void Right();
	bool isOut();
	int getWidth();
	
};

