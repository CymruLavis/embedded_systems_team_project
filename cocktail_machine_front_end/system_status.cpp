#include "system_status.h"
#include "ui_system_status.h"

system_status::system_status(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::system_status)
{
    ui->setupUi(this);
}

system_status::~system_status()
{
    delete ui;
}
