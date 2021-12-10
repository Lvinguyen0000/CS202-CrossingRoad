#pragma once
#include "CObstacle.h"
#include "CConsole.h"

#define LEFT_IN 80
#define LEFT_OUT 3
#define RIGHT_IN 1
#define RIGHT_OUT 80

class CCar : public CObstacle {
public:
	CCar(int x, int y, bool direction, bool light, int speed);
	~CCar() = default;
	void Move();
	void Draw();
	void Left();
	void Right();
	int getWidth();
};

