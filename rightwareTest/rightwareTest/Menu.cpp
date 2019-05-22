#include "Menu.h"

Menu::Menu()
{
	m_pm = new PhotoManager();
}

Menu::~Menu()
{
	delete m_pm;
}

void Menu::printMenu()
{
	cout << "-----------------------------" << endl;
	cout << "Photo Manager / Choose option:" << endl;
	cout << "	1. Read image files in folder" << endl;
	cout << "	2. Combine images" << endl;
	cout << "	x. Exit" << endl;
	cout << "-----------------------------" << endl;
}

void Menu::handleCommand()
{
	while (true) {
		string command;
		cout << "Enter command: ";
		cin >> command;
		cin.ignore();

		if (command == "1") {
			string path;
			cout << "Enter a path to a folder (e.g., C:/Users/PC/Pictures): ";
			getline(cin, path);
			m_pm->readImageFiles(path);
			this->printMenu();
		}
		else if (command == "2") {
			string path1;
			string path2;
			cout << "Enter a path to first image: ";
			getline(cin, path1);
			cout << "Enter a path to second image: ";
			getline(cin, path2);
			cout << "Combining images ..." << endl;
			m_pm->horizontalCombine(path1, path2);
			m_pm->verticalCombine(path1, path2);
		}
		else if (command == "x") {
			break;
		}
	}
}
