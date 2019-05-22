#pragma once
#include "PhotoManager.h"

class Menu
{
private:
	PhotoManager *m_pm;
public:
	Menu();
	~Menu();
	void printMenu();
	void handleCommand();
};

