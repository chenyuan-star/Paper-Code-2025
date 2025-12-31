#ifndef PICKHANDLER_H
#define PICKHANDLER_H

#include <osg/Node>
#include <osgViewer/Viewer>
#include <QTreeWidget>

class pickHandler : public osgGA::GUIEventHandler
{
public:
	pickHandler(QTreeWidget* treeWidget);

public:
	/** Deprecated, Handle events, return true if handled, false otherwise. */
	virtual bool handle(const osgGA::GUIEventAdapter& guiEventAdapter, osgGA::GUIActionAdapter& guiActionAdapter);

protected:
	bool pick(const double x, const double y, osgViewer::View *pView, osg::Vec3dArray *pVec3dArrayOut);
	osg::Vec3d screen2Word(osg::Vec3d screenVec3d, osgViewer::View *pViewer);

private:
	float _scale;   // 保存当前相对于原始比例的缩放系数
	bool _pickEarth;
	osg::Vec3d _originVec3d;
	osg::Vec3d _lastVec3d;

	QTreeWidget* _treeObjects;
};

#endif	//PICKHANDLER_H