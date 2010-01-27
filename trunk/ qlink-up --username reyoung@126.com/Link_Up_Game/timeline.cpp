//*******************************************************************************//
//Name :      Reyoung
//School :      Tju
//QQ :      383147262
//licence :  LGPL
//*******************************************************************************//
#include "timeline.h"
#include <QDebug>
struct TimeLine::TimeLinePrivate
{
    int time;//Total time
    int currentTime;//Current Time
    bool isPause;
};
TimeLine::TimeLine(QWidget *parent) :
    QLabel(parent)
{
    this->setMaximumSize(640,20);
    this->setMinimumSize(640,20);
    this->privateData = new TimeLine::TimeLinePrivate;
    this->privateData->isPause = false;
    this->privateData->currentTime = -1;
    QTimer* timer;
    timer = new QTimer(this);
    this->connect(timer,SIGNAL(timeout()),this,SLOT(timerSlot()));
    timer->start(1000);
}
void TimeLine::setTime(const unsigned int &sec)
{
    this->privateData->time = sec;
    this->privateData->currentTime = sec;
}
void TimeLine::paintEvent(QPaintEvent *e)
{
    if(this->privateData->currentTime==-1)return;
    QPainter* painter;
    painter = new QPainter(this);
    //delete the black edge of time line;
    painter->setPen(Qt::NoPen);
    //The color will change from green to red by time passing
    painter->setBrush(QBrush(QColor::fromRgb(255*double(this->privateData->time-this->privateData->currentTime)/this->privateData->time,
                                             255*(1-double(this->privateData->time-this->privateData->currentTime)/this->privateData->time)
                                             ,0),Qt::SolidPattern));
    //To draw the time line
    painter->drawRect(0,0,this->privateData->currentTime!=-1
                                         ?this->width()*this->privateData->currentTime/this->privateData->time
                                             :this->width()
                                             ,this->height());
    painter->end();
    delete painter;
}
void TimeLine::resetTime()
{
    this->privateData->currentTime = -1;
}

void TimeLine::timerSlot()
{
    if(this->privateData->isPause)return;
    if(this->privateData->currentTime>0)
        this->privateData->currentTime--;
    else if(this->privateData->currentTime==0)
        emit timeOut();
    this->update();
}

TimeLine::~TimeLine()
{
    delete this->privateData;
}

void TimeLine::pause()
{
    this->privateData->isPause = !this->privateData->isPause;
}

void TimeLine::timePlusPlus()
{
    this->privateData->currentTime+= 3;
    if(this->privateData->currentTime>this->privateData->time)
    {
        this->privateData->currentTime = this->privateData->time;
    }
    this->update();
}
int TimeLine::getCurrentTime()
{
    return this->privateData->currentTime;
}
void TimeLine::timeSubSub()
{
    this->privateData->currentTime-= 6;
    if(this->privateData->currentTime!=-1&&this->privateData->currentTime<0)
    {
        this->privateData->currentTime = 0;
    }
    this->update();
}
