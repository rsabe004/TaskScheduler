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

void FullDisplay::display(Scheduler* s){
    Display* d = new TaskDisplay;
    if (!s->is_list()){
	d->display(s);	
    }
    else{
	d = new ListDisplay;
	d->display(s);
    }
}

void CompactDisplay::display(Scheduler* s){
    if (!s->is_list()){
	cout<<"Name: "<<s->getName()<<endl
	    <<"Due Date: "<<s->getDueDate()<<endl;	
    }
    else{
	vector<Scheduler* > children = s->getChildren(s->getID());
	cout<<"Name: "<<children[0]->getName()<<endl
            <<"Due Date: "<<children[0]->getDueDate()<<endl;
	for (int i = 1; i<children.size(); ++i){
            cout<<"--------------------\n"
		<<"Name: "<<children[i]->getName()<<endl
                <<"Due Date: "<<children[i]->getDueDate()<<endl;
        }
    }
		
}
