#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "lab.h"

#include <iostream>
#include <string>
#include <QLineEdit>
#include <QApplication>
#include <unistd.h>

std::string RWHOFILE = "/home/sysassist/Ethan/qt/QT_UofL_Lab_Status/rwho.txt";

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    w.ui->tabWidget->setStyleSheet("QTabBar::tab { height: 50px; width: 150px; }");

    // Setup for C Lab
    w.ui->tabWidget->setTabText(0, "C Lab");
    std::vector<QWidget *> CMachine{};
    Lab cLab(RWHOFILE, CMachine);


    // Setup for D Lab
    w.ui->tabWidget->setTabText(1, "D Lab");
    std::vector<QWidget *> DMachine{w.ui->oberon, w.ui->neried, w.ui->naiad, w.ui->miranada,
                                    w.ui->metis, w.ui->lysithea, w.ui->leda, w.ui->larissa,
                                    w.ui->rhea, w.ui->puck, w.ui->proteus, w.ui->portia,
                                    w.ui->phoebe, w.ui->phobos, w.ui->pasiphae, w.ui->pandora,
                                    w.ui->ophelia, w.ui->titania, w.ui->titan, w.ui->thebe,
                                    w.ui->thalassa, w.ui->thethys, w.ui->telesto, w.ui->sinope,
                                    w.ui->rosalind, w.ui->mimas};
    Lab dLab(RWHOFILE, DMachine);
    dLab.updateLoggedIn();


    // Setup for Overflow Lab
    w.ui->tabWidget->setTabText(2, "Overflow Lab");
    std::vector<QWidget *> overflowMachine{w.ui->amycus, w.ui->asbolus, w.ui->bienor, w.ui->chariklo,
                                           w.ui->chiron, w.ui->hylonome, w.ui->nessus, w.ui->pholus};
    Lab overFlow(RWHOFILE, overflowMachine);
    overFlow.updateLoggedIn();

    return a.exec();
}
