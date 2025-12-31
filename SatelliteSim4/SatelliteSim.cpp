#pragma execution_character_set("utf-8")

#include "SatelliteSim.h"
#include "NewSatelliteDialog.h"
#include "AboutDialog.h"
#include "FixPosLookAroundDialog.h"
#include "StructDefine.h"
#include "QueryFromServiceDialog.h"

#include <osgDB/ReadFile>
#include <osgViewer/Viewer>
#include <osgUtil/Optimizer>
#include <osgGA/TrackballManipulator>
#include <osgEarth/TerrainOptions>
#include <osgEarth/Config>
#include <osgEarth/MapNodeOptions>
#include <osgEarth/MapNode>
#include <osgEarthUtil/EarthManipulator>
#include <osgEarthUtil/Controls>
#include <osgGA/StateSetManipulator>
#include <osgViewer/ViewerEventHandlers>
#include <osgEarth/GLUtils>
#include <osg/LineWidth>
#include <osgUtil/SmoothingVisitor>
#include <osg/ShapeDrawable>
#include <osgDB/WriteFile>
#include <osg/PositionAttitudeTransform>
#include <osgAnimation/Keyframe>
#include <osgAnimation/Sampler>
#include <osgAnimation/Channel>
#include <osgAnimation/Animation>
#include <osg/CoordinateSystemNode>
#include <osg/Depth>

#include <QMessageBox>
#include <QResizeEvent>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QProgressDialog>
#include <QSettings>
#include <QDir>
#include <QProgressBar>
#include <QNetworkAccessManager.h>
#include <QNetworkReply.h>
#include <QJsonDocument>
#include <QJsonArray>

using namespace osgEarth::Util::Controls;

static LabelControl*  s_idLabel = 0L;
static LabelControl*  s_nameLabel = 0L;
static LabelControl*  s_iNumberLabel = 0L;
static LabelControl*  s_statusLabel = 0L;
static LabelControl*  s_lonLabel = 0L;
static LabelControl*  s_latLabel = 0L;
static LabelControl*  s_pitchLabel = 0L;
static LabelControl*  s_yawLabel = 0L;
static LabelControl*  s_rollLabel = 0L;
static LabelControl*  s_aLabel = 0L;
static LabelControl*  s_eLabel = 0L;
static LabelControl*  s_iLabel = 0L;
static LabelControl*  s_omegaLabel = 0L;
static LabelControl*  s_wLabel = 0L;
static LabelControl*  s_mLabel = 0L;
static LabelControl*  s_launchSiteLabel = 0L;
static LabelControl*  s_launchNumberLabel = 0L;
static LabelControl*  s_launchDateLabel = 0L;

/**
* @brief 构造函数
* @return
*/
SatelliteSim::SatelliteSim(QWidget *parent)
	: RibbonWindow(parent),
	m_ViewerWidget(NULL),
	m_pSkyNode(NULL),
	m_graticule(NULL),
	m_realtimeTimer(NULL),
	m_autoRotateTimer(NULL),
	m_earthTrans(NULL),
	m_miniMap(NULL),
	m_trackballManipulator(nullptr)
{
	ui.setupUi(this);

	createMenuFile();

	createRibbonBar();

	this->setStyleTheme(OfficeStyle::Office2016Black);

	ribbonBar()->setFrameThemeEnabled();

	initialEarth();
	initialUI();
	readConfig();

	ui.pushButtonAdd->setVisible(false);
	ui.pushButtonAddFromDB->setVisible(false);
	ui.groupBoxPara->setVisible(false);
	ui.groupBoxPos->setVisible(false);
	ui.groupBoxUnderPoint->setVisible(false);
	ui.groupBoxFixLookaround->setVisible(false);

	ui.dockWidgetLog->setVisible(false);
	this->showMaximized();
}

/**
* @brief 析构函数
* @return
*/
SatelliteSim::~SatelliteSim()
{

}

/**
* @brief 创建主菜单
* @return
*/
void SatelliteSim::createMenuFile()
{
	QIcon iconLogo;
	//    iconLogo.addPixmap(QPixmap(":/res/file.png"));
	iconLogo.addPixmap(QPixmap(":/SatelliteSim/Resources/Logo.png"));
	if (QAction* actionFile = ribbonBar()->addSystemButton(iconLogo, tr("文件")))
	{
		RibbonSystemPopupBar* popupBar = qobject_cast<RibbonSystemPopupBar*>(actionFile->menu());

		QAction* actionAddSatellite = new QAction();
		actionAddSatellite->setText(tr("添加卫星"));
		actionAddSatellite->setIcon(QIcon(":/SatelliteSim/Resources/AddSatellite.svg"));
		popupBar->addAction(actionAddSatellite);

		QAction* actionAddSatelliteFromDB = new QAction();
		actionAddSatelliteFromDB->setText(tr("从数据库添加"));
		actionAddSatelliteFromDB->setIcon(QIcon(":/SatelliteSim/Resources/AddSatelliteFromDB.svg"));
		popupBar->addAction(actionAddSatelliteFromDB);
	}
}

/**
* @brief 创建功能区
* @return
*/
void SatelliteSim::createRibbonBar()
{
	RibbonBarAutoUpdater updater(ribbonBar());

	RibbonPage* pageHome = ribbonBar()->addPage(tr("主页"));

	if (pageHome)
	{
		if (RibbonGroup* groupClipboard = pageHome->addGroup(tr("配置管理")))
		{
			QAction* actionAddSatellite = groupClipboard->addAction(
				QIcon(":/SatelliteSim/Resources/AddSatellite.svg"), tr("添加卫星"), Qt::ToolButtonTextUnderIcon);

			QAction* actionAddLoadEquipment = groupClipboard->addAction(
				QIcon(":/SatelliteSim/Resources/AddSatellite.svg"), tr("新建载荷"), Qt::ToolButtonTextUnderIcon);

			QAction* actionAddSatelliteFromDB = groupClipboard->addAction(
				QIcon(":/SatelliteSim/Resources/AddSatelliteFromDB.svg"), tr("从数据库添加"), Qt::ToolButtonTextUnderIcon);

			QAction* actionAddSatelliteFromService = groupClipboard->addAction(
				QIcon(":/SatelliteSim/Resources/Service.svg"), tr("从服务添加"), Qt::ToolButtonTextUnderIcon);

			QAction* actionAddGroundRadarStation = groupClipboard->addAction(
				QIcon(":/SatelliteSim/Resources/AddGroundRadarStation.svg"), tr("添加地面站"), Qt::ToolButtonTextUnderIcon);

			QAction* actionRegionalPlanning = groupClipboard->addAction(
				QIcon(":/SatelliteSim/Resources/RegionalPlanning.svg"), tr("区域选取"), Qt::ToolButtonTextUnderIcon);

			connect(actionAddSatellite, SIGNAL(triggered()), this, SLOT(slotNewSatellite()));
			connect(actionAddLoadEquipment, SIGNAL(triggered()), this, SLOT(slotLoadEquipment()));
			connect(actionAddSatelliteFromDB, SIGNAL(triggered()), this, SLOT(slotAddSatelliteFromDB()));
			connect(actionAddSatelliteFromService, SIGNAL(triggered()), this, SLOT(slotAddSatelliteFromService()));
			connect(actionAddGroundRadarStation, SIGNAL(triggered()), this, SLOT(slotAddGroundRadarStation()));
			connect(actionRegionalPlanning, SIGNAL(triggered()), this, SLOT(slotRegionalPlanning()));
		}

		if (RibbonGroup* groupView = pageHome->addGroup(tr("视图")))
		{
			QAction* actionTable = groupView->addAction(ui.dockWidgetObjects->toggleViewAction(), Qt::ToolButtonTextUnderIcon);
			actionTable->setIcon(QIcon(":/SatelliteSim/Resources/TableView.svg"));

			QAction* actionLog = groupView->addAction(ui.dockWidgetLog->toggleViewAction(), Qt::ToolButtonTextUnderIcon);
			actionLog->setIcon(QIcon(":/SatelliteSim/Resources/LogWindow.svg"));
			actionLog->setChecked(false);

			QAction* actionSatelliteList = groupView->addAction(QIcon(":/SatelliteSim/Resources/TableView.svg"), tr("卫星列表化"), Qt::ToolButtonTextUnderIcon);
			connect(actionSatelliteList, SIGNAL(triggered()), this, SLOT(slotSatelliteList()));

			QAction* actionLoadEquipmentList = groupView->addAction(QIcon(":/SatelliteSim/Resources/TableView.svg"), tr("载荷列表化"), Qt::ToolButtonTextUnderIcon);
			connect(actionLoadEquipmentList, SIGNAL(triggered()), this, SLOT(slotLoadEquipmentList()));

			QAction* actionFixPosLookAround = groupView->addAction(QIcon(":/SatelliteSim/Resources/FixPosLookAround.svg"), tr("定点环视"), Qt::ToolButtonTextUnderIcon);
			connect(actionFixPosLookAround, SIGNAL(triggered()), this, SLOT(slotFixPosLookAround()));

			QAction* actionReturnLookAround = groupView->addAction(QIcon(":/SatelliteSim/Resources/Return.svg"), tr("取消环视"), Qt::ToolButtonTextUnderIcon);
			connect(actionReturnLookAround, SIGNAL(triggered()), this, SLOT(slotReturnLookAround()));
		}

		//if (RibbonGroup* groupScene = pageHome->addGroup(tr("场景")))
		//{
			//QAction* actionHome = groupScene->addAction(QIcon(":/SatelliteSim/Resources/FixPosLookAround.svg"), tr("重置"), Qt::ToolButtonTextUnderIcon);
			//connect(actionHome, SIGNAL(triggered()), this, SLOT(slotFixPosLookAround()));
		//}

		if (RibbonGroup* groupView = pageHome->addGroup(tr("帮助")))
		{
			QAction* actionHelp = groupView->addAction(QIcon(":/SatelliteSim/Resources/Help.svg"), tr("帮助"), Qt::ToolButtonTextUnderIcon);
			QAction* actionAbout = groupView->addAction(QIcon(":/SatelliteSim/Resources/About.svg"), tr("关于"), Qt::ToolButtonTextUnderIcon);

			connect(actionAbout, SIGNAL(triggered()), this, SLOT(slotAbout()));
		}
	}

	RibbonPage* pageQuery = ribbonBar()->addPage(tr("检索"));

	if (pageQuery)
	{
		if (RibbonGroup* groupQuery = pageQuery->addGroup(tr("轨道")))
		{
			QAction* actionLowOrbit = groupQuery->addAction(QIcon(":/SatelliteSim/Resources/MidOrbit.svg"), tr("低轨"), Qt::ToolButtonTextUnderIcon);
			QAction* actionMidOrbit = groupQuery->addAction(QIcon(":/SatelliteSim/Resources/MidOrbit.svg"), tr("中轨"), Qt::ToolButtonTextUnderIcon);
			QAction* actionHighOrbit = groupQuery->addAction(QIcon(":/SatelliteSim/Resources/HighOrbit.svg"), tr("高轨"), Qt::ToolButtonTextUnderIcon);

			connect(actionLowOrbit, SIGNAL(triggered()), this, SLOT(slotQueryLowOrbit()));
			connect(actionMidOrbit, SIGNAL(triggered()), this, SLOT(slotQueryMidOrbit()));
			connect(actionHighOrbit, SIGNAL(triggered()), this, SLOT(slotQueryHighOrbit()));
		}

		if (RibbonGroup* groupConstellation = pageQuery->addGroup(tr("星座")))
		{
			QAction* actionBeidou = groupConstellation->addAction(QIcon(":/SatelliteSim/Resources/Beidou.svg"), tr("BEIDOU"), Qt::ToolButtonTextUnderIcon);
			QAction* actionGalileo = groupConstellation->addAction(QIcon(":/SatelliteSim/Resources/Galileo.svg"), tr("GALILEO"), Qt::ToolButtonTextUnderIcon);

			connect(actionBeidou, SIGNAL(triggered()), this, SLOT(slotQueryBeidou()));
			connect(actionGalileo, SIGNAL(triggered()), this, SLOT(slotQueryGalileo()));
		}

		if (RibbonGroup* groupFunction = pageQuery->addGroup(tr("功能")))
		{
			QAction* actionCommuSatellite = groupFunction->addAction(QIcon(":/SatelliteSim/Resources/Communication.svg"), tr("通讯卫星"), Qt::ToolButtonTextUnderIcon);
			QAction* actionNaviSatellite = groupFunction->addAction(QIcon(":/SatelliteSim/Resources/Navigation.svg"), tr("导航卫星"), Qt::ToolButtonTextUnderIcon);
			QAction* actionRemoteSatellite = groupFunction->addAction(QIcon(":/SatelliteSim/Resources/Navigation.svg"), tr("遥感卫星"), Qt::ToolButtonTextUnderIcon);

			connect(actionCommuSatellite, SIGNAL(triggered()), this, SLOT(slotQueryCommuSatellite()));
			connect(actionNaviSatellite, SIGNAL(triggered()), this, SLOT(slotQueryNaviSatellite()));
			connect(actionRemoteSatellite, SIGNAL(triggered()), this, SLOT(slotQueryRemoteSatellite()));
		}
	}
}

