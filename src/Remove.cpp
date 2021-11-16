#include "../headers/Remove.hpp"
#include "../headers/Scheduler.hpp"
#include <vector>
#include <iostream>
using namespace std;

void RemoveList::remove(int id, vector<Scheduler*> &children) {
    children.clear();
    cout << "\nremoved list " << id << endl;
}

void RemoveTask::remove(int id, vector<Scheduler*> &children) {
    cout << "\nsize of children: " << children.size() << endl;
    cout << "\nprinting children: " << endl;
    for (auto itr = children.begin(); itr != children.end(); ++itr) {
         cout << (*itr)->getID() << endl;
    }
    for (auto itr = children.begin(); itr != children.end(); ++itr) {
        if ((*itr)->getID() == id) {
            cout << "\nerased " << (*itr)->getID() << endl;
            children.erase(itr);
            return;
        }
    }
}