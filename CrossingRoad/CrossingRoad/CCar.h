#pragma once
#include "CVehicle.h"

class CCar : public CVehicle{
	public:
	CCar();
	~CCar();
	Move(int x, int y);
	private:
	char** a;
};

