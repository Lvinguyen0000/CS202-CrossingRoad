#pragma once
#include <deque>
#include "CObstacle.h"
#include "CAnimal.h"
#include "CVehicle.h"
#include "CDinausor.h"

#define row1Y 7
#define row2Y 12
#define row3Y 17
#define row4Y 22
//etimate do ko nho do cao tung dong

class CRoad
{
private:
	std::deque<CObstacle*> road[4];
	bool direction[4]; // hướng cho các làn đường
	bool light[2]; // đèn giao thông 1:red 0: green cho làn 3 và 4
	int speed; // tốc độ của đường
public:
	//CRoad();
	void SetDir(int index, bool light);
	void SetLight(int index, bool light);
	void SetSpeed(int speed);
	void GenerateNextState();
};

