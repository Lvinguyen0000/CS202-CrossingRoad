#include "CGame.h"
using namespace std;

int main() {
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);

	MoveWindow(console, r.left, r.top, 960, 630, TRUE);
	FixConsoleWindow();
	DisableMouse();
	CGame game;
	game.MenuGame();
}