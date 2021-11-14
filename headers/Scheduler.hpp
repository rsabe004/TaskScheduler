#ifndef __SCHEDULER_HPP__
#define __SCHEDULER_HPP__

#include "Menu.hpp"
#include "Remove.hpp"
#include "Display.hpp"

#include <vector>
#include <string>

using namespace std;

class Scheduler: public Menu {
    protected:
        Display *displayPtr;
        Remove *removePtr;
        int id;
    public:
        Scheduler() {
            displayPtr = nullptr;
            removePtr = nullptr;
        };
        void displaySchedule();
        void add(Scheduler*);
        void edit(Scheduler*);
        void remove(int);
        int getID();
};

class Task: public Scheduler {
    private:
        string name;
        string description;
        int priority;
        double duration;
        string dueDate;
    public:
        Task(int &);
        void displaySchedule();
        int getID();
};

class List: public Scheduler {
    private:
        std::vector<Scheduler*> children;
    public:
        List(int &);
        void displaySchedule();
        void add(Scheduler*);
        void edit(Scheduler*);
        void remove(int);
        int getID();
};

#endif //__SCHEDULER_HPP__