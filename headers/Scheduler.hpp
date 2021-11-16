#ifndef __SCHEDULER_HPP__
#define __SCHEDULER_HPP__

#include "Menu.hpp"
//#include "Remove.hpp"
//#include "Display.hpp"

#include <vector>
#include <string>
#include <iosfwd>

using namespace std;


class Display;

class Scheduler: public Menu {
    protected:
        Display *displayPtr;
//        Remove *removePtr;
        int id;
    public:
        //vector<Scheduler*> children;
        ~Scheduler();
        Scheduler() {
            displayPtr = nullptr;
//            removePtr = nullptr;
        }
        virtual void displaySchedule(){}
        //virtual void add(Scheduler*) {};
        void edit(Scheduler*);
        void remove(int);
	virtual void setName(string){}
        virtual void setDescription(string){}
        virtual void setPriority(int){}
        virtual void setDuration(double){}
        virtual void setDueDate(string){}
        virtual void setClassification(string){}

        virtual string getName(){}
        virtual string getDescription(){}
        virtual int getPriority(){}
        virtual double getDuration(){}
        virtual string getDueDate(){}
        virtual string getClassification(){}
	
        virtual int getID() {
            return this->id;
        }
        //virtual vector<Scheduler*>& getChildren(int) {return children;};
};

class Task: public Scheduler {
    private:
        string name;
        string description;
        int priority;
        double duration;
	string dueDate;
	string classification;
    public:
        Task(int &);
        void displaySchedule();
        int getID();
        void setName(string);
        void setDescription(string);
        void setPriority(int);
        void setDuration(double);
        void setDueDate(string);
	void setClassification(string);

        string getName();
        string getDescription();
        int getPriority();
        double getDuration();
        string getDueDate();
	string getClassification();
};

class List: public Scheduler {
    public:
        std::vector<Scheduler*> children;
    public:
        List(int &);
        void displaySchedule();
        void add(Scheduler*);
        void edit(Scheduler*);
        void remove(int);
        int getID();
        vector<Scheduler*>& getChildren(int);
};

#endif //__SCHEDULER_HPP__
