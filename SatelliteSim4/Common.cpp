#include "Common.h"
#include <osgUtil/SmoothingVisitor>
#include <osg/LineWidth>
#include <osgText/Font>
#include <osgText/Text>
#include <osg/PositionAttitudeTransform>
#include <osg/ShapeDrawable>
#include <osg/Vec3d>
#include <osg/Vec3>
#include <osg/LightModel>

#include <QColor>
#include <QApplication>
#include <QDir>
#include <QDateTime>

#include <string>
using namespace std;

QDateTime g_simTime;

#define muu (3.986005*pow(10.0,14))//地心引力常数

/**
* @brief 添加全局坐标系下轴
* @return
*/
osg::Geode* addAxis(float length)
{
	osg::Vec3 c(0, 0, 0);
	osg::Vec3 x(length/*10000000*/, 0, 0);
	osg::Vec3 y(0, length/*10000000*/, 0);
	osg::Vec3 z(0, 0, length/*10000000*/);

	osg::Geode* geode = new osg::Geode;

	osg::Geometry* linesgeom = new osg::Geometry();
	osg::Vec3dArray* vertices = new osg::Vec3dArray(6);

	(*vertices)[0] = c;
	(*vertices)[1] = x;
	(*vertices)[2] = c;
	(*vertices)[3] = y;
	(*vertices)[4] = c;
	(*vertices)[5] = z;

	//将创建的顶点数组传递给几何对象。
	linesgeom->setVertexArray(vertices);
	linesgeom->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::Mode::LINE_STRIP, 0, 6));

	//设置颜色
	osg::Vec4Array* colors = new osg::Vec4Array;
	linesgeom->setColorArray(colors);
	linesgeom->setColorBinding(osg::Geometry::BIND_PER_VERTEX);
	colors->push_back(osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f));
	colors->push_back(osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f));
	colors->push_back(osg::Vec4(0.0f, 1.0f, 0.0f, 1.0f));
	colors->push_back(osg::Vec4(0.0f, 1.0f, 0.0f, 1.0f));
	colors->push_back(osg::Vec4(0.0f, 0.0f, 1.0f, 1.0f));
	colors->push_back(osg::Vec4(0.0f, 0.0f, 1.0f, 1.0f));

	//设置法线。
	osg::Vec3Array* norms = new osg::Vec3Array;
	norms->push_back(osg::Vec3(0.0, -1.0, 0.0));
	osgUtil::SmoothingVisitor::smooth(*(linesgeom));//自动生成法线

	// linesgeom->setNormalArray(norms);
	// linesgeom->setNormalBinding(osg::Geometry::BIND_OVERALL);

	//限制线宽
	osg::LineWidth* width = new osg::LineWidth;

	//设置线宽
	width->setWidth(3.0);
	geode->getOrCreateStateSet()->setAttributeAndModes(width, osg::StateAttribute::ON);
	//打开透明度
	geode->getOrCreateStateSet()->setMode(GL_BLEND, osg::StateAttribute::ON);
	//将点几何添加到大地测量。
	geode->addDrawable(linesgeom);

	return geode;
}

/**
* @brief 添加屏幕文本
* @return
*/
osg::Node* addHUD()
{
	setlocale(LC_ALL, "chs");
	osg::Geode* geode = new osg::Geode();
	osgText::Font* fontHei = osgText::readFontFile("C:\\Windows\\Fonts\\simkai.ttf");
	osg::Vec3 position(10.0f, 30.0f, 0.0f);
	osgText::Text* mytext = new osgText::Text;
	geode->addDrawable(mytext);
	mytext->setFont(fontHei);
	mytext->setPosition(position);
	mytext->setCharacterSize(30.0f);
	mytext->setColor(osg::Vec4(1, 1, 1, 1));
	mytext->setDrawMode(osgText::Text::TEXT | osgText::Text::BOUNDINGBOX);
	char string[100] = "卫星仿真程序";
	int requiredSize = mbstowcs(NULL, string, 0);
	wchar_t* wText = new wchar_t[requiredSize + 1];
	mbstowcs(wText, string, requiredSize + 1);
	mytext->setText(wText);
	delete wText;

	osg::Camera* camera = new osg::Camera;
	camera->setProjectionMatrix(osg::Matrix::ortho2D(0, 1024, 0, 768));
	camera->setReferenceFrame(osg::Transform::ABSOLUTE_RF);
	camera->setViewMatrix(osg::Matrix::identity());
	camera->setClearMask(GL_DEPTH_BUFFER_BIT);
	camera->setRenderOrder(osg::Camera::POST_RENDER);
	camera->addChild(geode);
	return camera;

	osg::MatrixTransform* texttran = new osg::MatrixTransform;
	texttran->setMatrix(osg::Matrix::rotate(osg::DegreesToRadians(90.0), 1, 0, 0));
	texttran->addChild(geode);
	return texttran;
}

