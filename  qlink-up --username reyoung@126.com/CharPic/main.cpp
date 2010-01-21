#include <QtGui/QApplication>
#include "charpic.h"
#include <QTextCodec>
#include <QFileDialog>
#include <QTextStream>
#include <fstream>
#include <QFile>
#include <QDebug>
using namespace std;
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
    QString out = CharPic::getCharPic(imageFn,fin.readAll());
    foreach(QChar a,out)
    {
        if(a!=10)fout<<a;
        else fout<<"\r\n";
    }
    return 0;
}
