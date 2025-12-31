#include "DetailedInformationDialog.h"
#include <QFileDialog>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include <QMessageBox>
#include <QWidgetAction>
#include <QCheckBox>
#include "LoadEquipmentWidget.h"

void deleteAllitemsOfLayout1(QLayout* layout)
{
	QLayoutItem *child;
	while ((child = layout->takeAt(0)) != nullptr)
	{
		///setParent为NULL，防止删除之后界面不消失
		if (child->widget())
		{
			child->widget()->setParent(nullptr);
		}
		else if (child->layout()) {
			deleteAllitemsOfLayout1(child->layout());
		}
		delete child;
	}
}

DetailedInformationDialog::DetailedInformationDialog(COE_ELEMENT* element, QWidget *parent)
	: QDialog(parent)
	, _element(element)
{
	ui.setupUi(this);
	_loadEquList = getSatelliteLoadEquipmentByID(QString("%1").arg(_element->id));

	QVBoxLayout* layout = new QVBoxLayout();
	layout->setContentsMargins(0, 0, 0, 0);
	ui.widgetLoadEquipments->setLayout(layout);

	for (int i = 0; i < _loadEquList.count(); i++)
	{
		LoadEquipmentWidget* loadEquWidget = new LoadEquipmentWidget(i + 1, _loadEquList[i]);

		disconnect(loadEquWidget, SIGNAL(deletePayload(QString)), this, SLOT(slotDeletePayload(QString)));
		connect(loadEquWidget, SIGNAL(deletePayload(QString)), this, SLOT(slotDeletePayload(QString)));

		layout->addWidget(loadEquWidget);
	}

	//if (_loadEquList.size() >= 1)
	//{
	//	ui.LabelLoadEqu1Name->setText(_loadEquList[0].deviceName);
	//	ui.listWidgetLoadEqu1->addItem("id:" + _loadEquList[0].id);
	//	ui.listWidgetLoadEqu1->addItem("deviceName:" + _loadEquList[0].deviceName);
	//	ui.listWidgetLoadEqu1->addItem(QString("deviceId:%1").arg(_loadEquList[0].deviceId));
	//	ui.listWidgetLoadEqu1->addItem(QString("deviceNum:%1").arg(_loadEquList[0].deviceNum));
	//	ui.listWidgetLoadEqu1->addItem(QString("satelliteID:%1").arg(_loadEquList[0].satelliteID));
	//}

	//if (_loadEquList.size() >= 2)
	//{
	//	ui.LabelLoadEqu2Name->setText(_loadEquList[1].deviceName);
	//	ui.listWidgetLoadEqu2->addItem("id:" + _loadEquList[1].id);
	//	ui.listWidgetLoadEqu2->addItem("deviceName:" + _loadEquList[1].deviceName);
	//	ui.listWidgetLoadEqu2->addItem(QString("deviceId:%1").arg(_loadEquList[1].deviceId));
	//	ui.listWidgetLoadEqu2->addItem(QString("deviceNum:%1").arg(_loadEquList[1].deviceNum));
	//	ui.listWidgetLoadEqu2->addItem(QString("satelliteID:%1").arg(_loadEquList[1].satelliteID));
	//}

	//connect(ui.pushButtonUninstallLoadEqu1, SIGNAL(clicked()), this, SLOT(slotUninstallLoadEqu1()));
	//connect(ui.pushButtonUninstallLoadEqu2, SIGNAL(clicked()), this, SLOT(slotUninstallLoadEqu2()));
	connect(ui.pushButtonInstallLoadEqu, SIGNAL(clicked()), this, SLOT(slotInstallLoadEqu()));
	connect(ui.pushButtonClose, SIGNAL(clicked()), this, SLOT(slotClose()));

	//for each (LoadEquipment var in _loadEquList)
	//{
	//	QWidgetAction* widgetAction = new QWidgetAction(ui.comboBoxEquList);
	//	widgetAction->setDefaultWidget(new QCheckBox(var.deviceName));
	//	ui.comboBoxEquList->addAction(new QWidgetAction(widgetAction));
	//}

	_allLoadEquipment = getAllPayloadList();

	ui.comboBoxEquList->clear();
	QListWidget* pListWidget = new QListWidget();

	for (int i = 0; i < _allLoadEquipment.count(); i++)
	{
		//ui.comboBoxEquList->addItem(allLoadEquipment[i].deviceName);

		//QWidgetAction* widgetAction = new QWidgetAction(ui.comboBoxEquList);
		//widgetAction->setDefaultWidget(new QCheckBox(allLoadEquipment[i].deviceName));
		//ui.comboBoxEquList->addAction(new QWidgetAction(widgetAction));

		QCheckBox* checkBox = new QCheckBox(pListWidget);
		
		QString text = QString("Name:%1,Id:%2").arg(_allLoadEquipment[i].deviceName).arg(_allLoadEquipment[i].deviceId);
		QListWidgetItem* item = new QListWidgetItem(text, pListWidget);

		pListWidget->addItem(item);
		pListWidget->setItemWidget(item, checkBox);
	}

	ui.comboBoxEquList->setModel(pListWidget->model());
	ui.comboBoxEquList->setView(pListWidget);

	ui.comboBoxEquList->setMinimumWidth(200);
}

