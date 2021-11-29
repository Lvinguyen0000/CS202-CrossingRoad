#pragma once
#include "CPeople.h"
#include "CObstacle.h"
#include "CBird.h"
#include "CDinausor.h"
#include "CTruck.h"
#include "CCar.h"
#include "CRoad.h"
#include "CConsole.h"
#include "CMap.h"




class CGame {
	CMap map;
	bool isMute = 0;
	bool isPause = 0;
public:
	CGame() = default;
	//void drawGame();
	~CGame() = default;

	void MenuGame();
	void NewGame();
	void SettingGame();
	void Quit();
	void SaveGame();
	void LoadGame();
	void TogglePause();
	void ToggleMute();
	void FinishGame();
	void GameOver();
	void CountinueGame();
	vector<string> getAllFilename(const string& name);
};
