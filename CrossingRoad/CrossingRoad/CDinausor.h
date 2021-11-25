#pragma once
#include "CObstacle.h"
#include "CConsole.h"

#define LEFT_IN 83
#define LEFT_OUT 3
#define RIGHT_IN 0
#define RIGHT_OUT 83

class CDinausor : public CObstacle {
public:
	CDinausor();
	void Draw();
	void Move();
	void Left();
	void Right();
	bool isOut();
	int getWidth();
};


