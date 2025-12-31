#ifndef CONFIGMANAGEDIALOG_H
#define CONFIGMANAGEDIALOG_H

#include <QDialog>
#include "ui_ConfigManageDialog.h"
#include "Common.h"

class ConfigManageDialog : public QDialog
{
	Q_OBJECT

public:
	ConfigManageDialog(COE_ELEMENT* element, QWidget *parent = 0);
	~ConfigManageDialog();

protected slots:
	void slotClose();
	void slotUninstallLoadEqu1();
	void slotUninstallLoadEqu2();
	void slotInstallLoadEqu();
	void slotDeletePayload(QString id);

private:
	// 20220325
	// 根据卫星id返回该卫星载荷
	QList<LoadEquipment> getSatelliteLoadEquipmentByID(QString id);

	// 返回所有载荷列表
	QList<LoadEquipment> getAllPayloadList();

	// 根据卫星名称返回载荷列表
	QList<LoadEquipment> getSatelliteLoadEquipmentByName(QString name);

	// 根据载荷id删除载荷设备
	int deletePayload(QString id);

	// 增加载荷
	int insertPayload(LoadEquipment loadEqu);

private:
	Ui::ConfigManageDialog ui;
	COE_ELEMENT* _element;
	QList<LoadEquipment> _loadEquList;
	QList<LoadEquipment> _allLoadEquipment;
};

#endif // CONFIGMANAGEDIALOG_H
