#ifndef LAB_H
#define LAB_H

#include <iostream>
#include <string>
#include <vector>
#include <QMainWindow>

#define GET_VARIABLE_NAME(Variable) (#Variable)

const QString BLACK = "background-color:black;";
const QString RED = "background-color: rgb(192, 28, 40);";
const QString GREEN = "background-color:green;";


class Lab {
public:
    std::vector<QWidget *> machine;
    std::vector<std::string> machineNames;
public:
    Lab();

    Lab(std::vector<QWidget *> v);

    ~Lab();

    void changeColourAll(QString colour);

};

#endif // LAB_H
