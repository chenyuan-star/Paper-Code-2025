#include "PinTrackballManipulator.h"
#include <osgUtil/LineSegmentIntersector>

using namespace osg;
using namespace osgUtil;

/// Constructor.
PinTrackballManipulator::PinTrackballManipulator(int flags)
	: inherited(flags)
{
	setVerticalAxisFixed(false);
}


/// Constructor.
PinTrackballManipulator::PinTrackballManipulator(const PinTrackballManipulator& tm, const CopyOp& copyOp)
	: osg::Object(tm, copyOp),
	osg::Callback(tm, copyOp),
	inherited(tm, copyOp)
{
}

bool PinTrackballManipulator::setCenterByMousePointerIntersection(const GUIEventAdapter& ea, GUIActionAdapter& us)
{
	osg::View* view = us.asView();
	if (!view)
		return false;

	Camera *camera = view->getCamera();
	if (!camera)
		return false;

	// prepare variables
	float x = (ea.getX() - ea.getXmin()) / (ea.getXmax() - ea.getXmin());
	float y = (ea.getY() - ea.getYmin()) / (ea.getYmax() - ea.getYmin());
	LineSegmentIntersector::CoordinateFrame cf;
	Viewport *vp = camera->getViewport();
	if (vp) {
		cf = Intersector::WINDOW;
		x *= vp->width();
		y *= vp->height();
	}
	else
		cf = Intersector::PROJECTION;

	// perform intersection computation
	ref_ptr< LineSegmentIntersector > picker = new LineSegmentIntersector(cf, x, y);
	IntersectionVisitor iv(picker.get());
	camera->accept(iv);

	// return on no intersections
	if (!picker->containsIntersections())
		return false;

	// get all intersections
	LineSegmentIntersector::Intersections& intersections = picker->getIntersections();

	// get current transformation
	osg::Vec3d eye, oldCenter, up;
	getTransformation(eye, oldCenter, up);

	// new center
	osg::Vec3d newCenter = (*intersections.begin()).getWorldIntersectPoint();

	// make vertical axis correction
	if (getVerticalAxisFixed())
	{

		CoordinateFrame coordinateFrame = getCoordinateFrame(newCenter);
		Vec3d localUp = getUpVector(coordinateFrame);

		fixVerticalAxis(newCenter - eye, up, up, localUp, true);

	}

	// set the new center
	setTransformation(eye, newCenter, up);


	// warp pointer
	// note: this works for me on standard camera on GraphicsWindowEmbedded and Qt,
	//       while it was necessary to implement requestWarpPointer like follows:
	//
	// void QOSGWidget::requestWarpPointer( float x, float y )
	// {
	//    osgViewer::Viewer::requestWarpPointer( x, y );
	//    QCursor::setPos( this->mapToGlobal( QPoint( int( x+.5f ), int( y+.5f ) ) ) );
	// }
	//
	// Additions of .5f are just for the purpose of rounding.
	centerMousePointer(ea, us);

	return true;
}