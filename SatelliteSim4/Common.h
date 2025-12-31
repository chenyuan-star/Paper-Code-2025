#pragma once
#include <osg/MatrixTransform>
#include <osgEarth/MapNode>
#include <osg/Geode>
#include <osg/Node>
#include <QDateTime>
#include "miniMapTrack.h"
#include "StructDefine.h"
#include <QPlainTextEdit>

#define muu (3.986005*pow(10.0,14))//地心引力常数

/**
* @brief 卫星类型
* @return
*/
enum COE_TYPE
{
	UNKNOWN = 0,	// 未知
	GALILEO = 1,	// 伽利略卫星导航
	GLONASS = 2,	// 格洛纳斯星座
	GPS = 3,		// GPS导航
	BEIDOU = 4,		// 北斗卫星星座
	REMOTE = 5		// 遥感
};

// 轨道类型
enum ORBIT_TYPE
{
	UNKNONW = 0,
	LOW = 1,
	MIDDLE = 2,
	HIGH = 3
};

/**
* @brief 卫星模型与颜色
* @return
*/
struct MODEL_COLOR
{
	QString ModelFile;
	QColor Color;
};

/**
* @brief 卫星结构体定义
* @return
*/
struct COE_ELEMENT
{
	QString name;			// 名称

	COE_TYPE type;			// 卫星类型
	ORBIT_TYPE	orbitType;	// 轨道类型

	int	id;
	QString iNumber;
	QString status;

	double a;		// 长半轴
	double E;		// 偏心率
	double i;		// 轨道倾角
	double Omega;	// 近地点幅角
	double w;		// 升交点赤经
	double M;		// 平近点角

	double roll;	// 翻滚角
	double pitch;	// 俯仰角
	double yaw;		// 偏航角

	QString launchSite;
	int launchNumber;
	QString launchDate;

	osg::Vec3d firstPosition;	//	轨道计算的第一个点
	osg::Vec3d normal;			//	轨道平面的法向量

	osg::Geode* orbit;			// 轨道
	osg::Geometry* sateAxis;	// 轨道坐标系轴
	osg::MatrixTransform* cone;	// 卫星信号传导信息椎体
	osg::PositionAttitudeTransform* sateModel;
	miniMapTrack* track;

	osg::MatrixTransform* rotateMT;

	QDateTime startSimTime;	// 开始仿真时间
	QDateTime currentSimTime;	// 当前仿真时间

	SatelliteInfo	Info;
};

//SGP4, 即简化常规摄动模型是由KenCranford在1970年开发的, 用于近地卫星状态预报, 
//这些模型考虑到地球非球形引力、日月引力、太阳辐射压及大气阻力等摄动力的影响。
//可以应用于轨道周期小于225分钟的近地球物体。
//SDP4, 即简化深空摄动模型, 应用于远离地球或者轨道周期大于225分钟的物体的状态预报。将TLE轨道数据代入SGP4 / SDP4模型, 
//可以成功地对空间目标进行预测, 求解出目标物体在任意时刻的位置和速度。

/**
* @brief 仿真时间
* @return
*/
extern QDateTime g_simTime;

/**
* @brief 姿态转四元素
* @return
*/
osg::Quat HPRToQuat(double heading, double pitch, double roll);

/**
* @brief 添加全局坐标系轴
* @return
*/
osg::Geode* addAxis(float length);

/**
* @brief 添加卫星坐标系轴
* @return
*/
osg::Geometry* addSateAxis(float length, osg::Vec3 position, osg::Vec3 norOribt);

/**
* @brief 添加HUD
* @return
*/
osg::Node* addHUD();

/**
* @brief 添加HUD
* @return
*/
osg::Node* addHUD(const wchar_t* s, osg::Vec3 position);

// 世界坐标转经纬度
osg::Vec3d WorldToLonLatAlt(const osg::Vec3d world);

/**
* @brief 添加轨道
* @return
*/
osg::Geode* addOribt(COE_ELEMENT* element, double period, osg::Vec3& firstVert, osg::Vec3& oribtNor, std::vector<osg::Vec3>& lonlats, osg::Vec4 color);

/**
* @brief 计算某一时刻卫星的位置
* @return
*/
osg::Vec3d getSatePosition(COE_ELEMENT* element, double time_s);

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
	QColor color);

float calcAngle0(osg::Vec3f line1, osg::Vec3f line2);

/**
* @brief 计算两向量夹角
* @return
*/
float calcAngle(osg::Vec3f line1, osg::Vec3f line2, osg::Vec3f direction);

/**
* 两点画圆锥
*/
osg::MatrixTransform* createCone(const osg::Vec3 &from, const osg::Vec3 &to, float radius);

/**
* 两点画圆柱
*/
osg::MatrixTransform* createCylinder(const osg::Vec3 &from, const osg::Vec3 &to, float radius);

/**
* 打印日志
*/
void printLog(QString text, QPlainTextEdit* textEdit = nullptr);

/**
* 添加金字塔
*/
osg::MatrixTransform* createColorPyramid(float height, float fovx, float fovy, float radius, float transparency1, float transparency2);

/**
* 绘制最大扫描范围
*/
osg::MatrixTransform* drawMaxScanRange(float height, float fovx, float fovy, float radius, float transparency1, float transparency2);

/**
* 绘制当前扫描范围
*/
osg::MatrixTransform* drawCurrentScanRange(float height, float fovx, float fovy, float radius, float transparency1, float transparency2);