/**
* @brief 添加屏幕仿真时间文本
* @return
*/
osg::Node* addHUD(const wchar_t* s, osg::Vec3 position)
{
	wchar_t  buffer[200];

	swprintf(buffer, L"仿真时间:%i-%i-%i %i:%i:%i\n", g_simTime.date().year(),
		g_simTime.date().month(),
		g_simTime.date().day(),
		g_simTime.time().hour(),
		g_simTime.time().minute(),
		g_simTime.time().second());

	osgText::Text* text = new osgText::Text;
	std::string caiyun("fonts /simhei.ttf");//此处设置的是汉字字体
	text->setFont(caiyun);
	text->setCharacterSize(30.0f);
	text->setPosition(position);//设置文字位置
	text->setColor(osg::Vec4(1, 1, 0, 1));
	text->setText(s);//设置显示的文字

	osgText::Text* textSim = new osgText::Text;
	textSim->setFont(caiyun);
	textSim->setCharacterSize(30.0f);
	textSim->setPosition(position);//设置文字位置
	textSim->setPosition(osg::Vec3(0.0f, 40.0f, 0.0f));//设置文字位置
	textSim->setColor(osg::Vec4(1, 1, 0, 1));
	textSim->setText(buffer);//设置显示的文字

	//几何体节点
	osg::Geode* geode = new osg::Geode();
	geode->addDrawable(text);//将文字Text作这drawable加入到Geode节点中
	geode->addDrawable(textSim);//将文字Text作这drawable加入到Geode节点中
	//设置状态
	osg::StateSet* stateset = geode->getOrCreateStateSet();
	stateset->setMode(GL_LIGHTING, osg::StateAttribute::OFF);//关闭灯光
	stateset->setMode(GL_DEPTH_TEST, osg::StateAttribute::OFF);//关闭深度测试
	//打开GL_BLEND混合模式（以保证Alpha纹理正确）
	stateset->setMode(GL_BLEND, osg::StateAttribute::ON);

	osg::Camera* camera = new osg::Camera;
	camera->setProjectionMatrix(osg::Matrix::ortho2D(0, 1920, 0, 1080));//正交投影   
	//设置绝对参考坐标系，确保视图矩阵不会被上级节点的变换矩阵影响
	camera->setReferenceFrame(osg::Transform::ABSOLUTE_RF);
	//视图矩阵为默认的
	camera->setViewMatrix(osg::Matrix::identity());
	//设置背景为透明，否则的话可以设置ClearColor 
	camera->setClearMask(GL_DEPTH_BUFFER_BIT);
	camera->setAllowEventFocus(false);//不响应事件，始终得不到焦点
	camera->addChild(geode);//将要显示的Geode节点加入到相机

	camera->setName("TimeHUD");
	return camera;
};

/**
* @brief 计算某一时刻卫星的位置
* @return
*/
osg::Vec3d getSatePosition(COE_ELEMENT* element, double time_s)
{
	double m_M0 = element->M;
	double m_cj = element->Omega;
	double m_w = element->w;
	double m_i = element->i;
	double m_a = element->a;
	double m_e = element->E;

	const double PI = 4 * atan(1.0);
	m_M0 = m_M0 / (180.0 / PI);
	m_cj = m_cj / (180.0 / PI);
	m_w = m_w / (180.0 / PI);
	m_i = m_i / (180.0 / PI);
	double n, tao, M;
	n = sqrt(muu / (m_a * m_a * m_a));
	tao = m_M0 / n;

	M = n * (time_s - tao);

	for (; M > 2 * PI;)
		M -= 2 * PI;

	double E, temp, f;
	E = M;
	do
	{
		temp = E;
		E = M + m_e * sin(temp);
	} while (fabs(E - temp) > 0.00000001);

	//if ((sin(E) > 0) && (cos(E) > 0)) E = E;
	//if ((sin(E) > 0) && (cos(E) < 0)) E = PI - E;
	//if ((sin(E) < 0) && (cos(E) < 0)) E = E + PI;
	//if ((sin(E) < 0) && (cos(E) > 0)) E = 2.0 * PI - E;

	f = 2 * atan(sqrt((1 + m_e) / (1 - m_e)) * tan(E / 2.0));
	//if ((sin(f) > 0) && (cos(f) > 0)) f = f;
	//if ((sin(f) > 0) && (cos(f) < 0)) f = PI - f;
	//if ((sin(f) < 0) && (cos(f) < 0)) f = f + PI;
	//if ((sin(f) < 0) && (cos(f) > 0)) f = 2.0 * PI - f;

	double r;
	r = m_a * (1 - m_e * cos(E));

	double m_PX = r * (cos(m_cj) * cos(m_w + f) - sin(m_cj) * sin(m_w + f) * cos(m_i));
	double m_PY = r * (sin(m_cj) * cos(m_w + f) + cos(m_cj) * sin(m_w + f) * cos(m_i));
	double m_PZ = r * sin(m_w + f) * sin(m_i);

	double p1 = cos(m_w) * cos(m_cj) - sin(m_w) * sin(m_cj) * cos(m_i),
		p2 = cos(m_w) * sin(m_cj) + sin(m_w) * cos(m_cj) * cos(m_i),
		p3 = sin(m_w) * sin(m_i),
		q1 = -sin(m_w) * cos(m_cj) - cos(m_w) * sin(m_cj) * cos(m_i),
		q2 = -sin(m_w) * sin(m_cj) + cos(m_w) * cos(m_cj) * cos(m_i),
		q3 = cos(m_w) * sin(m_i);

	double x_point = sqrt(muu) * (-sin(f) / sqrt(m_a * (1 - m_e * m_e))),
		y_point = sqrt(muu) * (-(cos(f) + m_e) / sqrt(m_a * (1 - m_e * m_e)));//sqrt(m_a*(1-m_e*m_e))*cos(E)/r

	double m_VX = x_point * p1 - y_point * q1;
	double m_VY = x_point * p2 - y_point * q2;
	double m_VZ = x_point * p3 - y_point * q3;

	m_M0 = m_M0 / (PI / 180.0);
	m_cj = m_cj / (PI / 180.0);
	m_w = m_w / (PI / 180.0);
	m_i = m_i / (PI / 180.0);

	element->M = m_M0;
	element->Omega = m_cj;
	element->w = m_w;
	element->i = m_i;

	return osg::Vec3d(m_PX, m_PY, m_PZ);
}

