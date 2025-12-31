#ifndef MINIMAPLABEL_H
#define MINIMAPLABEL_H

#include <QLabel>
#include <QList>

/**
* @brief 小地图上的卫星星下点轨迹绘制
* @return
*/
class miniMapTrack : public QLabel
{
public:
	miniMapTrack(QString name);
	~miniMapTrack();

	void setName(QString name)
	{
		m_name = name;
	}

	QString getName()
	{
		return m_name;
	}

	/**
	* @brief 添加点
	* @return
	*/
	void addPoint(QPoint point)
	{
		m_points.append(point);
	}

	/**
	* @brief 清空所有点
	* @return
	*/
	void clear()
	{
		m_points.clear();
	}

	/**
	* @brief 设置卫星当前所在点
	* @return
	*/
	void setCurrentPoint(QPoint point)
	{
		m_currentPoint = point;
		this->update();
	}

	QPoint getCurrentPoint()
	{
		return m_currentPoint;
	}

	void setVisible(bool visible)
	{
		m_visible = visible;
	}

	bool getVisible()
	{
		return m_visible;
	}

protected:
	virtual void paintEvent(QPaintEvent *event) override;

public:
	QString	m_name;
	QColor	m_color;
	bool	m_visible;
	QList<QPoint>	m_points;
	QPoint	m_currentPoint;
};

#endif // MINIMAPLABEL_H
