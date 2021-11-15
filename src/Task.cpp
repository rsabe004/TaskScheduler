#include "../headers/Scheduler.hpp"

Task::Task(int &id) {
    this->id = id;
    id++;
}

int Task::getID() {
    return this->id;
}

void Task::setName(string n) {
    name = n;
}

void Task::setDescription(string d) {
    description = d;
}

void Task::setPriority(int p) {
    priority = p;
}

void Task::setDuration(double d) {
    duration = d;
}

void Task::setDueDate(string date) {
    dueDate = date;
}

string Task::getName() {
    return this->name;
}

string Task::getDescription() {
    return this->description;
}

int Task::getPriority() {
    return this->priority;
}

double Task::getDuration() {
    return this->duration;
}

string Task::getDueDate() {
    return this->dueDate;
}

