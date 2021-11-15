#pragma once
#include "CVehicle.h"
#include"CConsole.h"
using namespace std;
class CTruck: public CVehicle {
public:
	void DrawTruck(int x, int y);
	void DrawTruckReserve(int x, int y);
	~CTruck();
	void Move(int, int);
private:
	char** a;
};

