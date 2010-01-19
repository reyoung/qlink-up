#ifndef PLAYWIDGET_H
#define PLAYWIDGET_H

#include <QWidget>
#include <QVector>
#include <QPoint>
#include <time.h>
#include <QSound>
#include "piclabel.h"

namespace Ui {
    class PlayWidget;
}

class PlayWidget : public QWidget {
    Q_OBJECT
public:
    struct point;
    PlayWidget(QWidget *parent = 0);
    ~PlayWidget();
    void deletePics();
public slots:
    void levelChange(int level);
    void pause();
signals:
    void win();
    void exterminate();
    void indexChange(int index);
protected:
    void changeEvent(QEvent *e);
private slots:
    void handlePush(int i);

private:
    qint8 currentIndex;
    Ui::PlayWidget *ui;
    qint8 map[14][6];
    QVector <QVector<PicLabel* > > picLabels;
    QVector <point > enabelPoints;

    bool isWin();
    bool canExterminateAssist(point a);
    bool findPoint(const point& a);
    bool canExterminate(const qint8& x1,const qint8 &y1,const qint8& x2,const qint8 y2);
    bool needSwitch();
    void levelInit();
    void picInit(const qint8&x1,const qint8& y1,const qint8 &x2,const qint8& y2);
    void resetMap();
    void toSwitch();
};

#endif // PLAYWIDGET_H
