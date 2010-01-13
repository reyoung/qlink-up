#ifndef PICMAKER_H
#define PICMAKER_H

#include <QWidget>
#include <QMessageBox>
#include <QString>
#include <QTextStream>
#include <QFile>
#include <QFileDialog>
#include <QCloseEvent>

namespace Ui {
    class PicMaker;
}

class PicMaker : public QWidget {
    Q_OBJECT
public:
    PicMaker(QWidget *parent = 0);
    ~PicMaker();
protected:
    void changeEvent(QEvent *e);
    void closeEvent(QCloseEvent * e);
private slots:
    void openSlot();
    void saveOnePic();
    void getInformation(int index);
private:
    bool maybeSave();
    void load();

    QPixmap pic;
    Ui::PicMaker *ui;
};

#endif // PICMAKER_H
