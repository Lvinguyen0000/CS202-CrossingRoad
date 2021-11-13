#pragma once
#include "CConsole.h"
#include<iostream>
using namespace std;
class CAnimal {
	private:
		int mX, mY;
	public:
		virtual void Move(int, int) = 0;
};



