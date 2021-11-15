#pragma once
#include "CObstacle.h"
#include "CConsole.h"

class CAnimal : public CObstacle {
	public:
		virtual void Move() = 0;
		virtual void Draw() = 0;
		//void Tell();
};

