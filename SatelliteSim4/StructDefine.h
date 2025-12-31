#pragma once
#include <QString>
#include <vector>

// 载荷
struct Equipment
{
	QString DeviceType;		// 设备类型
	QString DeviceNumber;	// 设备编号
	bool LoadStatus;
	QString SatelliteID;
	QString Trait;
	QString DeviceModel;
	QString ID;
	QString DeviceName;
};

// 轨道子信息
struct OrbitChildInfo
{
	QString Description;
	QString Pid;
	QString Id;
};

// 卫星信息
struct SatelliteInfo
{
	QString	LaunchNumber;				// 发射序号
	QString Degree;						// 卫星收发器数量
	QString ResidualEnergy;				// 卫星结点剩余能量
	QString StorageCapacity;			// 存储容量
	QString ID;							// 编号
	QString LaunchDate;					// 发射日期
	QString LaunchSite;					// 发射场地
	QString Power;						// 功率
	QString ElectricityQuantity;		// 电量
	QString InternationalNumber;		// 国际编号
	QString ComputingUtilizationRate;	// 资源利用百分比
	QString SatelliteName;				// 卫星名称

	OrbitChildInfo OrbitInfo;			// 轨道信息

	std::vector<Equipment> Equipments;
};

// 轨道信息
struct OrbitInfo
{
	QString ParentDescription;
	QString MainClassId;
	QString ParentId;

	std::vector<OrbitChildInfo> ChildInfos;
};

// 截荷信息
struct LoadEquipment
{
	QString id;
	int deviceId;
	QString deviceName;
	int deviceNum;
	int satelliteID;
	QString deviceType;
	QString deviceState;
	QString image;

	QString toJson()
	{
		return QString("{\"deviceId\":\"%1\",\"satelliteId\":\"%2\",\"deviceName\":\"%3\",\"deviceNum\":\"%4\"}").arg(id).arg(satelliteID).arg(deviceName).arg(deviceNum);
	}
};