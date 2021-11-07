#include "CPeople.h"
#include "CAnimal.h"
#include "CBird.h"
#include "CDinausor.h"
#include "CVehicle.h"
#include "CTruck.h"
#include "CCar.h"
#include "CConsole.h"
#pragma once

class CGame {
	CTruck* axt;
	CCar* axh;
	CDinausor* akl;
	CBird* ac;
	CPeople cn;
	public:
		CGame();
		void drawGame();
		~CGame();
		CPeople getPeople();
		CVehicle* getVehicle();
		CAnimal* getAnimal();
		void resetGame();
		void exitGame(HANDLE);
		void startGame();
		void loadGame(istream);
		void pauseGame(HANDLE);
		void resumeGame(HANDLE);
		void updatePosPeople(char);
		void updatePosVehicle();
		void updatePosAnimal();
};

