#include "miniMapWidget.h"
#include <QMovie>
#include <QVBoxLayout>
#include <QPainter>
#include <QDir>

/**
* @brief 构造函数
* @return
*/
miniMapWidget::miniMapWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	//m_label = new miniMapLabel();
	//m_label->setObjectName(QStringLiteral("label"));

	//this->layout()->addWidget(m_label);

	// 加载全球地图
	QDir dir(qApp->applicationDirPath());
	dir.cdUp();
	dir.cd("data");
	m_bkimage.load(dir.absolutePath() + "/world.jpg");

	m_bNeedDrawOrbit = true;
}

/**
* @brief 析构函数
* @return
*/
miniMapWidget::~miniMapWidget()
{

}

void miniMapWidget::setCurrentPoint(QString name, QPoint point)
{
	if (m_tracks.contains(name) == false) return;
	m_tracks[name]->setCurrentPoint(point);
	this->update();
}

/**
* @brief 绘制函数
* @return
*/
void miniMapWidget::paintEvent(QPaintEvent *event)
{
	QWidget::paintEvent(event);
	QPainter painter(this);

	QPen pen;
	pen.setColor(QColor(255, 0, 0));
	painter.setPen(pen);

	// 绘制背景和轨道
	if (m_bNeedDrawOrbit == true)
	{
		m_bkPixmap = QPixmap(this->width(), this->height());

		QPainter tempPainter(&m_bkPixmap);
		tempPainter.drawImage(QPoint(0, 0), m_bkimage);

		QMap<QString, miniMapTrack*>::iterator iter = m_tracks.begin();
		while (iter != m_tracks.end())
		{
			if (iter.value()->getVisible() == true)
			{
				pen.setColor(iter.value()->m_color);
				tempPainter.setPen(pen);

				for (int i = 0; i < iter.value()->m_points.size(); i++)
				{
					QPoint point = iter.value()->m_points[i];
					point.setY(point.y() + 90);
					point.setX(point.x() + 180);

					tempPainter.drawEllipse(point, 1, 1);
				}
			}

			iter++;
		}

		painter.drawPixmap(QPoint(0, 0), m_bkPixmap);
		m_bNeedDrawOrbit = false;
	}
	else
	{
		painter.drawPixmap(QPoint(0, 0), m_bkPixmap);
	}

	// 绘制当前点
	pen.setColor(QColor(0, 255, 0));
	painter.setPen(pen);

	QMap<QString, miniMapTrack*>::iterator iter = m_tracks.begin();
	while (iter != m_tracks.end())
	{
		if (iter.value()->getVisible() == true)
		{
			pen.setColor(iter.value()->m_color);
			painter.setPen(pen);

			QPoint point = iter.value()->m_currentPoint;
			point.setY(point.y() + 90);
			point.setX(point.x() + 180);

			painter.drawEllipse(point, 5, 5);
		}

		iter++;
	}
}