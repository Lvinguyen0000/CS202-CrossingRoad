#pragma once
#include "CObstacle.h"
#include "CConsole.h"

class CCar : protected CObstacle {
	public:
		CCar();
		void Move();
		void Draw();
};

