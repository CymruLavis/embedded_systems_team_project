#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Include/Data.h"
#include <vector>
#include <algorithm>
#include <QAbstractItemView>
#include "../Include/MakeDrink.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Initial button connection setup
    QObject::connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(CT2()));
    QObject::connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(CT3()));
    QObject::connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(CT5()));
    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(CT6()));

    //Get drinks that can be made from present ingredients
    ui->comboBox->addItems(ConvertList(data->getActiveDrinkList()));
    connect(ui->comboBox, SIGNAL(currentTextChanged(const QString&)), this, SLOT(CT4()));

    //Drop down for Position pick on settings
    ui->comboBox_2->addItems({"Position 1", "Position 2", "Position 3", "Position 4", "Position 5", "Position 6"});

    //Drop down for Ingredient pick on settings
    ui->comboBox_3->addItems(ConvertList(data->getIngredients()));
    
    //Scroll bar enable
    ui->comboBox->view()->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->comboBox_3->view()->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::CT1()
{
    //Main page button listener
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
    //Page 2 transition
    QObject::connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(CT1()));
    ui->stackedWidget->setCurrentWidget(ui->page_2);
    ui->page->close();

    //Setting progress bar values from CSV
    SetPBarValue();
};

void MainWindow::CT3()
{
    //Transition to settings page
    QObject::connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(CT1()));
    ui->stackedWidget->setCurrentWidget(ui->page_3);
    ui->page->close();

};

void MainWindow::CT4()
{
    //Set text description based on drink selection on main page
    connect(ui->comboBox, SIGNAL(currentTextChanged(const QString&)), this, NULL);
    if(ui->comboBox->currentText() == "")
    {
        ui->textBrowser->setText("");
    }
    else
    {
        ui->textBrowser->setText(QString::fromStdString(data->getDrinkDescription(ui->comboBox->currentText().toStdString())));
    }

};

void MainWindow::CT5()
{
    //Append CSV with new values for position and ingredient from settings page
    connect(ui->pushButton_5, SIGNAL(clicked()), this, NULL);
    string pose = (ui->comboBox_2->currentText()).toStdString();
    string ing = (ui->comboBox_3->currentText()).toStdString();
    data->append_CSV(pose, ing);
    
};

void MainWindow::CT6()
{
    //Make Drink callback for main page, then UI refresh
    connect(ui->pushButton, SIGNAL(clicked()), this, NULL);
    string drinkName = (ui->comboBox->currentText()).toStdString();
    Make_a_drink(drinkName);
    ui->page->repaint();

};

QStringList MainWindow::ConvertList(vector<string> list)
{
    //Function to convert vector<string> list from Dataclass to QStringlist
    QStringList qList;
    for (const auto& str : list) {
        qList.append(QString::fromStdString(str));
    }
    return qList;
};

void MainWindow::SetPBarValue()
{
    //Set progress bar values from CSV object on page 2
    ui->progressBar->setValue(stoi(data->fill_data[0][2]));
    ui->progressBar_2->setValue(stoi(data->fill_data[1][2]));
    ui->progressBar_3->setValue(stoi(data->fill_data[2][2]));
    ui->progressBar_4->setValue(stoi(data->fill_data[3][2]));
    ui->progressBar_5->setValue(stoi(data->fill_data[4][2]));
    ui->progressBar_6->setValue(stoi(data->fill_data[5][2]));
};
