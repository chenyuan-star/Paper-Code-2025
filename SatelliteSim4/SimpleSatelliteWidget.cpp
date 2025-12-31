#include "SimpleSatelliteWidget.h"
#include <osgEarthUtil/Sky>
#include <QDateTime>
#include <QApplication>
#include <osgEarth/GLUtils>
#include <QHBoxLayout>

SimpleSatelliteWidget::SimpleSatelliteWidget(QWidget *parent)
	: QWidget(parent)
{
	//setWindowFlags(windowFlags() | Qt::Dialog);
	//setWindowModality(Qt::ApplicationModal);

	this->resize(QSize(800, 600));
	initialEarth();

	// 3：到柱体扫描结束时间，也就认为该颗卫星拍照完成，可以从后端获取该星的拍照结果


}

SimpleSatelliteWidget::~SimpleSatelliteWidget()
{
}

void SimpleSatelliteWidget::initialEarth()
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
	m_viewerWidget = new osgViewerWidget(nullptr, this, m_Root, Qt::Widget, threadingModel);
	m_mainViewer = m_viewerWidget->getViewer();

	// UI
	//Grid* grid = new Grid();
	//grid->setHorizAlign(Control::ALIGN_RIGHT);
	//grid->setVertAlign(Control::ALIGN_CENTER);
	//grid->setBackColor(osg::Vec4d(0.3, 0.3, 0.3, 0.0));
	////设置几个Label文字控件显示在场景中的第行
	//grid->setControl(0, 0, new LabelControl("ID:"));
	//grid->setControl(0, 1, new LabelControl("Name:"));
	//grid->setControl(0, 2, new LabelControl("INumber:"));
	//grid->setControl(0, 3, new LabelControl("Status:"));
	//grid->setControl(0, 4, new LabelControl("Lon:"));
	//grid->setControl(0, 5, new LabelControl("Lat:"));
	//grid->setControl(0, 6, new LabelControl("Pitch:"));
	//grid->setControl(0, 7, new LabelControl("Yaw:"));
	//grid->setControl(0, 8, new LabelControl("Roll:"));
	//grid->setControl(0, 9, new LabelControl("a:"));
	//grid->setControl(0, 10, new LabelControl("e:"));
	//grid->setControl(0, 11, new LabelControl("i:"));
	//grid->setControl(0, 12, new LabelControl("omega:"));
	//grid->setControl(0, 13, new LabelControl("w:"));
	//grid->setControl(0, 14, new LabelControl("m:"));
	//grid->setControl(0, 15, new LabelControl("LaunchSite:"));
	//grid->setControl(0, 16, new LabelControl("LaunchNumber:"));
	//grid->setControl(0, 17, new LabelControl("LaunchDate:"));

	//设置几个Label文字控件显示在场景中的第行
	//s_nameLabel->setEncoding(osgText::String::ENCODING_UTF8);//设置本地编码

	//string allStrUtf8;
	//gb2312ToUtf8("卫星编号", allStrUtf8);//字体转换

	//s_idLabel = grid->setControl(1, 0, new LabelControl(""));
	//s_nameLabel = grid->setControl(1, 1, new LabelControl(""));
	//s_iNumberLabel = grid->setControl(1, 2, new LabelControl(""));
	//s_statusLabel = grid->setControl(1, 3, new LabelControl(""));
	//s_lonLabel = grid->setControl(1, 4, new LabelControl(""));
	//s_latLabel = grid->setControl(1, 5, new LabelControl(""));
	//s_pitchLabel = grid->setControl(1, 6, new LabelControl(""));
	//s_yawLabel = grid->setControl(1, 7, new LabelControl(""));
	//s_rollLabel = grid->setControl(1, 8, new LabelControl(""));
	//s_aLabel = grid->setControl(1, 9, new LabelControl(""));
	//s_eLabel = grid->setControl(1, 10, new LabelControl(""));
	//s_iLabel = grid->setControl(1, 11, new LabelControl(""));
	//s_omegaLabel = grid->setControl(1, 12, new LabelControl(""));
	//s_wLabel = grid->setControl(1, 13, new LabelControl(""));
	//s_mLabel = grid->setControl(1, 14, new LabelControl(""));
	//s_launchSiteLabel = grid->setControl(1, 15, new LabelControl(""));
	//s_launchNumberLabel = grid->setControl(1, 16, new LabelControl(""));
	//s_launchDateLabel = grid->setControl(1, 17, new LabelControl(""));

	//ControlCanvas* canvas = ControlCanvas::get(m_ViewerWidget->getViewer());
	//m_Root->addChild(canvas);
	//canvas->addControl(grid);

	m_pSkyNode->attach(m_mainViewer, 0);

	m_pSkyNode->setAtmosphereVisible(true);
	m_pSkyNode->setSunVisible(true);
	m_pSkyNode->setMoonVisible(true);
	m_pSkyNode->getSunLight()->setConstantAttenuation(1.0);
	m_pSkyNode->getSunLight()->setLinearAttenuation(0.0);
	m_pSkyNode->getSunLight()->setQuadraticAttenuation(0.0);
	m_pSkyNode->getSunLight()->setSpotExponent(0.0);
	m_pSkyNode->getSunLight()->setSpotCutoff(0.0);

	m_pSkyNode->setMinimumAmbient(osg::Vec4(0.1f, 1.0f, 1.0f, 1.0f));

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
	m_mainViewer->setCameraManipulator(m_EarthManipulator);

	// 设置Camera
	osg::Camera* camera = m_mainViewer->getCamera();

	osg::GraphicsContext* pGC = camera->getGraphicsContext();

	if (!camera->getViewport())
	{
		camera->setViewport(new osg::Viewport(0, 0, pGC->getTraits()->width, pGC->getTraits()->height));
	}

	camera->setProjectionMatrixAsPerspective(30.0f, camera->getViewport()->width() / camera->getViewport()->height(), 1.0f, 10000.0f);
	camera->setNearFarRatio(0.00001);
	camera->setSmallFeatureCullingPixelSize(-1.0f);

	osgEarth::GLUtils::setGlobalDefaults(camera->getOrCreateStateSet());//osgearth2.10.1 添加后才可显示feature

	QHBoxLayout* layout = new QHBoxLayout();
	layout->setContentsMargins(0, 0, 0, 0);
	layout->addWidget(m_viewerWidget);
	this->setLayout(layout);
}


