#include "playwidget.h"
#include "ui_playwidget.h"
#include <QDebug>
PlayWidget::PlayWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlayWidget)
{
    ui->setupUi(this);
    this->setMaximumSize(640,480);
    this->setMinimumSize(640,480);
    for(char i=0;i<14;i++){
        QVector<PicLabel *> temp;
        for(char j=0;j<6;j++)
        {
            this->map[i][j]=-1;
            PicLabel* a = 0;
            temp.push_back(a);
        }
        this->picLabels.push_back(temp);
    }
}

PlayWidget::~PlayWidget()
{
    this->deletePics();

    delete ui;
}

void PlayWidget::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void PlayWidget::levelChange(int level)
{

    switch(level)
    {
    case 0:
        this->picInit(6,2,8,4);
    }

    this->levelInit();
}

void PlayWidget::deletePics()
{
    for(char i=0;i<14;i++)
        for(char j=0;j<6;j++)
        {
            if(this->picLabels[i][j]!=NULL)
        {
                delete this->picLabels[i][j];
                this->picLabels[i][j]=0;
            }
        }
}

void PlayWidget::picInit(const char &x1, const char &y1, const char &x2, const char &y2)
{
    for(char i=x1;i<x2;i++)
        for(char j=y1;j<y2;j++)
        {
            PicLabel* a = this->picLabels[i][j];
            a = new PicLabel(this,-1);
            a->move(50*i,80*j);
            a->show();
            this->picLabels[i][j]=a;
            this->connect(a,SIGNAL(pressIndex(int)),this,SIGNAL(indexChange(int)));
        }
}

void PlayWidget::levelInit()
{
    unsigned char count =0;
    QVector<PicLabel* > current;
    for(unsigned char i=0;i<14;i++)
        for(unsigned char j=0;j<6;j++)
            if(this->picLabels[i][j]!=NULL)
            {
                count++;
                current.push_back(this->picLabels[i][j]);
            }
    unsigned char kind = count>>1;
    for(unsigned char i=0;i<kind;i++)
    {
        for(unsigned char j=0;j<2;)
        {
            int rand = qrand()%count;
            if(current[rand]->getIndex()==-1)
            {
                current[rand]->setIndex(i);
                j++;
            }
        }
    }
    for(unsigned char i=0;i<14;i++)
        for(unsigned char j=0;j<6;j++)
            if(this->picLabels[i][j]!=NULL)this->map[i][j]= this->picLabels[i][j]->getIndex();

}
