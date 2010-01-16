#ifndef PICLABEL_H
#define PICLABEL_H

#include <QLabel>
#include <QString>

class PicLabel : public QLabel
{
Q_OBJECT
    struct privateData;
public:

    explicit PicLabel(QWidget *parent = 0);
    ~PicLabel();
    int getIndex()const;
    bool isPressed();
signals:
    void isPressed(bool p);
public slots:
    void setIndex(const int& index);
protected:
    void mousePressEvent(QMouseEvent *ev);
private:
    privateData* data;
};

#endif // PICLABEL_H
