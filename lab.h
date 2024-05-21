#ifndef LAB_H
#define LAB_H

#include <iostream>
#include <string>
#include <vector>
#include <QMainWindow>

const QString BLACK = "background-color:black;";
const QString UNKNOWN = "background-color:grey;";
const QString ONLINE = "background-color:green;";
const QString OFFLINE = "background-color:red;";
const QString IN_USE = "background-color:orange;";


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
