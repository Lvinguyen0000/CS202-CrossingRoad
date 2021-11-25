#pragma once
#include <iostream>
#include <deque>
#include "CObstacle.h"
#include "CDinausor.h"
#include "CBird.h"
#include "CCar.h"
#include "CTruck.h"


using namespace std;
#define row1Y 7
#define row2Y 12
#define row3Y 17
#define row4Y 22
//estimate do ko nho do cao tung dong

class CRoad
{
private:
	std::deque<CObstacle*> road;
	bool direction; // hướng cho các làn đường 1:left 0:right
	bool light; // đèn giao thông 1:red 0: green cho làn 3 và 4
	int speed; // tốc độ của đường
	int rowY; // độ cao của đường 
	
public:
	CRoad(int Y);
	void SetDir(bool direction);
	void SetLight(bool light);
	void SetSpeed(int speed);
	void ToggleLight();
	void DrawRoad();
	bool PushObstacle();
};

