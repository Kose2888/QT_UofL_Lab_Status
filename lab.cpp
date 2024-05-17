#include "lab.h"

#include <iostream>

Lab::Lab(){
}

Lab::Lab(std::vector<QWidget *> v) {
    machine = v;
}

Lab::~Lab() {

}

void Lab::changeColourAll(QString colour){
    for(unsigned long i = 0; i < machine.size(); i++) {
        machine[i]->setStyleSheet(colour);
    }
}
