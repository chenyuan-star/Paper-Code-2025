#ifndef FIXPOSLOOKAROUNDDIALOG_H
#define FIXPOSLOOKAROUNDDIALOG_H

#include <QDialog>
#include "ui_FixPosLookAroundDialog.h"

class FixPosLookAroundDialog : public QDialog
{
	Q_OBJECT

public:
	FixPosLookAroundDialog(QWidget *parent = 0);
	~FixPosLookAroundDialog();

	void getLonLat(double& lon, double& lat);

protected slots:
	void slotOK();
	void slotCancel();

private:
	Ui::FixPosLookAroundDialog ui;
};

#endif // FIXPOSLOOKAROUNDDIALOG_H
