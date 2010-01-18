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
    PlayWidget(QWidget *parent = 0);
    ~PlayWidget();
    void deletePics();
public slots:
    void levelChange(int level);
signals:
    void indexChange(int index);
protected:
    void changeEvent(QEvent *e);

private:
    Ui::PlayWidget *ui;
    char map[14][6];
    QVector <QVector<PicLabel* > > picLabels;

    void levelInit();
    void picInit(const char&x1,const char& y1,const char &x2,const char& y2);

};

#endif // PLAYWIDGET_H
