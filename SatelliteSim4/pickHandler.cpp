#include "pickHandler.h"
#include "osg/MatrixTransform"
#include <QtMath>

/**
* @brief 构造函数
* @return
*/
pickHandler::pickHandler(QTreeWidget* treeWidget)
	: osgGA::GUIEventHandler(),
	_scale(1.0),
	_pickEarth(false),
	_treeObjects(treeWidget)
{
}

/**
* @brief 事件处理
* @return
*/
bool pickHandler::handle(const osgGA::GUIEventAdapter
	&guiEventAdapter, osgGA::GUIActionAdapter &guiActionAdapter)
{
	bool flag = false;
	// 获取viwerer
	osg::ref_ptr<osgViewer::View> pView = dynamic_cast<osgViewer::View*>(&guiActionAdapter);
	if (!pView)
	{
		return false;
	}

	osg::ref_ptr<osg::Group> pGroup = pView->getSceneData()->asGroup();
	if (!pGroup)
	{
		return false;
	}

	osg::Vec3d eyeVect3D;
	osg::Vec3d centerVect3D;
	osg::Vec3d upVect3D;

	osg::Vec3d vec3d;
	osg::ref_ptr<osg::Vec3dArray> pVec3dArray = new osg::Vec3dArray();
	qreal offsetAngle;
	switch (guiEventAdapter.getEventType())
	{
	case osgGA::GUIEventAdapter::EventType::PUSH:
		switch (guiEventAdapter.getButton())
		{
		case osgGA::GUIEventAdapter::LEFT_MOUSE_BUTTON:
			pick(guiEventAdapter.getX(), guiEventAdapter.getY(), pView, pVec3dArray.get());
			break;
		default:
			break;
		}
		break;
	case osgGA::GUIEventAdapter::EventType::RELEASE:
		_pickEarth = false;
		break;

	default:
		break;
	}

	return false;
}

/**
* @brief 拾取函数
* @return
*/
bool pickHandler::pick(const double x, const double y, osgViewer::View *pViewer, osg::Vec3dArray *pVec3dArrayOut)
{
	bool ret = false;
	// 判断场景
	if (!pViewer->getSceneData())
	{
		return false;
	}
	// 判断是否拾取到物体
	osgUtil::LineSegmentIntersector::Intersections intersections;
	if (pViewer->computeIntersections(x, y, intersections))
	{
		for (auto iter = intersections.begin(); iter != intersections.end(); iter++)
		{
			const osgUtil::LineSegmentIntersector::Intersection& intersection = *iter;

			// 拾取路径
			osg::NodePath nodePath = intersection.nodePath;

			// 找到卫星节点
			osg::Node* pSate = NULL;

			for (int i = nodePath.size() - 1; i >= 0; --i)
			{
				std::string type;
				nodePath[i]->getUserValue("Type", type);

				if (type != "Satellite") continue;

				// 地形节点
				pSate = dynamic_cast<osg::Node*>(nodePath[i]);
				break;
			}

			if (pSate == NULL) continue;
			//pVec3dArrayOut->push_back(iter->getWorldIntersectPoint());

			std::string name;
			pSate->getUserValue("Name", name);

			// 设置树节点选中
			QTreeWidgetItemIterator it(_treeObjects);
			while (*it) 
			{
				QString text = (*it)->text(0);
				if (text == QString("%1").arg(name.c_str()))
				{
					_treeObjects->setCurrentItem((*it));
					break;
				}
				++it;
			}

			ret = true;
			break;
		}
	}
	return ret;
}

/**
* @brief 屏幕坐标转世界坐标
* @return
*/
osg::Vec3d pickHandler::screen2Word(osg::Vec3d screenVec3d, osgViewer::View *pViewer)
{
	osg::ref_ptr<osg::Camera> pCamera = pViewer->getCamera();
	osg::Matrix matrix = pCamera->getViewMatrix() *
		pCamera->getProjectionMatrix() *
		pCamera->getViewport()->computeWindowMatrix();
	osg::Matrix intertMatrix = osg::Matrix::inverse(matrix);
	osg::Vec3d worldVec3d = screenVec3d * intertMatrix;
	return worldVec3d;
}