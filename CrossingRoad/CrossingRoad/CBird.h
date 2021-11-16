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
	bool isOut(int x);
private:
	//char** b;
	string b[2];
};

