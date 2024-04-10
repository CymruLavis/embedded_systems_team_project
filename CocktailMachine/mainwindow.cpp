#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Include/Data.h"
#include <vector>
#include <algorithm>
#include <QAbstractItemView>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(CT2()));
    QObject::connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(CT3()));
    QObject::connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(CT5()));
    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(CT6()));

    ui->comboBox->addItems(ConvertList(data->getActiveDrinkList()));
    connect(ui->comboBox, SIGNAL(currentTextChanged(const QString&)), this, SLOT(CT4()));

    ui->comboBox_2->addItems({"Position 1", "Position 2", "Position 3", "Position 4", "Position 5", "Position 6"});

    ui->comboBox_3->addItems(ConvertList(data->getIngredients()));
    
    ui->comboBox->view()->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->comboBox_3->view()->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

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
    ui->comboBox->clear();
    ui->comboBox->addItem("");
    ui->comboBox->addItems(ConvertList(data->getActiveDrinkList()));
};

void MainWindow::CT2()
{
    QObject::connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(CT1()));
    ui->stackedWidget->setCurrentWidget(ui->page_2);
    ui->page->close();

    SetPBarValue();
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

void MainWindow::CT5()
{
    connect(ui->pushButton_5, SIGNAL(clicked()), this, NULL);
    string pose = (ui->comboBox_2->currentText()).toStdString();
    string ing = (ui->comboBox_3->currentText()).toStdString();
    data->append_CSV(pose, ing);
}

void MainWindow::CT6()
{

    connect(ui->pushButton, SIGNAL(clicked()), this, NULL);
    data->updateVolume("6");

}

QStringList MainWindow::ConvertList(vector<string> list)
{
    QStringList qList;
    for (const auto& str : list) {
        qList.append(QString::fromStdString(str));
    }
    return qList;
};

void MainWindow::SetPBarValue()
{
    ui->progressBar->setValue(stoi(data->fill_data[0][2]));
    ui->progressBar_2->setValue(stoi(data->fill_data[1][2]));
    ui->progressBar_3->setValue(stoi(data->fill_data[2][2]));
    ui->progressBar_4->setValue(stoi(data->fill_data[3][2]));
    ui->progressBar_5->setValue(stoi(data->fill_data[4][2]));
    ui->progressBar_6->setValue(stoi(data->fill_data[5][2]));
}
