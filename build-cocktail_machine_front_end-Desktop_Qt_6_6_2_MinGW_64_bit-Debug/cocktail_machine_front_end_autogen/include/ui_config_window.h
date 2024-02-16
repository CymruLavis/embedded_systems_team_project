/********************************************************************************
** Form generated from reading UI file 'config_window.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIG_WINDOW_H
#define UI_CONFIG_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_config_window
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_to_system_status;
    QPushButton *btn_to_menu;

    void setupUi(QDialog *config_window)
    {
        if (config_window->objectName().isEmpty())
            config_window->setObjectName("config_window");
        config_window->resize(480, 320);
        horizontalLayoutWidget = new QWidget(config_window);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(0, 289, 175, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btn_to_system_status = new QPushButton(horizontalLayoutWidget);
        btn_to_system_status->setObjectName("btn_to_system_status");

        horizontalLayout->addWidget(btn_to_system_status);

        btn_to_menu = new QPushButton(horizontalLayoutWidget);
        btn_to_menu->setObjectName("btn_to_menu");

        horizontalLayout->addWidget(btn_to_menu);


        retranslateUi(config_window);

        QMetaObject::connectSlotsByName(config_window);
    } // setupUi

    void retranslateUi(QDialog *config_window)
    {
        config_window->setWindowTitle(QCoreApplication::translate("config_window", "Dialog", nullptr));
        btn_to_system_status->setText(QCoreApplication::translate("config_window", "Sys. Status", nullptr));
        btn_to_menu->setText(QCoreApplication::translate("config_window", "Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class config_window: public Ui_config_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIG_WINDOW_H
