#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "lab.h"

#include <iostream>
#include <QLineEdit>
#include <string>
#include <unistd.h>

std::string RWHOFILE = "/home/sysassist/Ethan/qt/QT_UofL_Lab_Status/rwho.txt";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    // Setup for C Lab
    ui->tabWidget->setTabText(0, "C Lab");
    std::vector<QWidget *> CMachine{};
    Lab *cLab = new Lab(CMachine);


    // Setup for D Lab
    ui->tabWidget->setTabText(1, "D Lab");
    std::vector<QWidget *> DMachine{};
    Lab *dLab = new Lab(DMachine);


    // Setup for Overflow Lab
    ui->tabWidget->setTabText(2, "Overflow Lab");
    std::vector<QWidget *> overflowMachine{ui->amycus, ui->asbolus, ui->bienor, ui->chariklo,
                                           ui->chiron, ui->hylonome, ui->nessus, ui->pholus};
    Lab *overFlow = new Lab(overflowMachine);
    //overFlow->updateLoggedIn(RWHOFILE);


    if(ui->amycus->objectName() == "amycus")
        std::cout << "Working" << std::endl;


    delete cLab;
    delete dLab;
    delete overFlow;
}

MainWindow::~MainWindow()
{
    delete ui;
}
