#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QPainter>
#include <QMessageBox>
#include <QTimeLine>

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
    void on_actionMusic_On_Off_triggered();
    //For BGM Loop
    void bgmFinishSlot();
    //For new game
    void on_newGameButton_clicked();
    void on_actionNew_triggered();
    //GameOver Slot
    void gameOver();
    //For GameWin
    void winSlot();
    //Handle the picLabel exterminate
    void cancellation();
    //For prompt pressed
    void on_promptButton_clicked();
    //For the High Score
    void highScoreSlot();

    void timeLine1Finish();
    void timeLine2Slot(int frame);
    void timeLineSlot(int frame);
private:
    Phonon::MediaObject* mediaObject;
    Phonon::AudioOutput* audioOutput;

    Ui::MainWindow *m_ui;
    PlayWidget* playWidget;
    TimeLine* timeLine;
    NameAndDescriptionWidget* nameNDescriptionWidget;
    void levelUp(int l);

    unsigned int score;
    int tLevel;
    int level;
    int percent;
};

#endif // MAINWINDOW_H