/**
* @brief 世界坐标转经纬度
* @return
*/
osg::Vec3d WorldToLonLatAlt(const osg::Vec3d world)
{
	osg::EllipsoidModel* em = new osg::EllipsoidModel();
	osg::Vec3d lonLatAlt;
	em->convertXYZToLatLongHeight(world.x(), world.y(), world.z(),
		lonLatAlt.y(), lonLatAlt.x(), lonLatAlt.z());

	lonLatAlt.x() = osg::RadiansToDegrees(lonLatAlt.x());
	lonLatAlt.y() = osg::RadiansToDegrees(lonLatAlt.y());
	return lonLatAlt;
}

/**
* @brief 添加轨道
* @return
*/
osg::Geode* addOribt(COE_ELEMENT* element, double period, osg::Vec3& firstVert, osg::Vec3& oribtNor, std::vector<osg::Vec3>& lonlats, osg::Vec4 color)
{
	osg::Geode* geode = new osg::Geode;

	osg::Geometry* linesgeom = new osg::Geometry();
	osg::Vec3dArray* vertices = new osg::Vec3dArray();

	for (int i = 0; i < period; i++)
	{
		osg::Vec3d pos = getSatePosition(element, i);
		vertices->push_back(pos);

		lonlats.push_back(WorldToLonLatAlt(pos));
	}

	// 算出轨道法线
	osg::Vec3 vec0 = (*vertices)[0];
	osg::Vec3 vec90 = (*vertices)[period / 4];
	firstVert = vec0;

	osg::Vec3 nor = vec0 ^ vec90;
	nor.normalize();
	oribtNor = nor;

	//将创建的顶点数组传递给几何对象。
	linesgeom->setVertexArray(vertices);
	linesgeom->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::Mode::LINE_LOOP, 0, vertices->size()));

	//设置颜色
	osg::Vec4Array* colors = new osg::Vec4Array;
	linesgeom->setColorArray(colors);
	linesgeom->setColorBinding(osg::Geometry::BIND_OVERALL);
	//colors->push_back(osg::Vec4(1.0f, 1.0f, 0.0f, 0.5f));
	colors->push_back(color);

	//设置法线。
	osg::Vec3Array* norms = new osg::Vec3Array;
	norms->push_back(osg::Vec3(0.0, -1.0, 0.0));
	//osgUtil::SmoothingVisitor::smooth(*(linesgeom));//自动生成法线

	// linesgeom->setNormalArray(norms);
	// linesgeom->setNormalBinding(osg::Geometry::BIND_OVERALL);

	//限制线宽
	osg::LineWidth* width = new osg::LineWidth;

	//设置线宽
	width->setWidth(1);
	geode->getOrCreateStateSet()->setAttributeAndModes(width, osg::StateAttribute::ON);
	//打开透明度
	geode->getOrCreateStateSet()->setMode(GL_BLEND, osg::StateAttribute::OFF);
	geode->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF | osg::StateAttribute::OVERRIDE);
	//将点几何添加到大地测量。
	linesgeom->setName("Orbit");
	geode->addDrawable(linesgeom);

	return geode;
}

/**
* @brief 添加卫星坐标系轴
* @return
*/
osg::Geometry* addSateAxis(float length, osg::Vec3 position, osg::Vec3 norOribt)
{
	osg::Vec3 c = position;
	osg::Vec3 cNorm = position;
	cNorm.normalize();

	osg::Vec3 z = position + cNorm * -length;
	osg::Vec3 y = position + norOribt * -length;

	osg::Vec3 norYZ = (y ^ z);
	norYZ.normalize();
	osg::Vec3 x = position + norYZ * -length;

	osg::Geometry* linesgeom = new osg::Geometry();
	linesgeom->setName("SateAxis");

	osg::Vec3dArray* vertices = new osg::Vec3dArray(6);

	(*vertices)[0] = c;
	(*vertices)[1] = x;
	(*vertices)[2] = c;
	(*vertices)[3] = y;
	(*vertices)[4] = c;
	(*vertices)[5] = z;

	//将创建的顶点数组传递给几何对象。
	linesgeom->setVertexArray(vertices);
	linesgeom->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::Mode::LINE_STRIP, 0, 6));

	//设置颜色
	osg::Vec4Array* colors = new osg::Vec4Array;
	linesgeom->setColorArray(colors);
	linesgeom->setColorBinding(osg::Geometry::BIND_PER_VERTEX);
	colors->push_back(osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f));
	colors->push_back(osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f));
	colors->push_back(osg::Vec4(0.0f, 1.0f, 0.0f, 1.0f));
	colors->push_back(osg::Vec4(0.0f, 1.0f, 0.0f, 1.0f));
	colors->push_back(osg::Vec4(0.0f, 0.0f, 1.0f, 1.0f));
	colors->push_back(osg::Vec4(0.0f, 0.0f, 1.0f, 1.0f));

	//设置法线。
	osg::Vec3Array* norms = new osg::Vec3Array;
	norms->push_back(osg::Vec3(0.0, -1.0, 0.0));
	osgUtil::SmoothingVisitor::smooth(*(linesgeom));//自动生成法线

	linesgeom->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF | osg::StateAttribute::OVERRIDE);

	return linesgeom;
}

/**
* @brief 姿态转四元素
* @return
*/
osg::Quat HPRToQuat(double heading, double pitch, double roll)
{
	osg::Quat q(
		roll, osg::Vec3d(0.0, 1.0, 0.0),
		pitch, osg::Vec3d(1.0, 0.0, 0.0),
		heading, osg::Vec3d(0.0, 0.0, 1.0));
	return q;
}

