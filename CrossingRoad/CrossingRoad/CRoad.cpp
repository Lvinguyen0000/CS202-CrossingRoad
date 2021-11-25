#include "CRoad.h"

CRoad::CRoad(int Y) {
	this->rowY = Y;
	this->direction = 0;
	this->light = 0;
	this->speed = 0;
}

void CRoad::SetDir(bool direction) {
	this->direction = direction;
}

void CRoad::SetLight(bool light) {
	this->light = light;
}

void CRoad::SetSpeed(int speed) {
	this->speed = speed;
}

void CRoad::ToggleLight() {
	this->light = !this->light;
}