/**
* @brief 读取配置文件
* @return
*/
void SatelliteSim::readConfig()
{
	m_modelColors.clear();

	QDir dir(qApp->applicationDirPath());
	QFile f(dir.absolutePath() + "/Config.dat");
	if (!f.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		qDebug() << "Open failed." << endl;
		return;
	}

	QTextStream txtInput(&f);
	QString lineStr;
	while (!txtInput.atEnd())
	{
		lineStr = txtInput.readLine();
		QStringList fields = lineStr.split(",", QString::SkipEmptyParts);

		MODEL_COLOR modelColor;
		modelColor.ModelFile = fields[1];
		modelColor.Color = QColor(fields[2].toInt(), fields[3].toInt(), fields[4].toInt());

		m_modelColors.insert(fields[0], modelColor);

		qDebug() << lineStr << endl;
	}

	f.close();
}

/**
* @brief 初始化UI
* @return
*/
void SatelliteSim::initialUI()
{
	ui.actionNew->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/Resources/Add.svg"));
	ui.actionStartSim->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/Resources/Play.svg"));
	ui.actionPauseSim->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/Resources/Pause.svg"));
	ui.actionStopSim->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/Resources/Stop.svg"));
	ui.actionOpenTLEFile->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/Resources/OpenTLE.svg"));
	ui.actionOpenCOEFile->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/Resources/OpenCOE.svg"));

	connect(ui.actionNew, SIGNAL(triggered()), this, SLOT(slotNewSatellite()));
	connect(ui.actionAbout, SIGNAL(triggered()), this, SLOT(slotAbout()));
	connect(ui.pushButtonAdd, SIGNAL(clicked()), this, SLOT(slotNewSatellite()));
	connect(ui.pushButtonAddFromDB, SIGNAL(clicked()), this, SLOT(slotAddSatelliteFromDB()));
	connect(ui.pushButtonSearch, SIGNAL(clicked()), this, SLOT(slotSearchSatellite()));
	connect(ui.pushButtonSetToCurrent, SIGNAL(clicked()), this, SLOT(slotSetDatetimeToCurrent()));
	connect(ui.checkBoxLight, SIGNAL(stateChanged(int)), this, SLOT(slotLightChanged(int)));
	connect(ui.checkBoxInertia, SIGNAL(stateChanged(int)), this, SLOT(slotInertiaChanged(int)));
	connect(ui.checkBoxGraticules, SIGNAL(stateChanged(int)), this, SLOT(slotGraticulesChanged(int)));
	connect(ui.checkBoxAxis, SIGNAL(stateChanged(int)), this, SLOT(slotAxisChanged(int)));
	connect(ui.dateEditDate, SIGNAL(userDateChanged(const QDate&)), this, SLOT(slotUserDateChanged(const QDate&)));
	connect(ui.timeEditTime, SIGNAL(userTimeChanged(const QTime&)), this, SLOT(slotUserTimeChanged(const QTime&)));
	connect(ui.radioButtonRealtime, SIGNAL(clicked(bool)), this, SLOT(slotRealtimeChanged(bool)));
	connect(ui.radioButtonManual, SIGNAL(clicked(bool)), this, SLOT(slotManualChanged(bool)));
	connect(ui.treeWidgetObjects, SIGNAL(itemClicked(QTreeWidgetItem*, int)), SLOT(slotObjectClicked(QTreeWidgetItem*, int)));
	connect(ui.treeWidgetObjects, SIGNAL(currentItemChanged(QTreeWidgetItem*, QTreeWidgetItem*)), SLOT(slotCurrentObjectChanged(QTreeWidgetItem*, QTreeWidgetItem*)));
	connect(ui.checkBoxAutoRotate, SIGNAL(stateChanged(int)), this, SLOT(slotAutoRotate(int)));
	connect(ui.treeWidgetObjects, SIGNAL(itemChanged(QTreeWidgetItem*, int)), this, SLOT(slotTreeItemChanged(QTreeWidgetItem*, int)));

	connect(ui.pushButtonPinCamera, SIGNAL(clicked()), this, SLOT(slotPinCamera()));
	connect(ui.pushButtonResetCamera, SIGNAL(clicked()), this, SLOT(slotResetCamera()));

	connect(m_ViewerWidget, SIGNAL(signalResizeEvent(QResizeEvent*)), this, SLOT(slotResizeEvent(QResizeEvent*)));

	connect(ui.treeWidgetObjects, SIGNAL(itemPressed(QTreeWidgetItem*, int)), this, SLOT(slotTreeItemPressed(QTreeWidgetItem*, int)));

	//ui.menuView->addAction(ui.dockWidgetObjects->toggleViewAction());
	printLog("系统启动。", ui.plainTextEditLog);

	m_miniMap = new miniMapWidget(this);
	m_miniMap->show();
}

//记得加上头文件
#include <Windows.h>
#include <string>
using namespace std;

//转换为中文字符进行显示   
void gb2312ToUnicode(const string& src, wstring& result)
{
	int n = MultiByteToWideChar(CP_ACP, 0, src.c_str(), -1, NULL, 0);
	result.resize(n);
	::MultiByteToWideChar(CP_ACP, 0, src.c_str(), -1, (LPWSTR)result.c_str(), result.length());
}

void unicodeToUTF8(const wstring &src, string& result)
{
	int n = WideCharToMultiByte(CP_UTF8, 0, src.c_str(), -1, 0, 0, 0, 0);
	result.resize(n);
	::WideCharToMultiByte(CP_UTF8, 0, src.c_str(), -1, (char*)result.c_str(), result.length(), 0, 0);
}

void gb2312ToUtf8(const string& src, string& result)
{
	wstring strWideChar;
	gb2312ToUnicode(src, strWideChar);
	unicodeToUTF8(strWideChar, result);
}

#include "SimpleSatelliteWidget.h"
#include <QStackedWidget>
#include "MyTabWidget.h"

QStackedWidget* g_stackedWidget = nullptr;
QTabBar* g_tabBar = nullptr;

/**
* @brief 初始化地球
* @return
*/
void SatelliteSim::initialEarth()
{
	// 初始化节点
	m_Root = new osg::Group();

	std::string url = std::string(qApp->applicationDirPath().toLocal8Bit()) + "/simple.earth";

	m_EarthNode = osgDB::readNodeFile(url);
	//m_Root->addChild(m_EarthNode);

	m_MapNode = osgEarth::MapNode::findMapNode(m_EarthNode);

	osgEarth::Util::Ephemeris* ephemeris = new osgEarth::Util::Ephemeris;

	// 天空盒
	osgEarth::Util::SkyOptions opts;
	m_pSkyNode = osgEarth::Util::SkyNode::create(m_MapNode);
	m_pSkyNode->setName("SkyNode");
	m_pSkyNode->setEphemeris(ephemeris);

	// 设置时间;
	osgEarth::DateTime d = m_pSkyNode->getDateTime();
	QDateTime dt = QDateTime::currentDateTime();
	m_pSkyNode->setDateTime(osgEarth::DateTime(dt.date().year(), dt.date().month(), dt.date().day(), dt.time().hour() - 8)); // 格林尼治，时差8小时

	m_pSkyNode->setLighting(osg::StateAttribute::Values::ON);

	osgViewer::ViewerBase::ThreadingModel threadingModel = osgViewer::ViewerBase::SingleThreaded;
	m_ViewerWidget = new osgViewerWidget(ui.treeWidgetObjects, this, m_Root, Qt::Widget, threadingModel);
	m_MainViewer = m_ViewerWidget->getViewer();

	// UI
	Grid* grid = new Grid();
	grid->setHorizAlign(Control::ALIGN_RIGHT);
	grid->setVertAlign(Control::ALIGN_CENTER);
	grid->setBackColor(osg::Vec4d(0.3, 0.3, 0.3, 0.0));
	//设置几个Label文字控件显示在场景中的第行
	grid->setControl(0, 0, new LabelControl("ID:"));
	grid->setControl(0, 1, new LabelControl("Name:"));
	grid->setControl(0, 2, new LabelControl("INumber:"));
	grid->setControl(0, 3, new LabelControl("Status:"));
	grid->setControl(0, 4, new LabelControl("Lon:"));
	grid->setControl(0, 5, new LabelControl("Lat:"));
	grid->setControl(0, 6, new LabelControl("Pitch:"));
	grid->setControl(0, 7, new LabelControl("Yaw:"));
	grid->setControl(0, 8, new LabelControl("Roll:"));
	grid->setControl(0, 9, new LabelControl("a:"));
	grid->setControl(0, 10, new LabelControl("e:"));
	grid->setControl(0, 11, new LabelControl("i:"));
	grid->setControl(0, 12, new LabelControl("omega:"));
	grid->setControl(0, 13, new LabelControl("w:"));
	grid->setControl(0, 14, new LabelControl("m:"));
	grid->setControl(0, 15, new LabelControl("LaunchSite:"));
	grid->setControl(0, 16, new LabelControl("LaunchNumber:"));
	grid->setControl(0, 17, new LabelControl("LaunchDate:"));

	//设置几个Label文字控件显示在场景中的第行
	//s_nameLabel->setEncoding(osgText::String::ENCODING_UTF8);//设置本地编码

	//string allStrUtf8;
	//gb2312ToUtf8("卫星编号", allStrUtf8);//字体转换

	s_idLabel = grid->setControl(1, 0, new LabelControl(""));
	s_nameLabel = grid->setControl(1, 1, new LabelControl(""));
	s_iNumberLabel = grid->setControl(1, 2, new LabelControl(""));
	s_statusLabel = grid->setControl(1, 3, new LabelControl(""));
	s_lonLabel = grid->setControl(1, 4, new LabelControl(""));
	s_latLabel = grid->setControl(1, 5, new LabelControl(""));
	s_pitchLabel = grid->setControl(1, 6, new LabelControl(""));
	s_yawLabel = grid->setControl(1, 7, new LabelControl(""));
	s_rollLabel = grid->setControl(1, 8, new LabelControl(""));
	s_aLabel = grid->setControl(1, 9, new LabelControl(""));
	s_eLabel = grid->setControl(1, 10, new LabelControl(""));
	s_iLabel = grid->setControl(1, 11, new LabelControl(""));
	s_omegaLabel = grid->setControl(1, 12, new LabelControl(""));
	s_wLabel = grid->setControl(1, 13, new LabelControl(""));
	s_mLabel = grid->setControl(1, 14, new LabelControl(""));
	s_launchSiteLabel = grid->setControl(1, 15, new LabelControl(""));
	s_launchNumberLabel = grid->setControl(1, 16, new LabelControl(""));
	s_launchDateLabel = grid->setControl(1, 17, new LabelControl(""));

	ControlCanvas* canvas = ControlCanvas::get(m_ViewerWidget->getViewer());
	m_Root->addChild(canvas);
	canvas->addControl(grid);

	m_pSkyNode->attach(m_MainViewer, 0);

	m_pSkyNode->setAtmosphereVisible(true);
	m_pSkyNode->setSunVisible(true);
	m_pSkyNode->setMoonVisible(true);
	m_pSkyNode->getSunLight()->setConstantAttenuation(1.0);
	m_pSkyNode->getSunLight()->setLinearAttenuation(0.0);
	m_pSkyNode->getSunLight()->setQuadraticAttenuation(0.0);
	m_pSkyNode->getSunLight()->setSpotExponent(0.0);
	m_pSkyNode->getSunLight()->setSpotCutoff(0.0);

	m_pSkyNode->setMinimumAmbient(osg::Vec4(0.1f,1.0f,1.0f,1.0f));

	m_earthTrans = new osg::MatrixTransform();
	m_earthTrans->addChild(m_MapNode);
	m_pSkyNode->addChild(m_earthTrans);

	m_Root->addChild(m_pSkyNode);

	// 添加绝对坐标系轴
	//m_Root->addChild(m_axis = addAxis(10000000));

	// 设置漫游器
	m_EarthManipulator = new osgEarth::Util::EarthManipulator();
	m_EarthManipulator->getSettings()->setMinMaxPitch(-90, 0);//设置最大最小倾斜角度
	//m_EarthManipulator->getSettings()->setMinMaxDistance(100.0, 4e7);//设置最近最远距离
	m_EarthManipulator->getSettings()->setThrowingEnabled(true);
	m_MainViewer->setCameraManipulator(m_EarthManipulator);

	// 设置Camera
	osg::Camera* camera = m_MainViewer->getCamera();

	osg::GraphicsContext* pGC = camera->getGraphicsContext();

	if (!camera->getViewport())
	{
		camera->setViewport(new osg::Viewport(0, 0, pGC->getTraits()->width, pGC->getTraits()->height));
	}

	camera->setProjectionMatrixAsPerspective(30.0f, camera->getViewport()->width() / camera->getViewport()->height(), 1.0f, 10000.0f);
	camera->setNearFarRatio(0.00001);
	camera->setSmallFeatureCullingPixelSize(-1.0f);

	osgEarth::GLUtils::setGlobalDefaults(camera->getOrCreateStateSet());//osgearth2.10.1 添加后才可显示feature

	QVBoxLayout* layout = new QVBoxLayout();
	layout->setContentsMargins(0, 0, 0, 0);

	g_tabBar = new QTabBar();
	g_tabBar->addTab("主场景");
	g_tabBar->setTabsClosable(true);
	layout->addWidget(g_tabBar);

	connect(g_tabBar, SIGNAL(currentChanged(int)), this, SLOT(slotCurrentTabChanged(int)));
	connect(g_tabBar, SIGNAL(tabCloseRequested(int)), this, SLOT(slotTabCloseRequested(int)));

	//MyTabWidget* tabWidget = new MyTabWidget();
	//tabWidget->addTab(m_ViewerWidget, "主场景");
	//tabWidget->addTab(new SimpleSatelliteWidget(this), "次场景");

	//tabWidget->setTabsClosable(true);

	g_stackedWidget = new QStackedWidget();
	g_stackedWidget->addWidget(m_ViewerWidget);
	layout->addWidget(g_stackedWidget);

	QWidget* mainWidget = new QWidget();
	mainWidget->setLayout(layout);

	this->setCentralWidget(mainWidget);

	this->showMaximized();
	//replaceMinimap();
}

