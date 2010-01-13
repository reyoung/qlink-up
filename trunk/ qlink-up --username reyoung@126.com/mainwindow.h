#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>


#include <Phonon>

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

protected:
    void changeEvent(QEvent *e);
private slots:
    void bgmSlot();
    void bgmFinishSlot();
private:
    Phonon::MediaObject* mediaObject;
    Phonon::AudioOutput* audioOutput;

    Ui::MainWindow *m_ui;
    PlayWidget* playWidget;
    TimeLine* timeLine;
};

#endif // MAINWINDOW_H
