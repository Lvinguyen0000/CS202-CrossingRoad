#include "CObstacle.h"

CObstacle::CObstacle(int x , int y , bool direction , bool light , int speed)  {
	this->mX = x;
	this->mY = y;
	this->direction = direction;
	this->light = light;
	this->speed = speed;
}
