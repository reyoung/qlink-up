#include "mosaicthread.h"

mosaicThread::mosaicThread(QObject *parent):QThread(parent)
{
    this->m_pause = true;
}

void mosaicThread::setImage(QImage image)
{
    this->m_image = image;
    this->m_pause = false;
    this->start();
}

void mosaicThread::run()
{
    int x1,y1,x2,y2;
    int size = qMax(m_image.width()/20, m_image.height()/20);
    for(;size>0;size--)
    {
        for(int i=0;i<300;i++)
        {
            do
            {
                x2 = qrand()%this->m_image.width();
            }while(x2-20<0);
            x1 = x2 -20;
            do
            {
                y2 = qrand()%this->m_image.height();
            }while(y2-20<0);
            y1 = y2-20;
            int red=0,green=0,blue=0,n=0;
            for(int j=x1;j<=x2;j++)
            {
                for(int k=y1;k<=y2;k++)
                {
                    n++;
                    QColor t = QColor::fromRgb(this->m_image.pixel(j,k));
                    red +=t.red();
                    green += t.green();
                    blue +=t.blue();
                }
            }
            emit throwBlock(Block(QRect(QPoint(x1,y1),QPoint(x2,y2)),QColor::fromRgb(red/n,green/n,blue/n,64)));
            if(this->m_pause)return;
            usleep(1);
        }
    }
}

void mosaicThread::stop()
{
    this->m_mutex.lock();
    this->m_pause = true;
    this->m_mutex.unlock();
}

mosaicThread::~mosaicThread()
{
    this->stop();
    this->wait();
}
