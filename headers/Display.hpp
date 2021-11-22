#ifndef __DISPLAY_HPP__
#define __DISPLAY_HPP__
#include "../headers/Scheduler.hpp"
#include <vector>

class Display {
    public:
        virtual void display(Scheduler* s) = 0;
};

class FullListDisplay: public Display {
    public:
        void display(Scheduler* s);
};

class FullTaskDisplay: public Display {
    public:
	void display(Scheduler* s);
};

class CompactListDisplay: public Display {
    public:
        void display(Scheduler* s);
};

class CompactTaskDisplay: public Display {
    public:
	void display(Scheduler* s);
};

class FullDisplay: public Display {
    public:
	void display(Scheduler* s);
};

class CompactDisplay: public Display {
    public:
	void display(Scheduler* s);
}; 
#endif //__DISPLAY_HPP__
