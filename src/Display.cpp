#include "../headers/Display.hpp"
#include <iostream>

using namespace std;

void TaskDisplay::display(){
    cout<< "====================\n"
	<<"Priority: "<<task->getPriority()<<endl
	<<"Name: "<<task->getName()<<endl
	<<"Description: "<<task->getDescription()<<endl
	<<"Duration: "<<task->getDuration()<<" | "<<"Due Date: "<<task->getDueDate()<<endl
	<<"====================\n";
}

void ListDisplay::display(){
    cout<< "====================\n";
    cout<<"Priority: "<<list->children[0]->getPriority()<<endl
            <<"Name: "<<list->children[0]->getName()<<endl
            <<"Description: "<<list->children[0]->getDescription()<<endl
            <<"Duration: "<<list->children[0]->getDuration()<<" | "<<"Due Date: "<<list->children[0]->getDueDate()<<endl;
		
    for (int i = 1; i<list->children.size(); ++i){
	cout<<"--------------------\n"
	    <<"Priority: "<<list->children[i]->getPriority()<<endl
            <<"Name: "<<list->children[i]->getName()<<endl
            <<"Description: "<<list->children[i]->getDescription()<<endl
            <<"Duration: "<<list->children[i]->getDuration()<<" | "<<"Due Date: "<<list->children[i]->getDueDate()<<endl;
    }
    cout<<"====================\n";
}
