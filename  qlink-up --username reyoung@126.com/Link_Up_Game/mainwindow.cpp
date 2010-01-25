//*******************************************************************************//
//Name :      Reyoung
//School :      Tju
//QQ :      383147262
//licence :  LGPL
//*******************************************************************************//
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
    this->percent = 100;
    this->connect(this,SIGNAL(levelChange(int)),this->playWidget,SLOT(levelChange(int)));
    //connect time up
    this->setMinimumSize(860,580);
    this->setMaximumSize(860,580);

    this->score = 0;
    this->m_ui->scoreLabel->setText(tr("Score:")+tr("%1").arg(this->score));
    this->m_ui->promptButton->setEnabled(false);

    this->connect(this->m_ui->actionAbout_Me,SIGNAL(triggered()),this,SLOT(aboutMe()));
    this->connect(this->timeLine,SIGNAL(timeOut()),this,SLOT(gameOver()));
    this->connect(this->playWidget,SIGNAL(win()),this,SLOT(winSlot()));
    this->connect(this->m_ui->pauseButton,SIGNAL(clicked()),this->timeLine,SLOT(pause()));
    this->connect(this->m_ui->pauseButton,SIGNAL(clicked()),this->playWidget,SLOT(pause()));
    this->connect(this->playWidget,SIGNAL(exterminate()),this,SLOT(cancellation()));
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
void MainWindow::on_actionMusic_On_Off_triggered()
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
    painter.drawPixmap(deltaWidth/2,this->menuBar()->height()/2+deltaHeight/2,currentWidth*this->percent/100,currentHeight,currentLevel);
    painter.end();
}

void MainWindow::on_newGameButton_clicked()
{
    this->score = 0;
    this->levelUp(0);
    this->m_ui->promptButton->setEnabled(true);
    //this->timeLine->setTime(20*pow(2,level));
    this->update();
    //emit levelChange(this->level);
}

void MainWindow::gameOver()
{
    this->m_ui->promptButton->setEnabled(false);
    this->highScoreSlot();
    this->timeLine->resetTime();
    QMessageBox::warning(this,tr("Game Over"),tr("Time's up!\nGame Over!"));
    this->levelUp(-1);
    //this->level = -1;
    //this->playWidget->deletePics();
}

void MainWindow::winSlot()
{
    this->timeLine->pause();
    if(level+1==4)
    {
        this->m_ui->promptButton->setEnabled(false);
        this->score +=this->timeLine->getCurrentTime()*5;
        this->m_ui->scoreLabel->setText(tr("Score:")+tr("%1").arg(this->score));
        this->highScoreSlot();
        //this->timeLine->resetTime();
        QMessageBox::warning(this,tr("Level Up!"),tr("Level Clear!"));
        //this->level = -1;
        this->levelUp(-1);
        this->update();
    }
    else
    {
        //this->level++;
        QMessageBox::warning(this,tr("Level Up!"),tr("Level Up!"));
        //this->timeLine->setTime(20*pow(2,level));
        this->update();
        this->score +=this->timeLine->getCurrentTime()*5;
        this->m_ui->scoreLabel->setText(tr("Score:")+tr("%1").arg(this->score));
        //emit levelChange(this->level);
        this->levelUp(this->level+1);
    }
    this->timeLine->pause();
}

void MainWindow::cancellation()
{
    this->score += 10;
    this->m_ui->scoreLabel->setText(tr("Score:")+tr("%1").arg(this->score));
    this->timeLine->timePlusPlus();
}

void MainWindow::on_actionNew_triggered()
{
    this->on_newGameButton_clicked();
}

void MainWindow::on_promptButton_clicked()
{
    this->playWidget->getPrompt();
    this->timeLine->timeSubSub();
    this->score-=10;
    this->m_ui->scoreLabel->setText(tr("Score:")+tr("%1").arg(this->score));
}

void MainWindow::highScoreSlot()
{

}

void MainWindow::levelUp(int l)
{
    if(l!=-1)
    {
        this->timeLine->setTime(20*pow(2,level));
        emit levelChange(l);
    }
    else{
        this->timeLine->resetTime();
        this->playWidget->deletePics();
    }
    this->tLevel = l;
    QTimeLine* qTimeLine;
    qTimeLine = new QTimeLine(1000,this);
    qTimeLine->setFrameRange(0,100);
    this->connect(qTimeLine,SIGNAL(frameChanged(int)),this,SLOT(timeLineSlot(int)));
    this->connect(qTimeLine,SIGNAL(finished()),this,SLOT(timeLine1Finish()));
    qTimeLine->start();
}
void MainWindow::timeLineSlot(int frame)
{
    this->percent = 100 - frame;
    this->update();
}
void MainWindow::timeLine1Finish()
{
    QTimeLine* t2;
    t2 =new QTimeLine(1000,this);
    t2->setFrameRange(0,100);
    this->level = this->tLevel;
    this->connect(t2,SIGNAL(frameChanged(int)),this,SLOT(timeLine2Slot(int)));
    t2->start();
}
void MainWindow::timeLine2Slot(int frame)
{
    this->percent = frame;
    this->update();
}
void MainWindow::aboutMe()
{
    QMessageBox::warning(this,tr("About me"),tr("This application programed by reyoung under LGPL licence\nQQ:383147262\nE-mail:Reyoung@126.com"));
}