void SatelliteSim::addSimpleSateWidget()
{
	g_tabBar->addTab("子场景");
	g_stackedWidget->addWidget(new SimpleSatelliteWidget(this));
}

void SatelliteSim::slotCurrentTabChanged(int index)
{
	g_stackedWidget->setCurrentIndex(index);
}

void SatelliteSim::slotTabCloseRequested(int index)
{
	if (index == 0)
	{
		return;
	}

	g_tabBar->removeTab(index);
	g_stackedWidget->removeWidget(g_stackedWidget->widget(index));
}

double GetDistance(double dEleR, double dDirR, double dPercent1)
{
	return 1000000;
}

osg::Vec4 GetColor(double dPercent1, double transparency)
{
	return osg::Vec4(0, 0.5, 0.5, transparency);
}

/**
* @brief 改变窗体大小后，重置小地图位置
* @return
*/
void SatelliteSim::resizeEvent(QResizeEvent *event)
{
	replaceMinimap();
}

/**
* @brief 显示窗体
* @return
*/
void SatelliteSim::showEvent(QShowEvent *event)
{
	ui.dateEditDate->setDate(QDateTime::currentDateTime().date());
	ui.timeEditTime->setTime(QDateTime::currentDateTime().time());

	replaceMinimap();
}

void SatelliteSim::replaceMinimap()
{
	if (m_miniMap)
	{
		m_miniMap->setGeometry(this->centralWidget()->pos().x() + this->centralWidget()->width() - 362,
			this->centralWidget()->pos().y() + this->centralWidget()->height() - 182, 360, 180);
	}
}

void SatelliteSim::slotResizeEvent(QResizeEvent* event)
{
	replaceMinimap();
}

/**
* @brief DateTime转儒略日
* @return
*/
double dateTimeToS(QDateTime dt)
{
	return dt.time().hour() * 3600 + dt.time().minute() * 60 + dt.time().second();
}

void SatelliteSim::getModelAndColor(QString name, QString& model, QColor& color)
{
	QStringList fields = name.split(QRegExp("[_-]"));
	if (m_modelColors.contains(fields[0]) == true)
	{
		model = "/" + m_modelColors[fields[0]].ModelFile;
		color = m_modelColors[fields[0]].Color;
	}
	else
	{
		model = "/satellite90.obj";
		color.setRed(255);
		color.setGreen(255);
		color.setBlue(0);
	}
}

/**
* 卫星信号传导动画shader
*/
static char * fragShader1 = {
	"varying vec4 color;\n"
	"uniform sampler2D baseTex;\n"
	"uniform int osg_FrameNumber;\n"//当前OSG程序运行的帧数；
	"uniform float osg_FrameTime;\n"//当前OSG程序的运行总时间；
	"uniform float osg_DeltaFrameTime;\n"//当前OSG程序运行每帧的间隔时间；
	"uniform mat4 osg_ViewMatrix;\n"//当前OSG摄像机的观察矩阵；
	"uniform mat4 osg_ViewMatrixInverse;\n"// 当前OSG摄像机观察矩阵的逆矩阵。
	"void main(void){\n"
	"vec2 coord = gl_TexCoord[0].xy+vec2(0,osg_FrameTime*0.1);"
	"   vec4 clr = texture2D(baseTex, coord);\n"
	"   if(clr.a < 0.9) clr.a = 0;\n"
	"   gl_FragColor = clr;\n"
	"}\n"
};

#include <osg/LineStipple>

/**
* @brief 添加卫星
* @return
*/
void SatelliteSim::slotNewSatellite()
{
	QString newSateName = QString("Satellite_%1").arg(ui.treeWidgetObjects->topLevelItemCount() + 1);
	NewSatelliteDialog dialog(newSateName, this);
	if (dialog.exec())
	{
		COE_ELEMENT* element = new COE_ELEMENT();
		element->name = dialog.getName();
		element->a = dialog.getSemimajorAxis();
		element->E = dialog.getEccentricity();
		element->i = dialog.getInclination_D();
		element->Omega = dialog.getLongitudeOfTheAscendingNode_D();
		element->w = dialog.getArgumentOfPerigee_D();
		element->M = dialog.getMeanAnomaly_D();

		element->roll = dialog.getRoll();
		element->pitch = dialog.getPitch();
		element->yaw = dialog.getYaw();

		QString modelFile;
		QColor color;
		getModelAndColor(element->name, modelFile, color);

		element->startSimTime = element->currentSimTime = QDateTime::currentDateTime();

		// 算轨道周期
		double t = sqrt(pow(element->a, 3) * 4 * osg::PI * osg::PI / muu);

		// 画轨道
		osg::Vec3 firstVert;
		osg::Vec3 oribtNor;

		std::vector<osg::Vec3> lonlats;
		osg::Vec4 oribtColor(color.redF(), color.greenF(), color.blueF(), 0.5);
		element->orbit = addOribt(element, t, firstVert, oribtNor, lonlats, oribtColor);
		m_Root->addChild(element->orbit);

		// 添加星下点轨迹
		miniMapTrack* track = new miniMapTrack(element->name);
		track->m_color = color;
		for (int i = 0; i < lonlats.size(); i++)
		{
			track->addPoint(QPoint(lonlats[i].x(), lonlats[i].y()));
		}
		m_miniMap->addTrack(track);

		element->track = track;
		element->firstPosition = firstVert;
		element->normal = oribtNor;

		// 卫星旋转体
		osg::MatrixTransform* rotateMT = new osg::MatrixTransform;

		// 卫星组
		osg::PositionAttitudeTransform* sateGroup = addSatellite(std::string(element->name.toLocal8Bit()),
			std::string(modelFile.toLocal8Bit()), osg::Vec3d(0, 0, 0),
			dialog.getRoll(),
			dialog.getPitch(),
			dialog.getYaw(),
			rotateMT,
			color);

		sateGroup->setUserValue<std::string>("Type", "Satellite");
		sateGroup->setUserValue<std::string>("Name", std::string(element->name.toLocal8Bit()));

		// 添加扫描体
		osg::MatrixTransform* scanRangeBody = drawMaxScanRange(32, 15, 5, 50, 0.3, 0.1);
		osg::MatrixTransform* currentScanBody = drawCurrentScanRange(30, 5, 2, 50, 0.2, 0.6);
		sateGroup->addChild(scanRangeBody);
		sateGroup->addChild(currentScanBody);

		currentScanBody->setNodeMask(0);
		scanRangeBody->setNodeMask(0);

		// 添加载荷
		if (!dialog.getPayloadFile().isNull() && !dialog.getPayloadFile().isEmpty())
		{
			osgDB::Options* option = new osgDB::Options(std::string("LightmapTextures"));

			osg::Node* payload = osgDB::readNodeFile(std::string(dialog.getPayloadFile().toLocal8Bit()), option);
			payload->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF | osg::StateAttribute::OVERRIDE);

			osg::ref_ptr<osg::MatrixTransform> scale = new osg::MatrixTransform;
			scale->setMatrix(osg::Matrix::scale(0.002, 0.002, 0.002) * osg::Matrix::translate(0, 10, 0));
			scale->addChild(payload);

#if 0
			// 画连接线
			osg::ref_ptr<osg::Vec3Array> vex = new osg::Vec3Array;
			vex->push_back(osg::Vec3(0.0, 0.0, 0.0));
			vex->push_back(osg::Vec3(-1.0, 2.5, -0.5));
			vex->push_back(osg::Vec3(-2.0, 5.0, -1.0));
			vex->push_back(osg::Vec3(-4.0, 10.0, -2.0));

			osg::ref_ptr<osg::Geometry> geometry = new osg::Geometry;
			geometry->setVertexArray(vex.get());

			//设置成点画线
			osg::LineStipple* ls = new osg::LineStipple(1, 0x00FF);
			geometry->getOrCreateStateSet()->setAttributeAndModes(ls, osg::StateAttribute::ON);

			// 动画
			osg::Texture2D* texture = new osg::Texture2D;
			//texture->setDataVariance(osg::Object::DYNAMIC); // protect from being optimized away as static state.
			texture->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR);
			texture->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
			texture->setWrap(osg::Texture2D::WRAP_S, osg::Texture2D::REPEAT);
			texture->setWrap(osg::Texture2D::WRAP_T, osg::Texture2D::REPEAT);
			texture->setImage(osgDB::readImageFile("Images/test1.png"));

			osg::StateSet* stateset = geometry->getOrCreateStateSet();
			stateset->setTextureAttributeAndModes(0, texture, osg::StateAttribute::ON);
			osg::Program * program = new osg::Program;
			program->addShader(new osg::Shader(osg::Shader::FRAGMENT, fragShader1));
			stateset->addUniform(new osg::Uniform("baseTex", 0));
			stateset->setAttributeAndModes(program, osg::StateAttribute::ON);

			//设置颜色数组
			osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array;
			colors->push_back(osg::Vec4(0.0, 1.0, 1.0, 1.0));
			colors->push_back(osg::Vec4(0.0, 1.0, 1.0, 1.0));
			geometry->setColorArray(colors);
			geometry->setColorBinding(osg::Geometry::BIND_PER_VERTEX);

			osg::ref_ptr<osg::PrimitiveSet> primitiveSet = new osg::DrawArrays(osg::PrimitiveSet::LINE_STRIP, 0, 4);
			geometry->addPrimitiveSet(primitiveSet);

			//设置线宽
			osg::ref_ptr<osg::LineWidth> lw = new osg::LineWidth(2.0);
			geometry->getOrCreateStateSet()->setAttribute(lw, osg::StateAttribute::ON);
			geometry->getOrCreateStateSet()->setMode(GL_DEPTH_TEST, osg::StateAttribute::ON);

			osg::ref_ptr<osg::Geode> geode = new osg::Geode;
			geode->addDrawable(geometry);
#endif
			//sateGroup->addChild(geode.get());

			sateGroup->addChild(createCylinder(osg::Vec3(-1.0, 2.5, -0.5), osg::Vec3(-4.0, 10.0, -2.0), 0.2));
			sateGroup->addChild(scale.get());
		}

		m_sateModels.append(sateGroup);

		element->sateModel = sateGroup;
		element->rotateMT = rotateMT;

		// 添加卫星姿态坐标轴
		element->sateAxis = addSateAxis(500000, firstVert, oribtNor);
		//element->orbit->addChild(element->sateAxis);

		element->cone = nullptr;
		//element->cone = createCone(osg::Vec3(0, 0, 0), firstVert, 2000000);
		//m_Root->addChild(element->cone);

		m_coes.append(element);

		sateGroup->setUserValue("Name", std::string(dialog.getName().toLocal8Bit()));		// 名称
		sateGroup->setUserValue("SemimajorAxis", dialog.getSemimajorAxis() / 1000);				// 长半轴
		sateGroup->setUserValue("Eccentricity", dialog.getEccentricity());					// 偏心率
		sateGroup->setUserValue("Inclination", dialog.getInclination_D());					// 轨道倾角
		sateGroup->setUserValue("ArgumentOfPerigee", dialog.getArgumentOfPerigee_D());	// 近地点幅角
		sateGroup->setUserValue("LongitudeOfTheAscendingNode", dialog.getLongitudeOfTheAscendingNode_D());	// 升交点赤经
		sateGroup->setUserValue("MeanAnomaly", dialog.getMeanAnomaly_D());							// 平近点角

		sateGroup->setUserValue("Roll", dialog.getRoll());		// 翻滚角
		sateGroup->setUserValue("Pitch", dialog.getPitch());	// 俯仰角
		sateGroup->setUserValue("Yaw", dialog.getYaw());		// 偏航角

		m_Root->addChild(sateGroup);

		// 添加树节点
		addTreeItem(element);

		//g_simTime = QDateTime::currentDateTime();

		m_EarthManipulator->home(0.5);
		slotRealtimeChanged(true);

		printLog("添加了卫星。");
	}
}

