#include "CLevel.h"


CLevel::CLevel() {
	this->level = 1;
	this->maxObstacle = 4;
	this->speed = 50 - this->level * 1.5;
}

CLevel::CLevel(int level, int maxObstacle) {
	this->level = level;
	this->maxObstacle = maxObstacle;
}

int CLevel::GetLevel() {
	return this->level;
}

int CLevel::GetSpeed() {
	return this->speed;
}

bool CLevel::NewLevel(int lv) {
	if (lv > this->maxLevel) return false;
	this->level = lv;
	this->maxObstacle = 4 + (lv - 1);
	this->speed = 50 - this->level * 1.5;
	return true;
}


bool CLevel::NextLevel() {
	if (this->level == this->maxLevel) return false;
	this->level++;
	this->maxObstacle++;
	this->speed = 50 - this->level * 1.5;
	return true;
}