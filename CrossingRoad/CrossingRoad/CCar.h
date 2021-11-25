#pragma once
#include "CObstacle.h"
#include "CConsole.h"

class CCar : public CObstacle {
public:
	CCar();
	void Move();
	void Draw();
	void Left();
	void Right();
	bool isOut();
	int getWidth();
};

