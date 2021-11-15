#pragma once
#include "CAnimal.h"
#include<iostream>
using namespace std;
class CBird : public CAnimal {
public:
	CBird();
	~CBird();
	void Move(int x, int y);
	void Draw();
	bool isOut(int x);
private:
	char** b;
};

