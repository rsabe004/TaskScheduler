#include "../headers/Display.hpp"
#include "../headers/Scheduler.hpp"
#include <iostream>
#include <vector>
using namespace std;

void FullTaskDisplay::display(Scheduler* task){
    cout<<"\tTask Name: "<<task->getPriority()<<endl
    << "\tID: " << task->getID() << endl
	<<"\tPriority: "<<task->getName()<<endl
	<<"\tDescription: "<<task->getDescription()<<endl
	<<"\tDuration: "<<task->getDuration()<<" | "<<"Due Date: "<<task->getDueDate()<<endl << endl;
}

void CompactTaskDisplay::display(Scheduler* task){
    cout<<"\tTask Name: "<<task->getPriority()<<endl
	<<"\tDuration: "<<task->getDuration()<<" | "<<"Due Date: "<<task->getDueDate()<<endl << endl;
}

void FullListDisplay::display(Scheduler* s){
    // vector<Scheduler* > children = s->getChildren(s->getID());
    // Display* d = new TaskDisplay;
    // d->display(children[0]);
    // for (int i = 1; i<children.size(); ++i){
	//     cout<<"--------------------\n";
	//     d->display(children[i]);	
    // }
    cout << "List Name: " << s->getName() << endl;
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
    cout << "List Name: " << s->getName() << endl;
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
    // Display* d = new TaskDisplay;
    // if (!s->is_list()){
	// d->display(s);	
    // }
    // else{
	// d = new ListDisplay;
	// d->display(s);
    // }

    Display *d = nullptr;
    vector<Scheduler*> children = s->getChildren();
    // cout << "\nList id(" << s->getID() << ") contains the following\n";
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
    // if (!s->is_list()){
	// cout<<"Name: "<<s->getName()<<endl
	//     <<"Due Date: "<<s->getDueDate()<<endl;	
    // }
    // else{
	// vector<Scheduler* > children = s->getChildren(s->getID());
	// cout<<"Name: "<<children[0]->getName()<<endl
    //         <<"Due Date: "<<children[0]->getDueDate()<<endl;
	// for (int i = 1; i < children.size(); ++i){
    //     cout << "--------------------\n" <<"Name: "<<children[i]->getName() << endl << "Due Date: "<< children[i]->getDueDate()<<endl;
    // }

    // for (unsigned i = 0; i < s->getChildren(s->getID()).size(); ++i) {
        
    // }
    //}
    Display *d = nullptr;
    vector<Scheduler*> children = s->getChildren();
    // cout << "\nList id(" << s->getID() << ") contains the following\n";
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
