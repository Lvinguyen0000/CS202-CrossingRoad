#include "CObstacle.h"

CObstacle::CObstacle(int x = 0, int y = 0, bool direction = 0, bool light = 0, int speed = 0) {
	this->mX = x;
	this->mY = y;
	this->direction = direction;
	this->light = light;
	this->speed = speed;
}

void CObstacle::setX(int x) {
	mX = x;
}
void CObstacle::setY(int y) {
	mY = y;
}

int CObstacle::getX() {
	return mX;
}
int CObstacle::getY() {
	return mY;
}