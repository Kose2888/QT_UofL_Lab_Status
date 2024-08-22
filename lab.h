#ifndef LAB_H
#define LAB_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include <QMainWindow>
#include <QApplication>
#include <QtGui>
#include <qobject.h>


const QString BLACK = "background-color:black;";
const QString UNKNOWN = "background-color:grey;";
const QString ONLINE = "background-color:green;";
const QString OFFLINE = "background-color:red;";
const QString IN_USE = "background-color:orange;";


class Lab : public QWidget {
    Q_OBJECT
private:
    QString fileName;
    QString machineHealthFileName;
    std::vector<QWidget *> machine;

    // From rwho file
    QVector<QString> accountName;
    QVector<QString> machineName;

    QTimer *timer;

public:
    Lab(std::vector<QWidget *> v, QString fileName, QString fileName2);

    ~Lab();

    void changeColourAll(QString colour);

    void extract_rwho();

    void checkLoggedIn();

    void checkOffline();

public slots:
    void updateStatus();
};

#endif // LAB_H
