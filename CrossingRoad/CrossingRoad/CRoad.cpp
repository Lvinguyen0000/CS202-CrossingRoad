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
	for (int i = 0; i < road.size(); i++) {
		road[i]->SetLight(light);
	}
}


int CRoad::getSize() {
	return road.size();
}

int CRoad::getDir() {
	return int(direction);
}

int CRoad::getLight() {
	return int(light);
}

int CRoad::getSpeed() {
	return speed;
}

int CRoad::getType(int i) {
	if (typeid(road[i]) == typeid(CCar)) return 1;
	else if (typeid(road[i]) == typeid(CTruck)) return 2;
	else if (typeid(road[i]) == typeid(CDinausor)) return 3;
	else if (typeid(road[i]) == typeid(CBird)) return 4;
}

int CRoad::getX(int i) {
	return road[i]->GetX();
}

int CRoad::getY(int i) {
	return road[i]->GetY();
}

void CRoad::PushLoaded(CObstacle* L) {
	road.push_back(L);
}

bool CRoad::Collide(CObstacle* obs) {
	if (direction && (road.back()->GetX() + road.back()->getWidth() + obs->getWidth()) >= 90) {
		return true;
	}
	else if ((road.back()->GetX() - obs->getWidth()) <= 0) {
		return true;
	}
	return false;
}


void CRoad::PushObstacle(bool add, int max) {
	CObstacle* newOBS = nullptr;

	if (rowY == row3Y || rowY == row4Y) {
		bool type = rand() % 2;
		if (type == 0) {
			newOBS = new CCar(0, rowY, direction, light, speed);
		}
		else newOBS = new CTruck(0, rowY, direction, light, speed);
	}
	else if (rowY == row1Y || rowY == row2Y) {
		bool type = rand() % 2;
		if (type == 0) {
			newOBS = new CDinausor(0, rowY, direction, light, speed);
		}
		else newOBS = new CBird(0, rowY, direction, light, speed);
	}
	if (add && ((!road.empty() && !this->Collide(newOBS)) || road.empty()) && road.size() < max) {
		road.push_back(newOBS);
	}
}


void CRoad::DrawRoad() {
	for (int i = 0; i < road.size(); i++) {
		if (direction) {
			if (road[i]->GetX() != 0) {
				road[i]->Move();
			}
			else {
				delete road.front();
				road.pop_front();
			}
		}
		else {
			if (road[i]->GetX() != 91) {
				road[i]->Move();
			}
			else {
				delete road.front();
				road.pop_front();
			}
		}
	}
}