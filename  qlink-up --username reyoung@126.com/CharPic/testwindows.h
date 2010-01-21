#ifndef TESTWINDOWS_H
#define TESTWINDOWS_H

#include <QMainWindow>

namespace Ui {
    class TestWindows;
}

class TestWindows : public QMainWindow {
    Q_OBJECT
public:
    TestWindows(QWidget *parent = 0);
    ~TestWindows();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::TestWindows *ui;
};

#endif // TESTWINDOWS_H
