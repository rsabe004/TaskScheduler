#include "../headers/Scheduler.hpp"
#include "../headers/Display.hpp"
#include <iostream>
using namespace std;

List::List(int &id) {
    this->id = id;
    id++;
}

List::~List(){
    delete displayPtr;
    for (unsigned i = 0; i < children.size(); ++i){
        if(children[i]->is_list()){
            vector<Scheduler*> c = children[i]->getChildren();

            for (int j = 0; j<c.size(); ++j){
                delete c[j];
            }
        }
        else{
            delete children[i];
        }
    }

}

Scheduler* List::getList(int listID) {
    if((listID-1) < this->children.size()) {
    return this->children.at(listID - 1);
    }
    cout << "List does not exist." << endl;
    return nullptr;
}

int List::getID() {
    return this->id;
}
void List::setName(string n) {
    this->name = n;
}
void List::setDescription(string d) {
    this->description = d;
}
void List::setDueDate(string d) {
    this->dueDate = d;
}

string List::getName() {
    return this->name;
}
string List::getDescription() {
    return this->description;
}
string List::getDueDate() {
    return this->dueDate;
}

void List::add(Scheduler* obj) {
    this->children.push_back(obj);
} //adds a task/list

vector<Scheduler*>& List::getChildren() {
    return this->children;
}
vector<Scheduler*>& List::getChildrenList(int id) {
    if (id == 0) { return this->children; }
    else {
        for (unsigned i = 0; i < this->children.size(); ++i) {
            if (children.at(i)->getID() == id) {
                return this->children.at(i)->getChildrenList(0);
            }
        }
    }
    return this->children;
}
void List::displayLists() {
    for (unsigned int i = 0; i < this->children.size(); ++i) {
        if (this->children.at(i)->is_list()) {
            cout << "List ID " << i + 1 << ": " << this->children.at(i)->getName() << endl;
        }
    }
}
void List::displayLists(std::ostream& out)const {
    for (unsigned i = 0; i < this->children.size(); ++i) {
        if (this->children.at(i)->is_list()) {
            out << "List ID " << i + 1 << ": " << this->children.at(i)->getName() << endl;
        }
    }
}
void List::displaySchedule() {
    cout<<"1-Full Display\n2-Compact Display\n";
    int choice;
    string choiceStr;
    cin>>choiceStr;
	while(!this->check_num(choiceStr)) {
		cin >> choiceStr;
	}
    choice = stoi(choiceStr);
    if(choice == 1){
        displayPtr = new FullDisplay;
    }
    else if (choice == 2){
        displayPtr = new CompactDisplay;
    }
    cout<<"\n====================\n";
    displayPtr->display(this);
    cout<<"\n====================\n";
}
bool List::listExists(Scheduler *schedule) {
    vector<Scheduler*> children = schedule->getChildren();
    for (unsigned int i = 0; i < children.size(); ++i) {
        if (children.at(i)->is_list()) {
            return true;
        }
    }
    return false;
}
void List::editExistingTask(Scheduler* s) {
    int taskID = 0, input = 0, listID = 0;
    string strInput = "";
    int intInput = 0;
    double dbInput = 0.0;

    cout << "Enter the ID of the task to be edited: ";
    cin >> strInput;
    while(!this->check_num(strInput)) {
            cin >> strInput;
    }
    taskID = stoi(strInput);

    cout << "Enter the List the ID is under (0 if it isn't under any list): ";
    cin >> strInput;
    while(!this->check_num(strInput)) {
            cin >> strInput;
    }
    listID = stoi(strInput);

    cout << "\n1. name\n";
    cout << "2. description\n";
    cout << "3. priority\n";
    cout << "4. duration\n";
    cout << "5. due date\n";
    cout << "\nEnter the attribute you want to edit: ";
    cin >> strInput;
    while(!this->check_num(strInput)) {
            cin >> strInput;
    }
    input = stoi(strInput);

    if (input == 1 || input == 2 || input == 5) {
        cout << "Enter the new value: ";
        getline(cin>>ws, strInput);
    }
    else if (input == 3) {
        cout << "Enter the new value: ";
        cin >> strInput;
		while(!this->check_num(strInput)) {
			cin >> strInput;
		}
	    intInput = stoi(strInput);
    }
    else {
        cout << "Enter the new value: ";
	    cin >> strInput;
        while(!this->check_num(strInput)) {
                cin >> strInput;
        }
        dbInput = stod(strInput);
    }

    vector<Scheduler*> children = s->getChildrenList(listID);
    for (auto itr = children.begin(); itr != children.end(); ++itr) {
        if ((*itr)->getID() == taskID) {
            switch(input) {
                case 1:
                    (*itr)->setName(strInput);
                    break;
                case 2:
                    (*itr)->setDescription(strInput);
                    break;
                case 3:
                    (*itr)->setPriority(intInput);
                    break;
                case 4:
                    (*itr)->setDuration(dbInput);
                    break;
                case 5:
                    (*itr)->setDueDate(strInput);
                    break;
            }
            cout << "Updated task!\n";
            return;
        }
    }
}
void List::editExistingList(Scheduler* s) {
    int listID = 0;
    int intInput = 0;
    string strInput = "";

    cout << "Enter the ID of the list to be edited: ";
    cin >> strInput;
    while(!this->check_num(strInput)) {
            cin >> strInput;
    }
    listID = stoi(strInput);

    cout << "\n1. name\n";
    cout << "2. description\n";
    cout << "3. due date\n";
    cout << "\nEnter the attribute you want to edit: ";
    cin >> strInput;
    while(!this->check_num(strInput)) {
            cin >> strInput;
    }
    intInput = stoi(strInput);

    cout << "Enter the new value: ";
    getline(cin>>ws, strInput);

    for (auto itr = s->getChildren().begin(); itr != s->getChildren().end(); ++itr) {
        if ((*itr)->getID() == listID) {
            switch(intInput) {
                case 1:
                    (*itr)->setName(strInput);
                    break;
                case 2:
                    (*itr)->setDescription(strInput);
                    break;
                case 3:
                    (*itr)->setDueDate(strInput);
                    break;
            }
            cout << "Updated list!\n";
        }
    }
}
void List::removeList(int id, vector<Scheduler*>& children) {
    children.clear();
    cout << "\nremoved list " << id << endl;
}
void List::removeTask(int id, vector<Scheduler*>& children) {
    for (auto itr = children.begin(); itr != children.end(); ++itr) {
         cout << (*itr)->getID() << endl;
    }
    for (auto itr = children.begin(); itr != children.end(); ++itr) {
        if ((*itr)->getID() == id) {
            cout << "\nerased " << (*itr)->getID() << endl;
            children.erase(itr);
            return;
        }
    }
}
