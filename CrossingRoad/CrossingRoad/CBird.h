#pragma once
#include<iostream>
#include "CObstacle.h"
#include"CConsole.h"

using namespace std;

class CBird : protected CObstacle {
public:
	CBird();
	~CBird();
	void Move();
	void Draw();
	void Left();
	void Right();
	bool isOut();
private:
	string b[2];
};

