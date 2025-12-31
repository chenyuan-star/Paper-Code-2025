/****************************************************************************
** Meta object code from reading C++ file 'osgViewerWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../osgViewerWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'osgViewerWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_osgViewerWidget_t {
    QByteArrayData data[5];
    char stringdata0[55];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_osgViewerWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_osgViewerWidget_t qt_meta_stringdata_osgViewerWidget = {
    {
QT_MOC_LITERAL(0, 0, 15), // "osgViewerWidget"
QT_MOC_LITERAL(1, 16, 17), // "signalResizeEvent"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 13), // "QResizeEvent*"
QT_MOC_LITERAL(4, 49, 5) // "event"

    },
    "osgViewerWidget\0signalResizeEvent\0\0"
    "QResizeEvent*\0event"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_osgViewerWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void osgViewerWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        osgViewerWidget *_t = static_cast<osgViewerWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalResizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (osgViewerWidget::*_t)(QResizeEvent * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&osgViewerWidget::signalResizeEvent)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject osgViewerWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_osgViewerWidget.data,
      qt_meta_data_osgViewerWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *osgViewerWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *osgViewerWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_osgViewerWidget.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "osgViewer::CompositeViewer"))
        return static_cast< osgViewer::CompositeViewer*>(this);
    return QWidget::qt_metacast(_clname);
}

int osgViewerWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void osgViewerWidget::signalResizeEvent(QResizeEvent * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
