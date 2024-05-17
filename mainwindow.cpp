#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "lab.h"

#include <iostream>
#include <QLineEdit>
#include <string>

#define GET_VARIABLE_NAME(Variable) (#Variable)

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->tabWidget->setTabText(0, "C Lab");


    ui->tabWidget->setTabText(1, "D Lab");


    ui->tabWidget->setTabText(2, "Overflow Lab");

    std::vector<QWidget *> overflowMachine{ui->widget_5, ui->widget_6, ui->widget_7, ui->widget_8, ui->widget_9};

    /*
    for(unsigned long i = 0; i < overflowMachine.size(); i++) {
        overflowMachine[i]->setStyleSheet("background-color:black;");
    }
*/

    std::string var = GET_VARIABLE_NAME(ui->widget_2);

    std::cout << var << std::endl;


    Lab overFlow(overflowMachine);

    //overFlow.changeColour();

    std::cout << overFlow.Machine.size() << std::endl;

}

MainWindow::~MainWindow()
{
    delete ui;
}
