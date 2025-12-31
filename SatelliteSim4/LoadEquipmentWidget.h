#ifndef LOADEQUIPMENTWIDGET_H
#define LOADEQUIPMENTWIDGET_H

#include <QWidget>
#include "ui_LoadEquipmentWidget.h"
#include "StructDefine.h"

class LoadEquipmentWidget : public QWidget
{
	Q_OBJECT

public:
	LoadEquipmentWidget(int index, LoadEquipment loadEqu, QWidget *parent = 0);
	~LoadEquipmentWidget();

Q_SIGNALS:
	void deletePayload(QString id);

protected slots:
	void slotUninstallLoadEqu();
	void slotDetailInfomation();

private:
	Ui::LoadEquipmentWidget ui;
	LoadEquipment _loadEqu;
	int	_index;
};

#endif // LOADEQUIPMENTWIDGET_H
