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

void CRoad::DrawRoad() {
	for (int i = 0; i < road.size(); i++) {
		road[i]->Draw();
	}
}

bool CRoad::PushObstacle() {
	CObstacle* newOBS;
	if (rowY == row1Y || rowY == row2Y) {
		bool type = rand() % 2;
		if (type) {
			newOBS = new CCar(0, rowY, direction, light, speed);
		}
		else newOBS = new CTruck(0, rowY, direction, light, speed);
	}
	else if (rowY == row3Y || rowY == row4Y) {
		bool type = rand() % 2;
		if (type) {
			newOBS = new CDinausor(0, rowY, direction, light, speed);
		}
		else newOBS = new CBird(0, rowY, direction, light, speed);
	}
	else {
		return false;
	}
	road.push_back(newOBS);
	return true;
}