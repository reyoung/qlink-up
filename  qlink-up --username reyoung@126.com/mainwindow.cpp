#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::MainWindow)
{
    m_ui->setupUi(this);
    this->playWidget = new PlayWidget(this);
    this->m_ui->playWidgetLayout->addWidget(this->playWidget);
    this->timeLine = new TimeLine;
    this->timeLine->setText(tr("This is the Time Line , Need to be build"));
    this->m_ui->timeLineLayout->addWidget(this->timeLine);
}

MainWindow::~MainWindow()
{
    delete this->timeLine;
    delete m_ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
