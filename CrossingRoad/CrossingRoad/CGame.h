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
#include <thread>

using namespace std;


void MenuGame();
void SettingGame();
void Quit(thread& t);
void SaveGame();
void LoadGame();
void TogglePause();
void ToggleMute();
void FinishGame();
void GameOver();

vector<string> getAllFilename(const string& name);

