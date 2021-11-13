#ifndef __TASK_HPP__
#define __TASK_HPP__

#include "Scheduler.hpp"
#include <string>

using namespace std;

class Task: public Scheduler {
    private:
        string name;
        string description;
        int priority;
        double duration;
        string dueDate;
    public:
        void displaySchedule();
};

#endif //__TASK_HPP__