#include <osg/Switch>
/**
* @brief 添加卫星
* @return
*/
osg::PositionAttitudeTransform* addSatellite(std::string name, 
	std::string modelFile, 
	osg::Vec3d position, 
	double roll, 
	double pitch, 
	double yaw, 
	osg::MatrixTransform* rotateMT,
	QColor color)
{
	osg::PositionAttitudeTransform* pat = new osg::PositionAttitudeTransform();
	pat->setPosition(position);
	pat->setName("Satepat");
	//pat->setAttitude(HPRToQuat(osg::DegreesToRadians(0.0), osg::DegreesToRadians(90.0), osg::DegreesToRadians(0.0)));

	osgDB::Options* option = new osgDB::Options(std::string("noTriStripPolygons noRotation noTesselateLargePolygons"));

	QDir dir(qApp->applicationDirPath());
	dir.cdUp();
	dir.cd("data");

	osg::Node* sat = osgDB::readNodeFile(std::string(dir.absolutePath().toLocal8Bit()) + modelFile/*"/satellite90.obj"*/, option);
	sat->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF | osg::StateAttribute::OVERRIDE);

	// 创建一个球，默认显示为球
	osg::ref_ptr<osg::Geode> geo = new osg::Geode;
	osg::ref_ptr<osg::Sphere> sphere = new osg::Sphere(osg::Vec3(0, 0, 0), 3.0f);
	osg::ref_ptr<osg::ShapeDrawable> shapeDrawable = new osg::ShapeDrawable(sphere.get());
	shapeDrawable->setColor(osg::Vec4(color.redF(), color.greenF(), color.blueF(), 1.0f));
	geo->addDrawable(shapeDrawable.get());

	// 创建名称
	osg::ref_ptr<osgText::Text> textName = new osgText::Text;
	textName->setFont("Fonts/simhei.ttf");
	textName->setCharacterSize(10);
	textName->setText(name);
	textName->setColor(osg::Vec4(color.redF(), color.greenF(), color.blueF(), 1.0f));
	textName->setPosition(osg::Vec3(0.0, 0.0, 0.0));
	textName->setAxisAlignment(osgText::Text::SCREEN);
	textName->setCharacterSizeMode(osgText::Text::SCREEN_COORDS);

	// 切换节点
	osg::Switch* sw = new osg::Switch();
	sw->addChild(sat);
	sw->addChild(geo);
	sw->setValue(0, false);
	sw->setValue(1, true);

	rotateMT->setMatrix(osg::Matrix::rotate(osg::DegreesToRadians(90.0f), 1.0f, 0.0f, 0.0f) * 
		osg::Matrix::rotate(osg::DegreesToRadians(90.0f), 0.0f, 1.0f, 0.0f));
	rotateMT->addChild(sw);
	rotateMT->addChild(textName);

	pat->setScale(osg::Vec3(10000, 10000, 10000));
	//pat->setAttitude(osg::Quat(roll, osg::Vec3d(1, 0, 0), pitch, osg::Vec3d(0, 1, 0), yaw, osg::Vec3d(0, 0, 1)));
	//pat->addChild(addAxis(100));
	pat->addChild(rotateMT);

	return pat;
}

float calcAngle0(osg::Vec3f line1, osg::Vec3f line2)
{
	line1.normalize();
	line2.normalize();
	float temp = (line1 * line2);
	// 1和-1时为0和180°
	if (fabs(fabs(temp) - 1) < 0.000001)
	{
		return temp > 0 ? 0 : osg::PI;
	}
	float angle = (float)acos(temp);
	return angle;
}

/**
* @brief 计算两向量夹角
* @return
*/
float calcAngle(osg::Vec3f line1, osg::Vec3f line2, osg::Vec3f direction)
{
	line1.normalize();
	line2.normalize();
	float temp = (line1 * line2);
	// 1和-1时为0和180°
	if (fabs(fabs(temp) - 1) < 0.000001)
	{
		return temp > 0 ? 0 : osg::PI;
	}
	float angle = (float)acos(temp);

	// 两个向量的叉乘结果与屏幕方向是否一致来判断角度是否超过180°
	osg::Vec3f axis = line1 ^ line2;
	return axis * direction > 0 ? angle : 2 * osg::PI - angle;
}

/**
* 卫星信号传导动画shader
*/
static char * fragShader = {
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

/**
* 两点画圆锥
*/
osg::MatrixTransform* createCone(const osg::Vec3 &from, const osg::Vec3 &to, float radius)
{
	osg::ref_ptr<osg::Geode> geode = new osg::Geode();
	osg::ref_ptr<osg::MatrixTransform> mt = new osg::MatrixTransform();
	osg::ref_ptr<osg::ShapeDrawable> shapeDrawable = new osg::ShapeDrawable();
	osg::ref_ptr<osg::TessellationHints> hints = new osg::TessellationHints();

	hints->setDetailRatio(2.0f);
	osg::Vec3 cylCenter = (to + from) / 4;		//得到柱心
	float height = (to - from).length();		//得到长度
	shapeDrawable = new osg::ShapeDrawable(new osg::Cone(osg::Vec3(0.0, 0.0, 0.0), radius, height), hints.get());
	shapeDrawable->setColor(osg::Vec4(0, 255.0 / 255, 0, 1.0f));			//鹿皮鞋色

	osg::Texture2D* texture = new osg::Texture2D;
	//texture->setDataVariance(osg::Object::DYNAMIC); // protect from being optimized away as static state.
	texture->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR);
	texture->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	texture->setWrap(osg::Texture2D::WRAP_S, osg::Texture2D::REPEAT);
	texture->setWrap(osg::Texture2D::WRAP_T, osg::Texture2D::REPEAT);
	texture->setImage(osgDB::readImageFile("Images/test1.png"));

	osg::StateSet* stateset = shapeDrawable->getOrCreateStateSet();
	stateset->setTextureAttributeAndModes(0, texture, osg::StateAttribute::ON);
	osg::Program * program = new osg::Program;
	program->addShader(new osg::Shader(osg::Shader::FRAGMENT, fragShader));
	stateset->addUniform(new osg::Uniform("baseTex", 0));
	stateset->setAttributeAndModes(program, osg::StateAttribute::ON);

	stateset->setMode(GL_BLEND, osg::StateAttribute::ON);
	stateset->setRenderingHint(osg::StateSet::TRANSPARENT_BIN);

	stateset->setMode(GL_LIGHTING, osg::StateAttribute::ON);//关闭灯光

	osg::LightModel* plm = new osg::LightModel;
	plm->setTwoSided(true);
	stateset->setAttributeAndModes(plm, osg::StateAttribute::ON);

	//
	geode->addDrawable(shapeDrawable.get());
	osg::Matrix mRotate, mTrans;
	mRotate.makeRotate(osg::Vec3f(0.0f, 0.0f, 1.0f), to - from);
	mTrans.makeTranslate(cylCenter);
	mt->setMatrix(mRotate*mTrans);
	mt->addChild(geode.get());
	return mt.release();
}

