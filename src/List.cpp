#include "../headers/Scheduler.hpp"

List::List(int &id) {
    this->id = id;
    id++;
}

int List::getID() {
    return this->id;
}

void List::add(Scheduler* task) {
    children.push_back(task);
} //adds a task to a list

