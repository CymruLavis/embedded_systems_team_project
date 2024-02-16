/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QComboBox *cbo_drink_choice;
    QPushButton *btn_order_drink;
    QTextBrowser *txt_drink_description;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_to_config;
    QPushButton *btn_to_sys_status;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(480, 320);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        cbo_drink_choice = new QComboBox(centralwidget);
        cbo_drink_choice->setObjectName("cbo_drink_choice");
        cbo_drink_choice->setGeometry(QRect(30, 20, 181, 31));
        cbo_drink_choice->setDuplicatesEnabled(false);
        btn_order_drink = new QPushButton(centralwidget);
        btn_order_drink->setObjectName("btn_order_drink");
        btn_order_drink->setGeometry(QRect(280, 190, 151, 41));
        txt_drink_description = new QTextBrowser(centralwidget);
        txt_drink_description->setObjectName("txt_drink_description");
        txt_drink_description->setGeometry(QRect(280, 10, 151, 161));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(0, 229, 169, 61));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btn_to_config = new QPushButton(horizontalLayoutWidget);
        btn_to_config->setObjectName("btn_to_config");

        horizontalLayout->addWidget(btn_to_config);

        btn_to_sys_status = new QPushButton(horizontalLayoutWidget);
        btn_to_sys_status->setObjectName("btn_to_sys_status");

        horizontalLayout->addWidget(btn_to_sys_status);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 480, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        cbo_drink_choice->setCurrentText(QString());
        cbo_drink_choice->setPlaceholderText(QString());
        btn_order_drink->setText(QCoreApplication::translate("MainWindow", "Make Drink", nullptr));
        btn_to_config->setText(QCoreApplication::translate("MainWindow", "Configure", nullptr));
        btn_to_sys_status->setText(QCoreApplication::translate("MainWindow", "Sys. Status", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
