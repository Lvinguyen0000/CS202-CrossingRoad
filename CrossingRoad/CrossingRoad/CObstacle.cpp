#include "CObstacle.h"

CObstacle::CObstacle(int x , int y , bool direction , bool light , int speed)  {
	this->mX = x;
	this->mY = y;
	this->direction = direction;
	this->light = light;
	this->speed = speed;
}

int CObstacle::GetX() {
	return this->mX;
}

int CObstacle::GetY() {
	return this->mY;
}
void CObstacle::setLight(bool light) {
	this->light = light;
}

void CObstacle::SetSpeed(int speed) {
	this->speed = speed;
}

void CObstacle::SetLight(bool light) {
	this->light = light;
}

void CObstacle::SetDir(bool direction) {
	this->direction = direction;
}
