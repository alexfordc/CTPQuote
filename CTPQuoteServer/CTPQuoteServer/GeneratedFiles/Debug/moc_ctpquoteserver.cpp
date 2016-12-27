/****************************************************************************
** Meta object code from reading C++ file 'ctpquoteserver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ctpquoteserver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ctpquoteserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CTPQuoteServer_t {
    QByteArrayData data[11];
    char stringdata[133];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CTPQuoteServer_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CTPQuoteServer_t qt_meta_stringdata_CTPQuoteServer = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 7),
QT_MOC_LITERAL(2, 23, 0),
QT_MOC_LITERAL(3, 24, 13),
QT_MOC_LITERAL(4, 38, 14),
QT_MOC_LITERAL(5, 53, 31),
QT_MOC_LITERAL(6, 85, 10),
QT_MOC_LITERAL(7, 96, 7),
QT_MOC_LITERAL(8, 104, 11),
QT_MOC_LITERAL(9, 116, 7),
QT_MOC_LITERAL(10, 124, 8)
    },
    "CTPQuoteServer\0MDLogin\0\0ReceiveHqToDB\0"
    "ReceiveHqToDB2\0CThostFtdcDepthMarketDataField*\0"
    "getAppPath\0CString\0getDbConfig\0string&\0"
    "dbconfig"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CTPQuoteServer[] = {

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
       1,    0,   39,    2, 0x08 /* Private */,
       3,    1,   40,    2, 0x08 /* Private */,
       4,    1,   43,    2, 0x08 /* Private */,
       6,    0,   46,    2, 0x08 /* Private */,
       8,    1,   47,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    0x80000000 | 7,
    QMetaType::Bool, 0x80000000 | 9,   10,

       0        // eod
};

void CTPQuoteServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CTPQuoteServer *_t = static_cast<CTPQuoteServer *>(_o);
        switch (_id) {
        case 0: _t->MDLogin(); break;
        case 1: _t->ReceiveHqToDB((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->ReceiveHqToDB2((*reinterpret_cast< CThostFtdcDepthMarketDataField*(*)>(_a[1]))); break;
        case 3: { CString _r = _t->getAppPath();
            if (_a[0]) *reinterpret_cast< CString*>(_a[0]) = _r; }  break;
        case 4: { bool _r = _t->getDbConfig((*reinterpret_cast< string(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject CTPQuoteServer::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_CTPQuoteServer.data,
      qt_meta_data_CTPQuoteServer,  qt_static_metacall, 0, 0}
};


const QMetaObject *CTPQuoteServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CTPQuoteServer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CTPQuoteServer.stringdata))
        return static_cast<void*>(const_cast< CTPQuoteServer*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int CTPQuoteServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