/**
* 两点画圆柱
*/
osg::MatrixTransform* createCylinder(const osg::Vec3 &from, const osg::Vec3 &to, float radius)
{
	osg::ref_ptr<osg::Geode> geode = new osg::Geode();
	osg::ref_ptr<osg::MatrixTransform> mt = new osg::MatrixTransform();
	osg::ref_ptr<osg::ShapeDrawable> shapeDrawable = new osg::ShapeDrawable();
	osg::ref_ptr<osg::TessellationHints> hints = new osg::TessellationHints();

	hints->setDetailRatio(2.0f);
	osg::Vec3 cylCenter = (to + from) / 4;		//得到柱心
	float height = (to - from).length();		//得到长度
	shapeDrawable = new osg::ShapeDrawable(new osg::Cylinder(osg::Vec3(0.0, 0.0, 0.0), radius, height), hints.get());
	shapeDrawable->setColor(osg::Vec4(0, 255.0 / 255, 0, 1.0f));			//鹿皮鞋色

	osg::Texture2D* texture = new osg::Texture2D;
	//texture->setDataVariance(osg::Object::DYNAMIC); // protect from being optimized away as static state.
	texture->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR);
	texture->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	texture->setWrap(osg::Texture2D::WRAP_S, osg::Texture2D::REPEAT);
	texture->setWrap(osg::Texture2D::WRAP_T, osg::Texture2D::REPEAT);
	texture->setImage(osgDB::readImageFile("Images/test1.png"));

	osg::StateSet* stateset = shapeDrawable->getOrCreateStateSet();
	stateset->setTextureAttributeAndModes(0, texture, osg::StateAttribute::ON);
	osg::Program * program = new osg::Program;
	program->addShader(new osg::Shader(osg::Shader::FRAGMENT, fragShader));
	stateset->addUniform(new osg::Uniform("baseTex", 0));
	stateset->setAttributeAndModes(program, osg::StateAttribute::ON);

	stateset->setMode(GL_BLEND, osg::StateAttribute::ON);
	stateset->setRenderingHint(osg::StateSet::TRANSPARENT_BIN);

	stateset->setMode(GL_LIGHTING, osg::StateAttribute::ON);//关闭灯光

	osg::LightModel* plm = new osg::LightModel;
	plm->setTwoSided(true);
	stateset->setAttributeAndModes(plm, osg::StateAttribute::ON);

	//
	geode->addDrawable(shapeDrawable.get());
	osg::Matrix mRotate, mTrans;
	mRotate.makeRotate(osg::Vec3f(0.0f, 0.0f, 1.0f), to - from);
	mTrans.makeTranslate(cylCenter);
	mt->setMatrix(mRotate*mTrans);
	mt->addChild(geode.get());
	return mt.release();
}

static QPlainTextEdit* s_logTextEdit = nullptr;