/**
* @brief 读取数据库添加卫星
* @return
*/
void SatelliteSim::slotAddSatelliteFromDB(std::vector<SatelliteInfo> sateInfos)
{
	QStringList drivers = QSqlDatabase::drivers();
	foreach(QString driver, drivers)
		qDebug() << driver;

	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("1.15.154.157");
	db.setDatabaseName("cstk");
	db.setUserName("CSTK");
	db.setPassword("CSTK123");
	if (!db.open()) 
	{
		QMessageBox::critical(0, "Error", db.lastError().text(), QMessageBox::Cancel);
		return;
	}

	QSqlQuery countQuery = db.exec(" select count(*) as count from satellites");
	countQuery.next();
	int count = countQuery.value("count").toInt();

	// 显示加载进度
	QProgressDialog dialog("正在加载...", "取消", 0, count, this);
	dialog.setWindowTitle("加载中");
	//dialog.setBar(nullptr);
	dialog.setWindowModality(Qt::WindowModal);
	dialog.show();

	QSqlQuery result = db.exec(" select * from satellites left join satelliteInfo on  satelliteInfo.id = satellites.id");	// limit 10
	int index = 0;
	while (result.next())
	{
		QString name = result.value("satelliteName").toString();

		if (m_sateFilterNames.count() > 0 && m_sateFilterNames.contains(name) == false)
			continue;

		QString stl1 = result.value("STL1").toString();
		QString stl2 = result.value("STL2").toString();
		int type = result.value("belongConstellationId").toInt();	// 类型
		QString strOrbitType = result.value("orbitType").toString();
		QString strSatelliteType = result.value("satelliteType").toString();

		COE_ELEMENT* element = new COE_ELEMENT();

		QStringList fields = stl2.split(" ", QString::SkipEmptyParts);
		element->name = name;
		element->type = (COE_TYPE)type;

		if (strOrbitType.toLower() == "high")
		{
			element->orbitType = ORBIT_TYPE::HIGH;
		}
		else if (strOrbitType.toLower() == "middle")
		{
			element->orbitType = ORBIT_TYPE::MIDDLE;
		}
		else if (strOrbitType.toLower() == "low")
		{
			element->orbitType = ORBIT_TYPE::LOW;
		}
		else
		{
			element->orbitType = ORBIT_TYPE::UNKNONW;
		}

		if (strSatelliteType == "remoteSensing")
		{
			element->type = COE_TYPE::REMOTE;
		}
		
		element->i = fields[2].toDouble();			// 轨道倾角，单位:度
		element->w = fields[3].toDouble();			// 升交点赤经，单位:度
		element->E = ("0." + fields[4]).toDouble();	// 轨道偏心率
		element->Omega = fields[5].toDouble();		// 近地点幅角，单位:度
		element->M = fields[6].toDouble();			// 平近点角
		element->roll = 0;
		element->pitch = 0;
		element->yaw = 0;
		element->id = result.value("id").toInt();
		element->iNumber = result.value("internationalNumber").toString();
		element->status = result.value("satellitestatus").toString();
		element->launchSite = result.value("launchSite").toString();
		element->launchNumber = result.value("launchNumber").toInt();
		element->launchDate = result.value("launchDate").toString();
		getSatelliteInfo(element->Info, name, sateInfos);

		QString modelFile;
		QColor color;
		getModelAndColor(element->name, modelFile, color);

		element->startSimTime = element->currentSimTime = QDateTime::currentDateTime();

		double T = 1 / fields[7].toDouble();		// 周期
		element->a = pow((398.60047 * 10e12 * T * T) / (4 * osg::PI * osg::PI), 1.0 / 3.0) * 1000; // 长半轴

		// 算轨道周期
		double t = sqrt(pow(element->a, 3) * 4 * osg::PI * osg::PI / muu);

		// 画轨道
		osg::Vec3 firstVert;
		osg::Vec3 oribtNor;

		std::vector<osg::Vec3> lonlats;
		osg::Vec4 oribtColor(color.redF(), color.greenF(), color.blueF(), 0.5);
		element->orbit = addOribt(element, t, firstVert, oribtNor, lonlats, oribtColor);
		m_Root->addChild(element->orbit);

		// 添加星下点轨迹
		miniMapTrack* track = new miniMapTrack(element->name);
		track->m_color = color;
		for (int i = 0; i < lonlats.size(); i++)
		{
			track->addPoint(QPoint(lonlats[i].x(), lonlats[i].y()));
		}
		m_miniMap->addTrack(track);

		element->track = track;
		element->firstPosition = firstVert;
		element->normal = oribtNor;

		// 添加卫星
		osg::MatrixTransform* rotateMT = new osg::MatrixTransform;
		osg::PositionAttitudeTransform* sateGroup = addSatellite(std::string(name.toLocal8Bit()),
			std::string(modelFile.toLocal8Bit()), 
			osg::Vec3d(0, 0, 0),
			0,
			0,
			0,
			rotateMT, color);
		sateGroup->setUserValue<std::string>("Type", "Satellite");
		sateGroup->setUserValue<std::string>("Name", std::string(element->name.toLocal8Bit()));

		// 添加扫描体
		osg::MatrixTransform* scanRangeBody = drawMaxScanRange(32, 15, 5, 50, 0.3, 0.1);
		osg::MatrixTransform* currentScanBody = drawCurrentScanRange(30, 5, 2, 50, 0.2, 0.6);
		sateGroup->addChild(scanRangeBody);
		sateGroup->addChild(currentScanBody);

		currentScanBody->setNodeMask(0);
		scanRangeBody->setNodeMask(0);

		m_sateModels.append(sateGroup);

		element->sateModel = sateGroup;
		element->rotateMT = rotateMT;

		// 添加卫星姿态坐标轴
		element->sateAxis = addSateAxis(500000, firstVert, oribtNor);
		//element->orbit->addChild(element->sateAxis);

		element->cone = nullptr;
		//element->cone = createCone(osg::Vec3(0, 0, 0), firstVert, 2000000);
		//m_Root->addChild(element->cone);

		m_coes.append(element);

		sateGroup->setUserValue("Name", std::string(name.toLocal8Bit()));	// 名称
		sateGroup->setUserValue("SemimajorAxis", element->a);				// 长半轴
		sateGroup->setUserValue("Eccentricity", element->E);				// 偏心率
		sateGroup->setUserValue("Inclination", element->i);					// 轨道倾角
		sateGroup->setUserValue("ArgumentOfPerigee", element->Omega);		// 近地点幅角
		sateGroup->setUserValue("LongitudeOfTheAscendingNode", element->w);	// 升交点赤经
		sateGroup->setUserValue("MeanAnomaly", element->M);					// 平近点角

		sateGroup->setUserValue("Roll", 0);		// 翻滚角
		sateGroup->setUserValue("Pitch", 0);	// 俯仰角
		sateGroup->setUserValue("Yaw", 0);		// 偏航角

		m_Root->addChild(sateGroup);

		// 添加树节点
		addTreeItem(element);

		dialog.setValue(++index);
		qApp->processEvents();
	}

	m_EarthManipulator->home(0.5);
	slotRealtimeChanged(true);

	printLog("从数据库添加了卫星。");
}

/**
* @brief 添加树节点
* @return
*/
void SatelliteSim::addTreeItem(COE_ELEMENT* element)
{
	std::string name;
	element->sateModel->getUserValue("Name", name);

	QTreeWidgetItem* kindItem = nullptr;

	QStringList fields = QString("%1").arg(name.c_str()).split(QRegExp("[_-]"), QString::SkipEmptyParts);
	if (m_sateTreeItemMap.contains(fields[0]) == false)
	{
		kindItem = new QTreeWidgetItem(ui.treeWidgetObjects, QStringList(fields[0]));
		kindItem->setCheckState(0, Qt::Checked);
		m_sateTreeItemMap.insert(fields[0], kindItem);
	}
	else
	{
		kindItem = m_sateTreeItemMap[fields[0]];
	}

	QTreeWidgetItem* newItem = new QTreeWidgetItem(kindItem, QStringList(QString::fromLocal8Bit(name.c_str())));
	newItem->setIcon(0, QIcon(QCoreApplication::applicationDirPath() + "/Resources/satellite.svg"));
	newItem->setData(0, Qt::UserRole + 1, QVariant::fromValue((void*)element));
	newItem->setCheckState(0, Qt::Checked);

	ui.treeWidgetObjects->setCurrentItem(newItem);
	slotObjectClicked(newItem, 0);
}

/**
* @brief 关于
* @return
*/
void SatelliteSim::slotAbout()
{
	AboutDialog dialog(this);
	dialog.exec();
}

/**
* @brief 设置到当前时间
* @return
*/
void SatelliteSim::slotSetDatetimeToCurrent()
{
	QDateTime dt = QDateTime::currentDateTime();
	m_pSkyNode->setDateTime(osgEarth::DateTime(dt.date().year(), dt.date().month(), dt.date().day(), dt.time().hour() - 8));

	QDateTime newDT;
	newDT.setDate(ui.dateEditDate->date());
	newDT.setTime(ui.timeEditTime->time());

	g_simTime = newDT;
	slotUpdateSatellite();
}

/**
* @brief 手动设置时间
* @return
*/
void SatelliteSim::slotSetDatetime()
{
	QDate date = ui.dateEditDate->date();
	QTime time = ui.dateEditDate->time();
	m_pSkyNode->setDateTime(osgEarth::DateTime(date.year(), date.month(), date.day(), time.hour() - 8));
}

/**
* @brief 开启/关闭灯光
* @return
*/
void SatelliteSim::slotLightChanged(int value)
{
	m_pSkyNode->setLighting(value != 0);

	if (value == 0)
	{
		printLog("关闭灯光。");
	}
	else
	{
		printLog("开启灯光。");
	}
}

/**
* @brief 开启/关闭惯性
* @return
*/
void SatelliteSim::slotInertiaChanged(int value)
{
	m_EarthManipulator->getSettings()->setThrowingEnabled(value != 0);

	if (value == 0)
	{
		printLog("关闭惯性。");
	}
	else
	{
		printLog("开启惯性。");
	}
}

/**
* @brief 开启/关闭经纬网
* @return
*/
void SatelliteSim::slotGraticulesChanged(int value)
{
	if (value == 0)
	{
		m_MapNode->getMap()->removeLayer(m_graticule);
		printLog("关闭经纬网。");
	}
	else
	{
		m_graticule = new osgEarth::Util::GeodeticGraticule();
		m_MapNode->getMap()->addLayer(m_graticule);
		printLog("开启经纬网。");
	}
}

/**
* @brief 显示/隐藏坐标轴
* @return
*/
void SatelliteSim::slotAxisChanged(int value)
{
	if (value == 0)
	{
		m_Root->removeChild(m_axis);
	}
	else
	{
		m_Root->addChild(m_axis = addAxis(10000000));
	}

	if (value == 0)
	{
		printLog("关闭坐标轴。");
	}
	else
	{
		printLog("开启坐标轴。");
	}
}

/**
* @brief 设置日期
* @return
*/
void SatelliteSim::slotUserDateChanged(const QDate&)
{
	QDate date = ui.dateEditDate->date();
	QTime time = ui.timeEditTime->time();
	m_pSkyNode->setDateTime(osgEarth::DateTime(date.year(), date.month(), date.day(), time.hour() - 8));
}

/**
* @brief 设置时间
* @return
*/
void SatelliteSim::slotUserTimeChanged(const QTime&)
{
	QDate date = ui.dateEditDate->date();
	QTime time = ui.timeEditTime->time();
	m_pSkyNode->setDateTime(osgEarth::DateTime(date.year(), date.month(), date.day(), time.hour() - 8));
}

/**
* @brief 实时
* @return
*/
void SatelliteSim::slotRealtimeChanged(bool value)
{
	if (m_realtimeTimer == NULL)
	{
		m_realtimeTimer = new QTimer(this);
		m_realtimeTimer->setTimerType(Qt::PreciseTimer);
		connect(m_realtimeTimer, SIGNAL(timeout()), this, SLOT(slotUpdateSatellite()));
	}

	if (value == true)
	{
		m_realtimeTimer->start(20);
		ui.groupBoxManual->setEnabled(false);
		ui.groupBoxAuto->setEnabled(true);
	}
}

/**
* @brief 手动设置
* @return
*/
void SatelliteSim::slotManualChanged(bool)
{
	if (m_realtimeTimer != NULL)
	{
		m_realtimeTimer->stop();
		ui.groupBoxManual->setEnabled(true);
		ui.groupBoxAuto->setEnabled(false);
	}
}

