#include "SatelliteSim.h"
#include <QtWidgets/QApplication>
#include <QSurfaceFormat>
#include <osg/ShapeDrawable>
#include <osgViewer/Viewer>
#include "LoginDialog.h"
#include "RegionalPlanningWidget.h"
#include <QtnRibbonStyle.h>
#include <QtWebEngine>
#include <osg/State>

#define NEED_LOGIN 1

/**
* @brief Ö÷º¯Êý
* @return
*/
int main(int argc, char *argv[])
{
	QSurfaceFormat format = QSurfaceFormat::defaultFormat();

	//QCoreApplication::setAttribute(Qt::AA_UseOpenGLES);
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QCoreApplication::setAttribute(Qt::AA_ShareOpenGLContexts);

	format.setVersion(2, 0);
	format.setProfile(QSurfaceFormat::CompatibilityProfile);
	format.setRenderableType(QSurfaceFormat::OpenGL);
	format.setOption(QSurfaceFormat::DebugContext);

	format.setDepthBufferSize(24);
	format.setSamples(8);
	format.setStencilBufferSize(8);
	format.setSwapBehavior(QSurfaceFormat::DoubleBuffer);
	QSurfaceFormat::setDefaultFormat(format);

	osg::setNotifyLevel(osg::NotifySeverity::ALWAYS);

	QApplication a(argc, argv);
	a.setStyle(new RibbonStyle());

#if NEED_LOGIN
	LoginDialog dialog;
	if (dialog.exec() == QDialog::Accepted)
	{
		SatelliteSim w;
		w.show();
		return a.exec();
	}
	else
	{
		return 0;
	}
#else
	SatelliteSim* w = new SatelliteSim();
	w->show();

	//RegionalPlanningWidget* slw = new RegionalPlanningWidget();
	//slw->show();
	return a.exec();
#endif
}
