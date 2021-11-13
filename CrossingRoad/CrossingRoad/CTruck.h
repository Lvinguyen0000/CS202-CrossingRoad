#pragma once
#include "CVehicle.h"
#include"CConsole.h"
using namespace std;
class CTruck: public CVehicle {
public:
	CTruck();
	~CTruck();
	void Move(int, int);
private:
	char** a;
};

