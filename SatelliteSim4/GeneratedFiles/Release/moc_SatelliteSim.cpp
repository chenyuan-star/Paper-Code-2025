/****************************************************************************
** Meta object code from reading C++ file 'SatelliteSim.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SatelliteSim.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SatelliteSim.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SatelliteSim_t {
    QByteArrayData data[52];
    char stringdata0[972];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SatelliteSim_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SatelliteSim_t qt_meta_stringdata_SatelliteSim = {
    {
QT_MOC_LITERAL(0, 0, 12), // "SatelliteSim"
QT_MOC_LITERAL(1, 13, 16), // "slotNewSatellite"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 17), // "slotLoadEquipment"
QT_MOC_LITERAL(4, 49, 22), // "slotAddSatelliteFromDB"
QT_MOC_LITERAL(5, 72, 26), // "std::vector<SatelliteInfo>"
QT_MOC_LITERAL(6, 99, 9), // "sateInfos"
QT_MOC_LITERAL(7, 109, 27), // "slotAddSatelliteFromService"
QT_MOC_LITERAL(8, 137, 25), // "slotAddGroundRadarStation"
QT_MOC_LITERAL(9, 163, 20), // "slotRegionalPlanning"
QT_MOC_LITERAL(10, 184, 9), // "slotAbout"
QT_MOC_LITERAL(11, 194, 24), // "slotSetDatetimeToCurrent"
QT_MOC_LITERAL(12, 219, 15), // "slotSetDatetime"
QT_MOC_LITERAL(13, 235, 16), // "slotLightChanged"
QT_MOC_LITERAL(14, 252, 18), // "slotInertiaChanged"
QT_MOC_LITERAL(15, 271, 21), // "slotGraticulesChanged"
QT_MOC_LITERAL(16, 293, 15), // "slotAxisChanged"
QT_MOC_LITERAL(17, 309, 19), // "slotUserDateChanged"
QT_MOC_LITERAL(18, 329, 19), // "slotUserTimeChanged"
QT_MOC_LITERAL(19, 349, 19), // "slotRealtimeChanged"
QT_MOC_LITERAL(20, 369, 17), // "slotManualChanged"
QT_MOC_LITERAL(21, 387, 19), // "slotUpdateSatellite"
QT_MOC_LITERAL(22, 407, 17), // "slotObjectClicked"
QT_MOC_LITERAL(23, 425, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(24, 442, 24), // "slotCurrentObjectChanged"
QT_MOC_LITERAL(25, 467, 14), // "slotAutoRotate"
QT_MOC_LITERAL(26, 482, 18), // "slotEarthRotateing"
QT_MOC_LITERAL(27, 501, 13), // "slotPinCamera"
QT_MOC_LITERAL(28, 515, 15), // "slotResetCamera"
QT_MOC_LITERAL(29, 531, 20), // "slotFixPosLookAround"
QT_MOC_LITERAL(30, 552, 20), // "slotReturnLookAround"
QT_MOC_LITERAL(31, 573, 17), // "slotSatelliteList"
QT_MOC_LITERAL(32, 591, 21), // "slotLoadEquipmentList"
QT_MOC_LITERAL(33, 613, 19), // "slotTreeItemPressed"
QT_MOC_LITERAL(34, 633, 19), // "slotTreeItemChanged"
QT_MOC_LITERAL(35, 653, 17), // "slotSatelliteInfo"
QT_MOC_LITERAL(36, 671, 16), // "slotConfigManage"
QT_MOC_LITERAL(37, 688, 17), // "slotQueryLowOrbit"
QT_MOC_LITERAL(38, 706, 17), // "slotQueryMidOrbit"
QT_MOC_LITERAL(39, 724, 18), // "slotQueryHighOrbit"
QT_MOC_LITERAL(40, 743, 15), // "slotQueryBeidou"
QT_MOC_LITERAL(41, 759, 16), // "slotQueryGalileo"
QT_MOC_LITERAL(42, 776, 23), // "slotQueryCommuSatellite"
QT_MOC_LITERAL(43, 800, 22), // "slotQueryNaviSatellite"
QT_MOC_LITERAL(44, 823, 24), // "slotQueryRemoteSatellite"
QT_MOC_LITERAL(45, 848, 19), // "slotSearchSatellite"
QT_MOC_LITERAL(46, 868, 15), // "slotResizeEvent"
QT_MOC_LITERAL(47, 884, 13), // "QResizeEvent*"
QT_MOC_LITERAL(48, 898, 23), // "slotShowSimpleSateScene"
QT_MOC_LITERAL(49, 922, 21), // "slotCurrentTabChanged"
QT_MOC_LITERAL(50, 944, 5), // "index"
QT_MOC_LITERAL(51, 950, 21) // "slotTabCloseRequested"

    },
    "SatelliteSim\0slotNewSatellite\0\0"
    "slotLoadEquipment\0slotAddSatelliteFromDB\0"
    "std::vector<SatelliteInfo>\0sateInfos\0"
    "slotAddSatelliteFromService\0"
    "slotAddGroundRadarStation\0"
    "slotRegionalPlanning\0slotAbout\0"
    "slotSetDatetimeToCurrent\0slotSetDatetime\0"
    "slotLightChanged\0slotInertiaChanged\0"
    "slotGraticulesChanged\0slotAxisChanged\0"
    "slotUserDateChanged\0slotUserTimeChanged\0"
    "slotRealtimeChanged\0slotManualChanged\0"
    "slotUpdateSatellite\0slotObjectClicked\0"
    "QTreeWidgetItem*\0slotCurrentObjectChanged\0"
    "slotAutoRotate\0slotEarthRotateing\0"
    "slotPinCamera\0slotResetCamera\0"
    "slotFixPosLookAround\0slotReturnLookAround\0"
    "slotSatelliteList\0slotLoadEquipmentList\0"
    "slotTreeItemPressed\0slotTreeItemChanged\0"
    "slotSatelliteInfo\0slotConfigManage\0"
    "slotQueryLowOrbit\0slotQueryMidOrbit\0"
    "slotQueryHighOrbit\0slotQueryBeidou\0"
    "slotQueryGalileo\0slotQueryCommuSatellite\0"
    "slotQueryNaviSatellite\0slotQueryRemoteSatellite\0"
    "slotSearchSatellite\0slotResizeEvent\0"
    "QResizeEvent*\0slotShowSimpleSateScene\0"
    "slotCurrentTabChanged\0index\0"
    "slotTabCloseRequested"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SatelliteSim[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      46,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  244,    2, 0x09 /* Protected */,
       3,    0,  245,    2, 0x09 /* Protected */,
       4,    1,  246,    2, 0x09 /* Protected */,
       4,    0,  249,    2, 0x29 /* Protected | MethodCloned */,
       7,    0,  250,    2, 0x09 /* Protected */,
       8,    0,  251,    2, 0x09 /* Protected */,
       9,    0,  252,    2, 0x09 /* Protected */,
      10,    0,  253,    2, 0x09 /* Protected */,
      11,    0,  254,    2, 0x09 /* Protected */,
      12,    0,  255,    2, 0x09 /* Protected */,
      13,    1,  256,    2, 0x09 /* Protected */,
      14,    1,  259,    2, 0x09 /* Protected */,
      15,    1,  262,    2, 0x09 /* Protected */,
      16,    1,  265,    2, 0x09 /* Protected */,
      17,    1,  268,    2, 0x09 /* Protected */,
      18,    1,  271,    2, 0x09 /* Protected */,
      19,    1,  274,    2, 0x09 /* Protected */,
      20,    1,  277,    2, 0x09 /* Protected */,
      21,    0,  280,    2, 0x09 /* Protected */,
      22,    2,  281,    2, 0x09 /* Protected */,
      24,    2,  286,    2, 0x09 /* Protected */,
      25,    1,  291,    2, 0x09 /* Protected */,
      26,    0,  294,    2, 0x09 /* Protected */,
      27,    0,  295,    2, 0x09 /* Protected */,
      28,    0,  296,    2, 0x09 /* Protected */,
      29,    0,  297,    2, 0x09 /* Protected */,
      30,    0,  298,    2, 0x09 /* Protected */,
      31,    0,  299,    2, 0x09 /* Protected */,
      32,    0,  300,    2, 0x09 /* Protected */,
      33,    2,  301,    2, 0x09 /* Protected */,
      34,    2,  306,    2, 0x09 /* Protected */,
      35,    0,  311,    2, 0x09 /* Protected */,
      36,    0,  312,    2, 0x09 /* Protected */,
      37,    0,  313,    2, 0x09 /* Protected */,
      38,    0,  314,    2, 0x09 /* Protected */,
      39,    0,  315,    2, 0x09 /* Protected */,
      40,    0,  316,    2, 0x09 /* Protected */,
      41,    0,  317,    2, 0x09 /* Protected */,
      42,    0,  318,    2, 0x09 /* Protected */,
      43,    0,  319,    2, 0x09 /* Protected */,
      44,    0,  320,    2, 0x09 /* Protected */,
      45,    0,  321,    2, 0x09 /* Protected */,
      46,    1,  322,    2, 0x09 /* Protected */,
      48,    0,  325,    2, 0x09 /* Protected */,
      49,    1,  326,    2, 0x09 /* Protected */,
      51,    1,  329,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QDate,    2,
    QMetaType::Void, QMetaType::QTime,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 23, QMetaType::Int,    2,    2,
    QMetaType::Void, 0x80000000 | 23, 0x80000000 | 23,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 23, QMetaType::Int,    2,    2,
    QMetaType::Void, 0x80000000 | 23, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 47,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   50,
    QMetaType::Void, QMetaType::Int,   50,

       0        // eod
};