/**
* @brief 定时器动画
* @return
*/
void SatelliteSim::slotUpdateSatellite()
{
	for (int i = 0; i < m_coes.count(); i++)
	{
		COE_ELEMENT* element = m_coes[i];

		osg::Vec3d currentVec3 = getSatePosition(element, element->currentSimTime.toSecsSinceEpoch()/*dateTimeToS(g_simTime)*/);

		osg::Vec3d lonlat = WorldToLonLatAlt(currentVec3);

		m_miniMap->setCurrentPoint(element->name, QPoint(lonlat.x(), lonlat.y()));

		//m_sateModels[i]->setPivotPoint(currentVec3);
		m_sateModels[i]->setPosition(currentVec3);
		//m_sateModels[i]->setScale(osg::Vec3(10000000.0f, 10000000.0f, 10000000.0f));

		if (ui.comboBoxTimeUnit->currentText() == "hours")
		{
			//g_simTime = g_simTime.addMSecs(ui.comboBoxIntervalTime->currentText().toInt() * 72000);
			element->currentSimTime = element->currentSimTime.addMSecs(ui.comboBoxIntervalTime->currentText().toInt() * 72000);
		}
		else if (ui.comboBoxTimeUnit->currentText() == "minutes")
		{
			//g_simTime = g_simTime.addMSecs(ui.comboBoxIntervalTime->currentText().toInt() * 1200);
			element->currentSimTime = element->currentSimTime.addMSecs(ui.comboBoxIntervalTime->currentText().toInt() * 1200);
		}
		else if (ui.comboBoxTimeUnit->currentText() == "seconds")
		{
			//g_simTime = g_simTime.addMSecs(ui.comboBoxIntervalTime->currentText().toInt() * 20);
			element->currentSimTime = element->currentSimTime.addMSecs(ui.comboBoxIntervalTime->currentText().toInt() * 20);
		}

		// 更新卫星坐标轴
		if (element->sateAxis != NULL)
		{
			osg::Vec3 c = currentVec3;
			osg::Vec3 cNorm = currentVec3;
			cNorm.normalize();

			osg::Vec3dArray* vertices = dynamic_cast<osg::Vec3dArray*>(element->sateAxis->getVertexArray());

			osg::Vec3 z = currentVec3 + cNorm * -500000;
			osg::Vec3 y = currentVec3 + element->normal * -500000;

			osg::Vec3 norYZ = (y ^ z);
			norYZ.normalize();
			osg::Vec3 x = currentVec3 + norYZ * -500000;

			osg::Vec3dArray* newVertices = new osg::Vec3dArray(6);

			(*newVertices)[0] = c;
			(*newVertices)[1] = x;
			(*newVertices)[2] = c;
			(*newVertices)[3] = y;
			(*newVertices)[4] = c;
			(*newVertices)[5] = z;

			osg::Vec3d orbitNormalX = x - c;
			orbitNormalX.normalize();

			osg::Vec3d orbitNormalY = y - c;
			orbitNormalY.normalize();

			osg::Vec3d orbitNormalZ = z - c;
			orbitNormalZ.normalize();

			element->sateAxis->setVertexArray(newVertices);
			element->sateAxis->dirtyDisplayList();

			// 旋转卫星
			float angle = calcAngle(element->firstPosition, currentVec3, element->normal/*osg::Vec3(0, 0, 1)*/);

			//m_sateModels[i]->setAttitude(osg::Quat(angle, element.normal/*osg::Vec3(0, 0, 1)*/) *
			//	osg::Quat(osg::DegreesToRadians(element.i), norRot) *
			//	osg::Quat(osg::DegreesToRadians(element.roll), osg::Vec3(0, 0, 1)) *
			//	osg::Quat(osg::DegreesToRadians(element.pitch), osg::Vec3(1, 0, 0)) *
			//	osg::Quat(osg::DegreesToRadians(element.yaw), osg::Vec3(0, 1, 0)));

			// Y轴渲染量
			float angleY = calcAngle0(osg::Vec3d(0, 1, 0), orbitNormalY);
			osg::Vec3 norY = (osg::Vec3d(0, 1, 0) ^ orbitNormalY);
			norY.normalize();

			//float angleZ = calcAngle(osg::Vec3d(0, 1, 0), orbitNormalZ, element.normal);
			//osg::Vec3 norZ = (osg::Vec3d(0, 1, 0) ^ orbitNormalZ);
			//norZ.normalize();

			float angleX = calcAngle0(osg::Vec3d(1, 0, 0), orbitNormalX);
			osg::Vec3 norX = (osg::Vec3d(1, 0, 0) ^ orbitNormalX);
			norX.normalize();

			// 先旋转Y轴
			osg::Quat quatY = osg::Quat(angleY, norY);

			// 再旋转Z轴
			osg::Vec3d zAfterRotateY = quatY * osg::Vec3d(0, 0, 1);

			float angleZ = calcAngle0(zAfterRotateY, orbitNormalZ);
			osg::Vec3 norZ = (zAfterRotateY ^ orbitNormalZ);
			norZ.normalize();

			m_sateModels[i]->setAttitude(quatY * 
				osg::Quat(angleZ, norZ));

			element->rotateMT->setMatrix(osg::Matrix::rotate(osg::DegreesToRadians(90.0f), 1.0f, 0.0f, 0.0f) *
				osg::Matrix::rotate(osg::DegreesToRadians(90.0f), 0.0f, 1.0f, 0.0f) *
				osg::Matrix::rotate(osg::DegreesToRadians(element->roll), 0, 0, 1) *
				osg::Matrix::rotate(osg::DegreesToRadians(element->pitch), 1, 0, 0) *
				osg::Matrix::rotate(osg::DegreesToRadians(element->yaw), 0, 1, 0));

			//m_sateModels[i]->setAttitude(osg::Quat(osg::DegreesToRadians(-90.0), osg::Vec3(1, 0, 0)) *
			//	osg::Quat(-angleZ, norZ) *
			//	osg::Quat(-angleX, orbitNormalZ));

			//m_sateModels[i]->setAttitude(osg::Quat(0, orbitNormalX, 0, orbitNormalY, 0, orbitNormalZ));
		}

		// 更新辐射椎
		if (element->cone)
		{
			osg::Matrix oriMat = element->cone->getMatrix();
			osg::Matrix mRotate, mTrans;
			mRotate.makeRotate(osg::Vec3d(0.0f, 0.0f, 1.0f), currentVec3);
			osg::Vec3 cylCenter = (osg::Vec3(0, 0, 0) + currentVec3) / 4;
			mTrans.makeTranslate(cylCenter);
			element->cone->setMatrix(mRotate * mTrans);
		}

		// 更新当前选中卫星的仿真时间
		if (ui.treeWidgetObjects->currentItem() != nullptr)
		{
			COE_ELEMENT* currElement = (COE_ELEMENT*)ui.treeWidgetObjects->currentItem()->data(0, Qt::UserRole + 1).value<void*>();
			if (currElement != nullptr)
			{
				g_simTime = currElement->currentSimTime;
				ui.doubleSpinBoxLon->setValue(lonlat.x());
				ui.doubleSpinBoxLat->setValue(lonlat.y());

				osg::Vec3d currPos = currElement->sateModel->getPosition();
				osg::Vec3d currlonlat = WorldToLonLatAlt(currPos);

				s_idLabel->setText(std::to_string(currElement->id));
				s_nameLabel->setText(std::string(currElement->name.toLocal8Bit()));
				s_iNumberLabel->setText(std::string(currElement->iNumber.toLocal8Bit()));
				s_statusLabel->setText(std::string(currElement->status.toLocal8Bit()));
				s_lonLabel->setText(std::to_string(currlonlat.x()));
				s_latLabel->setText(std::to_string(currlonlat.y()));
				s_pitchLabel->setText(std::to_string(currElement->pitch));
				s_yawLabel->setText(std::to_string(currElement->yaw));
				s_rollLabel->setText(std::to_string(currElement->roll));
				s_aLabel->setText(std::to_string(currElement->a));
				s_eLabel->setText(std::to_string(currElement->E));
				s_iLabel->setText(std::to_string(currElement->i));
				s_omegaLabel->setText(std::to_string(currElement->Omega));
				s_wLabel->setText(std::to_string(currElement->w));
				s_mLabel->setText(std::to_string(currElement->M));
			}
		}
	}
}

/**
* @brief 点击了树控件中的卫星节点
* @return
*/
void SatelliteSim::slotObjectClicked(QTreeWidgetItem *item, int column)
{
	if (item->parent() == nullptr) return;

	COE_ELEMENT* element = (COE_ELEMENT*)item->data(0, Qt::UserRole + 1).value<void*>();

	double semimajorAxis, eccentricity, inclination, argumentOfPerigee, longitudeOfTheAscendingNode, meanAnomaly;
	element->sateModel->getUserValue("SemimajorAxis", semimajorAxis);				// 长半轴
	element->sateModel->getUserValue("Eccentricity", eccentricity);					// 偏心率
	element->sateModel->getUserValue("Inclination", inclination);					// 轨道倾角
	element->sateModel->getUserValue("ArgumentOfPerigee", argumentOfPerigee);	// 近地点幅角
	element->sateModel->getUserValue("LongitudeOfTheAscendingNode", longitudeOfTheAscendingNode);	// 升交点赤经
	element->sateModel->getUserValue("MeanAnomaly", meanAnomaly);							// 平近点角

	double roll, pitch, yaw;
	element->sateModel->getUserValue("Roll", roll);	// 翻滚角
	element->sateModel->getUserValue("Pitch", pitch);	// 俯仰角
	element->sateModel->getUserValue("Yaw", yaw);		// 偏航角

	//setOrbitColor(element, osg::Vec4(1.0, 0.0, 0.0, 1.0));

	ui.doubleSpinBoxSemimajorAxis->setValue(semimajorAxis);
	ui.doubleSpinBoxEccentricity->setValue(eccentricity);
	ui.doubleSpinBoxInclination->setValue(inclination);
	ui.doubleSpinBoxArgumentOfPerigee->setValue(argumentOfPerigee);
	ui.doubleSpinBoxLongitudeOfTheAscendingNode->setValue(longitudeOfTheAscendingNode);
	ui.doubleSpinBoxMeanAnomaly->setValue(meanAnomaly);

	ui.doubleSpinBoxRoll->setValue(roll);
	ui.doubleSpinBoxPitch->setValue(pitch);
	ui.doubleSpinBoxYaw->setValue(yaw);
}

void currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous);

/**
* @brief 启动/停止地球自转
* @return
*/
void SatelliteSim::slotAutoRotate(int state)
{
	if (state != 0)
	{
		if (m_autoRotateTimer == NULL)
		{
			m_autoRotateTimer = new QTimer();
			connect(m_autoRotateTimer, SIGNAL(timeout()), this, SLOT(slotEarthRotateing()));
		}

		m_MainViewer->setCameraManipulator(NULL);
		g_simTime = QDateTime::currentDateTime();
		m_autoRotateTimer->start(20);
	}
	else
	{
		m_autoRotateTimer->stop();

		m_EarthManipulator = new osgEarth::Util::EarthManipulator();
		m_EarthManipulator->getSettings()->setMinMaxPitch(-90, 0);//设置最大最小倾斜角度
		//m_EarthManipulator->getSettings()->setMinMaxDistance(100.0, 4e7);//设置最近最远距离
		m_EarthManipulator->getSettings()->setThrowingEnabled(true);
		m_MainViewer->setCameraManipulator(m_EarthManipulator);
	}
}

/**
* @brief 地球自转定时器函数
* @return
*/
void SatelliteSim::slotEarthRotateing()
{
	static double rotateAngle = 0;

	m_earthTrans->setMatrix(osg::Matrix::rotate(osg::DegreesToRadians(rotateAngle), 0, 0, 1));
	rotateAngle += ui.spinBoxSpeed->value();

	g_simTime = g_simTime.addMSecs((ui.spinBoxSpeed->value() / 360.0) * 24.0 * 60 * 60 * 1000);
}

/**
* @brief 搜索子节点
* @return
*/
void SatelliteSim::searchChild(QTreeWidgetItem *cItem, const QString &txt)
{
	int childCount = cItem->childCount();
	for (int i = 0; i < childCount; ++i) {
		QTreeWidgetItem *item = cItem->child(i);
		if (-1 != item->text(0).indexOf(txt)) {
			item->setExpanded(true);
			item->setBackground(0, Qt::green);
			parentExpand(item);
		}
		else {
			item->setBackground(0, m_itemBrush);
		}
		searchChild(item, txt);
	}
}

/**
* @brief 展开父节点
* @return
*/
void SatelliteSim::parentExpand(QTreeWidgetItem *item)
{
	if (item->parent() != NULL) {
		QTreeWidgetItem *pItem = item->parent();
		if (!pItem->isExpanded()) {
			pItem->setExpanded(true);
		}
		parentExpand(pItem);
	}
}

// 检索卫星
void SatelliteSim::querySatellite(QString key)
{
	m_itemBrush.setColor(QColor(217, 217, 217));

	//ui.treeWidgetObjects->collapseAll();
	QString txt = key;
	bool isEmptyTxt = txt.isEmpty();
	bool isEmptyTree = ui.treeWidgetObjects->topLevelItemCount(); //非零个为true
	if (isEmptyTxt) {
		QTreeWidgetItemIterator it(ui.treeWidgetObjects);
		while (*it) {
			(*it)->setBackground(0, m_itemBrush);
			it++;
		}
		return;
	}
	if (!isEmptyTree) { return; }


#if 0
	int count = ui->treeWidget->topLevelItemCount();
	for (int i = 0; i < count; ++i) {
		QTreeWidgetItem *cItem = ui->treeWidget->topLevelItem(i);
		if (-1 != cItem->text(0).indexOf(txt)) {
			cItem->setBackground(0, Qt::green);
		}
		else {
			cItem->setBackground(0, m_itemBrush);
		}
		searchChild(cItem, txt);
	}
#else

	QTreeWidgetItemIterator it(ui.treeWidgetObjects);
	while (*it) {
		QString str = (*it)->text(0);
		if (-1 != str.indexOf(txt)) {
			QTreeWidgetItem *pItem = (*it)->parent();
			if (pItem != NULL) {
				bool isExpanded = pItem->isExpanded();
				if (!isExpanded){
					ui.treeWidgetObjects->expandItem(pItem);
				}
			}
			(*it)->setBackground(0, Qt::gray);
			parentExpand(*it);
		}
		else{
			(*it)->setBackground(0, m_itemBrush);
		}
		it++;
	}
#endif
}

/**
* @brief 搜索卫星
* @return
*/
void SatelliteSim::slotSearchSatellite()
{
	querySatellite(ui.lineEditSearch->text());
}

/**
* @brief 更新节点状态
* @return
*/
void updateTreeItemState(QTreeWidgetItem* item)
{
	int cnt = item->childCount();
	if (cnt == 0) return;

	int checkedCount = 0;
	for (int i = 0; i < cnt; i++)
	{
		if (item->child(i)->checkState(0) == Qt::Checked)
		{
			checkedCount++;
		}
	}

	if (checkedCount > 0 && checkedCount < cnt)
	{
		if (item->checkState(0) != Qt::PartiallyChecked)
			item->setCheckState(0, Qt::PartiallyChecked);
	}
	else if (checkedCount == cnt)
	{
		if (item->checkState(0) != Qt::Checked)
			item->setCheckState(0, Qt::Checked);
	}
	else
	{
		if (item->checkState(0) != Qt::Unchecked)
			item->setCheckState(0, Qt::Unchecked);
	}
}

