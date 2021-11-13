#pragma once
#include "CVehicle.h"

class CTruck: public CVehicle {
public:
	CTruck();
	~CTruck();
	void Move(int, int);
private:
	char** a;
};

