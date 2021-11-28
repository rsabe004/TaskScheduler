#include "headers/Menu.hpp"
#include "headers/Scheduler.hpp"
#include "headers/Display.hpp"

#include <iostream>
#include <cctype>
using namespace std;

int main(){
    static int id = 0;

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
            getline(cin>>ws, tmp);
            list->setName(tmp);

            cout << "Enter the description of the list: ";
            getline(cin>>ws, tmp);
            list->setDescription(tmp);

            cout << "Enter the due date of the List: ";
            getline(cin>>ws, tmp);
            list->setDueDate(tmp);

            schedule->add(list);
            menu.displayMenu();
            cin >> userInput;
        }
        else if (userInput == 'B'){
            cout << "Enter the ID of the list to be deleted: ";
	    string idStr  = "";
            cin >> idStr;
	    	while(!schedule->check_num(idStr)) {
			cin >> idStr;
		}
	    int listID = stoi(idStr);
            schedule->removeList(listID, schedule->getChildrenList(listID));
            
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
            string tmpIntStr = "";
            string durationStr = "";
            Scheduler *task = new Task(id);

            cout << "Enter the name of the task: ";
            getline(cin>>ws, tmp);
            task->setName(tmp);

            cout << "Enter the description of the task: ";
            getline(cin>>ws, tmp);
            task->setDescription(tmp);

            cout << "Enter the priority of the task: ";
            cin >> tmpIntStr;
		while(!schedule->check_num(tmpIntStr)) {
			cin >> tmpIntStr;
		}
	    int tmpInt = stoi(tmpIntStr);
            task->setPriority(tmpInt);

            cout << "Enter the duration of the task: ";
            cin >> durationStr;
		while(!schedule->check_num(durationStr)) {
			cin >> durationStr;
		}
	    double duration = stod(durationStr);
            task->setDuration(duration);

            cout << "Enter the due date of the task: ";
            getline(cin>>ws, tmp);
            task->setDueDate(tmp);

            //when there is no existing list
            if (!(schedule->listExists(schedule))) {
                schedule->add(task);
            }
            else {
                cout << "\ncurrent existing lists\n----------------------\n";
                schedule->displayLists();
                cout << "\nEnter the list number for the task to be added under: ";

		cin >> tmpIntStr;
		   while(!schedule->check_num(tmpIntStr)) {
			cin >> tmpIntStr;
		   }
		int tmpInt = stoi(tmpIntStr);
                if(schedule->getList(tmpInt) != nullptr) {
			schedule->getList(tmpInt)->add(task);
		}
            }
            menu.displayMenu();
            cin >> userInput;
        }
        else if (userInput == 'D'){
	    string idStr = "";
            cout << "Enter the ID of the task to be deleted: ";
            cin >> idStr;
		while(!schedule->check_num(idStr)) {
			cin >> idStr;
		}
	    int taskID = stoi(idStr);
            cout << "Enter the List the ID is under (0 if it isn't under any list): ";
            cin >> idStr;
		while(!schedule->check_num(idStr)) {
			cin >> idStr;
		}
	    int listID = stoi(idStr);
            schedule->removeTask(taskID, schedule->getChildrenList(listID));
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
        else if (userInput == 'G') {
            schedule->editExistingList(schedule);
            menu.displayMenu();
            cin >> userInput;
        }
        else {
            break;
        }
    }
    cout << "\nThanks for using our task scheduler!\n";
    delete schedule;
    return 0;
}	
