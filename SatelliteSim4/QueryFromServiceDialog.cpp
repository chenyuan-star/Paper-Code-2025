#include "QueryFromServiceDialog.h"

QueryFromServiceDialog::QueryFromServiceDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	ui.lineEditUrl->setText("http://localhost:8088");

	connect(ui.pushButtonOK, &QPushButton::clicked, this, &QueryFromServiceDialog::slotOK);
	connect(ui.pushButtonCancel, &QPushButton::clicked, this, &QueryFromServiceDialog::slotCancel);
}

QueryFromServiceDialog::~QueryFromServiceDialog()
{

}

void QueryFromServiceDialog::slotOK()
{
	this->accept();
}

void QueryFromServiceDialog::slotCancel()
{
	this->reject();
}

QString QueryFromServiceDialog::getServiceUrl()
{
	return ui.lineEditUrl->text();
}