#ifndef QUERYFROMSERVICEDIALOG_H
#define QUERYFROMSERVICEDIALOG_H

#include <QDialog>
#include "ui_QueryFromServiceDialog.h"

class QueryFromServiceDialog : public QDialog
{
	Q_OBJECT

public:
	QueryFromServiceDialog(QWidget *parent = 0);
	~QueryFromServiceDialog();

	QString getServiceUrl();

protected slots:
	void slotOK();
	void slotCancel();

private:
	Ui::QueryFromServiceDialog ui;
};

#endif // QUERYFROMSERVICEDIALOG_H
