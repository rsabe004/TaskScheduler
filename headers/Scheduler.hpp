#ifndef __SCHEDULER_HPP__
#define __SCHEDULER_HPP__

#include "Menu.hpp"
#include<iostream>
#include <vector>
#include <string>
#include <iosfwd>

using namespace std;


class Display;

class Scheduler: public Menu {
    protected:
        Display *displayPtr;
        int id;
    public:
        ~Scheduler();
        Scheduler() {
            displayPtr = nullptr;
        }
        virtual void displaySchedule(){}
        virtual void displayLists(){}
        virtual void add(Scheduler*) {};
        void edit(Scheduler*);
	    virtual void setName(string){}
        virtual void setDescription(string){}
        virtual void setPriority(int){}
        virtual void setDuration(double){}
        virtual void setDueDate(string){}
        
        virtual string getName(){}
        virtual string getDescription(){}
        virtual int getPriority(){}
        virtual double getDuration(){}
        virtual string getDueDate(){}
        virtual Scheduler* getList(int){}
        virtual bool is_list(){}
        virtual bool listExists(Scheduler*){}
        virtual void editExistingTask(Scheduler*){}
        virtual void editExistingList(Scheduler*){}
        virtual int getID() {
            return this->id;
        }
        virtual vector<Scheduler*>& getChildren() {}
        virtual vector<Scheduler*>& getChildrenList(int) {}
        virtual void removeTask(int, vector<Scheduler*>&) {}
        virtual void removeList(int, vector<Scheduler*>&) {}
	    bool check_num(string str) {
            for (int i = 0; i < str.length(); i++) {
                if(isdigit(str[i]) == false) {
                    cout << "Please input a number." << endl;
                    return false;
                    }
                }
                return true;
	    }
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
        void setName(string);
        void setDescription(string);
        void setPriority(int);
        void setDuration(double);
        void setDueDate(string);

        string getName();
        string getDescription();
        int getPriority();
        double getDuration();
        string getDueDate();
	    bool is_list(){return false;}
};

class List: public Scheduler {
    protected:
        std::vector<Scheduler*> children;
        string name;
        string description;
        string dueDate;
    public:
        List(int &);

        void setName(string);
        void setDescription(string);
        void setDueDate(string);
        
        string getName();
        string getDescription();
        string getDueDate();

        void displaySchedule();
        void displayLists();
        void add(Scheduler*);
        void edit(Scheduler*);
        int getID();
        vector<Scheduler*>& getChildren();
        vector<Scheduler*>& getChildrenList(int);
	    bool is_list(){return true;}
        bool listExists(Scheduler*);
        Scheduler* getList(int);
        void editExistingTask(Scheduler*);
        void editExistingList(Scheduler*);
        void removeList(int id, vector<Scheduler*>& children);
        void removeTask(int id, vector<Scheduler*>& children);
};

#endif //__SCHEDULER_HPP__
