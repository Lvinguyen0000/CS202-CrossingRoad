#pragma once
#include "CObstacle.h"
#include "CConsole.h"

class CAnimal : public CObstacle {
	public:
		virtual void Move();
		virtual void Draw();
		//void Tell();
};

