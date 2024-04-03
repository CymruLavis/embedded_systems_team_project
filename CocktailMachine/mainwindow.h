#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "Include/Data.h"
using namespace std;

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
    Data* data = new Data();

private:
    Ui::MainWindow *ui;

public slots:
    void CT1();
    void CT2();
    void CT3();
    void CT4();
    void CT5();
    QStringList ConvertList(vector<string> list);
    void SetPBarValue();
};
#endif // MAINWINDOW_H