/**
* @brief 勾选了卫星节点
* @return
*/
void SatelliteSim::slotTreeItemChanged(QTreeWidgetItem* item, int column)
{
	QString itemText = item->text(0);
	if (item->checkState(0) == Qt::Checked)
	{
		int cnt = item->childCount();
		if (cnt > 0)
		{
			for (int i = 0; i < cnt; i++)
			{
				item->child(i)->setCheckState(0, Qt::Checked);
			}
		}

		if (item->parent() != nullptr)
		{
			// 更新卫星显示状态
			COE_ELEMENT* element = (COE_ELEMENT*)item->data(0, Qt::UserRole + 1).value<void*>();

			if (element != nullptr)
			{
				osg::PositionAttitudeTransform* pat = element->sateModel;
				osg::Geometry* axis = element->sateAxis;
				osg::MatrixTransform* cone = element->cone;
				osg::Geode* orbit = element->orbit;

				element->track->setVisible(true);
				m_miniMap->needDrawOrbit();

				if (pat != nullptr)
					pat->setNodeMask(0xffffff);
				if (axis != nullptr)
					axis->setNodeMask(0xffffff);
				if (cone != nullptr)
					cone->setNodeMask(0xffffff);
				if (orbit != nullptr)
					orbit->setNodeMask(0xffffff);
			}
		}
	}
	else if (item->checkState(0) == Qt::Unchecked)
	{
		int cnt = item->childCount();
		if (cnt > 0)
		{
			for (int i = 0; i < cnt; i++)
			{
				item->child(i)->setCheckState(0, Qt::Unchecked);
			}
		}

		if (item->parent() != nullptr)
		{
			// 更新卫星显示状态
			COE_ELEMENT* element = (COE_ELEMENT*)item->data(0, Qt::UserRole + 1).value<void*>();

			if (element != nullptr)
			{
				osg::PositionAttitudeTransform* pat = element->sateModel;
				osg::Geometry* axis = element->sateAxis;
				osg::MatrixTransform* cone = element->cone;
				osg::Geode* orbit = element->orbit;

				element->track->setVisible(false);
				m_miniMap->needDrawOrbit();

				if (pat != nullptr)
					pat->setNodeMask(0);
				if (axis != nullptr)
					axis->setNodeMask(0);
				if (cone != nullptr)
					cone->setNodeMask(0);
				if (orbit != nullptr)
					orbit->setNodeMask(0);
			}
		}
	}

	if (item->parent() != nullptr)
	{
		ui.lineEditSearch->blockSignals(true);
		updateTreeItemState(item->parent());
		ui.lineEditSearch->blockSignals(false);
	}
}

/**
* @brief 设置轨道颜色
* @return
*/
void SatelliteSim::setOrbitColor(COE_ELEMENT* sate, osg::Vec4d color)
{
	int drawableCount = sate->orbit->getNumDrawables();
	for (int i = 0; i < drawableCount; i++)
	{
		osg::Drawable* drawable = sate->orbit->getDrawable(i);
		osg::Geometry* orbitLine = dynamic_cast<osg::Geometry*>(drawable);

		osg::Vec4Array* color = dynamic_cast<osg::Vec4Array*>(orbitLine->getColorArray());
		(*color)[i] = osg::Vec4(1.0, 0.0, 0.0, 1.0);
		orbitLine->dirtyDisplayList();
	}
}

#include <osgEarth/Viewpoint>
/**
* @brief 当前选中的卫星改变
* @return
*/
void SatelliteSim::slotCurrentObjectChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous)
{
	//if (current->parent() == nullptr) return;

	if (previous != nullptr)
	{
		COE_ELEMENT* element = (COE_ELEMENT*)previous->data(0, Qt::UserRole + 1).value<void*>();

		if (element != nullptr)
		{
			osg::MatrixTransform* mt = dynamic_cast<osg::MatrixTransform*>(element->sateModel->getChild(0));
			osg::Switch* sw = dynamic_cast<osg::Switch*>(mt->getChild(0));

			sw->setValue(0, false);
			sw->setValue(1, true);

			// 关闭扫描体
			osg::MatrixTransform* scanBody1 = dynamic_cast<osg::MatrixTransform*>(element->sateModel->getChild(1));
			osg::MatrixTransform* scanBody2 = dynamic_cast<osg::MatrixTransform*>(element->sateModel->getChild(2));

			scanBody1->setNodeMask(0);
			scanBody2->setNodeMask(0);
		}
	}

	if (current == nullptr)
	{
		return;
	}

	COE_ELEMENT* element = (COE_ELEMENT*)current->data(0, Qt::UserRole + 1).value<void*>();

	if (element == nullptr) return;

	// 把圆球变成模型
	osg::MatrixTransform* mt = dynamic_cast<osg::MatrixTransform*>(element->sateModel->getChild(0));
	osg::Switch* sw = dynamic_cast<osg::Switch*>(mt->getChild(0));

	sw->setValue(0, true);
	sw->setValue(1, false);

	// 显示扫描体
	osg::MatrixTransform* scanBody1 = dynamic_cast<osg::MatrixTransform*>(element->sateModel->getChild(1));
	osg::MatrixTransform* scanBody2 = dynamic_cast<osg::MatrixTransform*>(element->sateModel->getChild(2));

	scanBody1->setNodeMask(0xffff);
	scanBody2->setNodeMask(0xffff);

	osg::Vec3d currPos = element->sateModel->getPosition();

	osg::Vec3d lonlat = WorldToLonLatAlt(currPos);

	osgEarth::Viewpoint currViewpoint = m_EarthManipulator->getViewpoint();
	m_EarthManipulator->setViewpoint(osgEarth::Viewpoint("111", lonlat.x(), lonlat.y(), lonlat.z(), currViewpoint.getHeading(), currViewpoint.getPitch(), lonlat.z() * 0.3));

	slotObjectClicked(current, 0);

	s_idLabel->setText(std::to_string(element->id));
	s_nameLabel->setText(std::string(element->name.toLocal8Bit()));
	s_iNumberLabel->setText(std::string(element->iNumber.toLocal8Bit()));
	s_statusLabel->setText(std::string(element->status.toLocal8Bit()));
	s_lonLabel->setText(std::to_string(lonlat.x()));
	s_latLabel->setText(std::to_string(lonlat.y()));
	s_pitchLabel->setText(std::to_string(element->pitch));
	s_yawLabel->setText(std::to_string(element->yaw));
	s_rollLabel->setText(std::to_string(element->roll));
	s_aLabel->setText(std::to_string(element->a));
	s_eLabel->setText(std::to_string(element->E));
	s_iLabel->setText(std::to_string(element->i));
	s_omegaLabel->setText(std::to_string(element->Omega));
	s_wLabel->setText(std::to_string(element->w));
	s_mLabel->setText(std::to_string(element->M));

	s_launchSiteLabel->setText(std::string(element->launchSite.toLocal8Bit()));
	s_launchNumberLabel->setText(std::to_string(element->launchNumber));
	s_launchDateLabel->setText(std::string(element->launchDate.toLocal8Bit()));
}

#include <osg/CoordinateSystemNode>

osg::Vec3d LonLatAltToWorld(const osg::Vec3d lonLatAlt)
{
	osg::Vec3d world;
	osg::EllipsoidModel* em = new osg::EllipsoidModel();
	//Lat纬度Long经度
	em->convertLatLongHeightToXYZ(osg::DegreesToRadians(lonLatAlt.y()),
		osg::DegreesToRadians(lonLatAlt.x()), lonLatAlt.z(), world.x(), world.y(), world.z());

	return world;
}

/**
* @brief 开始环视
* @return
*/
void SatelliteSim::slotPinCamera()
{
	FixPosLookAround(ui.doubleSpinBoxPinLon->value(), ui.doubleSpinBoxPinLat->value(), 1000);

	printLog("开始环视。");
}

/**
* @brief 定点环视
* @return
*/
void SatelliteSim::FixPosLookAround(double x, double y, double z)
{
#if 0
	if (m_trackballManipulator == nullptr)
	{
		m_trackballManipulator = new PinTrackballManipulator(osgGA::StandardManipulator::DEFAULT_SETTINGS | osgGA::StandardManipulator::SET_CENTER_ON_WHEEL_FORWARD_MOVEMENT);
		//m_trackballManipulator = new osgGA::TrackballManipulator();
	}

	if (m_MainViewer->getCameraManipulator() != m_trackballManipulator)
	{
		m_MainViewer->setCameraManipulator(m_trackballManipulator);
	}

	osg::Vec3d eye;
	osg::Vec3d oldCenter;
	osg::Vec3d up;
	m_trackballManipulator->getTransformation(eye, oldCenter, up);

	osg::Vec3d lonlatalt;
	lonlatalt.set(ui.doubleSpinBoxPinLon->value(), ui.doubleSpinBoxPinLat->value(), 0);
	osg::Vec3d newCenter = LonLatAltToWorld(lonlatalt);
	newCenter.z() = 6378137;
	m_trackballManipulator->setTransformation(eye, newCenter, up);

	////m_trackballManipulator->setElevation(0);
	//m_trackballManipulator->setDistance(0);

	//osgEarth::Viewpoint currViewpoint = m_EarthManipulator->getViewpoint();
	//m_EarthManipulator->setViewpoint(osgEarth::Viewpoint("pin", lonlatalt.x(), lonlatalt.y(), lonlatalt.z(), currViewpoint.getHeading(), currViewpoint.getPitch(), 1000));
#endif

	osg::Vec3d lonlatalt;
	lonlatalt.set(x, y, z);

	//osgEarth::Viewpoint currViewpoint = m_EarthManipulator->getViewpoint();
	m_EarthManipulator->getSettings()->setTerrainAvoidanceEnabled(true);
	m_EarthManipulator->getSettings()->setLockAzimuthWhilePanning(true);
	//m_EarthManipulator->getSettings()->setArcViewpointTransitions(false);

	//m_EarthManipulator->getSettings()->getBreakTetherActions().push_back(osgEarth::Util::EarthManipulator::ACTION_GOTO);

	// Set the minimum distance to something larger than the default
	m_EarthManipulator->getSettings()->setMinMaxDistance(0.1, m_EarthManipulator->getSettings()->getMaxDistance());

	// Sets the maximum focal point offsets (usually for tethering)
	//m_EarthManipulator->getSettings()->setMaxOffset(5000.0, 5000.0);

	// Pitch limits.
	m_EarthManipulator->getSettings()->setMinMaxPitch(-180, 180);

	m_EarthManipulator->getSettings()->bindMouse(
		osgEarth::Util::EarthManipulator::ACTION_EARTH_DRAG,
		osgGA::GUIEventAdapter::LEFT_MOUSE_BUTTON,
		osgGA::GUIEventAdapter::MODKEY_SHIFT);

	//m_EarthManipulator->getSettings()->bindMouseClick(
	//	osgEarth::Util::EarthManipulator::ACTION_GOTO,
	//	osgGA::GUIEventAdapter::LEFT_MOUSE_BUTTON,
	//	osgGA::GUIEventAdapter::MODKEY_SHIFT);

	//m_EarthManipulator->getSettings()->setArcViewpointTransitions(true);

	//m_EarthManipulator->setTetherCallback(new TetherCB());

	//m_EarthManipulator->getSettings()->setTetherMode(m_EarthManipulator->TETHER_CENTER);
	
	if (!_autoClipPlaneCuller.valid())
	{
		_autoClipPlaneCuller = new osgEarth::Util::EarthAutoClipPlaneCullCallback(m_MapNode);
	}

	//m_MainViewer->getCamera()->addCullCallback(_autoClipPlaneCuller);

	m_MainViewer->getCamera()->setNearFarRatio(0.00001);

	m_EarthManipulator->getSettings()->bindMouse(osgEarth::Util::EarthManipulator::ACTION_PAN, osgGA::GUIEventAdapter::MIDDLE_MOUSE_BUTTON);
	m_EarthManipulator->getSettings()->bindMouse(osgEarth::Util::EarthManipulator::ACTION_ROTATE, osgGA::GUIEventAdapter::LEFT_MOUSE_BUTTON);

	// 关闭大气
	//m_pSkyNode->setAtmosphereVisible(false);

	m_EarthManipulator->setViewpoint(osgEarth::Viewpoint("Pin", lonlatalt.x(), lonlatalt.y(), lonlatalt.z(), 90.0, 0.0, 4.0));

	printLog("开始定点环视。");
}

/**
* @brief 结束环视
* @return
*/
void SatelliteSim::slotResetCamera()
{
	if (_autoClipPlaneCuller.valid())
	{
		m_MainViewer->getCamera()->removeCullCallback(_autoClipPlaneCuller);
	}

	m_EarthManipulator->getSettings()->bindMouse(osgEarth::Util::EarthManipulator::ACTION_PAN, osgGA::GUIEventAdapter::LEFT_MOUSE_BUTTON);
	m_EarthManipulator->getSettings()->bindMouse(osgEarth::Util::EarthManipulator::ACTION_ROTATE, osgGA::GUIEventAdapter::MIDDLE_MOUSE_BUTTON);

	// 开启大气
	m_pSkyNode->setAtmosphereVisible(true);
	m_EarthManipulator->home(0.0);

	//m_MainViewer->setCameraManipulator(m_EarthManipulator);

	printLog("结束定点环视。");
}

