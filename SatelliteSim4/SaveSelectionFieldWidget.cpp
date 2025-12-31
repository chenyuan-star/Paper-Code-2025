#include "SaveSelectionFieldWidget.h"
#include "ui_SaveSelectionFieldWidget.h"

SaveSelectionFieldWidget::SaveSelectionFieldWidget(QVector<QPair<float,float>> list, QWidget *parent) :
	QDialog(parent),
    ui(new Ui::SaveSelectionFieldWidget),
	_coordMap(list)
{
//    setWindowFlags(Qt::FramelessWindowHint);
    ui->setupUi(this);

	connect(ui->pushButton_submit, &QPushButton::clicked, this, &SaveSelectionFieldWidget::slotSubmit);
	connect(ui->pushButton_cancel, &QPushButton::clicked, this, &SaveSelectionFieldWidget::slotCancel);

    QString listToString = "";
    for(int i = 0 ; i < list.size() ; ++ i){
        listToString += "The "+QString::number(i+1)+" point:<"+QString::number(list[i].first)+","+QString::number(list[i].second)+">;\n";
    }
    ui->textBrowser_coordinateList->setText(listToString);
    setWindowFlags(windowFlags() |Qt::Dialog);
    setWindowModality(Qt::ApplicationModal);
}

SaveSelectionFieldWidget::~SaveSelectionFieldWidget()
{
    delete ui;
}

// 取消
void SaveSelectionFieldWidget::on_pushButton_cancel_clicked()
{
    close();
}

#include <QMessageBox>

// 将经纬度提交给后端，返回一张图片
void SaveSelectionFieldWidget::slotSubmit()
{
	this->accept();
}

// 显示
void SaveSelectionFieldWidget::showEvent(QShowEvent *)
{
	//QMessageBox::information(this, QStringLiteral("调用接口"), QStringLiteral("将经纬度提交给后端接口，返回一张图片。"));

	QList<QPointF> points;

	for (int i = 0; i < _coordMap.size(); i++)
	{
		QPointF point;
		point.setX(_coordMap[i].first);
		point.setY(_coordMap[i].second);

		points.append(point);
	}

	//QImage image = getCoordinate("http://localhost:8088/getCoordinate", points);

	QImage image(qApp->applicationDirPath() + "/Images/test.tif");
	ui->label_showImage->setPixmap(QPixmap::fromImage(image));
}

// 取消
void SaveSelectionFieldWidget::slotCancel()
{
	this->reject();
}

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonParseError>
#include <QMessageBox>
#include <QBuffer>
#include <QImageReader>

QImage SaveSelectionFieldWidget::getCoordinate(QString url, QList<QPointF> coords)
{
	// http://localhost:8088/getCoordinate
	QString urlFull = QString("%1").arg(url);
	QNetworkAccessManager manager;
	QNetworkRequest req;
	req.setUrl(QUrl(urlFull));
	req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json;charset=UTF-8");
	QNetworkReply* reply = manager.post(req, "");
	QEventLoop eventLoop;
	connect(&manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
	//connect(progDialog, SIGNAL(canceled), &eventLoop, SLOT(quit()));
	eventLoop.exec();

	//QList<LoadEquipment> loadEquipments;

	//if (progDialog->wasCanceled() == true) return loadEquipments;

	if (reply->error() == QNetworkReply::NoError)
	{
		QByteArray ba = reply->readAll();

		QBuffer buffer(&ba);
		buffer.open(QIODevice::ReadOnly);
		QImageReader reader(&buffer, "JPG");
		QImage img = reader.read();
		if (!img.isNull()) 
		{
			QPixmap pix = QPixmap::fromImage(img);
		}
	}
	else
	{
		QMessageBox::information(this, "错误", reply->errorString(), QMessageBox::Ok);
	}

	return QImage();
}