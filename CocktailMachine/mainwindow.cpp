#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(CT2()));
    QObject::connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(CT3()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::CT1()
{
    QObject::connect(ui->pushButton_2, SIGNAL(clicked()), this, NULL);
    ui->stackedWidget->setCurrentWidget(ui->page);
    ui->page_2->close();
    ui->page_3->close();
};

void MainWindow::CT2()
{
    QObject::connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(CT1()));
    ui->stackedWidget->setCurrentWidget(ui->page_2);
    ui->page->close();
};

void MainWindow::CT3()
{
    QObject::connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(CT1()));
    ui->stackedWidget->setCurrentWidget(ui->page_3);
    ui->page->close();
};
