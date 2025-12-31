#ifndef OSGEARTHUTIL_EARTHAUTOCLIPPLANEHANDLER_H
#define OSGEARTHUTIL_EARTHAUTOCLIPPLANEHANDLER_H

#include <osgEarthUtil/Common>
#include <osgEarth/Containers>
#include <osgEarth/Utils>
#include <osgGA/GUIEventHandler>
#include <osgGA/EventVisitor>
#include <osg/Camera>

namespace osgEarth {
	class MapNode;
}

namespace osgEarth {
	namespace Util
	{
		using namespace osgEarth;

		/**
		* A CULL callback that automatically adjusts the calculated near and far clip planes for
		* use in a geocentric map.
		*
		* Usage: add this as a cull callback to a camera, like:
		*
		* osgViewer::Viewer viewer;
		* ...
		* viewer.getCamera()->addCullCallback( new AutoClipPlaneCallback(map) )
		*/
		class EarthAutoClipPlaneCullCallback : public osg::NodeCallback
		{
		public:
			/**
			* Constructs a new auto-clip plane manager corresponding to the parameters
			* in the specified map.
			* @param map Map to take ellipsoid information from; if NULL, use WGS84 values
			*/
			EarthAutoClipPlaneCullCallback(MapNode* mapNode = 0L);

			virtual ~EarthAutoClipPlaneCullCallback() { }

			/**
			* Sets the minimum near/far ratio to use for this camera. The minimum ratio takes
			* effect when the camera HAE hits zero.
			*/
			void setMinNearFarRatio(double value) { _minNearFarRatio = value; }
			double getMinNearFarRatio() const { return _minNearFarRatio; }

			/**
			* Sets the maximum near/far ratio to use for the camera. The maximum ratio
			* takes effect when the camera HAE hits the Height Threshold.
			*/
			void setMaxNearFarRatio(double value) { _maxNearFarRatio = value; }
			double getMaxNearFarRatio() const { return _maxNearFarRatio; }

			/**
			* Sets the camera Height (above ellipsoide) at which the near/far ratio
			* hits its maximum value.
			*/
			void setHeightThreshold(double value) { _haeThreshold = value; }
			double getHeightThreshold() const { return _haeThreshold; }

			/**
			* Whether to clamp the the far clipping plane to the approximate
			* visible horizon.
			*/
			void setClampFarClipPlane(bool value) { _autoFarPlaneClamping = value; }
			bool getClampFarClipPlane() const { return _autoFarPlaneClamping; }

		public:
			virtual void operator()(osg::Node* node, osg::NodeVisitor* nv);

		protected:
			bool   _active;
			double _minNearFarRatio, _maxNearFarRatio;
			double _haeThreshold;
			double _rp2, _rp;
			bool   _autoFarPlaneClamping;
			osg::observer_ptr<MapNode> _mapNode;
			PerObjectFastMap< osg::Camera*, osg::ref_ptr<osg::CullSettings::ClampProjectionMatrixCallback> > _clampers;
		};
	}
} // namespace osgEarth::Util

#endif // OSGEARTHUTIL_EARTHAUTOCLIPPLANEHANDLER_H
