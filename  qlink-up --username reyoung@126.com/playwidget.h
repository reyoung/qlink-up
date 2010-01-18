#ifndef PLAYWIDGET_H
#define PLAYWIDGET_H

#include <QWidget>
#include <QVector>
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
signals:
    void win();
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
    bool findPoint(const point& a);
    bool canExterminate(const qint8& x1,const qint8 &y1,const qint8& x2,const qint8 y2);
    void levelInit();
    void picInit(const qint8&x1,const qint8& y1,const qint8 &x2,const qint8& y2);

};

#endif // PLAYWIDGET_H
