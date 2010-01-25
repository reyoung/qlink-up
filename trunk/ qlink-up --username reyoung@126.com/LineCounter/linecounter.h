//*******************************************************************************//
//Name :      Reyoung
//School :      Tju
//QQ :      383147262
//licence :  LGPL
//*******************************************************************************//
#ifndef LINECOUNTER_H
#define LINECOUNTER_H

#include <QWidget>
#include <QTextDocument>
#include "../../../NotePad0/fileManager/filemanager.h"
#include "../pro7Ziper/window.h"
namespace Ui {
    class LineCounter;
}

class LineCounter : public QWidget {
    Q_OBJECT
public:
    LineCounter(QWidget *parent = 0);
    ~LineCounter();

protected:
    void changeEvent(QEvent *e);
private slots:
    void countStart();
private:
    Ui::LineCounter *ui;
    fileManager* manager;
friend class fileManager;
};

#endif // LINECOUNTER_H
