#include "FixPosLookAroundDialog.h"

FixPosLookAroundDialog::FixPosLookAroundDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.pushButtonOK, &QPushButton::clicked, this, &FixPosLookAroundDialog::slotOK);
	connect(ui.pushButtonCancel, &QPushButton::clicked, this, &FixPosLookAroundDialog::slotCancel);
}

FixPosLookAroundDialog::~FixPosLookAroundDialog()
{

}

void FixPosLookAroundDialog::getLonLat(double& lon, double& lat)
{
	lon = ui.doubleSpinBoxLon->value();
	lat = ui.doubleSpinBoxLat->value();
}

void FixPosLookAroundDialog::slotOK()
{
	this->accept();
}

void FixPosLookAroundDialog::slotCancel()
{
	this->reject();
}