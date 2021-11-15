#pragma once
#include "CObstacle.h"
#include "CConsole.h"

class CAnimal : protected CObstacle {
	public:
		CAnimal();
		virtual void Move() = 0;
		virtual void Draw() = 0;
		//void Tell();
};

