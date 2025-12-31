#pragma once

#include <QWidget>
#include "osgViewerWidget.h"
#include <osg/Group>
#include <osgEarth/MapNode>
#include <osg/MatrixTransform>
#include <osgEarthUtil/EarthManipulator>
#include <osgEarthUtil/Sky>
#include <osgViewer/View>
#include <vector>
#include <string>
#include <osg/PositionAttitudeTransform>
#include "StructDefine.h"
#include "Common.h"

// 部分卫星视图
class SimpleSatelliteWidget : public QWidget
{
	Q_OBJECT

public:
	struct SimpleSate
	{
		int	id;
		double	startTime;
		double	endTime;
	};

	SimpleSatelliteWidget(QWidget *parent = 0);
	~SimpleSatelliteWidget();

	void getSatellites(QString url, std::vector<SimpleSate>& coords);

private:
	void initialEarth();

	void slotAddSatelliteFromDB(std::vector<SatelliteInfo> sateInfos);

	/**
	* @brief 通过名称获取卫星信息
	* @return
	*/
	bool getSatelliteInfo(SatelliteInfo& info, QString name, std::vector<SatelliteInfo>& sateInfos);

	void getModelAndColor(QString name, QString& model, QColor& color);

private:
	osgViewerWidget*					m_viewerWidget;
	osgViewer::View*					m_mainViewer;

	osg::Group*							m_Root;
	osg::Node*							m_EarthNode;
	osgEarth::MapNode*					m_MapNode;
	osg::MatrixTransform*				m_earthTrans;
	osgEarth::Util::EarthManipulator*	m_EarthManipulator;
	osgEarth::Util::SkyNode*			m_pSkyNode;

	// 所有轨道的集合
	QList<COE_ELEMENT*>	m_coes;

	//
	QSet<QString> m_sateFilterNames;
	QMap<QString, MODEL_COLOR>	m_modelColors;
	// 所有卫星模型的集合
	QList<osg::PositionAttitudeTransform*>	m_sateModels;
};
