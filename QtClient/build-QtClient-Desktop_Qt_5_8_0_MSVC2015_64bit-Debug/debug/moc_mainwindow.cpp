/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QtClient/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[23];
    char stringdata0[360];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 11), // "updateClock"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 12), // "displayError"
QT_MOC_LITERAL(4, 37, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(5, 66, 11), // "readMessage"
QT_MOC_LITERAL(6, 78, 11), // "QTcpSocket*"
QT_MOC_LITERAL(7, 90, 9), // "tcpSocket"
QT_MOC_LITERAL(8, 100, 13), // "get_user_info"
QT_MOC_LITERAL(9, 114, 15), // "get_weather7day"
QT_MOC_LITERAL(10, 130, 20), // "get_weather7day_full"
QT_MOC_LITERAL(11, 151, 13), // "get_city_code"
QT_MOC_LITERAL(12, 165, 8), // "get_city"
QT_MOC_LITERAL(13, 174, 9), // "city_code"
QT_MOC_LITERAL(14, 184, 19), // "update_weather_info"
QT_MOC_LITERAL(15, 204, 9), // "update_ui"
QT_MOC_LITERAL(16, 214, 21), // "on_listWidget_clicked"
QT_MOC_LITERAL(17, 236, 5), // "index"
QT_MOC_LITERAL(18, 242, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(19, 266, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(20, 290, 23), // "on_listWidget_2_clicked"
QT_MOC_LITERAL(21, 314, 23), // "on_listWidget_3_clicked"
QT_MOC_LITERAL(22, 338, 21) // "on_pushButton_clicked"

    },
    "MainWindow\0updateClock\0\0displayError\0"
    "QAbstractSocket::SocketError\0readMessage\0"
    "QTcpSocket*\0tcpSocket\0get_user_info\0"
    "get_weather7day\0get_weather7day_full\0"
    "get_city_code\0get_city\0city_code\0"
    "update_weather_info\0update_ui\0"
    "on_listWidget_clicked\0index\0"
    "on_pushButton_2_clicked\0on_pushButton_3_clicked\0"
    "on_listWidget_2_clicked\0on_listWidget_3_clicked\0"
    "on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x08 /* Private */,
       3,    1,   95,    2, 0x08 /* Private */,
       5,    1,   98,    2, 0x08 /* Private */,
       8,    0,  101,    2, 0x08 /* Private */,
       9,    0,  102,    2, 0x08 /* Private */,
      10,    0,  103,    2, 0x08 /* Private */,
      11,    0,  104,    2, 0x08 /* Private */,
      12,    1,  105,    2, 0x08 /* Private */,
      14,    0,  108,    2, 0x08 /* Private */,
      15,    1,  109,    2, 0x08 /* Private */,
      16,    1,  112,    2, 0x08 /* Private */,
      18,    0,  115,    2, 0x08 /* Private */,
      19,    0,  116,    2, 0x08 /* Private */,
      20,    1,  117,    2, 0x08 /* Private */,
      21,    1,  120,    2, 0x08 /* Private */,
      22,    0,  123,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::QString, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString, QMetaType::QString,   13,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::QModelIndex,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   17,
    QMetaType::Void, QMetaType::QModelIndex,   17,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateClock(); break;
        case 1: _t->displayError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 2: { QString _r = _t->readMessage((*reinterpret_cast< QTcpSocket*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 3: _t->get_user_info(); break;
        case 4: _t->get_weather7day(); break;
        case 5: _t->get_weather7day_full(); break;
        case 6: _t->get_city_code(); break;
        case 7: { QString _r = _t->get_city((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 8: _t->update_weather_info(); break;
        case 9: _t->update_ui((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->on_listWidget_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 11: _t->on_pushButton_2_clicked(); break;
        case 12: _t->on_pushButton_3_clicked(); break;
        case 13: _t->on_listWidget_2_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 14: _t->on_listWidget_3_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 15: _t->on_pushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTcpSocket* >(); break;
            }
            break;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
