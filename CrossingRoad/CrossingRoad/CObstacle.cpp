#include "CObstacle.h"

CObstacle::CObstacle(int x = 0, int y = 0, bool direction = 0, bool light = 0, int speed = 0) {
	this->mX = x;
	this->mY = y;
	this->direction = direction;
	this->light = light;
	this->speed = speed;
}
