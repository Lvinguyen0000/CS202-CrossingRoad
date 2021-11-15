#include "CAnimal.h"

void CAnimal::Move(int x, int y) {
	CObstacle::Move(x, y);
}

bool CAnimal::DIRECTION() {
	return CObstacle::DIRECTION();
}