void SatelliteSim::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SatelliteSim *_t = static_cast<SatelliteSim *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotNewSatellite(); break;
        case 1: _t->slotLoadEquipment(); break;
        case 2: _t->slotAddSatelliteFromDB((*reinterpret_cast< std::vector<SatelliteInfo>(*)>(_a[1]))); break;
        case 3: _t->slotAddSatelliteFromDB(); break;
        case 4: _t->slotAddSatelliteFromService(); break;
        case 5: _t->slotAddGroundRadarStation(); break;
        case 6: _t->slotRegionalPlanning(); break;
        case 7: _t->slotAbout(); break;
        case 8: _t->slotSetDatetimeToCurrent(); break;
        case 9: _t->slotSetDatetime(); break;
        case 10: _t->slotLightChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->slotInertiaChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->slotGraticulesChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->slotAxisChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->slotUserDateChanged((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 15: _t->slotUserTimeChanged((*reinterpret_cast< const QTime(*)>(_a[1]))); break;
        case 16: _t->slotRealtimeChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->slotManualChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->slotUpdateSatellite(); break;
        case 19: _t->slotObjectClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 20: _t->slotCurrentObjectChanged((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QTreeWidgetItem*(*)>(_a[2]))); break;
        case 21: _t->slotAutoRotate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->slotEarthRotateing(); break;
        case 23: _t->slotPinCamera(); break;
        case 24: _t->slotResetCamera(); break;
        case 25: _t->slotFixPosLookAround(); break;
        case 26: _t->slotReturnLookAround(); break;
        case 27: _t->slotSatelliteList(); break;
        case 28: _t->slotLoadEquipmentList(); break;
        case 29: _t->slotTreeItemPressed((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 30: _t->slotTreeItemChanged((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 31: _t->slotSatelliteInfo(); break;
        case 32: _t->slotConfigManage(); break;
        case 33: _t->slotQueryLowOrbit(); break;
        case 34: _t->slotQueryMidOrbit(); break;
        case 35: _t->slotQueryHighOrbit(); break;
        case 36: _t->slotQueryBeidou(); break;
        case 37: _t->slotQueryGalileo(); break;
        case 38: _t->slotQueryCommuSatellite(); break;
        case 39: _t->slotQueryNaviSatellite(); break;
        case 40: _t->slotQueryRemoteSatellite(); break;
        case 41: _t->slotSearchSatellite(); break;
        case 42: _t->slotResizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        case 43: _t->slotShowSimpleSateScene(); break;
        case 44: _t->slotCurrentTabChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 45: _t->slotTabCloseRequested((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject SatelliteSim::staticMetaObject = {
    { &RibbonWindow::staticMetaObject, qt_meta_stringdata_SatelliteSim.data,
      qt_meta_data_SatelliteSim,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SatelliteSim::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SatelliteSim::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SatelliteSim.stringdata0))
        return static_cast<void*>(this);
    return RibbonWindow::qt_metacast(_clname);
}

int SatelliteSim::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = RibbonWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 46)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 46;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 46)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 46;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
