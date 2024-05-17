#ifndef LAB_H
#define LAB_H

#include<iostream>
#include<vector>
#include <QMainWindow>

class Lab {
public:
    std::vector<QWidget *> Machine;
public:
    Lab();

    Lab(std::vector<QWidget *> v);

    ~Lab();

    void changeColour();

};

#endif // LAB_H
