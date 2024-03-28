#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Include/Data.h"
#include <vector>
#include <algorithm>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(CT2()));
    QObject::connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(CT3()));

    QStringList Drinks = ConvertList(data->getWholeDrinkList());
    ui->comboBox->addItems(Drinks);
    connect(ui->comboBox, SIGNAL(currentTextChanged(const QString&)), this, SLOT(CT4()));
    

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

void MainWindow::CT4()
{
    connect(ui->comboBox, SIGNAL(currentTextChanged(const QString&)), this, NULL);
    if(ui->comboBox->currentText() == "")
    {
        ui->textBrowser->setText("");
    }
    else
    {
        ui->textBrowser->setText(QString::fromStdString(data->getDrinkDescription(ui->comboBox->currentText().toStdString())));
    }

}

QStringList MainWindow::ConvertList(vector<string> list)
{
    QStringList qList;
    for (const auto& str : list) {
        qList.append(QString::fromStdString(str));
    }
    return qList;
};

