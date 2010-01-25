//*******************************************************************************//
//Name :      Reyoung
//School :      Tju
//QQ :      383147262
//licence :  LGPL
//*******************************************************************************//
#include <QtGui/QApplication>
#include "picmosaic.h"
#include "qtwin.h"
int main(int argc, char *argv[])
{
    qRegisterMetaType<Block>();
    QApplication a(argc, argv);

    PicMosaic w;
    w.show();
    if (QtWin::isCompositionEnabled()) {
        QtWin::extendFrameIntoClientArea(&w);
        w.setContentsMargins(0, 0, 0, 0);
    }
    return a.exec();
}
