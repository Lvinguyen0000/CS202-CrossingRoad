#pragma once
#include "CObstacle.h"
#include "CConsole.h"

#define LEFT_IN 80
#define LEFT_OUT 3
#define RIGHT_IN 0
#define RIGHT_OUT 80

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

