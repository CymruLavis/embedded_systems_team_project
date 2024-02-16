#ifndef SYSTEM_STATUS_H
#define SYSTEM_STATUS_H

#include <QDialog>

namespace Ui {
class system_status;
}

class system_status : public QDialog
{
    Q_OBJECT

public:
    explicit system_status(QWidget *parent = nullptr);
    ~system_status();

private:
    Ui::system_status *ui;
};

#endif // SYSTEM_STATUS_H
