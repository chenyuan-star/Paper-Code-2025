#include "LoadEquipmentWidget.h"
#include "LoadquipInformation.h"

LoadEquipmentWidget::LoadEquipmentWidget(int index, LoadEquipment loadEqu, QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	_loadEqu = loadEqu;
	_index = index;
	connect(ui.pushButtonUninstallLoadEqu, SIGNAL(clicked()), this, SLOT(slotUninstallLoadEqu()));
	connect(ui.pushButtonDetailInfomation, SIGNAL(clicked()), this, SLOT(slotDetailInfomation()));
	
	ui.LabelLoadEquName->setText(_loadEqu.deviceName);
	ui.listWidgetLoadEqu->addItem("id:" + _loadEqu.id);
	ui.listWidgetLoadEqu->addItem("deviceName:" + _loadEqu.deviceName);
	ui.listWidgetLoadEqu->addItem(QString("deviceId:%1").arg(_loadEqu.deviceId));
	ui.listWidgetLoadEqu->addItem(QString("deviceNum:%1").arg(_loadEqu.deviceNum));
	ui.listWidgetLoadEqu->addItem(QString("satelliteID:%1").arg(_loadEqu.satelliteID));
	ui.label_num->setText(QString("%1").arg(index));
}

LoadEquipmentWidget::~LoadEquipmentWidget()
{

}

// –∂‘ÿ‘ÿ∫…
void LoadEquipmentWidget::slotUninstallLoadEqu()
{
	Q_EMIT deletePayload(QString("%1").arg(_loadEqu.deviceId));
}

// œÍœ∏–≈œ¢
void LoadEquipmentWidget::slotDetailInfomation()
{
	LoadquipInformation dialog(_loadEqu);
	dialog.exec();
}