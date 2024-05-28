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
    std::vector<QWidget *> CMachine{w.ui->adrastea, w.ui->amalthea, w.ui->ananke, w.ui->ariel,
                                    w.ui->belinda, w.ui->bianca, w.ui->callisto, w.ui->calypso,
                                    w.ui->carme, w.ui->charon, w.ui->cordelia, w.ui->cressida,
                                    w.ui->deimos, w.ui->depina, w.ui->dione, w.ui->elara,
                                    w.ui->europa, w.ui->galatea, w.ui->ganymede, w.ui->helene,
                                    w.ui->himalia, w.ui->hyperion, w.ui->iapetus, w.ui->janus,
                                    w.ui->juliet, w.ui->triton, w.ui->thor, w.ui->jacob,
                                    w.ui->lancer, w.ui->enzo};
    Lab cLab(RWHOFILE, CMachine);
    //cLab.updateLoggedIn();


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
