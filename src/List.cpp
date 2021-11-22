#include "../headers/Scheduler.hpp"
#include "../headers/Display.hpp"
#include <iostream>
using namespace std;

List::List(int &id) {
    this->id = id;
    id++;
}

Scheduler* List::getList(int listID) {
    return this->children.at(listID);
}

int List::getID() {
    return this->id;
}

void List::add(Scheduler* obj) {
    this->children.push_back(obj);
} //adds a task/list

vector<Scheduler*>& List::getChildren(int id) {
    return children;
/*
    if (id == 0) { return this->children; }
    else {
        for (unsigned i = 0; i < this->children.size(); ++i) {
            if (children.at(i)->getID() == id) {
                return this->children.at(i)->getChildren(0);
            }
        }
    }
    return this->children;
*/
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
/*
    cout << this->getID();
    // cout << "\nList id(" << this->getID() << ") contains the following\n";
    for (unsigned i = 0; i < this->children.size(); ++i) {
        children.at(i)->displaySchedule();
    }
*/
}
