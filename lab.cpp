#include "lab.h"

#include <iostream>

Lab::Lab(){
}

Lab::Lab(std::vector<QWidget *> v) {
    Machine = v;
}

Lab::~Lab() {

}

void Lab::changeColour(){
    for(unsigned long i = 0; i < Machine.size(); i++) {
        Machine[i]->setStyleSheet("background-color:black;");
    }
}
