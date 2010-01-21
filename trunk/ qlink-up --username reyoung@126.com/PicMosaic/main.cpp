#include <QtGui/QApplication>
#include "picmosaic.h"

int main(int argc, char *argv[])
{
    qRegisterMetaType<Block>();
    QApplication a(argc, argv);
    PicMosaic w;
    w.show();
    return a.exec();
}
