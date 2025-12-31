#include "miniMapTrack.h"
#include <QPainter>
#include <QColor>
#include <QDir>
#include <QApplication>

/**
* @brief 构造函数
* @return
*/
miniMapTrack::miniMapTrack(QString name)
{
	this->m_name = name;
	this->m_visible = true;
}

/**
* @brief 析构函数
* @return
*/
miniMapTrack::~miniMapTrack()
{

}

/**
* @brief 绘制函数
* @return
*/
void miniMapTrack::paintEvent(QPaintEvent *event)
{
	QLabel::paintEvent(event);
	QPainter painter(this);

	QPen pen;
	pen.setColor(m_color);
	painter.setPen(pen);

	// 绘制轨迹
	QPolygon polyline;
	for (int i = 0; i < m_points.size(); i++)
	{
		QPoint point = m_points[i];
		point.setY(point.y() + 90);
		point.setX(point.x() + 180);

		painter.drawEllipse(point, 1, 1);
	}

	// 绘制当前点
	pen.setColor(m_color);
	painter.setPen(pen);

	m_currentPoint.setY(m_currentPoint.y() + 90);
	m_currentPoint.setX(m_currentPoint.x() + 180);

	painter.drawEllipse(m_currentPoint, 5, 5);
}