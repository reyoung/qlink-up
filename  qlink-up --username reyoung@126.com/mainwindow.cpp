#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
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
    this->m_ui->actionMusic_On_Off->setCheckable(true);
    this->connect(this->m_ui->actionMusic_On_Off,SIGNAL(triggered(bool)),
                  this,SLOT(bgmSlot()));

    //BGM
    this->audioOutput = new Phonon::AudioOutput(Phonon::VideoCategory,this);
    this->mediaObject = new Phonon::MediaObject(this);
    Phonon::createPath(this->mediaObject,this->audioOutput);

    this->connect(this->mediaObject,SIGNAL(aboutToFinish()),this,SLOT(bgmFinishSlot()));

    this->setWindowTitle(tr("QLink-Up"));

    this->nameNDescriptionWidget = new NameAndDescriptionWidget(this);
    this->m_ui->nameAndDescription->addWidget(this->nameNDescriptionWidget);
    this->connect(this->playWidget,SIGNAL(indexChange(int)),this->nameNDescriptionWidget,SLOT(indexChange(int)));

    //For Debug Only
    this->timeLine->setTime(300);
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
//BGM Play Or Pause
void MainWindow::bgmSlot()
{
    if(this->m_ui->actionMusic_On_Off->isChecked())
    {
        this->mediaObject->setCurrentSource(Phonon::MediaSource("BGM/BGM.mp3"));
        this->mediaObject->play();
    }
    else
        this->mediaObject->stop();
}
//For BGM Loop
void MainWindow::bgmFinishSlot()
{
    this->mediaObject->setCurrentSource(Phonon::MediaSource("BGM/BGM.mp3"));
    this->mediaObject->play();
}
