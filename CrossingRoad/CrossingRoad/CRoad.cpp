#include "CRoad.h"


CRoad::CRoad(int Y) {
	this->rowY = Y;
	this->direction = 0;
	this->light = 0;
	this->speed = 0;
}


CRoad::~CRoad() {
	this->road.clear();
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
	if (road[i]->getWidth() == 10) return 1;
	else if (road[i]->getWidth() == 8) return 2;
	else if (road[i]->getWidth() == 6) return 3;
	else if (road[i]->getWidth() == 3) return 4;
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
	if (rowY == row3Y) {
		if (light) {
			GotoXY(92, row3Y);
			TextColor(12);
			cout << char(254);
		}
		else {
			GotoXY(92, row3Y);
			TextColor(10);
			cout << char(254);
		}
	}
	else if (rowY == row4Y) {
		 if (light) {
			GotoXY(92, row4Y);
			TextColor(12);
			cout << char(254);
		 }
		 else {
			GotoXY(92, row4Y);
			TextColor(10);
			cout << char(254);
		 }
	}
	TextColor(7);
	for (int i = 0; i < road.size(); i++) {
		if (direction) {
			if (road[i]->GetX() != 0) {
				road[i]->Move();
			}
			else {
				road.front()->~CObstacle();
				road.pop_front();
			}
		}
		else {
			if (road[i]->GetX() != 91) {
				road[i]->Move();
			}
			else {
				road.front()->~CObstacle();
				road.pop_front();
			}
		}
	}
}

CObstacle*& CRoad::GetObstacle(int i) {
	return this->road[i];
}