/**
* 打印日志
*/
void printLog(QString text, QPlainTextEdit* textEdit)
{
	if (s_logTextEdit == nullptr)
	{
		s_logTextEdit = textEdit;
	}

	s_logTextEdit->appendPlainText(QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss:zzz ->") + text);
}

/**
* 添加金字塔
*/
osg::MatrixTransform* createColorPyramid(float height, float fovx, float fovy, float radius, float transparency1, float transparency2)
{
	osg::ref_ptr<osg::MatrixTransform> mt = new osg::MatrixTransform();

	osg::Geode* pyramidGeode = new osg::Geode();
	osg::Geometry* pyramidGeometry = new osg::Geometry();
	//pyramidGeode->setUpdateCallback(new TextureCoordUpdateCallback(0.01));
	pyramidGeode->setDataVariance(osg::Object::DYNAMIC);
	pyramidGeode->addDrawable(pyramidGeometry);

	float lenx = tan(osg::DegreesToRadians(fovx / 2.0)) * height;
	float leny = tan(osg::DegreesToRadians(fovy / 2.0)) * height;

	osg::Vec3Array* pyramidVertices = new osg::Vec3Array;
	pyramidVertices->push_back(osg::Vec3(-lenx, -leny, height)); // 左前 
	pyramidVertices->push_back(osg::Vec3(lenx, -leny, height)); // 右前 
	pyramidVertices->push_back(osg::Vec3(lenx, leny, height)); // 右后 
	pyramidVertices->push_back(osg::Vec3(-lenx, leny, height)); // 左后 
	pyramidVertices->push_back(osg::Vec3(0, 0, 0)); // 塔尖
	pyramidGeometry->setVertexArray(pyramidVertices);
	osg::DrawElementsUInt* pyramidBase = new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, 0);
	pyramidBase->push_back(3);
	pyramidBase->push_back(2);
	pyramidBase->push_back(1);
	pyramidBase->push_back(0);
	//pyramidGeometry->addPrimitiveSet(pyramidBase);
	osg::DrawElementsUInt* pyramidFaceOne = new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES, 0);
	pyramidFaceOne->push_back(0);
	pyramidFaceOne->push_back(1);
	pyramidFaceOne->push_back(4);
	pyramidGeometry->addPrimitiveSet(pyramidFaceOne);
	osg::DrawElementsUInt* pyramidFaceTwo = new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES, 0);
	pyramidFaceTwo->push_back(1);
	pyramidFaceTwo->push_back(2);
	pyramidFaceTwo->push_back(4);
	pyramidGeometry->addPrimitiveSet(pyramidFaceTwo);
	osg::DrawElementsUInt* pyramidFaceThree = new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES, 0);
	pyramidFaceThree->push_back(2);
	pyramidFaceThree->push_back(3);
	pyramidFaceThree->push_back(4);
	pyramidGeometry->addPrimitiveSet(pyramidFaceThree);
	osg::DrawElementsUInt* pyramidFaceFour = new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES, 0);
	pyramidFaceFour->push_back(3);
	pyramidFaceFour->push_back(0);
	pyramidFaceFour->push_back(4);
	pyramidGeometry->addPrimitiveSet(pyramidFaceFour);

	osg::Vec4Array* colors = new osg::Vec4Array;
	colors->push_back(osg::Vec4(1.0f, 1.0f, 0.0f, transparency1));     
	colors->push_back(osg::Vec4(1.0f, 1.0f, 0.0f, transparency1));
	colors->push_back(osg::Vec4(1.0f, 1.0f, 0.0f, transparency1));
	colors->push_back(osg::Vec4(1.0f, 1.0f, 0.0f, transparency1));
	colors->push_back(osg::Vec4(1.0f, 1.0f, 0.0f, transparency2));

	pyramidGeometry->setColorArray(colors);
	pyramidGeometry->setColorBinding(osg::Geometry::BIND_PER_VERTEX);

	osg::Vec3Array* normals = new osg::Vec3Array(1);
	(*normals)[0].set(0.0f, -1.0f, 0.0f);
	pyramidGeometry->setNormalArray(normals, osg::Array::BIND_OVERALL);

	pyramidGeometry->getOrCreateStateSet()->setMode(GL_BLEND, osg::StateAttribute::ON);
	pyramidGeometry->getOrCreateStateSet()->setRenderingHint(osg::StateSet::TRANSPARENT_BIN);

	mt->setMatrix(osg::Matrix::scale(radius, radius, radius));
	mt->addChild(pyramidGeode);
	return mt.release();
}

/**
* 绘制最大扫描范围线框
*/
osg::Geode* drawMaxScanRange_Line(float height, float fovx, float fovy, float radius, float transparency1, float transparency2)
{
	osg::Geode* pyramidGeode = new osg::Geode();
	osg::Geometry* pyramidGeometry = new osg::Geometry();
	//pyramidGeode->setUpdateCallback(new TextureCoordUpdateCallback(0.01));
	pyramidGeode->setDataVariance(osg::Object::DYNAMIC);
	pyramidGeode->addDrawable(pyramidGeometry);

	float lenx = tan(osg::DegreesToRadians(fovx / 2.0)) * height;
	float leny = tan(osg::DegreesToRadians(fovy / 2.0)) * height;

	osg::Vec3Array* pyramidVertices = new osg::Vec3Array;
	pyramidVertices->push_back(osg::Vec3(0, 0, 0)); // 塔尖
	pyramidVertices->push_back(osg::Vec3(-lenx, -leny, height)); // 左前 
	pyramidVertices->push_back(osg::Vec3(lenx, -leny, height)); // 右前 
	pyramidVertices->push_back(osg::Vec3(lenx, leny, height)); // 右后 
	pyramidVertices->push_back(osg::Vec3(-lenx, leny, height)); // 左后 
	pyramidGeometry->setVertexArray(pyramidVertices);

	// 线框
	osg::DrawElementsUInt* pyramidLine = new osg::DrawElementsUInt(osg::PrimitiveSet::LINE_STRIP, 0);
	pyramidLine->push_back(0);
	pyramidLine->push_back(1);
	pyramidGeometry->addPrimitiveSet(pyramidLine);

	pyramidLine = new osg::DrawElementsUInt(osg::PrimitiveSet::LINE_STRIP, 0);
	pyramidLine->push_back(0);
	pyramidLine->push_back(2);
	pyramidGeometry->addPrimitiveSet(pyramidLine);

	pyramidLine = new osg::DrawElementsUInt(osg::PrimitiveSet::LINE_STRIP, 0);
	pyramidLine->push_back(0);
	pyramidLine->push_back(3);
	pyramidGeometry->addPrimitiveSet(pyramidLine);

	pyramidLine = new osg::DrawElementsUInt(osg::PrimitiveSet::LINE_STRIP, 0);
	pyramidLine->push_back(0);
	pyramidLine->push_back(4);
	pyramidGeometry->addPrimitiveSet(pyramidLine);

	pyramidLine = new osg::DrawElementsUInt(osg::PrimitiveSet::LINE_STRIP, 0);
	pyramidLine->push_back(1);
	pyramidLine->push_back(2);
	pyramidGeometry->addPrimitiveSet(pyramidLine);

	pyramidLine = new osg::DrawElementsUInt(osg::PrimitiveSet::LINE_STRIP, 0);
	pyramidLine->push_back(2);
	pyramidLine->push_back(3);
	pyramidGeometry->addPrimitiveSet(pyramidLine);

	pyramidLine = new osg::DrawElementsUInt(osg::PrimitiveSet::LINE_STRIP, 0);
	pyramidLine->push_back(3);
	pyramidLine->push_back(4);
	pyramidGeometry->addPrimitiveSet(pyramidLine);

	pyramidLine = new osg::DrawElementsUInt(osg::PrimitiveSet::LINE_STRIP, 0);
	pyramidLine->push_back(4);
	pyramidLine->push_back(1);
	pyramidGeometry->addPrimitiveSet(pyramidLine);

	osg::Vec4Array* colors = new osg::Vec4Array;
	colors->push_back(osg::Vec4(1.0f, 0.0f, 0.0f, transparency1));
	colors->push_back(osg::Vec4(1.0f, 0.0f, 0.0f, transparency1));
	colors->push_back(osg::Vec4(1.0f, 0.0f, 0.0f, transparency1));
	colors->push_back(osg::Vec4(1.0f, 0.0f, 0.0f, transparency1));
	colors->push_back(osg::Vec4(1.0f, 0.0f, 0.0f, transparency2));

	pyramidGeometry->setColorArray(colors);
	pyramidGeometry->setColorBinding(osg::Geometry::BIND_PER_VERTEX);

	osg::ref_ptr<osg::LineWidth> lineWidth = new osg::LineWidth(1.0f);
	pyramidGeometry->getOrCreateStateSet()->setAttribute(lineWidth);

	return pyramidGeode;
}

