#include "AddRadarStationDialog.h"

AddRadarStationDialog::AddRadarStationDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.pushButtonOk, &QPushButton::clicked, this, &AddRadarStationDialog::slotOk);
	connect(ui.pushButtonCancel, &QPushButton::clicked, this, &AddRadarStationDialog::slotCancel);
}

AddRadarStationDialog::~AddRadarStationDialog()
{

}

void AddRadarStationDialog::slotOk()
{
	this->accept();
}

void AddRadarStationDialog::slotCancel()
{
	this->reject();
}