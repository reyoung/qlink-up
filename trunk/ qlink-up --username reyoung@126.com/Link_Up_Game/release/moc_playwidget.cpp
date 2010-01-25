/****************************************************************************
** Meta object code from reading C++ file 'playwidget.h'
**
** Created: Mon Jan 25 11:30:08 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../playwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'playwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PlayWidget[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      18,   11,   11,   11, 0x05,
      38,   32,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      61,   55,   11,   11, 0x0a,
      78,   11,   11,   11, 0x0a,
      88,   86,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PlayWidget[] = {
    "PlayWidget\0\0win()\0exterminate()\0index\0"
    "indexChange(int)\0level\0levelChange(int)\0"
    "pause()\0i\0handlePush(int)\0"
};

const QMetaObject PlayWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PlayWidget,
      qt_meta_data_PlayWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PlayWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PlayWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PlayWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PlayWidget))
        return static_cast<void*>(const_cast< PlayWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int PlayWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: win(); break;
        case 1: exterminate(); break;
        case 2: indexChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: levelChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: pause(); break;
        case 5: handlePush((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void PlayWidget::win()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void PlayWidget::exterminate()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void PlayWidget::indexChange(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
