#pragma once
#include "CObstacle.h"
#include "CConsole.h"

#define LEFT_IN 83
#define LEFT_OUT 3
#define RIGHT_IN 1
#define RIGHT_OUT 83

class CDinausor : public CObstacle {
public:
	CDinausor(int x, int y, bool direction, bool light, int speed);
	~CDinausor() = default;
	void Draw();
	void Move();
	void Left();
	void Right();
	bool isOut();
	int getWidth();
};


