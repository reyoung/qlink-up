//*******************************************************************************//
//Name :      Reyoung
//School :      Tju
//QQ :      383147262
//licence :  LGPL
//*******************************************************************************//
#include <QtGui/QApplication>
#include "charpic.h"
#include <QTextCodec>
#include <QFileDialog>
#include <QTextStream>
#include <QFile>
#include <QDebug>
int main(int argc, char *argv[])
{
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    QApplication a(argc, argv);
    QString imageFn;
    QString tableFn;
    QString outputFn;
    imageFn = QFileDialog::getOpenFileName(0,("Open Image File"),QDir::currentPath(),"*.jpg *.bmp *.png");
    tableFn = QFileDialog::getOpenFileName(0,("Open Text File"),QDir::currentPath(),"*.txt");
    outputFn = QFileDialog::getSaveFileName(0,("Save File"),QDir::currentPath(),"*.txt");
    QFile file(outputFn);
    file.open(QFile::WriteOnly);
    QTextStream fout(&file);
    QFile file2(tableFn);
    file2.open(QFile::ReadOnly);
    QTextStream fin(&file2);
    QString out = CharPic::getCharPic(imageFn,fin.readAll(),QString(),2);
    foreach(QChar a,out)
    {
        if(a!=10)fout<<a;
#ifdef Q_OS_WIN32
        else fout<<"\r\n";
#else
        else fout<<"\n";
#endif
    }
    return 0;
}
