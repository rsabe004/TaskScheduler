#include "../headers/Display.hpp"
#include "../headers/Scheduler.hpp"
#include <iostream>
#include <vector>
using namespace std;

void TaskDisplay::display(Scheduler* task){
    cout<<"Priority: "<<task->getPriority()<<endl
	<<"Name: "<<task->getName()<<endl
	<<"Description: "<<task->getDescription()<<endl
	<<"Duration: "<<task->getDuration()<<" | "<<"Due Date: "<<task->getDueDate()<<endl;
}

void ListDisplay::display(Scheduler* s){
    vector<Scheduler* > children = s->getChildren(s->getID());
    Display* d = new TaskDisplay;
    d->display(children[0]);
    for (int i = 1; i<children.size(); ++i){
	cout<<"--------------------\n";
	d->display(children[i]);	
    }
}

