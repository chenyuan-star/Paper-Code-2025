#include "LoadequipListWidget.h"
#include "ui_LoadequipListWidget.h"
#include "LoadquipInformation.h"
#include "StructDefine.h"
#include "DetailedInformationDialog.h"

// 载荷列表化对话框
LoadequipListWidget::LoadequipListWidget(QWidget *parent) :
	QDialog(parent),
    ui(new Ui::LoadequipListWidget)
{
    ui->setupUi(this);
	ui->tableWidget->setEditTriggers(QTableWidget::NoEditTriggers);

	connect(ui->tableWidget, SIGNAL(itemDoubleClicked(QTableWidgetItem *)), this, SLOT(slotItemDoubleClicked(QTableWidgetItem *)));

	QList<LoadEquipment> allLoadEquipment = getAllPayloadList();
	
	ui->tableWidget->clearContents();
	ui->tableWidget->setRowCount(allLoadEquipment.size());
	for (int i = 0; i < allLoadEquipment.size(); i++)
	{
		LoadEquipment loadEquiment = allLoadEquipment[i];
		ui->tableWidget->setItem(i, 0, new QTableWidgetItem(loadEquiment.id));
		ui->tableWidget->setItem(i, 1, new QTableWidgetItem(loadEquiment.deviceName));
		ui->tableWidget->setItem(i, 2, new QTableWidgetItem(loadEquiment.deviceNum));
		ui->tableWidget->setItem(i, 3, new QTableWidgetItem(loadEquiment.satelliteID));

		ui->tableWidget->setRowHeight(i, 20);
	}
}

LoadequipListWidget::~LoadequipListWidget()
{
    delete ui;
}

void LoadequipListWidget::slotItemDoubleClicked(QTableWidgetItem *)
{
	int currRow = ui->tableWidget->currentRow();
	QList<LoadEquipment> allLoadEquipment = getAllPayloadList();

	LoadEquipment currLoadEqui;
	for (int i = 0; i < allLoadEquipment.size(); i++)
	{
		if (allLoadEquipment[i].id == ui->tableWidget->item(i, 0)->text())
		{
			currLoadEqui = allLoadEquipment[i];
			break;
		}
	}

	LoadquipInformation* widget = new LoadquipInformation(currLoadEqui);
	widget->exec();
}

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include <QMessageBox>

// 返回所有载荷列表
QList<LoadEquipment> LoadequipListWidget::getAllPayloadList()
{
	QString url = "http://localhost:8088/getAllPayloadList";

	QNetworkAccessManager manager;
	QNetworkRequest req;
	req.setUrl(QUrl(url));
	req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json;charset=UTF-8");
	QNetworkReply* reply = manager.post(req, "");
	QEventLoop eventLoop;
	connect(&manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
	//connect(progDialog, SIGNAL(canceled), &eventLoop, SLOT(quit()));
	eventLoop.exec();

	QList<LoadEquipment> loadEquipments;

	//if (progDialog->wasCanceled() == true) return loadEquipments;

	if (reply->error() == QNetworkReply::NoError)
	{
		QByteArray ba = reply->readAll();
		QJsonParseError jsonpe;
		QJsonDocument json = QJsonDocument::fromJson(ba, &jsonpe);

		if (jsonpe.error == QJsonParseError::NoError)
		{
			QJsonObject rootObj = json.object();

			int size = rootObj.value("size").toInt();

			QJsonArray loadEquList = rootObj.value("loadEquipmentsList").toArray();

			// 载荷
			for (int k = 0; k < loadEquList.count(); k++)
			{
				QJsonObject childInfoObj = loadEquList.at(k).toObject();

				LoadEquipment loadEqu;

				loadEqu.id = childInfoObj["_id"].toString();
				loadEqu.deviceId = childInfoObj["deviceId"].toString().toInt();
				loadEqu.deviceName = childInfoObj["deviceName"].toString();
				loadEqu.deviceNum = childInfoObj["deviceNum"].toString().toInt();
				loadEqu.satelliteID = childInfoObj["satelliteID"].toString().toInt();

				loadEquipments.push_back(loadEqu);
			}
		}
		else
		{
			QMessageBox::information(this, "Error", jsonpe.errorString(), QMessageBox::Ok);
		}
	}
	else
	{
		QMessageBox::information(this, "Error", reply->errorString(), QMessageBox::Ok);
	}

	return loadEquipments;
}