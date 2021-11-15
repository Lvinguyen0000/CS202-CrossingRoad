#pragma once
#include "CAnimal.h"

class CDinausor : public CAnimal {
public:
	void drawDino(int, int);
	void drawDinoreverse(int, int);
	void Move(int, int);
	void Tell() {}
};


