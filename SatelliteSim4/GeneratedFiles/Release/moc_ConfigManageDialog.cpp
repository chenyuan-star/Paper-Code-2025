/****************************************************************************
** Meta object code from reading C++ file 'ConfigManageDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ConfigManageDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ConfigManageDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ConfigManageDialog_t {
    QByteArrayData data[8];
    char stringdata0[114];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ConfigManageDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ConfigManageDialog_t qt_meta_stringdata_ConfigManageDialog = {
    {
QT_MOC_LITERAL(0, 0, 18), // "ConfigManageDialog"
QT_MOC_LITERAL(1, 19, 9), // "slotClose"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 21), // "slotUninstallLoadEqu1"
QT_MOC_LITERAL(4, 52, 21), // "slotUninstallLoadEqu2"
QT_MOC_LITERAL(5, 74, 18), // "slotInstallLoadEqu"
QT_MOC_LITERAL(6, 93, 17), // "slotDeletePayload"
QT_MOC_LITERAL(7, 111, 2) // "id"

    },
    "ConfigManageDialog\0slotClose\0\0"
    "slotUninstallLoadEqu1\0slotUninstallLoadEqu2\0"
    "slotInstallLoadEqu\0slotDeletePayload\0"
    "id"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ConfigManageDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x09 /* Protected */,
       3,    0,   40,    2, 0x09 /* Protected */,
       4,    0,   41,    2, 0x09 /* Protected */,
       5,    0,   42,    2, 0x09 /* Protected */,
       6,    1,   43,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,

       0        // eod
};

void ConfigManageDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ConfigManageDialog *_t = static_cast<ConfigManageDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotClose(); break;
        case 1: _t->slotUninstallLoadEqu1(); break;
        case 2: _t->slotUninstallLoadEqu2(); break;
        case 3: _t->slotInstallLoadEqu(); break;
        case 4: _t->slotDeletePayload((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject ConfigManageDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ConfigManageDialog.data,
      qt_meta_data_ConfigManageDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ConfigManageDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConfigManageDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ConfigManageDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ConfigManageDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
