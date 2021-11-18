#include "headers/Menu.hpp"
#include "headers/Scheduler.hpp"
#include "headers/Remove.hpp"

#include <iostream>
#include <cctype>
using namespace std;

int main(){
    static int id = 0;
    Scheduler* test = new Task(id);
    test->setName("Lab 6");
    test->setDescription("Finish unit tests");
    test->setPriority(2);
    test->setDuration(4);
    test->setDueDate("Nov 20");
    test->displaySchedule();

    Scheduler* test2 = new Task(id);
    test2->setName("Final");
    test2->setDescription("Study Final");
    test2->setPriority(3);
    test2->setDuration(4);
    test2->setDueDate("Dec 20");
    
    Scheduler* list = new List(id);
    list->add(test);
    list->add(test2);
    list->displaySchedule();
/*
    Menu menu;
    Scheduler *schedule = new List(id);

    int listID = 0;
    int taskID = 0;
    char userInput;

    menu.displayMenu();
    cin >> userInput;

    while ((userInput != 'q') || (userInput != 'Q')) {
        userInput = toupper(userInput);
        if (userInput == 'A'){
            schedule->add(new List(id));
            menu.displayMenu();
            cin >> userInput;
        }
        else if (userInput == 'B'){
            cout << "Enter the ID of the list to be deleted: ";
            cin >> listID;
            Remove *remove = new RemoveList;
            remove->remove(listID, schedule->getChildren(listID));

            menu.displayMenu();
            cin >> userInput;
        }
        else if (userInput == 'C'){
            //implement which list to add task under
            schedule->add(new Task(id));


            menu.displayMenu();
            cin >> userInput;
        }
        else if (userInput == 'D'){
            cout << "Enter the ID of the task to be deleted: ";
            cin >> taskID;
            cout << "Enter the List the ID is under: ";
            cin >> listID;
            Remove *remove = new RemoveTask;
            remove->remove(taskID, schedule->getChildren(listID));

            menu.displayMenu();
            cin >> userInput;
        }
        else if (userInput == 'E') {
            schedule->displaySchedule();
            menu.displayMenu();
            cin >> userInput;
        }
        else {
            break;
        }
    }
    cout << "\nThanks for using our task scheduler!";
*/
return 0;
}	