#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonParseError>
#include <QMessageBox>
#include <QBuffer>
#include <QImageReader>
#include <QJsonArray>

void SimpleSatelliteWidget::getSatellites(QString url, std::vector<SimpleSate>& sates)
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

		QJsonParseError jsonpe;
		QJsonDocument json = QJsonDocument::fromJson(ba, &jsonpe);

		if (jsonpe.error == QJsonParseError::NoError)
		{
			QJsonArray rootArray = json.array();

			// 卫星
			for (int k = 0; k < rootArray.count(); k++)
			{
				QJsonObject childInfoObj = rootArray.at(k).toObject();

				SimpleSate simpleSate;
				simpleSate.id = childInfoObj["_id"].toInt();
				simpleSate.startTime = childInfoObj["startTime"].toDouble();
				simpleSate.endTime = childInfoObj["startTime"].toDouble();

				sates.push_back(simpleSate);
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

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QProgressDialog>
#include "Common.h"

/**
* @brief 通过名称获取卫星信息
* @return
*/
bool SimpleSatelliteWidget::getSatelliteInfo(SatelliteInfo& info, QString name, std::vector<SatelliteInfo>& sateInfos)
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

void SimpleSatelliteWidget::getModelAndColor(QString name, QString& model, QColor& color)
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

#include <QSqlError>
/**
* @brief 读取数据库添加卫星
* @return
*/
void SimpleSatelliteWidget::slotAddSatelliteFromDB(std::vector<SatelliteInfo> sateInfos)
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

	QSqlQuery result = db.exec(" select * from satellites left join satelliteInfo on  satelliteInfo.id = satellites.id limit 10");
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
		//m_miniMap->addTrack(track);

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
		//addTreeItem(element);

		dialog.setValue(++index);
		qApp->processEvents();
	}

	m_EarthManipulator->home(0.5);
	//slotRealtimeChanged(true);

	printLog("从数据库添加了卫星。");
}