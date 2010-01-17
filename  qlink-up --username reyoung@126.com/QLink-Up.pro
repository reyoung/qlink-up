HEADERS += mainwindow.h \
    playwidget.h \
    piclabel.h \
    timeline.h \
    nameanddescriptionwidget.h
SOURCES += mainwindow.cpp \
    Main.cxx \
    playwidget.cpp \
    piclabel.cpp \
    timeline.cpp \
    nameanddescriptionwidget.cpp
FORMS += mainwindow.ui \
    playwidget.ui \
    nameanddescriptionwidget.ui
DESTDIR += Build
RESOURCES += Resources.qrc
QT += phonon
