/****************************************************************************
** Meta object code from reading C++ file 'linecounter.h'
**
** Created: Sun Jan 24 23:46:46 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../linecounter.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'linecounter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LineCounter[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_LineCounter[] = {
    "LineCounter\0\0countStart()\0"
};

const QMetaObject LineCounter::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_LineCounter,
      qt_meta_data_LineCounter, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LineCounter::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LineCounter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LineCounter::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LineCounter))
        return static_cast<void*>(const_cast< LineCounter*>(this));
    return QWidget::qt_metacast(_clname);
}

int LineCounter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: countStart(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
