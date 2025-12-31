#include "osgViewerWidget.h"
#include <QWidget>
#include <QWindow>
#include <QApplication>
#include <osgViewer/ViewerEventHandlers>
#include <QScreen>
#include <QGridLayout>
#include <osgEarthUtil/EarthManipulator>
#include "Common.h"
#include <QDateTime>
#include "pickHandler.h"

/**
* @brief 构造函数
* @return
*/
osgViewerWidget::osgViewerWidget(QTreeWidget* treeWidget, QWidget* parent, osg::Node* scene, Qt::WindowFlags f, osgViewer::ViewerBase::ThreadingModel threadingModel)
	: QWidget(parent, f),
	_bShow(true),
	_treeObjects(treeWidget)
{
	setThreadingModel(threadingModel);

	setKeyEventSetsDone(0);

	QWidget* widget1 = addViewWidget(createGraphicsWindow(0, 0, 100, 100), _scene = scene);
	//QWidget* widget2 = addViewWidget(createGraphicsWindow(0, 0, 100, 100), _scene = scene);
	widget1->show();

	QGridLayout* grid = new QGridLayout;
	grid->addWidget(widget1, 0, 0);
	setLayout(grid);

	grid->setMargin(1);

	connect(&_timer, SIGNAL(timeout()), this, SLOT(update()));
	_timer.start(10);
}

/**
* @brief 析构函数
* @return
*/
osgViewerWidget::~osgViewerWidget()
{

}

#include <osgGA/StateSetManipulator>
/**
* @brief 把OSG窗体加入到QT中
* @return
*/
QWidget* osgViewerWidget::addViewWidget(osgQt::GraphicsWindowQt* gw, osg::ref_ptr<osg::Node> scene)
{
	osgViewer::View* view = new osgViewer::View;
	addView(view);

	osg::Camera* camera = view->getCamera();
	camera->setGraphicsContext(gw);

	const osg::GraphicsContext::Traits* traits = gw->getTraits();

	camera->setClearColor(osg::Vec4(0.4, 0.4, 0.4, 1.0));
	camera->setViewport(new osg::Viewport(0, 0, traits->width, traits->height));

	// set the draw and read buffers up for a double buffered window with rendering going to back buffer
	camera->setDrawBuffer(GL_BACK);
	camera->setReadBuffer(GL_BACK);

	camera->setProjectionMatrixAsPerspective(30.0f, static_cast<double>(traits->width) / static_cast<double>(traits->height), 1.0f, 10000.0f);

	view->setSceneData(scene);
	view->addEventHandler(new osgViewer::StatsHandler);
	//view->addEventHandler(new osgViewer::WindowSizeHandler);
	view->addEventHandler(new pickHandler(this->_treeObjects));
	view->setCameraManipulator(new osgEarth::Util::EarthManipulator());
	//view->addEventHandler(new osgGA::StateSetManipulator(view->getCamera()->getOrCreateStateSet()));

	return gw->getGLWidget();
}

/**
* @brief 创建OSG窗体
* @return
*/
osgQt::GraphicsWindowQt* osgViewerWidget::createGraphicsWindow(int x, int y, int w, int h, const std::string& name, bool windowDecoration)
{
	osg::DisplaySettings* ds = osg::DisplaySettings::instance().get();
	osg::ref_ptr<osg::GraphicsContext::Traits> traits = new osg::GraphicsContext::Traits;
	traits->windowName = name;
	traits->windowDecoration = windowDecoration;
	traits->x = x;
	traits->y = y;
	traits->width = w;
	traits->height = h;
	traits->doubleBuffer = true;
	traits->alpha = ds->getMinimumNumAlphaBits();
	traits->stencil = ds->getMinimumNumStencilBits();
	traits->sampleBuffers = ds->getMultiSamples();
	traits->samples = 8/*ds->getNumMultiSamples()*/;

	return new osgQt::GraphicsWindowQt(traits.get());
}

/**
* @brief 重载advance函数，刷新显示时间
* @return
*/
void osgViewerWidget::advance(double simulationTime)
{
	osgViewer::CompositeViewer::advance();

	for (int i = 0; i < _scene->asGroup()->getNumChildren(); i++)
	{
		if ("TimeHUD" == _scene->asGroup()->getChild(i)->getName())
		{
			_scene->asGroup()->removeChild(i);
			//break;
		}
	}
	

	//显示程序运行时间
	wchar_t  buffer[200];
	swprintf(buffer, L"当前时间:%i-%i-%i %i:%i:%i\n", QDateTime::currentDateTime().date().year(), 
		QDateTime::currentDateTime().date().month(),
		QDateTime::currentDateTime().date().day(),
		QDateTime::currentDateTime().time().hour(),
		QDateTime::currentDateTime().time().minute(),
		QDateTime::currentDateTime().time().second());
	_scene->asGroup()->addChild(addHUD(buffer, osg::Vec3(0.0f, 10.0f, 0.0f)));
}

#include "ribbonwindow.h"
void osgViewerWidget::resizeEvent(QResizeEvent *event)
{
	if (this->parent())
	{
		RibbonWindow* parentWindow = dynamic_cast<RibbonWindow*>(this->parent());
		
		if (parentWindow)
		{
			parentWindow->resize(parentWindow->size());
		}
	}

	Q_EMIT signalResizeEvent(event);
}