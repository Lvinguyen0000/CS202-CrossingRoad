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
	std::deque<CObstacle*> obs1, obs2, obs3, obs4;
	bool road1dec, road2dec, road3dec, road4dec;
	bool redLight;
public:
	void randomizedirection();
	void toggleRedLight();
	void drawNextState();
};

