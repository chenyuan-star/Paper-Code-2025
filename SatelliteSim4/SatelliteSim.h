#ifndef SATELLITESIM_H
#define SATELLITESIM_H

#include <QtWidgets/QMainWindow>
#include "ui_SatelliteSim.h"
#include <osg/Group>
#include <osgEarth/MapNode>
#include <osgEarthUtil/EarthManipulator>
#include <osgEarthUtil/Sky>
#include <osgEarthUtil/GeodeticGraticule>
#include <osgGA/TrackballManipulator>
#include <osgEarthUtil/AutoClipPlaneHandler>
#include "osgViewerWidget.h"
#include "Common.h"
#include "miniMapWidget.h"
#include "PinTrackballManipulator.h"
#include "earthAutoClipPlaneHandler.h"
#include "ribbonwindow.h"
#include "StructDefine.h"
#include <QProgressDialog>

/**
* @brief 主窗体
* @return
*/
class SatelliteSim : public RibbonWindow
{
	Q_OBJECT

public:
	SatelliteSim(QWidget *parent = 0);
	~SatelliteSim();

protected slots :
	void slotNewSatellite();
	void slotLoadEquipment();
	void slotAddSatelliteFromDB(std::vector<SatelliteInfo> sateInfos = std::vector<SatelliteInfo>());
	void slotAddSatelliteFromService();
	void slotAddGroundRadarStation();
	void slotRegionalPlanning();
	void slotAbout();
	void slotSetDatetimeToCurrent();
	void slotSetDatetime();
	void slotLightChanged(int);
	void slotInertiaChanged(int);
	void slotGraticulesChanged(int);
	void slotAxisChanged(int);
	void slotUserDateChanged(const QDate&);
	void slotUserTimeChanged(const QTime&);
	void slotRealtimeChanged(bool);
	void slotManualChanged(bool);
	void slotUpdateSatellite();
	void slotObjectClicked(QTreeWidgetItem*, int);
	void slotCurrentObjectChanged(QTreeWidgetItem*, QTreeWidgetItem*);
	void slotAutoRotate(int);
	void slotEarthRotateing();
	void slotPinCamera();
	void slotResetCamera();
	void slotFixPosLookAround();
	void slotReturnLookAround();
	void slotSatelliteList();
	void slotLoadEquipmentList();
	void slotTreeItemPressed(QTreeWidgetItem*, int);
	void slotTreeItemChanged(QTreeWidgetItem*, int);

	void slotSatelliteInfo();
	void slotConfigManage();

	// 检索
	void slotQueryLowOrbit();
	void slotQueryMidOrbit();
	void slotQueryHighOrbit();
	void slotQueryBeidou();
	void slotQueryGalileo();
	void slotQueryCommuSatellite();
	void slotQueryNaviSatellite();
	void slotQueryRemoteSatellite();
	void slotSearchSatellite();

	void slotResizeEvent(QResizeEvent*);
	void slotShowSimpleSateScene();
	void slotCurrentTabChanged(int index);
	void slotTabCloseRequested(int index);

protected:
	virtual void resizeEvent(QResizeEvent *event);
	virtual void showEvent(QShowEvent *event);

private:
	void createMenuFile();

	void createRibbonBar();

	void replaceMinimap();

	void initialUI();
	void initialEarth();
	void readConfig();
	void addTreeItem(COE_ELEMENT*);

	void searchChild(QTreeWidgetItem *cItem, const QString &txt);
	void parentExpand(QTreeWidgetItem *item);

	// 设置轨道颜色
	void setOrbitColor(COE_ELEMENT* sate, osg::Vec4d color);

	void getModelAndColor(QString name, QString& model, QColor& color);

	// 检索卫星
	void querySatellite(QString key);

	// 定点环视
	void FixPosLookAround(double x, double y, double z);

	// 从服务查询
	void queryFromService(QString url, 
		std::vector<SatelliteInfo>& sateInfos);

	// 从服务获取卫星数据
	void getSatelliteByType(QString url, 
		std::vector<SatelliteInfo>& sateInfos, 
		std::vector<OrbitInfo>& oribtInfos, 
		QProgressDialog* progDialog);

	// 从服务获取轨道数据
	void getOribtByType(QString url, 
		std::vector<OrbitInfo>& oribtInfos, 
		QProgressDialog* progDialog);

	// 根据卫星id返回该卫星载荷
	QList<LoadEquipment> getSatelliteLoadEquipmentByID(QString url, 
		int sateID, 
		QProgressDialog* progDialog);

	// 根据卫星名称返回载荷列表
	QList<LoadEquipment> getSatelliteLoadEquipmentByName(QString url, 
		QString name, 
		QProgressDialog* progDialog);

	// 返回所有载荷列表
	QList<LoadEquipment> getAllPayloadList(QString url, 
		QProgressDialog* progDialog);

	// 从轨道数据中获取卫星类型
	OrbitChildInfo getSatelliteTypeFromOribtInfo(QString id, 
		std::vector<OrbitInfo>& oribtInfos);

	// 通过名称获取卫星信息
	bool getSatelliteInfo(SatelliteInfo& info, 
		QString name, 
		std::vector<SatelliteInfo>& sateInfos);

	// 根据载荷id删除载荷设备
	bool deletePayloadByID(QString url, 
		int deviceId, 
		QProgressDialog* progDialog);

	// 增加载荷接口
	bool insertPayload(QString url, 
		QString deviceId, 
		QString satelliteId, 
		QString deviceName, 
		QString deviceNum, 
		QProgressDialog* progDialog);

	void addSimpleSateWidget();

private:
	Ui::SatelliteSimClass ui;
	osg::Group*	m_Root;

	osg::MatrixTransform* m_earthTrans;
	osg::Node* m_EarthNode;

	osg::Geode*	m_axis;
	osgEarth::MapNode* m_MapNode;

	// 星空盒
	osgEarth::Util::SkyNode* m_pSkyNode;

	// 经纬网
	osgEarth::Util::GeodeticGraticule* m_graticule;

	osgViewerWidget* m_ViewerWidget;
	osgViewer::View* m_MainViewer;

	osg::ref_ptr<osgEarth::Util::EarthAutoClipPlaneCullCallback> _autoClipPlaneCuller;

	// 地球相机操控器
	osgEarth::Util::EarthManipulator* m_EarthManipulator;
	PinTrackballManipulator*	m_trackballManipulator;

	// 自动更新定时器
	QTimer*	m_realtimeTimer;
	QTimer*	m_autoRotateTimer;

	// 所有轨道的集合
	QList<COE_ELEMENT*>	m_coes;

	// 所有卫星模型的集合
	QList<osg::PositionAttitudeTransform*>	m_sateModels;

	miniMapWidget* m_miniMap;

	QBrush m_itemBrush;

	QMap<QString, QTreeWidgetItem*>	m_sateTreeItemMap;
	QMap<QString, MODEL_COLOR>	m_modelColors;

	// 用卫星名称过滤
	QSet<QString> m_sateFilterNames;
};

#endif // SATELLITESIM_H
