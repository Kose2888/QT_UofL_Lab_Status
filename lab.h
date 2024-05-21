#ifndef LAB_H
#define LAB_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <QMainWindow>


const QString BLACK = "background-color:black;";
const QString UNKNOWN = "background-color:grey;";
const QString ONLINE = "background-color:green;";
const QString OFFLINE = "background-color:red;";
const QString IN_USE = "background-color:orange;";


class Lab {
private:
    std::vector<QWidget *> machine;

    // From rwho file
    std::vector<std::string> accountName;
    std::vector<std::string> machineName;

public:
    Lab();

    Lab(std::vector<QWidget *> v);

    ~Lab();

    void changeColourAll(QString colour);

    void extract_rwho(std::string fileName);

    void updateLoggedIn(std::string fileName);

};

#endif // LAB_H
