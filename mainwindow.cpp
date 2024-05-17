#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "lab.h"

#include <iostream>
#include <QLineEdit>
#include <string>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->tabWidget->setTabText(0, "C Lab");


    ui->tabWidget->setTabText(1, "D Lab");


    ui->tabWidget->setTabText(2, "Overflow Lab");

    std::vector<QWidget *> overflowMachine{ui->amycus, ui->asbolus, ui->bienor, ui->chariklo,
                                           ui->chiron, ui->hylonome, ui->nessus, ui->pholus};

    /*
    for(unsigned long i = 0; i < overflowMachine.size(); i++) {
        overflowMachine[i]->setStyleSheet("background-color:black;");
    }
*/

    Lab overFlow(overflowMachine);

    overFlow.changeColourAll(GREEN);

    std::cout << overFlow.machine.size() << std::endl;

    if(ui->amycus->objectName() == "amycus")
        std::cout << "Working" << std::endl;

}

MainWindow::~MainWindow()
{
    delete ui;
}
