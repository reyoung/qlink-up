#ifndef PLAYWIDGET_H
#define PLAYWIDGET_H

#include <QWidget>

namespace Ui {
    class PlayWidget;
}

class PlayWidget : public QWidget {
    Q_OBJECT
public:
    PlayWidget(QWidget *parent = 0);
    ~PlayWidget();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::PlayWidget *ui;
};

#endif // PLAYWIDGET_H
