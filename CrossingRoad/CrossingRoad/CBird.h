#include "CAnimal.h"
#pragma once

class CBird : public CAnimal {
public:
	CBird();
	~CBird();
	void Move(int x, int y);
	void Tell();
	bool isOut(int x);
	void Draw();
private:
	char** b;
};

