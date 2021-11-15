#pragma once
#include <iostream>
#include "CObstacle.h"
using namespace std;


class CVehicle : public CObstacle {
	public:
		virtual void Move();
		virtual void Draw();

};

