/****************************************************************************
** Meta object code from reading C++ file 'timeline.h'
**
** Created: Fri Jan 15 22:28:35 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../timeline.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'timeline.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TimeLine[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      20,    9,    9,    9, 0x0a,
      32,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TimeLine[] = {
    "TimeLine\0\0timeOut()\0resetTime()\0"
    "timerSlot()\0"
};

const QMetaObject TimeLine::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_TimeLine,
      qt_meta_data_TimeLine, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TimeLine::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TimeLine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TimeLine::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TimeLine))
        return static_cast<void*>(const_cast< TimeLine*>(this));
    return QLabel::qt_metacast(_clname);
}

int TimeLine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: timeOut(); break;
        case 1: resetTime(); break;
        case 2: timerSlot(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void TimeLine::timeOut()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
