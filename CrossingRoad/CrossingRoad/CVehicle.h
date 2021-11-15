#pragma once
#include<iostream>
#include"CObstacle.h"
using namespace std;
class CVehicle : public CObstacle {
	private:
		int mX, mY;
	public:
		virtual void Move(int, int) = 0;
		virtual bool DIRECTION();
};

