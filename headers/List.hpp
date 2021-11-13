#ifndef __LIST_HPP__
#define __LIST_HPP__

#include "Scheduler.hpp"
#include <vector>

class List: public Scheduler {
    private:
        std::vector<Scheduler*> children;
    public:
        void displaySchedule();
        void add(Scheduler*);
        void edit(Scheduler*);
        void remove(Scheduler*);
};

#endif //__LIST_HPP__