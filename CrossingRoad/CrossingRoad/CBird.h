#pragma once
#include<iostream>
#include "CObstacle.h"

using namespace std;

class CBird : protected CObstacle {
public:
	CBird();
	~CBird();
	void Move(int x, int y);
	void Draw();
	bool isOut(int x);
private:
	char** b;
};

