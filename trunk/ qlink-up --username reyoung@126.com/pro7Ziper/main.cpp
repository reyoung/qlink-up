//*******************************************************************************//
//Name :      Reyoung
//School :      Tju
//QQ :      383147262
//licence :  LGPL
//*******************************************************************************//
#include <QtGui/QApplication>
#include "window.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Window w;
    w.show();
    return a.exec();
}
