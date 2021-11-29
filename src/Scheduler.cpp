#include "../headers/Scheduler.hpp"
#include "../headers/Display.hpp"

using namespace std;

Scheduler::~Scheduler(){
    delete displayPtr;
    
    for (unsigned i = 0; i < this->getChildren().size(); ++i){
        if(getChildren()[i]->is_list()){
            vector<Scheduler*> c = getChildren()[i]->getChildren();

            for (int j = 0; j<c.size(); ++j){
                delete c[j];
            }
        }
        else{
            delete getChildren()[i];
        }
    }


}