/**
* @brief 检索北斗卫星
* @return
*/
void SatelliteSim::slotQueryBeidou()
{
	//querySatellite("BEIDOU");

	ui.treeWidgetObjects->clear();
	m_sateTreeItemMap.clear();

	for (int i = 0; i < m_coes.count(); i++)
	{
		COE_ELEMENT* coe = m_coes[i];

		if (coe->type == BEIDOU)
		{
			addTreeItem(coe);
		}
	}
}

/**
* @brief 检索伽利略卫星
* @return
*/
void SatelliteSim::slotQueryGalileo()
{
	//querySatellite("GALILEO");

	ui.treeWidgetObjects->clear();
	m_sateTreeItemMap.clear();

	for (int i = 0; i < m_coes.count(); i++)
	{
		COE_ELEMENT* coe = m_coes[i];

		if (coe->type == GALILEO)
		{
			addTreeItem(coe);
		}
	}
}

/**
* @brief 定点环视
* @return
*/
void SatelliteSim::slotFixPosLookAround()
{
	FixPosLookAroundDialog dialog(this);
	if (dialog.exec())
	{
		double lon = 0;
		double lat = 0;
		dialog.getLonLat(lon, lat);

		FixPosLookAround(lon, lat , 1000);
	}
}

/**
* @brief 取消环视
* @return
*/
void SatelliteSim::slotReturnLookAround()
{
	slotResetCamera();
}

/**
* @brief 从服务添加
* @return
*/
void SatelliteSim::slotAddSatelliteFromService()
{
	QueryFromServiceDialog dialog(this);
	if (dialog.exec())
	{
		std::vector<SatelliteInfo> sateInfos;
		queryFromService(dialog.getServiceUrl(), sateInfos);

		m_sateFilterNames.clear();
		for (int i = 0; i < sateInfos.size(); i++)
		{
			if (m_sateFilterNames.contains(sateInfos[i].SatelliteName) == false)
			{
				m_sateFilterNames.insert(sateInfos[i].SatelliteName);
			}
		}

		ui.treeWidgetObjects->clear();
		slotAddSatelliteFromDB(sateInfos);
	}
}

/**
* @brief 从轨道数据中获取卫星类型
* @return
*/
OrbitChildInfo SatelliteSim::getSatelliteTypeFromOribtInfo(QString id, std::vector<OrbitInfo>& oribtInfos)
{
	for (int i = 0; i < oribtInfos.size(); i++)
	{
		std::vector<OrbitChildInfo>& orbitChildInfos = oribtInfos[i].ChildInfos;

		for (int j = 0; j < orbitChildInfos.size(); j++)
		{
			if (orbitChildInfos[j].Id == id)
			{
				return orbitChildInfos[j];
			}
		}
	}

	return OrbitChildInfo();
}

/**
* @brief 通过名称获取卫星信息
* @return
*/
bool SatelliteSim::getSatelliteInfo(SatelliteInfo& info, QString name, std::vector<SatelliteInfo>& sateInfos)
{
	for (int i = 0; i < sateInfos.size(); i++)
	{
		if (sateInfos[i].SatelliteName == name)
		{
			info = sateInfos[i];
			return true;
		}
	}

	return false;
}

