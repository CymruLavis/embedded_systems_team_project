#include "mainwindow.h"
#include "./ui_mainwindow.h"
// inclue backend.cpp

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    // create object of sql connection
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    // send drink name tag to backend

}


void MainWindow::on_cbo_drink_choice_currentTextChanged(const QString &arg1)
{
    // validate that something is slected in the drop down box
    //send drink name tag to backend to return drink descrption
    // insert the drink description into the text box
}


void MainWindow::on_btn_to_config_clicked()
{
    hide();
    configureWindow = new config_window(this);
    configureWindow->show();
    // query for this to happen
    // object.function()
}

