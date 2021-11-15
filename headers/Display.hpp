#ifndef __DISPLAY_HPP__
#define __DISPLAY_HPP__
#include "../headers/Scheduler.hpp"

class Display {
    public:
        virtual void display() = 0;
};

class ListDisplay: public Display {
    private:
        List* list;
    public:
        ListDisplay(List* list):list(list){}
        void display();
};

class TaskDisplay: public Display {
    private:
        Task* task;
    public:
        TaskDisplay(Task* task):task(task){}
        void display();
};

#endif //__DISPLAY_HPP__
