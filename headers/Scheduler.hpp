#ifndef __SCHEDULER_HPP__
#define __SCHEDULER_HPP__

#include "Menu.hpp"
#include "Display.hpp"

class Scheduler: public Menu {
    protected:
        Display display;
        int id;
    public:
        void displaySchedule();
        void add(Scheduler*);
        void edit(Scheduler*);
        void remove(Scheduler*);
        int getID();
};

#endif //__SCHEDULER_HPP__