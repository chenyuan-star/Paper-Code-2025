#pragma once

#include <QDialog>
#include "ui_DetailedInformationDialog.h"
#include "Common.h"

// 卫星详细信息
class DetailedInformationDialog : public QDialog
{
	Q_OBJECT

public:
	DetailedInformationDialog(COE_ELEMENT* element, QWidget *parent = 0);
	~DetailedInformationDialog();

	// 返回所有载荷列表
	QList<LoadEquipment> getAllPayloadList();

	void setName(QString name)
	{
		ui.lineEditNameSateName->setText(name);
	}
	void setInternationalNumber(QString internationalNumber)
	{
		ui.lineEditNameInternationalNumber->setText(internationalNumber);
	}
	void setLaunchSite(QString launchSite)
	{
		ui.lineEditNameLaunchSite->setText(launchSite);
	}
	void setLaunchNumber(QString launchNumber)
	{
		ui.lineEditNameLaunchNumber->setText(launchNumber);
	}
	void setLaunchDate(QString launchDate)
	{
		ui.lineEditNameLaunchSequence->setText(launchDate);
	}

	void setLongitudeOfTheAscendingNode(double longitudeOfTheAscendingNode) {
		ui.labelLongitudeOfTheAscendingNode->setText(QString("%1").arg(longitudeOfTheAscendingNode));
	}

	void setInclination(double inclination) {
		ui.labelInclination->setText(QString("%1").arg(inclination));
	}

	void setSemimajorAxis(double semimajorAxis) {
		ui.labelSemimajorAxis->setText(QString("%1").arg(semimajorAxis));
	}

	void setEccentricity(double eccentricity) {
		ui.labelEccentricity->setText(QString("%1").arg(eccentricity));
	}

	void setArgumentOfPerigee(double argumentOfPerigee) {
		ui.labelArgumentOfPerigee->setText(QString("%1").arg(argumentOfPerigee));
	}

	void setRoll(double roll) {
		if (roll < 0.0000001)
		{
			ui.labelRoll->setText("0");
		}
		else
		{
			ui.labelRoll->setText(QString("%1").arg(roll));
		}
	}

	void setPitch(double pitch) {
		if (pitch < 0.0000001)
		{
			ui.labelPitch->setText("0");
		}
		else
		{
			ui.labelPitch->setText(QString("%1").arg(pitch));
		}
	}

	void setYaw(double yaw) {
		if (yaw < 0.0000001)
		{
			ui.labelYaw->setText("0");
		}
		else
		{
			ui.labelYaw->setText(QString("%1").arg(yaw));
		}
	}
	
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

	// 根据卫星名称返回载荷列表
	QList<LoadEquipment> getSatelliteLoadEquipmentByName(QString name);

	// 根据载荷id删除载荷设备
	int deletePayload(QString id);

	// 增加载荷
	int insertPayload(LoadEquipment loadEqu);

private:
	Ui::DetailedInformationDialog ui;
	COE_ELEMENT* _element;
	QList<LoadEquipment> _loadEquList;
	QList<LoadEquipment> _allLoadEquipment;
};

