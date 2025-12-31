#include "LoadquipInformation.h"
#include "ui_LoadquipInformation.h"

// 载荷详细信息
LoadquipInformation::LoadquipInformation(LoadEquipment loadEqui, QWidget *parent) :
	QDialog(parent),
    ui(new Ui::LoadquipInformation),
	_loadEqui(loadEqui)
{
    ui->setupUi(this);

	ui->lineEditName->setText(_loadEqui.deviceName);
	ui->lineEditType->setText(_loadEqui.deviceType);
	ui->lineEditState->setText(_loadEqui.deviceState);
	ui->lineEditNumber->setText(_loadEqui.id);
	ui->lineEditDeviceNumber->setText(QString("%1").arg(_loadEqui.deviceId));
	ui->lineEditImage->setText(_loadEqui.image);

	// 具体功能
	ui->listWidgetFunctions->addItem(QStringLiteral("无。"));

	// 详细参数
	ui->listWidgetDetailParameter->addItem(QStringLiteral("无。"));
}

LoadquipInformation::~LoadquipInformation()
{
    delete ui;
}
