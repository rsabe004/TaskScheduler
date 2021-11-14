#include "../headers/List.hpp"

List::List(int &id) {
    this->id = id;
    id++;
}

int List::getID() {
    return this->id;
}