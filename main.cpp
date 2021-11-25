#include "headers/Menu.hpp"
#include "headers/Scheduler.hpp"
#include "headers/Remove.hpp"
#include "headers/Display.hpp"

#include <iostream>
#include <cctype>
using namespace std;

int main(){
    static int id = 0;

    // Scheduler* test = new Task(id);
    // test->setName("Lab 6");
    // test->setDescription("Finish unit tests");
    // test->setPriority(2);
    // test->setDuration(4);
    // test->setDueDate("Nov 20");
    // test->displaySchedule();

    // Scheduler* test2 = new Task(id);
    // test2->setName("Final");
    // test2->setDescription("Study Final");
    // test2->setPriority(3);
    // test2->setDuration(4);
    // test2->setDueDate("Dec 20");
    
    // Scheduler* list = new List(id);
    // list->add(test);
    // list->add(test2);
    // list->displaySchedule();


    Menu menu;
    Scheduler *schedule = new List(id);

    int listID = 0;
    int taskID = 0;
    int input = 0;
    char userInput;

    menu.displayMenu();
    cin >> userInput;

    while ((userInput != 'q') || (userInput != 'Q')) {
        userInput = toupper(userInput);
        if (userInput == 'A'){
            Scheduler *list = new List(id);
            string tmp = "";

            cout << "Enter the name of the list: ";
            cin >> tmp;
            list->setName(tmp);

            cout << "Enter the description of the list: ";
            cin >> tmp;
            list->setDescription(tmp);

            cout << "Enter the due date of the List: ";
            cin >> tmp;
            list->setDueDate(tmp);

            schedule->add(list);
            menu.displayMenu();
            cin >> userInput;
        }
        else if (userInput == 'B'){
            cout << "Enter the ID of the list to be deleted: ";
            cin >> listID;
            Remove *remove = new RemoveList;
            remove->remove(listID, schedule->getChildrenList(listID));
            
            vector<Scheduler*> &children = schedule->getChildren();
            for (auto itr = children.begin(); itr != children.end(); ++itr) {
                if ((*itr)->getID() == listID) {
                    children.erase(itr);
                    break;
                }
            }

            menu.displayMenu();
            cin >> userInput;
        }
        else if (userInput == 'C'){
            //implement which list to add task under
            string tmp = "";
            int tmpInt = 0;
            double duration = 0;
            Scheduler *task = new Task(id);

            cout << "Enter the name of the task: ";
            cin >> tmp;
            task->setName(tmp);

            cout << "Enter the description of the task: ";
            cin >> tmp;
            task->setDescription(tmp);

            cout << "Enter the priority of the task: ";
            cin >> tmpInt;
            task->setPriority(tmpInt);

            cout << "Enter the duration of the task: ";
            cin >> duration;
            task->setDuration(duration);

            cout << "Enter the due date of the task: ";
            cin >> tmp;
            task->setDueDate(tmp);

            cout << "Enter the classification of the task: ";
            cin >> tmp;
            task->setClassification(tmp);

            //when there is no existing list
            if (!(schedule->listExists(schedule))) {
                schedule->add(task);
            }
            else {
                cout << "\ncurrent existing lists\n----------------------\n";
                schedule->displayLists();
                cout << "\nEnter the list number for the task to be added under: ";

                cin >> tmpInt;

                schedule->getList(tmpInt)->add(task);
            }
            menu.displayMenu();
            cin >> userInput;
        }
        else if (userInput == 'D'){
            cout << "Enter the ID of the task to be deleted: ";
            cin >> taskID;
            cout << "Enter the List the ID is under (0 if it isn't under any list): ";
            cin >> listID;
            Remove *remove = new RemoveTask;
            remove->remove(taskID, schedule->getChildrenList(listID));

            menu.displayMenu();
            cin >> userInput;
        }
        else if (userInput == 'E') {
            schedule->displaySchedule();
            menu.displayMenu();
            cin >> userInput;
        }
        else if (userInput == 'F') {
            schedule->editExistingTask(schedule);
            menu.displayMenu();
            cin >> userInput;
        }
        else {
            break;
        }
    }
    cout << "\nThanks for using our task scheduler!\n";

    return 0;
}	
