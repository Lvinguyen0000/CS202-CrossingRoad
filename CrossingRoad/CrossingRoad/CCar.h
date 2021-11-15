#pragma once
#include "CVehicle.h"
#include "CConsole.h"

class CCar : protected CVehicle {
	public:
		CCar();
		void Move();
		void Draw();
};

