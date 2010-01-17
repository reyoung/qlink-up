/****************************************************************************
** Meta object code from reading C++ file 'piclabel.h'
**
** Created: Sun Jan 17 12:23:17 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../piclabel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'piclabel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PicLabel[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   10,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      32,   10,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_PicLabel[] = {
    "PicLabel\0\0index\0pressIndex(int)\0"
    "setIndex(int)\0"
};

const QMetaObject PicLabel::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_PicLabel,
      qt_meta_data_PicLabel, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PicLabel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PicLabel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PicLabel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PicLabel))
        return static_cast<void*>(const_cast< PicLabel*>(this));
    return QLabel::qt_metacast(_clname);
}

int PicLabel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: pressIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: setIndex((*reinterpret_cast< const int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void PicLabel::pressIndex(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
