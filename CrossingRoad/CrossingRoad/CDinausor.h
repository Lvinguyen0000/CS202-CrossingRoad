#pragma once
#include "CObstacle.h"
#include "CConsole.h"

class CDinausor : protected CObstacle {
public:
	CDinausor();
	void Draw();
	void Move();
	void Left();
	void Right();
	bool isOut();
};


