#pragma once
#include "CAnimal.h"
#include<iostream>
using namespace std;
class CBird : public CAnimal {
public:
	CBird();
	~CBird();
	void Move(int x, int y);
	bool isOut(int x);
	void Draw();
private:
	char** b;
};

