#include "headers/Menu.hpp"
#include "headers/Scheduler.hpp"
#include "headers/Remove.hpp"

#include <iostream>
using namespace std;

int main() {
    static int idCounter = 0;

    Scheduler *list = new List(idCounter);

    list->add(new Task(idCounter));
    list->add(new Task(idCounter));
    list->add(new Task(idCounter));
    list->add(new Task(idCounter));
    
    Scheduler *nestedList = new List(idCounter);
    nestedList->add(new Task(idCounter));
    nestedList->add(new Task(idCounter)); 
    nestedList->add(new Task(idCounter)); 
    nestedList->add(new Task(idCounter)); 
    list->add(nestedList);

    list->displaySchedule();

    //if id is task (ask for task id and list id)
    int listId = 0;
    int taskID = 2;
    Remove *remove = new RemoveTask;
    remove->remove(taskID, list->getChildren(listId)); 
    cout << endl;
    list->displaySchedule();

    //if id is task in a nested list
    listId = 5;
    taskID = 6;
    remove = new RemoveTask;
    remove->remove(taskID, list->getChildren(listId)); 
    cout << endl;
    list->displaySchedule();
    
    //if id is list
    listId = 5;
    remove = new RemoveList;
    remove->remove(listId, list->getChildren(listId));
    cout << endl;

    list->displaySchedule();
}
