#ifndef cAnimal_h_
#define cAnimal_h_

#include "CConsole.h"

class CAnimal {
	private:
		int mX, mY;
	public:
		virtual void Move(int, int) = 0;
};
#endif


