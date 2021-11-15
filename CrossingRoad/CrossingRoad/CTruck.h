#pragma once
#include <iostream>
#include "CObstacle.h"
#include"CConsole.h"

using namespace std;

class CTruck: protected CObstacle {
public:
	CTruck();
	~CTruck();
	void Move(int, int);
private:
	char** a;
};