/**
* 绘制最大扫描范围
*/
osg::MatrixTransform* drawMaxScanRange(float height, float fovx, float fovy, float radius, float transparency1, float transparency2)
{
	osg::ref_ptr<osg::MatrixTransform> mt = new osg::MatrixTransform();

	osg::Geode* pyramidGeode = new osg::Geode();
	osg::Geometry* pyramidGeometry = new osg::Geometry();
	//pyramidGeode->setUpdateCallback(new TextureCoordUpdateCallback(0.01));
	pyramidGeode->setDataVariance(osg::Object::DYNAMIC);
	pyramidGeode->addDrawable(pyramidGeometry);

	float lenx = tan(osg::DegreesToRadians(fovx / 2.0)) * height;
	float leny = tan(osg::DegreesToRadians(fovy / 2.0)) * height;

	osg::Vec3Array* pyramidVertices = new osg::Vec3Array;
	pyramidVertices->push_back(osg::Vec3(-lenx, -leny, height)); // 左前 
	pyramidVertices->push_back(osg::Vec3(lenx, -leny, height)); // 右前 
	pyramidVertices->push_back(osg::Vec3(lenx, leny, height)); // 右后 
	pyramidVertices->push_back(osg::Vec3(-lenx, leny, height)); // 左后 
	pyramidVertices->push_back(osg::Vec3(0, 0, 0)); // 塔尖
	pyramidGeometry->setVertexArray(pyramidVertices);
	osg::DrawElementsUInt* pyramidBase = new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, 0);
	pyramidBase->push_back(3);
	pyramidBase->push_back(2);
	pyramidBase->push_back(1);
	pyramidBase->push_back(0);
	//pyramidGeometry->addPrimitiveSet(pyramidBase);
	osg::DrawElementsUInt* pyramidFaceOne = new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES, 0);
	pyramidFaceOne->push_back(0);
	pyramidFaceOne->push_back(1);
	pyramidFaceOne->push_back(4);
	pyramidGeometry->addPrimitiveSet(pyramidFaceOne);
	osg::DrawElementsUInt* pyramidFaceTwo = new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES, 0);
	pyramidFaceTwo->push_back(1);
	pyramidFaceTwo->push_back(2);
	pyramidFaceTwo->push_back(4);
	pyramidGeometry->addPrimitiveSet(pyramidFaceTwo);
	osg::DrawElementsUInt* pyramidFaceThree = new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES, 0);
	pyramidFaceThree->push_back(2);
	pyramidFaceThree->push_back(3);
	pyramidFaceThree->push_back(4);
	pyramidGeometry->addPrimitiveSet(pyramidFaceThree);
	osg::DrawElementsUInt* pyramidFaceFour = new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES, 0);
	pyramidFaceFour->push_back(3);
	pyramidFaceFour->push_back(0);
	pyramidFaceFour->push_back(4);
	pyramidGeometry->addPrimitiveSet(pyramidFaceFour);

	// 线框
	osg::DrawElementsUInt* pyramidLineOne = new osg::DrawElementsUInt(osg::PrimitiveSet::LINE_STRIP, 0);
	pyramidLineOne->push_back(0);
	pyramidLineOne->push_back(4);
	pyramidGeometry->addPrimitiveSet(pyramidLineOne);

	osg::Vec4Array* colors = new osg::Vec4Array;
	colors->push_back(osg::Vec4(1.0f, 1.0f, 0.0f, transparency1));
	colors->push_back(osg::Vec4(1.0f, 1.0f, 0.0f, transparency1));
	colors->push_back(osg::Vec4(1.0f, 1.0f, 0.0f, transparency1));
	colors->push_back(osg::Vec4(1.0f, 1.0f, 0.0f, transparency1));
	colors->push_back(osg::Vec4(1.0f, 1.0f, 0.0f, transparency2));

	pyramidGeometry->setColorArray(colors);
	pyramidGeometry->setColorBinding(osg::Geometry::BIND_PER_VERTEX);

	osg::Vec3Array* normals = new osg::Vec3Array(1);
	(*normals)[0].set(0.0f, -1.0f, 0.0f);
	pyramidGeometry->setNormalArray(normals, osg::Array::BIND_OVERALL);

	pyramidGeometry->getOrCreateStateSet()->setMode(GL_BLEND, osg::StateAttribute::ON);
	pyramidGeometry->getOrCreateStateSet()->setRenderingHint(osg::StateSet::TRANSPARENT_BIN);
	pyramidGeometry->getOrCreateStateSet()->setRenderBinDetails(-2, "RenderBin");

	mt->setMatrix(osg::Matrix::scale(radius, radius, radius));
	mt->addChild(pyramidGeode);
	mt->addChild(drawMaxScanRange_Line(height, fovx, fovy, radius, transparency1, transparency2));
	return mt.release();
}

