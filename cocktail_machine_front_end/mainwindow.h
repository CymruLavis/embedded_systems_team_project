#pragma once

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "config_window.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_cbo_drink_choice_currentTextChanged(const QString &arg1);

    void on_btn_to_config_clicked();

private:
    Ui::MainWindow *ui;
    config_window *configureWindow;
};
#endif // MAINWINDOW_H
