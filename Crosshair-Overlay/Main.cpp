#include <Windows.h>
#include <vector>
#include <string>
#include <iostream>
#include <random>
#include "Direct2D/Direct2D.h"
#include "Definitions/Definitions.h"
#include "Definitions/Utilities.h"
#include "Definitions/Functions.h"
#include "Menu/Menu.h"


int main()
{
	SetConsoleTitleA("Crosshair Overlay");
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	if (GlobalFindAtomA("!@#$%^&*()") == 0)
	{
		MessageBoxA(GetDesktopWindow(), "Press Right Shift To Toggle Menu.\nMake Sure You Run Games In Windowed Fullscreen.", "Crosshair Overlay", MB_OK);
		GlobalAddAtomA("!@#$%^&*()");
	}
	InitializeOverlay(Menu, GetDesktopWindow());
	utils->create_thread(keybinds);
	getchar();
}