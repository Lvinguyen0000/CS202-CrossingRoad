#pragma once
#include<iostream>
using namespace std;
class CVehicle {
	private:
		int mX, mY;
	public:
		virtual void Move(int, int) = 0;
};

