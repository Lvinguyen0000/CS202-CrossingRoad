#include "CVehicle.h"

void CVehicle::Move(int x, int y) {
	CObstacle::Move(x, y);
}
bool CVehicle::DIRECTION() {
	return CObstacle::DIRECTION();
}
