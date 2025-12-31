#ifndef NEWSATELLITEDIALOG_H
#define NEWSATELLITEDIALOG_H

#include <QDialog>
#include "ui_NewSatelliteDialog.h"
#include <osg/Math>

/**
* @brief 新建卫星对话框
* @return
*/
class NewSatelliteDialog : public QDialog
{
	Q_OBJECT

public:
	NewSatelliteDialog(QString name, QWidget *parent = 0);
	~NewSatelliteDialog();

	/**
	* 获取名字
	*/
	QString getName()
	{
		return ui.lineEditName->text();
	}

	/**
	* 升交点赤经
	*/
	double getLongitudeOfTheAscendingNode_R()
	{
		return osg::DegreesToRadians(ui.doubleSpinBoxLongitudeOfTheAscendingNode->value());
	}

	double getLongitudeOfTheAscendingNode_D()
	{
		return ui.doubleSpinBoxLongitudeOfTheAscendingNode->value();
	}

	/**
	* 轨道倾角
	*/
	double getInclination_R()
	{
		return osg::DegreesToRadians(ui.doubleSpinBoxInclination->value());
	}

	double getInclination_D()
	{
		return ui.doubleSpinBoxInclination->value();
	}

	/**
	* 长半轴
	*/
	double getSemimajorAxis()
	{
		return ui.doubleSpinBoxSemimajorAxis->value() * 1000;
	}

	/**
	* 偏心率
	*/
	double getEccentricity()
	{
		return ui.doubleSpinBoxEccentricity->value();
	}

	/**
	* 近地点幅角
	*/
	double getArgumentOfPerigee_R()
	{
		return osg::DegreesToRadians(ui.doubleSpinBoxArgumentOfPerigee->value());
	}

	double getArgumentOfPerigee_D()
	{
		return ui.doubleSpinBoxArgumentOfPerigee->value();
	}

	/**
	* 真近点角
	*/
	double getMeanAnomaly_R()
	{
		return osg::DegreesToRadians(ui.doubleSpinBoxMeanAnomaly->value());
	}

	double getMeanAnomaly_D()
	{
		return ui.doubleSpinBoxMeanAnomaly->value();
	}

	/**
	* 翻滚角
	*/
	double getRoll()
	{
		return ui.doubleSpinBoxRoll->value();
	}

	/**
	* 俯仰角
	*/
	double getPitch()
	{
		return ui.doubleSpinBoxPitch->value();
	}

	/**
	* 偏航角
	*/
	double getYaw()
	{
		return ui.doubleSpinBoxYaw->value();
	}

	/**
	* 载荷
	*/
	QString getPayloadFile()
	{
		return ui.lineEditPayloadFile->text();
	}

protected slots:
	void slotOK();
	void slotCancel();
	void slotOpenPayload();

private:
	Ui::NewSatelliteDialog ui;
};

#endif // NEWSATELLITEDIALOG_H
