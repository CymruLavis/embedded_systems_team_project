#include "config_window.h"
#include "ui_config_window.h"

config_window::config_window(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::config_window)
{
    ui->setupUi(this);
}

config_window::~config_window()
{
    delete ui;
}

void config_window::on_btn_to_system_status_clicked()
{
}

