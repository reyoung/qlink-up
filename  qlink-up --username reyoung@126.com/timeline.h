#ifndef TIMELINE_H
#define TIMELINE_H

#include <QLabel>
#include <QPaintEvent>
#include <QPainter>
#include <QTimer>

class TimeLine : public QLabel
{
    Q_OBJECT
    struct TimeLinePrivate;
public:
    explicit TimeLine(QWidget *parent = 0);
    //to set the time by second
    void setTime(const unsigned int& sec);
    //increase time
    void timePlusPlus();
    //decrease time
    void timeSubSub();
    //get currentTime;
    int getCurrentTime();
    ~TimeLine();
signals:
    //time out signal
    void timeOut();
public slots:
    //reset the timeline to the maxsize
    void resetTime();
    //pause
    void pause();

protected:
    //paint the timeline
    void paintEvent(QPaintEvent * e);
private slots:
    //reflash timer slot ,call by 1 sec
    void timerSlot();
private:
    //the private data struct of timeline class
    TimeLinePrivate* privateData;
};

#endif // TIMELINE_H
