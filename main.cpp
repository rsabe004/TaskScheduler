#include "headers/Menu.hpp"
#include "headers/Scheduler.hpp"

#include <iostream>
using namespace std;

int main(){

  char userInput;

          while((userInput != "q") || (userInput != "Q")){
                  displayMenu();


                  cin >> userInput;

                  while(userInput != "A" && userInput != "B" && userInput != "C"
                          userInput != "D" && userInput != "E" && userInput != "F" && userInput != "Q"){

                                  cout << "Please enter a valid input." <<endl;
                                  cout << displayMenu();
                                  cin >> userInput;
                  }

                  if (userInput == "a" || userInput == "A"){
                          addList();
                  }
                  if (userInput == "b" || userInput == "B"){
                          removeList();
                  }
                  if (userInput == "c" || userInput == "C"){
                          addTask();
                  }
                  if (userInput == "d" || userInput == "D"){
                          removeTask();
                  }
                  if (userInput == "e" || userInput == "E"){
                          displayList();
                  }
                  if (userInput == "f" || userInput == "F"){
                          displayTask();
                  }
  }
  return 0;
}
