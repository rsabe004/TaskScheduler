#include "../headers/Scheduler.hpp"
#include "../headers/Display.hpp"
#include <iostream>
using namespace std;

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

void Task::setClassification(string c) {
    classification = c;
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

string Task::getClassification() {
    return this->classification;
}

void Task::displaySchedule(){
    displayPtr = new TaskDisplay;
    displayPtr->display(this);
}

