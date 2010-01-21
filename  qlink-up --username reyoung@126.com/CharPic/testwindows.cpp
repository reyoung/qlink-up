#include "testwindows.h"
#include "ui_testwindows.h"

TestWindows::TestWindows(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TestWindows)
{
    ui->setupUi(this);
}

TestWindows::~TestWindows()
{
    delete ui;
}

void TestWindows::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
