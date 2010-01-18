#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QPainter>
#include <QMessageBox>

#include <math.h>

#include <Phonon>

#include "nameanddescriptionwidget.h"
#include "playwidget.h"
#include "timeline.h"


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:
    void levelChange(int l);
protected:
    void changeEvent(QEvent *e);
    void paintEvent(QPaintEvent *e);
private slots:
    //BGM Play Or Pause
    void bgmSlot();
    //For BGM Loop
    void bgmFinishSlot();
    //For new game
    void newGame();
    //GameOver Slot
    void gameOver();
    //For GameWin
    void winSlot();

private:
    Phonon::MediaObject* mediaObject;
    Phonon::AudioOutput* audioOutput;

    Ui::MainWindow *m_ui;
    PlayWidget* playWidget;
    TimeLine* timeLine;
    NameAndDescriptionWidget* nameNDescriptionWidget;

    int level;
};

#endif // MAINWINDOW_H
