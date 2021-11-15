#pragma once
#include <iostream>
#include "CObstacle.h"
#include"CConsole.h"

using namespace std;

class CTruck: protected CObstacle {
public:
	void DrawTruck(int x, int y);
	void DrawTruckReserve(int x, int y);
	void Move();
private:
	
};

