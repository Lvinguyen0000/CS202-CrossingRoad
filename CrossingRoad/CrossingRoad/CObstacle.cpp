#include "CObstacle.h"

void CObstacle::Move(int x, int y) {
	mX = x;
	mY = y;
}

bool CObstacle::DIRECTION() {
	return direction;
}
