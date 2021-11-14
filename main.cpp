#include "headers/Menu.hpp"
#include "headers/Scheduler.hpp"

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

    cout << endl << test4->getID() << endl;
    cout << "Name: " << test4->getName() << endl;
    cout << "Description: " << test4->getDescription() << endl;
    cout << "Priority: " << test4->getPriority() << endl;
    cout << "Duration: " << test4->getDuration() << endl;
    cout << "Due date: " << test4->getDueDate() << endl;


}
