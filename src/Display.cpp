#include "../headers/Display.hpp"
#include "../headers/Scheduler.hpp"
#include <iostream>
#include <vector>
using namespace std;

void FullTaskDisplay::display(Scheduler* task){
    cout<<"\n\tTask Name: "<<task->getName()<<endl
    << "\tID: " << task->getID() << endl
	<<"\tPriority: "<<task->getPriority()<<endl
	<<"\tDescription: "<<task->getDescription()<<endl
	<<"\tDuration: "<<task->getDuration()<<" | "<<"Due Date: "<<task->getDueDate()<<endl;
}

void CompactTaskDisplay::display(Scheduler* task){
    cout<<"\n\tTask Name: "<<task->getName()<<endl
	<<"\tDuration: "<<task->getDuration()<<" | "<<"Due Date: "<<task->getDueDate()<<endl;
}

void FullListDisplay::display(Scheduler* s){
    cout << "\nList Name: " << s->getName() << endl;
    cout << "ID: " << s->getID() << endl;
    cout << "Due Date: " << s->getDueDate() << endl;
    cout << "Description: " << s->getDescription() << endl;
    cout << "--------------" << endl;
    Display *d = nullptr;
    vector<Scheduler*> children = s->getChildren();
    for (unsigned i = 0; i < children.size(); ++i) {
        if (children.at(i)->is_list()) {
            d = new FullListDisplay;
            d->display(children.at(i));
        }
        else {
            d = new FullTaskDisplay;
            d->display(children.at(i));
        }
    }
}

void CompactListDisplay::display(Scheduler* s){
    cout << "\nList Name: " << s->getName() << endl;
    cout << "Due Date: " << s->getDueDate() << endl;
    cout << "--------------" << endl;
    Display *d = nullptr;
    vector<Scheduler*> children = s->getChildren();
    for (unsigned i = 0; i < children.size(); ++i) {
        if (children.at(i)->is_list()) {
            d = new CompactListDisplay;
            d->display(children.at(i));
        }
        else {
            d = new CompactTaskDisplay;
            d->display(children.at(i));
        }
    }
}

void FullDisplay::display(Scheduler* s){
    Display *d = nullptr;
    vector<Scheduler*> children = s->getChildren();
    for (unsigned i = 0; i < children.size(); ++i) {
        if (children.at(i)->is_list()) {
            d = new FullListDisplay;
            d->display(children.at(i));
        }
        else {
            d = new FullTaskDisplay;
            d->display(children.at(i));
        }
    }
}

void CompactDisplay::display(Scheduler* s){
    Display *d = nullptr;
    vector<Scheduler*> children = s->getChildren();
    for (unsigned i = 0; i < children.size(); ++i) {
        if (children.at(i)->is_list()) {
            d = new CompactListDisplay;
            d->display(children.at(i));
        }
        else {
            d = new CompactTaskDisplay;
            d->display(children.at(i));
        }
    }
		
}
