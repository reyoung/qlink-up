#include <QtGui/QApplication>
#include "testwindows.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestWindows w;
    w.show();
    return a.exec();
}
