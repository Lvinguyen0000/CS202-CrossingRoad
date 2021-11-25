#pragma once
//#include <iostream>
#include "CObstacle.h"
#include"CConsole.h"

using namespace std;

class CTruck: public CObstacle {
public:
	//void DrawTruck(int x, int y);
	//void DrawTruckReserve(int x, int y);
	void Draw();
	void Move();
	void Left();
	void Right();
	bool isOut();
private:
	
};

