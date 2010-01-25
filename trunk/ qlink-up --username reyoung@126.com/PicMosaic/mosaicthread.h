//*******************************************************************************//
//Name :      Reyoung
//School :      Tju
//QQ :      383147262
//licence :  LGPL
//*******************************************************************************//
#ifndef MOSAICTHREAD_H
#define MOSAICTHREAD_H

#include <QThread>
#include <QImage>
#include <QColor>
#include <QMutex>
#include "block.h"


class mosaicThread : public QThread
{
    Q_OBJECT
public:
    mosaicThread(QObject* parent);
    void setImage(QImage image);
    ~mosaicThread();
public slots:
    void stop();
protected:
    void run();
signals:
    void throwBlock(Block a);
private:
    bool m_pause;
    QImage m_image;
    QMutex m_mutex;
};

#endif // MOSAICTHREAD_H
