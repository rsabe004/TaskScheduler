#include "../headers/Scheduler.hpp"
#include "../headers/Display.hpp"

using namespace std;

Scheduler::~Scheduler(){
	delete displayPtr;
}
