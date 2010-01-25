//*******************************************************************************//
//Name :      Reyoung
//School :      Tju
//QQ :      383147262
//licence :  LGPL
//*******************************************************************************//
#ifndef NAMEANDDESCRIPTIONWIDGET_H
#define NAMEANDDESCRIPTIONWIDGET_H

#include <QWidget>
#include <QFile>
#include <QTextStream>

namespace Ui {
    class NameAndDescriptionWidget;
}

class NameAndDescriptionWidget : public QWidget {
    Q_OBJECT
public:
    NameAndDescriptionWidget(QWidget *parent = 0);
    ~NameAndDescriptionWidget();
    void init();
public slots:
    void indexChange(int index);
protected:
    void changeEvent(QEvent *e);
    void paintEvent(QPaintEvent *e);

private:
    Ui::NameAndDescriptionWidget *ui;
};

#endif // NAMEANDDESCRIPTIONWIDGET_H
