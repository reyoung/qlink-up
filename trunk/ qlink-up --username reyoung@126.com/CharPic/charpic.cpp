#include "charpic.h"
#include <QDebug>
struct CharPic::ValueTable
{
    int value;
    QChar data;
    bool operator<(const ValueTable& other)const
    {
        return this->value<other.value;
    }
    bool operator > (const ValueTable& other)const
    {
        return this->value>other.value;
    }
};
int CharPic::getCharPixelValue(QChar a,QString family)
{
    QImage paintZone(20,20,QImage::Format_RGB888);
    QPainter painter(&paintZone);
    QFont tempFont;
    if(family.size())tempFont.setFamily(family);
    tempFont.setPixelSize(20);
    painter.setPen(QColor::fromRgb(0,0,0));
    painter.setBrush(QColor::fromRgb(255,255,255));
    painter.drawRect(0,0,20,20);
    painter.setFont(tempFont);
    painter.drawText(QRectF(0,0,20,20),Qt::AlignCenter,QString().append(a));
    unsigned long long count=0;
    int n=0;
    for(qint8 i =0;i<20;i++)
        for(qint8 j =0;j<20;j++)
        {
            n++;
            count+= qGray(paintZone.pixel(i,j));
        }
    count/=n;
    return count;
}

QString CharPic::getCharPic(QString fn, QString words, QString family, int scale)
{
    CharPic a;
    a.initValueTable(words,family);
    QImage image(fn);
    image = image.scaled(image.width()/scale,image.height()/scale);
    QString output;
    for(int i=0;i<image.height();i++)
    {
        for(int j=0;j<image.width();j++)
        {
            int current = qGray(image.pixel(j,i));
            int k;
            for(k=0;k<a.valueTable.size();k++)
            {
                if(current>a.valueTable[k].value)continue;
                output.append(a.valueTable[k].data);
                break;
            }
            if(k==a.valueTable.size())output.append(tr("¡¡"));

        }
        output.append(10);
    }
    return output;
}

void CharPic::initValueTable(QString words, QString family)
{
    QString word=words;
    if(words.size()==0)
    {
        char ch = 0;
        for(;ch<127;ch++)
        {
            word.append(ch);
        }
        ValueTable t;
        t.value = 250;
        t.data = ' ';
        this->valueTable.push_back(t);
    }

    foreach(QChar a,word)
    {
        if(isInTable(a)&&words.size()!=0)continue;
        int v = getCharPixelValue(a,family);
        ValueTable t;
        t.data = a;
        t.value = v;
        this->valueTable.push_back(t);
    }
    qSort(valueTable);
}

bool CharPic::isInTable(QChar a)
{
    if(!a.isLetter())return true;
    else if((a>='a'&&a<='z')||(a>='A'&&a<='Z'))return true;
    foreach(ValueTable t,valueTable)
    {
        if(a==t.data)return true;
    }
    return false;
}
