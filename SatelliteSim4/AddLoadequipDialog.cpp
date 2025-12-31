#include "AddLoadequipDialog.h"
#include "ui_AddLoadequipDialog.h"

AddLoadequipDialog::AddLoadequipDialog(QWidget *parent) :
	QDialog(parent),
    ui(new Ui::AddLoadequipDialog)
{
    ui->setupUi(this);
}

AddLoadequipDialog::~AddLoadequipDialog()
{
    delete ui;
}
