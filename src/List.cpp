#include "../headers/Scheduler.hpp"
#include "../headers/Display.hpp"
#include <iostream>
using namespace std;

List::List(int &id) {
    this->id = id;
    id++;
}

Scheduler* List::getList(int listID) {
    return this->children.at(listID - 1);
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
    for (unsigned i = 0; i < this->children.size(); ++i) {
        if (this->children.at(i)->is_list()) {
            cout << "List " << i + 1 << ": " << this->children.at(i)->getName() << endl;
        }
    }
}
void List::displaySchedule() {
    cout<<"1-Full Display\n2-Compact Display\n";
    int choice;
    cin>>choice;
    if(choice == 1){
        displayPtr = new FullDisplay;
    }
    else if (choice == 2){
        displayPtr = new CompactDisplay;
    }
    cout<<"====================\n";
    displayPtr->display(this);
    cout<<"====================\n";
}
