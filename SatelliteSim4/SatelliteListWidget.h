#ifndef SATELLITELISTWIDGET_H
#define SATELLITELISTWIDGET_H

#include <QDialog>
#include "ui_SatelliteListWidget.h"

class SatelliteListWidget : public QDialog
{
	Q_OBJECT

public:
	SatelliteListWidget(QWidget *parent = 0);
	~SatelliteListWidget();
	void setTableHeader();
	void setTableContent(QString s = "SELECT * FROM satellites ORDER BY ID");

	protected slots:
	void slot_clickTableHeader(int col);

private:
	Ui::SatelliteListWidget ui;
};

#endif // SATELLITELISTWIDGET_H