//*******************************************************************************//
//Name :      Reyoung
//School :      Tju
//QQ :      383147262
//licence :  LGPL
//*******************************************************************************//
#ifndef PICMOSAIC_H
#define PICMOSAIC_H

#include <QWidget>
#include <QPixmap>
#include <QString>
#include <QFileDialog>
#include <QImage>
#include <QPainter>

#include "mosaicthread.h"
#include "block.h"

namespace Ui {
    class PicMosaic;
}

class PicMosaic : public QWidget {
    Q_OBJECT
public:
    PicMosaic(QWidget *parent = 0);
    ~PicMosaic();
protected:
    void changeEvent(QEvent *e);
private slots:
    void on_loadFile_clicked();
    void on_reset_clicked();
    void handleBlock(Block a);
    void finishSlot();
private:
    void loadFile(const QString& fn);

    mosaicThread* thread;
    Ui::PicMosaic *ui;
    QPixmap* pixmap;
    QString currentFn;
};

#endif // PICMOSAIC_H
