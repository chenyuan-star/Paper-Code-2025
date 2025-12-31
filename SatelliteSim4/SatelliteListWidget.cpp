#pragma execution_character_set("utf-8")

#include "SatelliteListWidget.h"
#include<iostream>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include<qboxlayout.h>
#include<qradiobutton.h>
#include<qcheckbox.h>
#include<qpushbutton.h>
#include<qdialogbuttonbox.h>
#include<qradiobutton.h>
using namespace std;

SatelliteListWidget::SatelliteListWidget(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	this->setWindowTitle("卫星列表");
	ui.tableWidget->setRowCount(20);
	ui.tableWidget->setColumnCount(11);
	setTableHeader();
	setTableContent();
	connect(ui.tableWidget->horizontalHeader(), SIGNAL(sectionClicked(int)), this,
		SLOT(slot_clickTableHeader(int)));
}

SatelliteListWidget::~SatelliteListWidget()
{

}

void SatelliteListWidget::setTableHeader(){
	QStringList drivers = QSqlDatabase::drivers();
	
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("1.15.154.157");
	db.setDatabaseName("cstk");
	db.setUserName("CSTK");
	db.setPassword("CSTK123");
	if (!db.open())
	{
		QMessageBox::critical(0, "Error", db.lastError().text(), QMessageBox::Cancel);
		return;
	}

	QSqlQuery result = db.exec("SELECT COLUMN_NAME, COLUMN_COMMENT FROM information_schema.COLUMNS WHERE TABLE_NAME = 'satellites'");
	QStringList qsl;
	result.next();
	qsl.append(result.value(0).toString());
	while (result.next())
	{
		qsl.append(result.value(1).toString());
	}
	ui.tableWidget->setHorizontalHeaderLabels(qsl);
}

void SatelliteListWidget::setTableContent(QString s){
	QStringList drivers = QSqlDatabase::drivers();

	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("1.15.154.157");
	db.setDatabaseName("cstk");
	db.setUserName("CSTK");
	db.setPassword("CSTK123");
	if (!db.open())
	{
		QMessageBox::critical(0, "Error", db.lastError().text(), QMessageBox::Cancel);
		return;
	}

	QSqlQuery result = db.exec(s);
	int i = 0;

	ui.tableWidget->clearContents();
	while (result.next())
	{
		ui.tableWidget->setRowCount(i + 1);//设置表格行数
		ui.tableWidget->setItem(i, 0, new QTableWidgetItem(result.value(0).toString()));
		ui.tableWidget->item(i, 0)->setTextAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
		
		ui.tableWidget->setItem(i, 1, new QTableWidgetItem(result.value(1).toString()));
		ui.tableWidget->item(i, 1)->setTextAlignment(Qt::AlignVCenter | Qt::AlignHCenter);

		ui.tableWidget->setItem(i, 2, new QTableWidgetItem(result.value(2).toString()));
		ui.tableWidget->item(i, 2)->setTextAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
		
		ui.tableWidget->setItem(i, 3, new QTableWidgetItem(result.value(3).toString()));
		ui.tableWidget->item(i, 3)->setTextAlignment(Qt::AlignVCenter | Qt::AlignHCenter);

		ui.tableWidget->setItem(i, 4, new QTableWidgetItem(result.value(4).toString()));
		ui.tableWidget->item(i, 4)->setTextAlignment(Qt::AlignVCenter | Qt::AlignHCenter);

		ui.tableWidget->setItem(i, 5, new QTableWidgetItem(result.value(5).toString()));
		ui.tableWidget->item(i, 5)->setTextAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
		
		ui.tableWidget->setItem(i, 6, new QTableWidgetItem(result.value(6).toString()));
		ui.tableWidget->item(i, 6)->setTextAlignment(Qt::AlignVCenter | Qt::AlignHCenter);

		ui.tableWidget->setItem(i, 7, new QTableWidgetItem(result.value(7).toString()));
		ui.tableWidget->item(i, 7)->setTextAlignment(Qt::AlignVCenter | Qt::AlignHCenter);

		ui.tableWidget->setItem(i, 8, new QTableWidgetItem(result.value(8).toString()));
		ui.tableWidget->item(i, 8)->setTextAlignment(Qt::AlignVCenter | Qt::AlignHCenter);

		ui.tableWidget->setItem(i, 9, new QTableWidgetItem(result.value(9).toString()));
		ui.tableWidget->item(i, 9)->setTextAlignment(Qt::AlignVCenter | Qt::AlignHCenter);

		ui.tableWidget->setItem(i, 10, new QTableWidgetItem(result.value(10).toString()));
		ui.tableWidget->item(i, 10)->setTextAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
		
		i++;
	}
}


void SatelliteListWidget::slot_clickTableHeader(int col)
{
	if (col == 10){
		QStringList drivers = QSqlDatabase::drivers();

		QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
		db.setHostName("1.15.154.157");
		db.setDatabaseName("cstk");
		db.setUserName("CSTK");
		db.setPassword("CSTK123");
		if (!db.open())
		{
			QMessageBox::critical(0, "Error", db.lastError().text(), QMessageBox::Cancel);
			return;
		}

		QSqlQuery result = db.exec("SELECT ID, CONSTELLATIONNAME, INTRODUCTION FROM satelliteConstellation");
		int i = 1;
		QDialog* qd = new QDialog(this);
		QVBoxLayout* qvl = new QVBoxLayout(qd);
		
		QButtonGroup* qbg = new QButtonGroup(qvl);

		qd->setWindowTitle("星座");

		QDialogButtonBox *button = new QDialogButtonBox(qd);
		button->addButton("OK", QDialogButtonBox::YesRole);
		button->addButton("NO", QDialogButtonBox::NoRole);
		connect(button, SIGNAL(accepted()), qd, SLOT(accept()));
		connect(button, SIGNAL(rejected()), qd, SLOT(reject()));
		
		
		while (result.next())
		{
			QRadioButton *rb = new QRadioButton(result.value(1).toString() + result.value(2).toString());
			qbg->addButton(rb, i);
			qvl->addWidget(rb);
			i++;
		}
		qvl->addWidget(button);
		qd->show();

		if (qd->exec() == QDialog::Accepted)
		{
			int t = qbg->checkedId();
			QString qs = "SELECT * FROM satellites WHERE BELONGCONSTELLATIONID = " + QString::number(t);
			setTableContent(qs);
		}
	}
}
