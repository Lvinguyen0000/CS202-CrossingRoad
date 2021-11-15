#pragma once
#include "CObstacle.h"

class CDinausor : protected CObstacle {
public:
	void drawDino(int, int);
	void drawDinoreverse(int, int);
	void Move(int, int, bool);
	void Tell() {}
};


