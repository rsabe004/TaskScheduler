#ifndef __REMOVE_HPP__
#define __REMOVE_HPP__

#include "Scheduler.hpp"
#include <vector>

class Remove {
    public:
        virtual void remove(int, vector<Scheduler*>&) = 0;
};

class RemoveList: public Remove {
    public:
        void remove(int, vector<Scheduler*>&);
};

class RemoveTask: public Remove {
    public:
        void remove(int, vector<Scheduler*>&);
};

#endif //__REMOVE_HPP__

