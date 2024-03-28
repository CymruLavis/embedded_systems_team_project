/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *label;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QTextBrowser *textBrowser;
    QWidget *page_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QProgressBar *progressBar;
    QProgressBar *progressBar_2;
    QProgressBar *progressBar_3;
    QProgressBar *progressBar_4;
    QProgressBar *progressBar_5;
    QProgressBar *progressBar_6;
    QPushButton *pushButton_4;
    QWidget *page_3;
    QLabel *label_9;
    QLabel *label_10;
    QComboBox *comboBox_2;
    QLabel *label_11;
    QComboBox *comboBox_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(480, 320);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 480, 320));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        label = new QLabel(page);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(200, 20, 75, 25));
        label->setAlignment(Qt::AlignCenter);
        comboBox = new QComboBox(page);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(20, 60, 180, 25));
        pushButton = new QPushButton(page);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(70, 110, 90, 25));
        pushButton_2 = new QPushButton(page);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 210, 90, 25));
        pushButton_3 = new QPushButton(page);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(20, 240, 90, 25));
        textBrowser = new QTextBrowser(page);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(210, 60, 255, 195));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        label_2 = new QLabel(page_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(180, 20, 120, 25));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(page_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 60, 120, 25));
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(page_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 90, 120, 25));
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(page_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 120, 120, 25));
        label_5->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(page_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 150, 120, 25));
        label_6->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(page_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 180, 120, 25));
        label_7->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(page_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 210, 120, 25));
        label_8->setAlignment(Qt::AlignCenter);
        progressBar = new QProgressBar(page_2);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(140, 60, 280, 25));
        progressBar->setValue(24);
        progressBar_2 = new QProgressBar(page_2);
        progressBar_2->setObjectName(QString::fromUtf8("progressBar_2"));
        progressBar_2->setGeometry(QRect(140, 90, 280, 25));
        progressBar_2->setValue(24);
        progressBar_3 = new QProgressBar(page_2);
        progressBar_3->setObjectName(QString::fromUtf8("progressBar_3"));
        progressBar_3->setGeometry(QRect(140, 120, 280, 25));
        progressBar_3->setValue(24);
        progressBar_4 = new QProgressBar(page_2);
        progressBar_4->setObjectName(QString::fromUtf8("progressBar_4"));
        progressBar_4->setGeometry(QRect(140, 150, 280, 25));
        progressBar_4->setValue(24);
        progressBar_5 = new QProgressBar(page_2);
        progressBar_5->setObjectName(QString::fromUtf8("progressBar_5"));
        progressBar_5->setGeometry(QRect(140, 180, 280, 25));
        progressBar_5->setValue(24);
        progressBar_6 = new QProgressBar(page_2);
        progressBar_6->setObjectName(QString::fromUtf8("progressBar_6"));
        progressBar_6->setGeometry(QRect(140, 210, 280, 25));
        progressBar_6->setValue(24);
        pushButton_4 = new QPushButton(page_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(35, 250, 90, 25));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        label_9 = new QLabel(page_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(195, 20, 90, 25));
        label_9->setAlignment(Qt::AlignCenter);
        label_10 = new QLabel(page_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(35, 80, 90, 25));
        label_10->setAlignment(Qt::AlignCenter);
        comboBox_2 = new QComboBox(page_3);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(20, 110, 120, 25));
        label_11 = new QLabel(page_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(195, 80, 90, 25));
        label_11->setAlignment(Qt::AlignCenter);
        comboBox_3 = new QComboBox(page_3);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(180, 110, 120, 25));
        pushButton_5 = new QPushButton(page_3);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(360, 110, 90, 25));
        pushButton_6 = new QPushButton(page_3);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(20, 240, 90, 25));
        stackedWidget->addWidget(page_3);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 480, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Home", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Make Drink", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Status Menu", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Status Menu", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Position 1", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Position 2", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Position 3", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Position 4", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Position 5", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Position 6", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Home", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Position", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Ingredient", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Refill", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Home", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
