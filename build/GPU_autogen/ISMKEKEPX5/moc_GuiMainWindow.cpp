/****************************************************************************
** Meta object code from reading C++ file 'GuiMainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/app/GuiMainWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GuiMainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GuiMainWindow_t {
    QByteArrayData data[9];
    char stringdata0[106];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GuiMainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GuiMainWindow_t qt_meta_stringdata_GuiMainWindow = {
    {
QT_MOC_LITERAL(0, 0, 13), // "GuiMainWindow"
QT_MOC_LITERAL(1, 14, 11), // "calcPhysics"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 6), // "toggle"
QT_MOC_LITERAL(4, 34, 5), // "state"
QT_MOC_LITERAL(5, 40, 17), // "toggleFastPlacing"
QT_MOC_LITERAL(6, 58, 20), // "updatePlaceAsteroids"
QT_MOC_LITERAL(7, 79, 20), // "updateAnimationSpeed"
QT_MOC_LITERAL(8, 100, 5) // "reset"

    },
    "GuiMainWindow\0calcPhysics\0\0toggle\0"
    "state\0toggleFastPlacing\0updatePlaceAsteroids\0"
    "updateAnimationSpeed\0reset"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GuiMainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a /* Public */,
       3,    1,   45,    2, 0x0a /* Public */,
       5,    1,   48,    2, 0x0a /* Public */,
       6,    0,   51,    2, 0x0a /* Public */,
       7,    0,   52,    2, 0x0a /* Public */,
       8,    0,   53,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GuiMainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GuiMainWindow *_t = static_cast<GuiMainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->calcPhysics(); break;
        case 1: _t->toggle((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->toggleFastPlacing((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->updatePlaceAsteroids(); break;
        case 4: _t->updateAnimationSpeed(); break;
        case 5: _t->reset(); break;
        default: ;
        }
    }
}

const QMetaObject GuiMainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_GuiMainWindow.data,
      qt_meta_data_GuiMainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GuiMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GuiMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GuiMainWindow.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::MainWindow"))
        return static_cast< Ui::MainWindow*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int GuiMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
