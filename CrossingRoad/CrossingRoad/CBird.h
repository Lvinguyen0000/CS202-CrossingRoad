#pragma once
#include<iostream>
#include "CObstacle.h"
#include"CConsole.h"

using namespace std;

class CBird : public CObstacle {
public:
	CBird();
	void Move();
	void Draw();
	void Left();
	void Right();
	bool isOut();
};

