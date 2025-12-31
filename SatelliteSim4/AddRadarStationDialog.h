#ifndef ADDRADARSTATIONDIALOG_H
#define ADDRADARSTATIONDIALOG_H

#include <QDialog>
#include "ui_AddRadarStationDialog.h"

class AddRadarStationDialog : public QDialog
{
	Q_OBJECT

public:
	AddRadarStationDialog(QWidget *parent = 0);
	~AddRadarStationDialog();

	QString getName() { return ui.lineEditName->text(); }

	double getLon() { return ui.doubleSpinBoxLon->value(); }

	double getLat() { return ui.doubleSpinBoxLat->value(); }

	double getHei() { return ui.doubleSpinBoxHei->value(); }

protected slots:
	void slotOk();
	void slotCancel();

private:
	Ui::AddRadarStationDialog ui;
};

#endif // ADDRADARSTATIONDIALOG_H
