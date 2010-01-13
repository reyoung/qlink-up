HEADERS += mainwindow.h \
    playwidget.h \
    piclabel.h \
    timeline.h
SOURCES += mainwindow.cpp \
    Main.cxx \
    playwidget.cpp \
    piclabel.cpp \
    timeline.cpp
FORMS += mainwindow.ui \
    playwidget.ui
DESTDIR += Build
RESOURCES += Resources.qrc
QT += phonon
