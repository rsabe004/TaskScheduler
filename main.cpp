#include "headers/Menu.hpp"
#include "headers/Scheduler.hpp"
#include "headers/Task.hpp"
#include "headers/List.hpp"

#include <iostream>
using namespace std;

int main() {
    static int idCounter = 0;
    
    List *test = new List(idCounter);
    cout << test->getID();
    List *test2 = new List(idCounter);
    cout << endl << test2->getID();

    Task *test3 = new Task(idCounter);
    cout << endl << test3->getID();
    Task *test4 = new Task(idCounter);
    cout << endl << test4->getID();
}