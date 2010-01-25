//*******************************************************************************//
//Name :      Reyoung
//School :      Tju
//QQ :      383147262
//licence :  LGPL
//*******************************************************************************//
#include <QtGui/QApplication>
#include "linecounter.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LineCounter w;
    w.show();
    return a.exec();
}