void DetailedInformationDialog::slotClose()
{
	this->close();
}

DetailedInformationDialog::~DetailedInformationDialog()
{
}

// 根据卫星id返回该卫星载荷
QList<LoadEquipment> DetailedInformationDialog::getSatelliteLoadEquipmentByID(QString id)
{
	QString url = "http://localhost:8088/getSatelliteLoadEquipmentByID";
	QString urlFull = QString("%1/%2").arg(url).arg(id);
	QNetworkAccessManager manager;
	QNetworkRequest req;
	req.setUrl(QUrl(urlFull));
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

// 返回所有载荷列表
QList<LoadEquipment> DetailedInformationDialog::getAllPayloadList()
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

// 根据卫星名称返回载荷列表
QList<LoadEquipment> DetailedInformationDialog::getSatelliteLoadEquipmentByName(QString name)
{
	QString url = "http://localhost:8088/getSatelliteLoadEquipmentByName";

	QString urlFull = QString("%1/%2").arg(url).arg(name);
	QNetworkAccessManager manager;
	QNetworkRequest req;
	req.setUrl(QUrl(urlFull));
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

// 根据载荷id删除载荷设备
int DetailedInformationDialog::deletePayload(QString id)
{
	QString url = "http://localhost:8088/delePayload";

	QString urlFull = QString("%1/%2").arg(url).arg(id);
	QNetworkAccessManager manager;
	QNetworkRequest req;
	req.setUrl(QUrl(urlFull));
	req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json;charset=UTF-8");
	QNetworkReply* reply = manager.post(req, "");
	QEventLoop eventLoop;
	connect(&manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
	//connect(progDialog, SIGNAL(canceled), &eventLoop, SLOT(quit()));
	eventLoop.exec();

	QList<LoadEquipment> loadEquipments;

	//if (progDialog->wasCanceled() == true) return false;

	if (reply->error() == QNetworkReply::NoError)
	{
		QByteArray ba = reply->readAll();
		QJsonParseError jsonpe;
		QJsonDocument json = QJsonDocument::fromJson(ba, &jsonpe);

		if (jsonpe.error == QJsonParseError::NoError)
		{
			QJsonObject rootObj = json.object();

			int result = rootObj.value("result").toInt();

			if (result != 1)
			{
				QMessageBox::information(this, "Error", "Delete failed.", QMessageBox::Ok);

				return true;
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

	return false;
}

// 增加载荷
int DetailedInformationDialog::insertPayload(LoadEquipment loadEqu)
{
	QString url = "http://localhost:8088/insertPayload";

	QString urlFull = QString("%1").arg(url);
	QNetworkAccessManager manager;
	QNetworkRequest req;
	req.setUrl(QUrl(urlFull));
	req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json;charset=UTF-8");

	QString para = QString("{\"deviceId\":\"%1\",\"satelliteId\":\"%2\",\"deviceName\":\"%3\",\"deviceNum\":\"%4\"}").arg(loadEqu.deviceId).arg(loadEqu.satelliteID).arg(loadEqu.deviceName).arg(loadEqu.deviceNum);
	QNetworkReply* reply = manager.post(req, para.toUtf8());
	QEventLoop eventLoop;
	connect(&manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
	//connect(progDialog, SIGNAL(canceled), &eventLoop, SLOT(quit()));
	eventLoop.exec();

	QList<LoadEquipment> loadEquipments;

	//if (progDialog->wasCanceled() == true) return false;

	if (reply->error() == QNetworkReply::NoError)
	{
		QByteArray ba = reply->readAll();
		QJsonParseError jsonpe;
		QJsonDocument json = QJsonDocument::fromJson(ba, &jsonpe);

		if (jsonpe.error == QJsonParseError::NoError)
		{
			QJsonObject rootObj = json.object();

			int result = rootObj.value("result").toInt();

			if (result != 1)
			{
				QMessageBox::information(this, "Error", "Insert failed.", QMessageBox::Ok);

				return true;
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

	return false;
}

void DetailedInformationDialog::slotUninstallLoadEqu1()
{
	deletePayload(_loadEquList[0].id);
}

void DetailedInformationDialog::slotUninstallLoadEqu2()
{
	deletePayload(_loadEquList[1].id);
}

//QListWidget* pListWidget = new QListWidget();
//
//for (int i = 0; i < allLoadEquipment.count(); i++)
//{
//	//ui.comboBoxEquList->addItem(allLoadEquipment[i].deviceName);
//
//	//QWidgetAction* widgetAction = new QWidgetAction(ui.comboBoxEquList);
//	//widgetAction->setDefaultWidget(new QCheckBox(allLoadEquipment[i].deviceName));
//	//ui.comboBoxEquList->addAction(new QWidgetAction(widgetAction));
//
//	QCheckBox* checkBox = new QCheckBox(pListWidget);
//
//	QString text = QString("Name:%1,Id:%2").arg(allLoadEquipment[i].deviceName).arg(allLoadEquipment[i].deviceId);
//	QListWidgetItem* item = new QListWidgetItem(text, pListWidget);
//
//	pListWidget->addItem(item);
//	pListWidget->setItemWidget(item, checkBox);
//}
//
//ui.comboBoxEquList->setModel(pListWidget->model());
//ui.comboBoxEquList->setView(pListWidget);

// 挂载
void DetailedInformationDialog::slotInstallLoadEqu()
{
	QListWidget* pListWidget = qobject_cast<QListWidget*>(ui.comboBoxEquList->view());

	for (int i = 0; i < pListWidget->count(); i++)
	{
		QListWidgetItem* pItem = pListWidget->item(i);

		QWidget* pWidget = pListWidget->itemWidget(pItem);
		QCheckBox* pCheckBox = (QCheckBox*)pWidget;

		if (pCheckBox && pCheckBox->isChecked())
		{
			for each (LoadEquipment var in _allLoadEquipment)
			{
				QString text = QString("Name:%1,Id:%2").arg(var.deviceName).arg(var.deviceId);
				QString cbText = pItem->text();

				if (text == cbText)
				{
					var.satelliteID = _element->id;
					insertPayload(var);
				}
			}
		}
	}

	_loadEquList = getSatelliteLoadEquipmentByID(QString("%1").arg(_element->id));

	QLayout* layout = ui.widgetLoadEquipments->layout();

	deleteAllitemsOfLayout1(layout);
	for (int i = 0; i < _loadEquList.count(); i++)
	{
		LoadEquipmentWidget* loadEquWidget = new LoadEquipmentWidget(i + 1, _loadEquList[i]);

		disconnect(loadEquWidget, SIGNAL(deletePayload(QString)), this, SLOT(slotDeletePayload(QString)));
		connect(loadEquWidget, SIGNAL(deletePayload(QString)), this, SLOT(slotDeletePayload(QString)));

		layout->addWidget(loadEquWidget);
	}
}

void DetailedInformationDialog::slotDeletePayload(QString id)
{
	deletePayload(id);

	_loadEquList = getSatelliteLoadEquipmentByID(QString("%1").arg(_element->id));

	QLayout* layout = ui.widgetLoadEquipments->layout();

	deleteAllitemsOfLayout1(layout);
	for (int i = 0; i < _loadEquList.count(); i++)
	{
		LoadEquipmentWidget* loadEquWidget = new LoadEquipmentWidget(i + 1, _loadEquList[i]);

		disconnect(loadEquWidget, SIGNAL(deletePayload(QString)), this, SLOT(slotDeletePayload(QString)));
		connect(loadEquWidget, SIGNAL(deletePayload(QString)), this, SLOT(slotDeletePayload(QString)));

		layout->addWidget(loadEquWidget);
	}
}