#ifndef OSGVIEWERWIDGET_H
#define OSGVIEWERWIDGET_H

#include <QObject>
#include <osg/Node>
#include <osgViewer/ViewerBase>
#include <osgViewer/CompositeViewer>
#include <osgQt/GraphicsWindowQt>
#include <QTimer>
#include <QTreeWidget>

/**
* @brief OSG显示窗体
* @return
*/
class osgViewerWidget : public QWidget, public osgViewer::CompositeViewer
{
	Q_OBJECT

public:
	osgViewerWidget(QTreeWidget* treeWidget, QWidget* parent = 0, osg::Node* scene = 0L, Qt::WindowFlags f = 0, osgViewer::ViewerBase::ThreadingModel threadingModel = osgViewer::CompositeViewer::SingleThreaded);
	~osgViewerWidget();

	/**
	* @brief 获取View
	* @return
	*/
	osgViewer::View* getViewer() { return this->getView(0); }

Q_SIGNALS:
	void signalResizeEvent(QResizeEvent *event);

protected:
	/**
	* @brief 把OSG窗体加入到QT中
	* @return
	*/
	QWidget* addViewWidget(osgQt::GraphicsWindowQt* gw, osg::ref_ptr<osg::Node> scene);

	/**
	* @brief 创建OSG窗体
	* @return
	*/
	osgQt::GraphicsWindowQt* createGraphicsWindow(int x, int y, int w, int h, const std::string& name = "", bool windowDecoration = false);

	/**
	* @brief 刷新QT窗体时绘制OSG
	* @return
	*/
	virtual void paintEvent(QPaintEvent* /*event*/)
	{
		if (_bShow == true)
		{
			frame();
		}
	}

	virtual void resizeEvent(QResizeEvent *event);

	/**
	* @brief 重载advance函数，刷新显示时间
	* @return
	*/
	virtual void advance(double simulationTime = USE_REFERENCE_TIME);

private:
	QTimer _timer;
	bool _bShow;
	osg::Node*	_scene;

	QTreeWidget*	_treeObjects;
};

#endif // OSGVIEWERWIDGET_H
