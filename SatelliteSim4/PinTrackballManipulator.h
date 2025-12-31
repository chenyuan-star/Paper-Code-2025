#ifndef PIN_TRACKBALL_MANIPULATOR
#define PIN_TRACKBALL_MANIPULATOR

#include <osgGA/OrbitManipulator>

using namespace osgGA;

class PinTrackballManipulator : public OrbitManipulator
{
	typedef OrbitManipulator inherited;

protected:
	virtual bool setCenterByMousePointerIntersection(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& us);

public:

	PinTrackballManipulator(int flags = DEFAULT_SETTINGS);
	PinTrackballManipulator(const PinTrackballManipulator& tm,
		const osg::CopyOp& copyOp = osg::CopyOp::SHALLOW_COPY);

	META_Object(osgGA, PinTrackballManipulator);

};


#endif	//PIN_TRACKBALL_MANIPULATOR