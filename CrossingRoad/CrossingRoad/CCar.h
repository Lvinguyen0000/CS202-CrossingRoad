#pragma once
#include "CVehicle.h"
#include"CConsole.h"

class CCar : public CVehicle{
public:
	CCar();
	~CCar();
	void Move(int x, int y);
private:
	char** a;
};

