#include "CAnimal.h"
#pragma once

class CDinausor : public CAnimal {
public:
	CDinausor();
	void Move(int, int);
	~CDinausor();
private:
	char** a;
};

