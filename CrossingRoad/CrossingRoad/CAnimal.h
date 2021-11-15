#pragma once
#include "CObstacle.h"
#include "CConsole.h"

class CAnimal : public CObstacle {
public:
	virtual void Move(int, int);
	virtual void Tell() = 0;
	virtual bool DIRECTION();
};

