#include "../headers/Scheduler.hpp"

Task::Task(int &id) {
    this->id = id;
    id++;
}

int Task::getID() {
    return this->id;
}