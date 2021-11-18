#pragma once
#include "CObstacle.h"
#include "CConsole.h"

class CDinausor : public CObstacle {
public:
	CDinausor();
	void Draw();
	void Move();
	void Left();
	void Right();
	bool isOut();
};


