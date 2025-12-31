#ifndef MINIMAPWIDGET_H
#define MINIMAPWIDGET_H

#include <QWidget>
#include "ui_miniMapWidget.h"
#include "miniMapTrack.h"

/**
* @brief 小地图
* @return
*/
class miniMapWidget : public QWidget
{
	Q_OBJECT

public:
	miniMapWidget(QWidget *parent = 0);
	~miniMapWidget();

	/**
	* @brief 添加点
	* @return
	*/
	void addTrack(miniMapTrack* track)
	{
		m_tracks.insert(track->getName(), track);
		m_bNeedDrawOrbit = true;
	}

	/**
	* @brief 需要重画轨道
	* @return
	*/
	void needDrawOrbit()
	{
		m_bNeedDrawOrbit = true;
		this->update();
	}
 
	/**
	* @brief 清空所有点
	* @return
	*/
	void clear()
	{
		m_tracks.clear();
		m_bNeedDrawOrbit = true;
	}

	/**
	* @brief 清空轨迹
	* @return
	*/
	void clearTracks()
	{
		m_tracks.clear();
		m_bNeedDrawOrbit = true;
	}

	void setCurrentPoint(QString name, QPoint point);

protected:
	virtual void paintEvent(QPaintEvent *event) override;

private:
	Ui::miniMapWidget ui;
	QMap<QString, miniMapTrack*> m_tracks;
	QImage m_bkimage;
	bool m_bNeedDrawOrbit;
	QPixmap	m_bkPixmap;
};

#endif // MINIMAPWIDGET_H
