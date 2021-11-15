#include "CRoad.h"

//void CRoad::randomizedirection() {
//	road1dec = rand() % 2;
//	road2dec = rand() % 2;
//	road3dec = rand() % 2;
//	road4dec = rand() % 2;
//}

//void CRoad::toggleRedLight() {
//	redLight = !redLight;
//}

//void CRoad::drawNextState() {
//	int add = rand() % 5;
//	if ((redLight && (rand() % 8 == 0)) || (!redLight && (rand() % 15 == 0))) {
//		toggleRedLight();
//	}
//	if (road2dec) {
//		if (!redLight) {
//			if (add == 3 && ((!obs2.empty() && obs2.back()->getX() > 6) || obs2.empty()) && obs2.size() < 5) {
//				CObstacle* obs;
//				obs = new CDinausor;
//				obs->direction = road2dec;
//				obs->setX(1);
//				obs->setY(row2Y);
//				obs2.push_back(obs);
//			}
//			for (int i = 0; i < obs2.size(); i++) {
//				int x = obs2[i]->getX();
//				if (x < 90) {
//					obs2[i]->Move(x, obs2[i]->getY(), road2dec);
//					obs2[i]->setX(++x);
//				}
//				else {
//					obs2.pop_front();
//				}
//			}
//		}
//	}
//	else {
//		if (!redLight) {
//			if (add == 3 && ((!obs2.empty() && obs2.back()->getX() < 84) || obs2.empty()) && obs2.size() < 5) {
//				CObstacle* obs;
//				obs = new CDinausor;
//				obs->direction = road2dec;
//				obs->setX(90);
//				obs->setY(row2Y);
//				obs2.push_back(obs);
//			}
//			for (int i = 0; i < obs2.size(); i++) {
//				int x = obs2[i]->getX();
//				if (x > 0) {
//					obs2[i]->Move(x, obs2[i]->getY(), road2dec);
//					obs2[i]->setX(--x);
//				}
//				else {
//					obs2.pop_front();
//				}
//			}
//		}
//	}
//}

