#include "../headers/Menu.hpp"

#include <iostream>
#include <string>
using namespace std;

void Menu::displayMenu(){

	cout << "\nPlease choose from the following tasks:\n";
	cout << "A - Create List\n";
	cout << "B - Remove List\n";
	cout << "C - Create Task\n";
	cout << "D - Remove Task\n";
	cout << "E - Display Schedule\n";
	cout << "F - Edit Task\n";
	cout << "Q - Quit\n";
	
	string prompt = "\nEnter choice: ";
	cout << prompt;
}

