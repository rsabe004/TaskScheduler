#include "../headers/Menu.hpp"
#include "../headers/Display.hpp"

#include <iostream>
#include <string>
using namespace std;

void Menu::displayMenu(){

	cout << "Please choose from the following tasks:\n";
	cout << "A - Create List\n";
	cout << "B - Remove List\n";
	cout << "C - Create Task\n";
	cout << "D - Remove Task\n";
	cout << "E - Display List\n";
	cout << "F - Display Tasks\n";
	cout << "Q - Quit\n";
	
//	char userInput;
	std::string prompt = "Enter choice: "
	cout << prompt;
}

int main(){

char userInput;

	while((userInput != "q") || (userInput != "Q")){
		displayMenu();
		
		
		cin >> userInput;
		
		while(userInput != "A" && userInput != "B" && userInput != "C"
			userInput != "D" && userInput != "E" && userInput != "F" && userInput != "Q"){
			
				cout << "Please enter a valid input." <<endl;
				cout << displayMenu();
				cin >> userInput;
		}
	
		if (userInput == "a" || userInput == "A"){
			addList();
		}
		if (userInput == "b" || userInput == "B"){
			removeList();
		}
		if (userInput == "c" || userInput == "C"){
			addTask();
		}
		if (userInput == "d" || userInput == "D"){
			removeTask();
		}
		if (userInput == "e" || userInput == "E"){
			displayList();
		}
		if (userInput == "f" || userInput == "F"){
			displayTask();
		}
} 
return 0;
}						  
