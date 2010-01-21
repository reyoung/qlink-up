#ifndef CHARPIXEL_H
#define CHARPIXEL_H
#include <QPainter>
#include <QBitmap>
#include <QString>
#include <QChar>
#include <QVector>
class CharPic:public QObject
{
public:
    static int getCharPixelValue(QChar a,QString family=tr(""));
    static QString getCharPic(QString fn,QString words=tr(""),QString family = tr(""));
private:
    void initValueTable(QString words=tr(""),QString family=tr(""));
    bool isInTable(QChar a);
    struct ValueTable;
    QVector<ValueTable> valueTable;
};

#endif // CHARPIXELVALUE_H
