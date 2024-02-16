#pragma once

#ifndef CONFIG_WINDOW_H
#define CONFIG_WINDOW_H

#include <QDialog>
//#include "mainwindow.h"

namespace Ui {
class config_window;
}

class config_window : public QDialog
{
    Q_OBJECT

public:
    explicit config_window(QWidget *parent = nullptr);
    ~config_window();

private slots:
    void on_btn_to_system_status_clicked();

private:
    Ui::config_window *ui;
    //MainWindow *main_window;
};

#endif // CONFIG_WINDOW_H
