#pragma execution_character_set("utf-8")

#include "LoginDialog.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>

LoginDialog::LoginDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	this->setWindowFlags(Qt::FramelessWindowHint);

	connect(ui.pushButtonLogin, &QPushButton::clicked, this, &LoginDialog::slotLogin);
	connect(ui.pushButtonQuit, &QPushButton::clicked, this, &LoginDialog::slotQuit);

	this->showMaximized();
}

LoginDialog::~LoginDialog()
{

}

void LoginDialog::slotLogin()
{
	if (ui.lineEditName->text().isNull() || ui.lineEditName->text().isEmpty())
	{
		QMessageBox::warning(this, tr("¾¯¸æ£¡"), tr("ÇëÊäÈëÓÃ»§Ãû£¡"), QMessageBox::Yes);
		return;
	}

	if (ui.lineEditPwd->text().isNull() || ui.lineEditPwd->text().isEmpty())
	{
		QMessageBox::warning(this, tr("¾¯¸æ£¡"), tr("ÇëÊäÈëÃÜÂë£¡"), QMessageBox::Yes);
		return;
	}

	QStringList drivers = QSqlDatabase::drivers();
	foreach(QString driver, drivers)
		qDebug() << driver;

	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("1.15.154.157");
	db.setDatabaseName("cstk");
	db.setUserName("CSTK");
	db.setPassword("CSTK123");
	if (!db.open())
	{
		QMessageBox::critical(0, tr("´íÎó"), tr("µÇÂ¼Ê§°Ü£¡"), QMessageBox::Cancel);
		return;
	}

	QSqlQuery result = db.exec("select pwd from user where username = '" + ui.lineEditName->text() + "'");
	int index = 0;
	QString pwd = QString::null;
	while (result.next())
	{
		 pwd = result.value(0).toString();
		 break;
	}

	if (pwd.isNull())
	{
		QMessageBox::critical(0, tr("´íÎó"), tr("µÇÂ¼Ê§°Ü£¡"), QMessageBox::Cancel);
		return;
	}

	if (pwd != ui.lineEditPwd->text())
	{
		QMessageBox::critical(0, tr("´íÎó"), tr("ÓÃ»§Ãû»òÃÜÂë´íÎó£¡"), QMessageBox::Cancel);
		return;
	}

	this->accept();
}

void LoginDialog::slotQuit()
{
	this->reject();
}