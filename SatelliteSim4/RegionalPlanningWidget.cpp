#pragma execution_character_set("utf-8")

#include "RegionalPlanningWidget.h"
#include<qdebug.h>
using namespace std;

RegionalPlanningWidget::RegionalPlanningWidget(QWidget *parent)
	: QWidget(parent),
	ui(new Ui::RegionalPlanningWidget)
{
	ui->setupUi(this);
	this->setWindowTitle("区域选择");

	initWebPage();	// 添加Web窗口，并初始化地图内容

	// 设置绘制模式为矩形
	connect(ui->rectangleSelectionBtn, &QPushButton::clicked, [this] {
		page->runJavaScript(QString(
			"js_setDrawingMode(0)"
		));
	});
	
	// 设置绘制模式为多边形
	connect(ui->polygonSelectionBtn, &QPushButton::clicked, [this] {
		page->runJavaScript(QString(
			"js_setDrawingMode(1)"
		));
	});

	// 设置绘制模式为多边形
	connect(ui->circleSelectionBtn, &QPushButton::clicked, [this] {
		page->runJavaScript(QString(
			"js_setDrawingMode(2)"
		));
	});

	// 清除所有覆盖物
	connect(ui->clearOverlaysBtn, &QPushButton::clicked, [this] {
		page->runJavaScript(QString(
			"js_clearAll()"
		));
	});

	// 调用js函数获取返回值并保存
	connect(ui->saveCoordinatesBtn, &QPushButton::clicked, [this] {
		page->runJavaScript(QString(
			"js_returnLongitudeAndLatitude()"
		), [&](const QVariant &v) {
			processLongitudeAndLatitude(v);
		});
	});
}

RegionalPlanningWidget::~RegionalPlanningWidget()
{
	delete ui;
}

/**
*
*/
void RegionalPlanningWidget::initWebPage() {
	webview = new QWebEngineView();
	page = webview->page();
	QString mappathA = qApp->applicationDirPath() + "/Resources/baiduMapApi.html";
	page->load(QUrl(mappathA));
	// webchannel = new QWebChannel(this);
	// webchannel->registerObject("qtagent", jsc);
	// page->setWebChannel(webchannel);

	webview->installEventFilter(this);		// 注册右键取消绘制模式的功能

	// 将web窗口添加至主窗口
	QGridLayout* gridLayout = new QGridLayout();
	gridLayout->addWidget(webview);
	ui->qTestWebWidget->setLayout(gridLayout);
}


#include "SimpleSatelliteWidget.h"
/**
*	将传入的QVarint的二维列表转化为二维vector列表
*/
void RegionalPlanningWidget::processLongitudeAndLatitude(const QVariant &v) {
	coordinates.clear();
	QList<QVariant> varList = v.value<QList<QVariant>>();
	for (int i = 0; i < varList.size(); i++) {
		QList<QVariant> coorList = varList[i].value<QList<QVariant>>();
		QPair<float, float> coordinate;
		coordinate.first = coorList.at(0).toFloat();
		coordinate.second = coorList.at(1).toFloat();
		coordinates.push_back(coordinate);
	}
	testCoordinates();	// debug输出覆盖物经纬度

	SaveSelectionFieldWidget* saveWidget = new SaveSelectionFieldWidget(coordinates, this);
	//saveWidget->setWindowModality(Qt::WindowModality::ApplicationModal);
	if (saveWidget->exec())
	{
		//_showSimpleSateView = true;
		Q_EMIT signalShowSimpleSateScene();
		this->close();
	}
}

/**
*	给webview添加事件，右键点击取消绘制模式
*/
bool RegionalPlanningWidget::eventFilter(QObject* watched, QEvent* e) {
	if (watched == webview) {
		if (e->type() == QEvent::ContextMenu){
			page->runJavaScript(QString(
				"js_closeDrawingMode()"
			));
			emit sendObject(webview);
		}
	}
	return 1;
}

/**
*	将类中QVector成员coordinates的经纬度转化为JsonDocument返回
*/
QJsonDocument RegionalPlanningWidget::toJsonDocument() {
	QJsonDocument jsonDocument;
	QJsonObject json;
	QJsonArray jsonArray;
	for (int i = 0; i < coordinates.size(); i++) {
		QJsonObject coordinate;
		coordinate["longitude"] = coordinates.at(i).first;
		coordinate["latitude"] = coordinates.at(i).second;
		jsonArray.append(coordinate);
	}
	json["coordinates"] = jsonArray;
	jsonDocument.setObject(json);
	return jsonDocument;
}

/**
*	将前端的经纬度坐标数组发送给后端
*	其中和后端做对接的url还没有弄好
*/
int RegionalPlanningWidget::sendLongitudeAndLatitude()
{
	int result = -1;

	QNetworkAccessManager manager;
	QNetworkRequest req;
	req.setUrl(QUrl("http://xx.com/xxxxxx"));	// 此url需要和后端做对接
	req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
	QNetworkReply* reply = manager.post(req, QString(QByteArray(this->toJsonDocument().toJson())).toLocal8Bit());
	QEventLoop eventLoop;
	connect(&manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
	eventLoop.exec();

	if (reply->error() == QNetworkReply::NoError)
	{
		QByteArray ba = reply->readAll();
		QJsonParseError jsonpe;
		QJsonDocument json = QJsonDocument::fromJson(ba, &jsonpe);

		if (jsonpe.error == QJsonParseError::NoError)
		{
			QJsonObject rootObj = json.object();

			result = rootObj["result"].toInt();
		}
		else
		{
			QMessageBox::information(this, "错误", jsonpe.errorString(), QMessageBox::Ok);
		}
	}
	else
	{
		QMessageBox::information(this, "错误", reply->errorString(), QMessageBox::Ok);
	}
	return result;
}

/**
*	在控制台输出记录的经纬度
*/
void RegionalPlanningWidget::testCoordinates() {
	for (int i = 0; i < coordinates.size(); i++) {
		qDebug() << i << "经度：" << coordinates[i].first << " 纬度：" << coordinates[i].second;
	}
}