/**
* 绘制当前扫描范围
*/
osg::MatrixTransform* drawCurrentScanRange(float height, float fovx, float fovy, float radius, float transparency1, float transparency2)
{
	osg::ref_ptr<osg::MatrixTransform> mt = new osg::MatrixTransform();

	osg::Geode* pyramidGeode = new osg::Geode();
	osg::Geometry* pyramidGeometry = new osg::Geometry();
	//pyramidGeode->setUpdateCallback(new TextureCoordUpdateCallback(0.01));
	pyramidGeode->setDataVariance(osg::Object::DYNAMIC);
	pyramidGeode->addDrawable(pyramidGeometry);

	float lenx = tan(osg::DegreesToRadians(fovx / 2.0)) * height;
	float leny = tan(osg::DegreesToRadians(fovy / 2.0)) * height;

	osg::Vec3Array* pyramidVertices = new osg::Vec3Array;
	pyramidVertices->push_back(osg::Vec3(-lenx, -leny, height)); // 左前 
	pyramidVertices->push_back(osg::Vec3(lenx, -leny, height)); // 右前 
	pyramidVertices->push_back(osg::Vec3(lenx, leny, height)); // 右后 
	pyramidVertices->push_back(osg::Vec3(-lenx, leny, height)); // 左后 
	pyramidVertices->push_back(osg::Vec3(0, 0, 0)); // 塔尖
	pyramidGeometry->setVertexArray(pyramidVertices);
	osg::DrawElementsUInt* pyramidBase = new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, 0);
	pyramidBase->push_back(3);
	pyramidBase->push_back(2);
	pyramidBase->push_back(1);
	pyramidBase->push_back(0);
	pyramidGeometry->addPrimitiveSet(pyramidBase);
	osg::DrawElementsUInt* pyramidFaceOne = new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES, 0);
	pyramidFaceOne->push_back(0);
	pyramidFaceOne->push_back(1);
	pyramidFaceOne->push_back(4);
	pyramidGeometry->addPrimitiveSet(pyramidFaceOne);
	osg::DrawElementsUInt* pyramidFaceTwo = new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES, 0);
	pyramidFaceTwo->push_back(1);
	pyramidFaceTwo->push_back(2);
	pyramidFaceTwo->push_back(4);
	pyramidGeometry->addPrimitiveSet(pyramidFaceTwo);
	osg::DrawElementsUInt* pyramidFaceThree = new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES, 0);
	pyramidFaceThree->push_back(2);
	pyramidFaceThree->push_back(3);
	pyramidFaceThree->push_back(4);
	pyramidGeometry->addPrimitiveSet(pyramidFaceThree);
	osg::DrawElementsUInt* pyramidFaceFour = new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES, 0);
	pyramidFaceFour->push_back(3);
	pyramidFaceFour->push_back(0);
	pyramidFaceFour->push_back(4);
	pyramidGeometry->addPrimitiveSet(pyramidFaceFour);

	osg::Vec4Array* colors = new osg::Vec4Array;
	colors->push_back(osg::Vec4(1.0f, 1.0f, 0.0f, transparency1));
	colors->push_back(osg::Vec4(1.0f, 1.0f, 0.0f, transparency1));
	colors->push_back(osg::Vec4(1.0f, 1.0f, 0.0f, transparency1));
	colors->push_back(osg::Vec4(1.0f, 1.0f, 0.0f, transparency1));
	colors->push_back(osg::Vec4(1.0f, 1.0f, 0.0f, transparency2));

	pyramidGeometry->setColorArray(colors);
	pyramidGeometry->setColorBinding(osg::Geometry::BIND_PER_VERTEX);

	osg::Vec3Array* normals = new osg::Vec3Array(1);
	(*normals)[0].set(0.0f, -1.0f, 0.0f);
	pyramidGeometry->setNormalArray(normals, osg::Array::BIND_OVERALL);

	pyramidGeometry->getOrCreateStateSet()->setMode(GL_BLEND, osg::StateAttribute::ON);
	pyramidGeometry->getOrCreateStateSet()->setRenderingHint(osg::StateSet::TRANSPARENT_BIN);
	//pyramidGeometry->getOrCreateStateSet()->setMode(GL_DEPTH_TEST, osg::StateAttribute::OFF);
	pyramidGeometry->getOrCreateStateSet()->setRenderBinDetails(-3, "RenderBin");

	mt->setMatrix(osg::Matrix::scale(radius, radius, radius));
	mt->addChild(pyramidGeode);
	mt->addChild(drawMaxScanRange_Line(height, fovx, fovy, radius, transparency1, transparency2));
	return mt.release();
}