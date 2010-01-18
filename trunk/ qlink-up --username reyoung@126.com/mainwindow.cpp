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
    //Name And Description
    //and Handle the signal from playwidget
    this->nameNDescriptionWidget = new NameAndDescriptionWidget(this);
    this->m_ui->nameAndDescription->addWidget(this->nameNDescriptionWidget);
    this->connect(this->playWidget,SIGNAL(indexChange(int)),this->nameNDescriptionWidget,SLOT(indexChange(int)));

    //The Background
    this->setAttribute(Qt::WA_NoBackground,true);

    this->level = -1;

    this->connect(this->m_ui->newGameButton,SIGNAL(clicked()),this,SLOT(newGame()));
    this->connect(this->m_ui->actionNew,SIGNAL(triggered()),this,SLOT(newGame()));
    this->connect(this,SIGNAL(levelChange(int)),this->playWidget,SLOT(levelChange(int)));
    //connect time up
    this->connect(this->timeLine,SIGNAL(timeOut()),this,SLOT(gameOver()));
    this->connect(this->playWidget,SIGNAL(win()),this,SLOT(winSlot()));
}

MainWindow::~MainWindow()
{
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
    this->mediaObject->enqueue(Phonon::MediaSource("BGM/BGM.mp3"));
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.setPen(Qt::NoPen);
    painter.setBrush(QBrush(QColor(0,0,0)));
    painter.drawRect(0,0,this->width(),this->height());
    QPixmap currentLevel(tr("BG/level%1.jpg").arg(this->level));

    int currentWidth = currentLevel.width();
    int currentHeight = currentLevel.height()-this->menuBar()->height();
    int deltaWidth,deltaHeight;
    for(;;){
        deltaWidth = this->width()-currentWidth;
        deltaHeight = this->height() - currentHeight;
        if(deltaWidth>=0&&deltaHeight>=0)break;
        currentWidth*=0.95;
        currentHeight*=0.95;
    }
    currentLevel = currentLevel.scaled(currentWidth,currentHeight);
    painter.drawPixmap(deltaWidth/2,this->menuBar()->height()/2+deltaHeight/2,currentWidth,currentHeight,currentLevel);
    painter.end();
}

void MainWindow::newGame()
{
    this->level = 0;
    this->timeLine->setTime(10*pow(2,level));
    this->update();
    emit levelChange(this->level);
}

void MainWindow::gameOver()
{
    this->timeLine->resetTime();
    QMessageBox::warning(this,tr("Game Over"),tr("Time's up!\nGame Over!"));
    this->level = -1;
    this->playWidget->deletePics();
}

void MainWindow::winSlot()
{

    QMessageBox::warning(this,tr("Level Up!"),tr("Level Clear!"));

    this->level = -1;
    this->timeLine->resetTime();
    this->playWidget->deletePics();
    this->nameNDescriptionWidget->indexChange(-1);
}
