#include "../headers/Display.hpp"
#include "../headers/Scheduler.hpp"
#include <iostream>

using namespace std;

void TaskDisplay::display(Scheduler* task){
    cout<<"Priority: "<<task->getPriority()<<endl
	<<"Name: "<<task->getName()<<endl
	<<"Description: "<<task->getDescription()<<endl
	<<"Duration: "<<task->getDuration()<<" | "<<"Due Date: "<<task->getDueDate()<<endl;
}
/*
void ListDisplay::display(){
    cout<< "====================\n";
    cout<<"Priority: "<<l->children[0]->getPriority()<<endl
            <<"Name: "<<l->children[0]->getName()<<endl
            <<"Description: "<<l->children[0]->getDescription()<<endl
            <<"Duration: "<<l->children[0]->getDuration()<<" | "<<"Due Date: "<<l->children[0]->getDueDate()<<endl;
		
    for (int i = 1; i<l->children.size(); ++i){
	cout<<"--------------------\n"
	    <<"Priority: "<<l->children[i]->getPriority()<<endl
            <<"Name: "<<l->children[i]->getName()<<endl
            <<"Description: "<<l->children[i]->getDescription()<<endl
            <<"Duration: "<<l->children[i]->getDuration()<<" | "<<"Due Date: "<<l->children[i]->getDueDate()<<endl;
    }
    cout<<"====================\n";
}
*/
