#include "Menu.h"

using namespace std;

int main() {
	Menu menu;
	menu.printMenu();
	menu.handleCommand();

	cin.get();
	return 0;
}