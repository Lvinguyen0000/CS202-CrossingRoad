#pragma once
#include<iostream>
#include "CObstacle.h"
#include"CConsole.h"

#define LEFT_IN 87
#define LEFT_OUT 3
#define RIGHT_IN 0
#define RIGHT_OUT 87

using namespace std;

class CBird : public CObstacle {
public:
	CBird(int x, int y, bool direction, bool light, int speed);
	~CBird() = default;
	void Move();
	void Draw();
	void Left();
	void Right();
	int getWidth();
};

