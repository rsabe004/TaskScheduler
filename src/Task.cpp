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

void Task::displaySchedule(){
    cout<<"1-Full Display\n2-Compact Display\n";
    int choice;
    cin>>choice;
    if(choice == 1){
	displayPtr = new FullDisplay;
    }
    else if (choice == 2){
	displayPtr = new CompactDisplay;	
    }
    
    displayPtr->display(this);
}

