#pragma once

#include <QDialog>
#include "ui_DetailedInformationDialog.h"

class DetailedInformationDialog : public QDialog
{
	Q_OBJECT

public:
	DetailedInformationDialog(QWidget *parent = 0);
	~DetailedInformationDialog();

	Ui::DetailedInformationDialog ui;


	
	

	void setName(QString name)
	{
		ui.lineEditName_2->setText(name);
	}

	void setLongitudeOfTheAscendingNode(double longitudeOfTheAscendingNode){
		ui.labelLongitudeOfTheAscendingNode->setText(QString("%1").arg(longitudeOfTheAscendingNode));
	}

	void setInclination(double inclination){
		ui.labelInclination->setText(QString("%1").arg(inclination));
	}

	void setSemimajorAxis(double semimajorAxis){
		ui.labelSemimajorAxis->setText(QString("%1").arg(semimajorAxis));
	}

	void setEccentricity(double eccentricity){
		ui.labelEccentricity->setText(QString("%1").arg(eccentricity));
	}

	void setArgumentOfPerigee(double argumentOfPerigee){
		ui.labelArgumentOfPerigee->setText(QString("%1").arg(argumentOfPerigee));
	}
	
	void setRoll(double roll){
		ui.labelRoll->setText(QString("%1").arg(roll));
	}

	void setPitch(double pitch){
		ui.labelPitch->setText(QString("%1").arg(pitch));
	}

	void setYaw(double yaw){
		ui.labelYaw->setText(QString("%1").arg(yaw));
	}

};
