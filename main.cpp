#include "headers/Menu.hpp"
#include "headers/Scheduler.hpp"
#include "headers/Display.hpp"

#include <iostream>
using namespace std;

int main() {

    static int idCounter = 0;

    List *test = new List(idCounter);
    cout << test->getID();
//    List *test2 = new List(idCounter);
//    cout << endl << test2->getID();

    Task *test3 = new Task(idCounter);
    cout << endl << test3->getID();
    

    Task *test4 = new Task(idCounter);
    test4->setName("Lab 6");
    test4->setDescription("Finish unit tests");
    test4->setPriority(2);
    test4->setDuration(4);
    test4->setDueDate("Nov 20");
    
    Task *test5 = new Task(idCounter);
    test4->setName("Lab 7");
    test4->setDescription("Check Memory Leak");
    test4->setPriority(3);
    test4->setDuration(4);
    test4->setDueDate("Nov 25");
    
    Task *test6 = new Task(idCounter);
    test4->setName("Final");
    test4->setDescription("Study final exam");
    test4->setPriority(1);
    test4->setDuration(14);
    test4->setDueDate("Dec 4");

    cout << endl << test4->getID() << endl;
    cout << "Name: " << test4->getName() << endl;
    cout << "Description: " << test4->getDescription() << endl;
    cout << "Priority: " << test4->getPriority() << endl;
    cout << "Duration: " << test4->getDuration() << endl;
    cout << "Due date: " << test4->getDueDate() << endl;

    Display* display = new TaskDisplay(test4);
    display->display();
  
    List* L1 = new List(idCounter);
    L1->add(test4);
    L1->add(test5);
    L1->add(test6);
    Display* d2 = new ListDisplay(L1);
    d2->display();   
}
