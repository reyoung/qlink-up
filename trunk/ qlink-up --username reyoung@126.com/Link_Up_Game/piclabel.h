//*******************************************************************************//
//Name :      Reyoung
//School :      Tju
//QQ :      383147262
//licence :  LGPL
//*******************************************************************************//
#ifndef PICLABEL_H
#define PICLABEL_H

#include <QLabel>
#include <QString>
#include <QImage>
#include <QRgb>
#include <QColor>

class PicLabel : public QLabel
{
Q_OBJECT
    struct privateData;
public:

    explicit PicLabel(QWidget *parent = 0,const int& index = -1);
    ~PicLabel();
    int getIndex()const;
    bool isPressed();
    void setPressed(bool pressed);
    bool isEnableClick()const;
    void setEnableClick(bool en);
signals:
    void pressIndex(int index);
public slots:
    void setIndex(const int& index);
protected:
    void mousePressEvent(QMouseEvent *ev);
private:
    void f_paint();


    privateData* data;
};

#endif // PICLABEL_H
