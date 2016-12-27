/****************************************************************************
** Meta object code from reading C++ file 'MdSpi.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MdSpi.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MdSpi.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MdSpi_t {
    QByteArrayData data[5];
    char stringdata[62];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MdSpi_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MdSpi_t qt_meta_stringdata_MdSpi = {
    {
QT_MOC_LITERAL(0, 0, 5),
QT_MOC_LITERAL(1, 6, 10),
QT_MOC_LITERAL(2, 17, 0),
QT_MOC_LITERAL(3, 18, 11),
QT_MOC_LITERAL(4, 30, 31)
    },
    "MdSpi\0SendHqToDB\0\0SendHqToDB2\0"
    "CThostFtdcDepthMarketDataField*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MdSpi[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,
       3,    1,   27,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 4,    2,

       0        // eod
};

void MdSpi::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MdSpi *_t = static_cast<MdSpi *>(_o);
        switch (_id) {
        case 0: _t->SendHqToDB((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->SendHqToDB2((*reinterpret_cast< CThostFtdcDepthMarketDataField*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MdSpi::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MdSpi::SendHqToDB)) {
                *result = 0;
            }
        }
        {
            typedef void (MdSpi::*_t)(CThostFtdcDepthMarketDataField * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MdSpi::SendHqToDB2)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject MdSpi::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MdSpi.data,
      qt_meta_data_MdSpi,  qt_static_metacall, 0, 0}
};


const QMetaObject *MdSpi::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MdSpi::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MdSpi.stringdata))
        return static_cast<void*>(const_cast< MdSpi*>(this));
    if (!strcmp(_clname, "CThostFtdcMdSpi"))
        return static_cast< CThostFtdcMdSpi*>(const_cast< MdSpi*>(this));
    return QObject::qt_metacast(_clname);
}

int MdSpi::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void MdSpi::SendHqToDB(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MdSpi::SendHqToDB2(CThostFtdcDepthMarketDataField * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
