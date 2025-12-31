#ifndef ADDLOADEQUIPDIALOG_H
#define ADDLOADEQUIPDIALOG_H

#include <QDialog>

namespace Ui {
class AddLoadequipDialog;
}

class AddLoadequipDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddLoadequipDialog(QWidget *parent = 0);
    ~AddLoadequipDialog();

private:
    Ui::AddLoadequipDialog *ui;
};

#endif // ADDLOADEQUIPDIALOG_H
