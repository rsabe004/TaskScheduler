#include "../headers/Scheduler.hpp"
#include <iostream>
using namespace std;

List::List(int &id) {
    this->id = id;
    id++;
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
/*
    cout << this->getID();
    // cout << "\nList id(" << this->getID() << ") contains the following\n";
    for (unsigned i = 0; i < this->children.size(); ++i) {
        children.at(i)->displaySchedule();
    }
*/
}
