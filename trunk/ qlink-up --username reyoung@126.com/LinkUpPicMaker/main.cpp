#include <QtGui/QApplication>
#include "picmaker.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PicMaker w;
    w.show();
    return a.exec();
}