/**
* @brief 从服务获取卫星数据
* @return
*/
void SatelliteSim::getSatelliteByType(QString url, 
	std::vector<SatelliteInfo>& sateInfos, 
	std::vector<OrbitInfo>& oribtInfos, 
	QProgressDialog* progDialog)
{
	QNetworkAccessManager manager;
	QNetworkRequest req;
	req.setUrl(QUrl(url));
	req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
	QNetworkReply* reply = manager.post(req, QByteArray("{}"));
	QEventLoop eventLoop;
	connect(&manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
	connect(progDialog, SIGNAL(canceled), &eventLoop, SLOT(quit()));
	eventLoop.exec();

	if (progDialog->wasCanceled() == true) return;

	if (reply->error() == QNetworkReply::NoError)
	{
		QByteArray ba = reply->readAll();
		QJsonParseError jsonpe;
		QJsonDocument json = QJsonDocument::fromJson(ba, &jsonpe);

		if (jsonpe.error == QJsonParseError::NoError)
		{
			QJsonArray rootArray = json.array();

			for (int i = 0; i < rootArray.count(); i++)
			{
				QJsonArray sateArray = rootArray.at(i).toArray();

				for (int j = 0; j < sateArray.count(); j++)
				{
					QJsonObject sateObj = sateArray.at(j).toObject();

					// 卫星信息
					QJsonObject sateInfoObj = sateObj["satelliteInfo"].toObject();

					SatelliteInfo sateInfo;
					sateInfo.LaunchNumber = sateInfoObj["launchNumber"].toString();
					sateInfo.Degree = sateInfoObj["degree"].toString();
					sateInfo.ResidualEnergy = sateInfoObj["residualEnergy"].toString();
					sateInfo.StorageCapacity = sateInfoObj["storageCapacity"].toString();
					sateInfo.ID = sateInfoObj["_id"].toString();
					sateInfo.LaunchDate = sateInfoObj["launchDate"].toString();
					sateInfo.LaunchSite = sateInfoObj["launchSite"].toString();
					sateInfo.Power = sateInfoObj["power"].toString();
					sateInfo.ElectricityQuantity = sateInfoObj["electricityQuantity"].toString();
					sateInfo.InternationalNumber = sateInfoObj["internationalNumber"].toString();
					sateInfo.ComputingUtilizationRate = sateInfoObj["computingUtilizationRate"].toString();
					sateInfo.SatelliteName = sateInfoObj["satelliteName"].toString();

					// 载荷
					QJsonArray equiArray = sateObj["equipments"].toArray();

					for (int k = 0; k < equiArray.count(); k++)
					{
						QJsonObject equiObj = equiArray.at(k).toObject();

						Equipment equi;

						equi.DeviceType = equiObj["deviceType"].toString();
						equi.DeviceNumber = equiObj["devicenumber"].toString();
						equi.LoadStatus = equiObj["loadStatus"].toBool();
						equi.SatelliteID = equiObj["satelliteID"].toString();
						equi.Trait = equiObj["trait"].toString();
						equi.DeviceModel = equiObj["deviceModel"].toString();
						equi.ID = equiObj["_id"].toString();
						equi.DeviceName = equiObj["deviceName"].toString();

						sateInfo.Equipments.push_back(equi);
					}

					sateInfo.OrbitInfo = getSatelliteTypeFromOribtInfo(sateInfo.ID, oribtInfos);

					sateInfos.push_back(sateInfo);
				}
			}
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
}

/**
* @brief 从服务获取轨道数据
* @return
*/
void SatelliteSim::getOribtByType(QString url, std::vector<OrbitInfo>& oribtInfos, QProgressDialog* progDialog)
{
	QNetworkAccessManager manager;
	QNetworkRequest req;
	req.setUrl(QUrl(url));
	req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
	QNetworkReply* reply = manager.post(req, QByteArray("{}"));
	QEventLoop eventLoop;
	connect(&manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
	connect(progDialog, SIGNAL(canceled), &eventLoop, SLOT(quit()));
	eventLoop.exec();

	if (progDialog->wasCanceled() == true) return;

	if (reply->error() == QNetworkReply::NoError)
	{
		QByteArray ba = reply->readAll();
		QJsonParseError jsonpe;
		QJsonDocument json = QJsonDocument::fromJson(ba, &jsonpe);

		if (jsonpe.error == QJsonParseError::NoError)
		{
			QJsonArray rootArray = json.array();

			for (int i = 0; i < rootArray.count(); i++)
			{
				QJsonObject oribtObj = rootArray.at(i).toObject();

				// 轨道信息
				OrbitInfo orbitInfo;
				orbitInfo.ParentDescription = oribtObj["parentDescription"].toString();
				orbitInfo.MainClassId = oribtObj["mainClassId"].toString();
				orbitInfo.ParentId = oribtObj["parentId"].toString();

				// 子信息
				QJsonArray childInfoArray = oribtObj["childInfo"].toArray();

				for (int k = 0; k < childInfoArray.count(); k++)
				{
					QJsonObject childInfoObj = childInfoArray.at(k).toObject();

					OrbitChildInfo childInfo;

					childInfo.Description = childInfoObj["description"].toString();
					childInfo.Pid = childInfoObj["pid"].toString();
					childInfo.Id = childInfoObj["_id"].toString();

					orbitInfo.ChildInfos.push_back(childInfo);
				}

				oribtInfos.push_back(orbitInfo);
			}
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
}

QList<LoadEquipment> SatelliteSim::getSatelliteLoadEquipmentByID(QString url, int sateID, QProgressDialog* progDialog)
{
	QString urlFull = QString("%1/%2").arg(url).arg(sateID);
	QNetworkAccessManager manager;
	QNetworkRequest req;
	req.setUrl(QUrl(urlFull));
	req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json;charset=UTF-8");
	QNetworkReply* reply = manager.post(req, "");
	QEventLoop eventLoop;
	connect(&manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
	connect(progDialog, SIGNAL(canceled), &eventLoop, SLOT(quit()));
	eventLoop.exec();

	QList<LoadEquipment> loadEquipments;

	if (progDialog->wasCanceled() == true) return loadEquipments;

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
			QMessageBox::information(this, "错误", jsonpe.errorString(), QMessageBox::Ok);
		}
	}
	else
	{
		QMessageBox::information(this, "错误", reply->errorString(), QMessageBox::Ok);
	}

	return loadEquipments;
}

QList<LoadEquipment> SatelliteSim::getSatelliteLoadEquipmentByName(QString url, QString name, QProgressDialog* progDialog)
{
	QString urlFull = QString("%1/%2").arg(url).arg(name);
	QNetworkAccessManager manager;
	QNetworkRequest req;
	req.setUrl(QUrl(urlFull));
	req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json;charset=UTF-8");
	QNetworkReply* reply = manager.post(req, "");
	QEventLoop eventLoop;
	connect(&manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
	connect(progDialog, SIGNAL(canceled), &eventLoop, SLOT(quit()));
	eventLoop.exec();

	QList<LoadEquipment> loadEquipments;

	if (progDialog->wasCanceled() == true) return loadEquipments;

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
			QMessageBox::information(this, "错误", jsonpe.errorString(), QMessageBox::Ok);
		}
	}
	else
	{
		QMessageBox::information(this, "错误", reply->errorString(), QMessageBox::Ok);
	}

	return loadEquipments;
}

QList<LoadEquipment> SatelliteSim::getAllPayloadList(QString url, QProgressDialog* progDialog)
{
	QNetworkAccessManager manager;
	QNetworkRequest req;
	req.setUrl(QUrl(url));
	req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json;charset=UTF-8");
	QNetworkReply* reply = manager.post(req, "");
	QEventLoop eventLoop;
	connect(&manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
	connect(progDialog, SIGNAL(canceled), &eventLoop, SLOT(quit()));
	eventLoop.exec();

	QList<LoadEquipment> loadEquipments;

	if (progDialog->wasCanceled() == true) return loadEquipments;

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
			QMessageBox::information(this, "错误", jsonpe.errorString(), QMessageBox::Ok);
		}
	}
	else
	{
		QMessageBox::information(this, "错误", reply->errorString(), QMessageBox::Ok);
	}

	return loadEquipments;
}

// 根据载荷id删除载荷设备
bool SatelliteSim::deletePayloadByID(QString url,
	int deviceId,
	QProgressDialog* progDialog)
{
	QString urlFull = QString("%1/%2").arg(url).arg(deviceId);
	QNetworkAccessManager manager;
	QNetworkRequest req;
	req.setUrl(QUrl(urlFull));
	req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json;charset=UTF-8");
	QNetworkReply* reply = manager.post(req, "");
	QEventLoop eventLoop;
	connect(&manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
	connect(progDialog, SIGNAL(canceled), &eventLoop, SLOT(quit()));
	eventLoop.exec();

	QList<LoadEquipment> loadEquipments;

	if (progDialog->wasCanceled() == true) return false;

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
				QMessageBox::information(this, "错误", "删除失败", QMessageBox::Ok);

				return true;
			}
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

	return false;
}

// 增加载荷接口
bool SatelliteSim::insertPayload(QString url,
	QString deviceId,
	QString satelliteId,
	QString deviceName,
	QString deviceNum,
	QProgressDialog* progDialog)
{
	QString urlFull = QString("%1").arg(url).arg(deviceId);
	QNetworkAccessManager manager;
	QNetworkRequest req;
	req.setUrl(QUrl(urlFull));
	req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json;charset=UTF-8");

	QString para = QString("{\"deviceId\":\"%1\",\"satelliteId\":\"%2\",\"deviceName\":\"%3\",\"deviceNum\":\"%4\"").arg(deviceId).arg(satelliteId).arg(deviceName).arg(deviceNum);
	QNetworkReply* reply = manager.post(req, para.toUtf8());
	QEventLoop eventLoop;
	connect(&manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
	connect(progDialog, SIGNAL(canceled), &eventLoop, SLOT(quit()));
	eventLoop.exec();

	QList<LoadEquipment> loadEquipments;

	if (progDialog->wasCanceled() == true) return false;

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
				QMessageBox::information(this, "错误", "删除失败", QMessageBox::Ok);

				return true;
			}
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

	return false;
}

/**
* @brief 从服务查询
* @return
*/
void SatelliteSim::queryFromService(QString url, std::vector<SatelliteInfo>& sateInfos)
{
	// 显示加载进度
	QProgressDialog progDialog("正在连接服务...", "取消", 0, 100, this);
	progDialog.setWindowTitle("连接中");

	QProgressBar bar;
	progDialog.setBar(&bar);
	bar.setVisible(false);
	progDialog.setWindowModality(Qt::WindowModal);
	progDialog.show();

	std::vector<OrbitInfo> orbitInfos;

	getSatelliteLoadEquipmentByID(url + "/getSatelliteLoadEquipmentByID", 1, &progDialog);

	getOribtByType(url + "/getSatelliteCategoriesForGUI", orbitInfos, &progDialog);

	getSatelliteByType(url + "/getSatelliteByType", sateInfos, orbitInfos, &progDialog);

	progDialog.setValue(100);
}

/**
* @brief 检索通信卫星
* @return
*/
void SatelliteSim::slotQueryCommuSatellite()
{
	ui.treeWidgetObjects->clear();
	m_sateTreeItemMap.clear();

	for (int i = 0; i < m_coes.count(); i++)
	{
		COE_ELEMENT* coe = m_coes[i];

		if (coe->type == COE_TYPE::GLONASS)
		{
			addTreeItem(coe);
		}
	}
}

/**
* @brief 检索导航卫星
* @return
*/
void SatelliteSim::slotQueryNaviSatellite()
{
	ui.treeWidgetObjects->clear();
	m_sateTreeItemMap.clear();

	for (int i = 0; i < m_coes.count(); i++)
	{
		COE_ELEMENT* coe = m_coes[i];

		if (coe->type == COE_TYPE::GALILEO ||
			coe->type == COE_TYPE::BEIDOU)
		{
			addTreeItem(coe);
		}
	}
}

/**
* @brief 检索遥感卫星
* @return
*/
void SatelliteSim::slotQueryRemoteSatellite()
{
	ui.treeWidgetObjects->clear();
	m_sateTreeItemMap.clear();

	for (int i = 0; i < m_coes.count(); i++)
	{
		COE_ELEMENT* coe = m_coes[i];

		if (coe->type == COE_TYPE::REMOTE)
		{
			addTreeItem(coe);
		}
	}
}

/**
* @brief 检索低轨卫星
* @return
*/
void SatelliteSim::slotQueryLowOrbit()
{
	ui.treeWidgetObjects->clear();
	m_sateTreeItemMap.clear();

	for (int i = 0; i < m_coes.count(); i++)
	{
		COE_ELEMENT* coe = m_coes[i];

		if (coe->orbitType == ORBIT_TYPE::LOW)
		{
			addTreeItem(coe);
		}
	}
}

/**
* @brief 检索中轨卫星
* @return
*/
void SatelliteSim::slotQueryMidOrbit()
{
	ui.treeWidgetObjects->clear();
	m_sateTreeItemMap.clear();

	for (int i = 0; i < m_coes.count(); i++)
	{
		COE_ELEMENT* coe = m_coes[i];

		if (coe->orbitType  == ORBIT_TYPE::MIDDLE )
		{
			addTreeItem(coe);
		}
	}
}

/**
* @brief 检索高轨卫星
* @return
*/
void SatelliteSim::slotQueryHighOrbit()
{
	ui.treeWidgetObjects->clear();
	m_sateTreeItemMap.clear();

	for (int i = 0; i < m_coes.count(); i++)
	{
		COE_ELEMENT* coe = m_coes[i];

		if (coe->orbitType == ORBIT_TYPE::HIGH)
		{
			addTreeItem(coe);
		}
	}
}

#include "AddRadarStationDialog.h"
#include <osgEarthAnnotation/ModelNode>

using namespace osgEarth::Annotation;

osg::PositionAttitudeTransform* addModel(osg::Vec3d position)
{
	osg::PositionAttitudeTransform* pat = new osg::PositionAttitudeTransform();
	pat->setPosition(position);
	pat->setName("Model");
	//pat->setAttitude(HPRToQuat(osg::DegreesToRadians(0.0), osg::DegreesToRadians(90.0), osg::DegreesToRadians(0.0)));

	osgDB::Options* option = new osgDB::Options(std::string("noTriStripPolygons noRotation"));

	QDir dir(qApp->applicationDirPath());
	dir.cdUp();
	dir.cd("data");

	osg::Node* sat = osgDB::readNodeFile(std::string(dir.absolutePath().toLocal8Bit()) + "/dish.obj", option);
	sat->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::ON);
	sat->getOrCreateStateSet()->setMode(GL_RESCALE_NORMAL, osg::StateAttribute::ON);
	sat->getOrCreateStateSet()->setMode(GL_LIGHT0, osg::StateAttribute::ON);

	osg::BoundingSphere boundSphere = sat->getBound();
	
	osg::ref_ptr<osg::Light> pLight = new osg::Light();

	pLight->setPosition(osg::Vec4(boundSphere.center().x(), boundSphere.center().y(), boundSphere.center().z() + boundSphere.radius(), 0.1f));
	
	// local light
	pLight->setLightNum(0);
	pLight->setDirection(osg::Vec3(1.0, 1.0, -1.0));
	//pLight->setPosition(osg::Vec4(0.0, -2.0, 0.0, 0.0));
	pLight->setDiffuse(osg::Vec4(1.0, 1.0, 1.0, 1.0));
	pLight->setConstantAttenuation(1.0);
	pLight->setLinearAttenuation(0.0);
	pLight->setQuadraticAttenuation(0.0);

	//pLight->setAmbient(osg::Vec4(1.0, 1.0, 1.0, 1.0));
	//pLight->setSpotCutoff(20.0f);
	//pLight->setSpotExponent(50.0f);
	
	osg::ref_ptr<osg::LightSource> pLightSource = new osg::LightSource;
	pLightSource->setLight(pLight.get());
	pLightSource->setLocalStateSetModes(osg::StateAttribute::ON);

	//osg::MatrixTransform* mt = new osg::MatrixTransform();
	//rotateMT->setMatrix(osg::Matrix::rotate(osg::DegreesToRadians(180.0f), 0.0f, 0.0f, 1.0f));
	//mt->addChild(sat);

	pat->setScale(osg::Vec3(100, 100, 100));
	//pat->setAttitude(osg::Quat(roll, osg::Vec3d(1, 0, 0), pitch, osg::Vec3d(0, 1, 0), yaw, osg::Vec3d(0, 0, 1)));
	//pat->addChild(addAxis(100));
	pat->addChild(sat);
	pat->addChild(pLightSource.get());

	return pat;
}

/**
* @brief 添加地面雷达站
* @return
*/
void SatelliteSim::slotAddGroundRadarStation()
{
	AddRadarStationDialog dialog(this);

	if (dialog.exec())
	{
		osg::Vec3d world;
		osg::EllipsoidModel* em = new osg::EllipsoidModel();
		//Lat纬度Long经度
		em->convertLatLongHeightToXYZ(osg::DegreesToRadians(dialog.getLat()),
			osg::DegreesToRadians(dialog.getLon()), dialog.getHei(), world.x(), world.y(), world.z());

		m_Root->addChild(addModel(world));
		//QDir dir(qApp->applicationDirPath());
		//dir.cdUp();
		//dir.cd("data");

		//osg::Node* model = osgDB::readNodeFile(std::string(dir.absolutePath().toLocal8Bit()) + "/dish2.obj", );

		//osg::MatrixTransform* mt = new osg::MatrixTransform();
		//mt->setMatrix(osg::Matrix::scale(100000, 100000, 100000));
		//mt->addChild(model);

		//const SpatialReference* latLong = SpatialReference::get("wgs84");
		//Style style;
		//style.getOrCreate<ModelSymbol>()->setModel(mt);

		GeoPoint point;
		point.x() = dialog.getLon();
		point.y() = dialog.getLat();
		point.z() = dialog.getHei();

		//ModelNode* node = new ModelNode(m_MapNode, style);
		//node->setPosition(point);

		//m_MapNode->addChild(node);

		osgEarth::Viewpoint currViewpoint = m_EarthManipulator->getViewpoint();
		osgEarth::Viewpoint vp("vp_radar_station", point.x(),
			point.y(),
			point.z() * 1.1,
			currViewpoint.getHeading(),
			currViewpoint.getPitch(),
			point.z() * 10);

		m_EarthManipulator->setViewpoint(vp, 1.0);
	}
}

#include "RegionalPlanningWidget.h"
void SatelliteSim::slotRegionalPlanning()
{
	//QMessageBox::information(this, "dfdfd", "ererer");
	RegionalPlanningWidget* slw = new RegionalPlanningWidget();

	connect(slw, SIGNAL(signalShowSimpleSateScene()), this, SLOT(slotShowSimpleSateScene()));
	slw->show();
}

void SatelliteSim::slotShowSimpleSateScene()
{
	// 通过接口2发送请求，后台进行任务分解返回前端
	//［（卫星1id，开始拍照时间，结束拍照时间，该卫星拍摄区域坐标：也就是子任务）.....］，
	// 前端在开始结束时间区间内显示扫描柱体。
	//QMessageBox::information(this, QStringLiteral("调用接口"), QStringLiteral("通过接口2发送请求，后台进行任务分解返回前端。"));

	if (g_tabBar->count() >= 2)
	{
		g_tabBar->setCurrentIndex(1);
		g_stackedWidget->setCurrentIndex(1);
		return;
	}

	this->addSimpleSateWidget();

	if (g_tabBar->count() >= 2)
	{
		g_tabBar->setCurrentIndex(1);
		g_stackedWidget->setCurrentIndex(1);
	}
}

// 卫星列表化
#include "SatelliteListWidget.h"
void SatelliteSim::slotSatelliteList()
{
	SatelliteListWidget* widget = new SatelliteListWidget(this);
	//widget->setWindowModality(Qt::WindowModality::ApplicationModal);
	widget->exec();
}

// 载荷列表化
#include "LoadequipListWidget.h"
void SatelliteSim::slotLoadEquipmentList()
{
	LoadequipListWidget* widget = new LoadequipListWidget(this);
	widget->exec();
}

void SatelliteSim::slotTreeItemPressed(QTreeWidgetItem* pressedItem, int column)
{
	if (qApp->mouseButtons() == Qt::RightButton)
	{
		QMenu* menu = new QMenu(ui.treeWidgetObjects);
		QAction* actionSateInfo = menu->addAction("卫星信息");
		QAction* actionConfigManage = menu->addAction("配置管理");

		connect(actionSateInfo, SIGNAL(triggered()), this, SLOT(slotSatelliteInfo()));
		connect(actionConfigManage, SIGNAL(triggered()), this, SLOT(slotConfigManage()));
		menu->exec(QCursor::pos());
	}
}

// 卫星信息
#include "DetailedInformationDialog.h"
void SatelliteSim::slotSatelliteInfo()
{
	QTreeWidgetItem* item = ui.treeWidgetObjects->currentItem();
	if (item->parent() == nullptr) return;

	COE_ELEMENT* element = (COE_ELEMENT*)item->data(0, Qt::UserRole + 1).value<void*>();

	double semimajorAxis, eccentricity, inclination, argumentOfPerigee, longitudeOfTheAscendingNode, meanAnomaly;
	element->sateModel->getUserValue("SemimajorAxis", semimajorAxis);				// 长半轴
	element->sateModel->getUserValue("Eccentricity", eccentricity);					// 偏心率
	element->sateModel->getUserValue("Inclination", inclination);					// 轨道倾角
	element->sateModel->getUserValue("ArgumentOfPerigee", argumentOfPerigee);	// 近地点幅角
	element->sateModel->getUserValue("LongitudeOfTheAscendingNode", longitudeOfTheAscendingNode);	// 升交点赤经
	element->sateModel->getUserValue("MeanAnomaly", meanAnomaly);							// 平近点角

	double roll, pitch, yaw;
	element->sateModel->getUserValue("Roll", roll);	// 翻滚角
	element->sateModel->getUserValue("Pitch", pitch);	// 俯仰角
	element->sateModel->getUserValue("Yaw", yaw);		// 偏航角

	//element->iNumber = result.value("internationalNumber").toString();
	//element->status = result.value("satellitestatus").toString();
	//element->launchSite = result.value("launchSite").toString();
	//element->launchNumber = result.value("launchNumber").toInt();
	//element->launchDate = result.value("launchDate").toString();

	// 新的详细信息对话框
	DetailedInformationDialog* widget = new DetailedInformationDialog(element);
	widget->setName(element->name);
	widget->setInternationalNumber(element->iNumber);
	widget->setLaunchSite(element->launchSite);
	widget->setLaunchNumber(QString("%1").arg(element->launchNumber));
	widget->setLaunchDate(element->launchDate);
	widget->setLongitudeOfTheAscendingNode(longitudeOfTheAscendingNode);
	widget->setInclination(inclination);
	widget->setSemimajorAxis(semimajorAxis);
	widget->setEccentricity(eccentricity);
	widget->setArgumentOfPerigee(argumentOfPerigee);
	widget->setRoll(roll);
	widget->setPitch(pitch);
	widget->setYaw(yaw);
	widget->setWindowModality(Qt::WindowModality::ApplicationModal);
	widget->show();
}

#include "ConfigManageDialog.h"
void SatelliteSim::slotConfigManage()
{
	QTreeWidgetItem* item = ui.treeWidgetObjects->currentItem();
	if (item->parent() == nullptr) return;

	COE_ELEMENT* element = (COE_ELEMENT*)item->data(0, Qt::UserRole + 1).value<void*>();

	ConfigManageDialog* dialog = new ConfigManageDialog(element, this);
	dialog->exec();
}

#include "AddLoadequipDialog.h"
// 新建载荷
void SatelliteSim::slotLoadEquipment()
{
	AddLoadequipDialog dialog;
	dialog.exec();
}