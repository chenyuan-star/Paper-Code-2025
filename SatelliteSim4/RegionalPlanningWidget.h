#pragma once
#ifndef REGIONALPLANNINGWIDGET_H
#define REGIONALPLANNINGWIDGET_H

#include <QWidget>
#include<qwebengineview.h>
#include<qwebenginepage.h>
#include<qmessagebox.h>
#include<qevent.h>
#include<qvector.h>
#include<qpair.h>
#include<qjsonarray.h>
#include<qjsondocument.h>
#include<qjsonobject.h>
#include<qnetworkreply.h>
#include<qnetworkaccessmanager.h>
//#include<qnetwork.h>
#include "SaveSelectionFieldWidget.h"
#include "ui_RegionalPlanningWidget.h"

using namespace std;

namespace Ui {
	class RegionalPlanningWidget;
}

// °Ù¶ÈµØÍ¼
class RegionalPlanningWidget : public QWidget
{
	Q_OBJECT

public:
	explicit RegionalPlanningWidget(QWidget *parent = 0);
	~RegionalPlanningWidget();

signals:
	void sendObject(QObject* t);
	void signalShowSimpleSateScene();

private:
	Ui::RegionalPlanningWidget* ui;
	QWebEngineView* webview;
	QWebEnginePage* page;
	QWebChannel* webchannel;
	QVector<QPair<float, float>> coordinates;
	void initWebPage();
	void testCoordinates();
	void processLongitudeAndLatitude(const QVariant& v);
	int sendLongitudeAndLatitude();
	QJsonDocument toJsonDocument();

private	slots:
	bool eventFilter(QObject* watched, QEvent* e);

};

#endif // REGIONALPLANNINGWIDGET_H