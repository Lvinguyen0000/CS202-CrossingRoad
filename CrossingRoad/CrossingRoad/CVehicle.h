#pragma once
#include <iostream>
#include "CObstacle.h"
using namespace std;


class CVehicle : protected CObstacle {
	public:
		CVehicle();
		virtual void Move() = 0;
		virtual void Draw() = 0;
};

