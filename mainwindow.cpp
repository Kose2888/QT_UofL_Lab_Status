#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->tabWidget->setTabText(0, "C Lab");


    ui->tabWidget->setTabText(1, "D Lab");


    ui->tabWidget->setTabText(2, "Overflow Lab");
}

MainWindow::~MainWindow()
{
    delete ui;
}
