#include "playwidget.h"
#include "ui_playwidget.h"
#include <QDebug>

struct PlayWidget::point
{
    qint8 x;
    qint8 y;
    bool operator == (const point& other)const
    {
        return this->x==other.x&&this->y==other.y;
    }
    point(qint8 tx=-1,qint8 ty=-1)
    {
        x= tx;y = ty;
    }
};





PlayWidget::PlayWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlayWidget)
{
    ui->setupUi(this);
    this->currentIndex = 0;
    this->setMaximumSize(640,480);
    this->setMinimumSize(640,480);
    for(qint8 i=0;i<14;i++){
        QVector<PicLabel *> temp;
        for(qint8 j=0;j<6;j++)
        {
            this->map[i][j]=-1;
            PicLabel* a = 0;
            temp.push_back(a);
        }
        this->picLabels.push_back(temp);
    }
    this->connect(this,SIGNAL(indexChange(int)),this,SLOT(handlePush(int)));
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
    this->deletePics();
    switch(level)
    {
    case 0:
        this->picInit(6,2,8,4);
    }

    this->levelInit();
    this->currentIndex = 0;
}

void PlayWidget::deletePics()
{
    for(qint8 i=0;i<14;i++)
        for(qint8 j=0;j<6;j++)
        {
            if(this->picLabels[i][j]!=NULL)
        {
                delete this->picLabels[i][j];
                this->picLabels[i][j]=0;
            }
        }
}

void PlayWidget::picInit(const qint8 &x1, const qint8 &y1, const qint8 &x2, const qint8 &y2)
{
    for(qint8 i=x1;i<x2;i++)
        for(qint8 j=y1;j<y2;j++)
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
    qint8 count =0;
    QVector<PicLabel* > current;
    for(qint8 i=0;i<14;i++)
        for(qint8 j=0;j<6;j++)
            if(this->picLabels[i][j]!=NULL)
            {
                count++;
                current.push_back(this->picLabels[i][j]);
            }
    qint8 kind = count>>1;
    for( qint8 i=0;i<kind;i++)
    {
        for( qint8 j=0;j<2;)
        {
            int rand = qrand()%count;
            if(current[rand]->getIndex()==-1)
            {
                current[rand]->setIndex(i);
                j++;
            }
        }
    }
    for( qint8 i=0;i<14;i++)
        for( qint8 j=0;j<6;j++)
            if(this->picLabels[i][j]!=NULL)this->map[i][j]= this->picLabels[i][j]->getIndex();

}

bool PlayWidget::canExterminate(const qint8 &x1, const qint8 &y1, const qint8 &x2, qint8 y2)
{
    if(this->picLabels[x1][y1]->getIndex()!=this->picLabels[x2][y2]->getIndex())return false;
    this->enabelPoints.clear();
    qint8 t_x1 = x1;
    qint8 t_y1 = y1;
    t_x1--;
    for(;t_x1>=0;t_x1--)
    {
        if(this->map[t_x1][t_y1]==-1)
        {
            point a;
            a.x = t_x1;
            a.y = t_y1;
            this->enabelPoints.push_back(a);
        }
        else break;
    }
    t_x1 = x1+1;
    for(;t_x1<14;t_x1++)
    {
        if(this->map[t_x1][t_y1]==-1)
        {
            point a;
            a.x = t_x1;
            a.y = t_y1;
            this->enabelPoints.push_back(a);
        }
        else break;
    }
    t_x1 = x1;
    t_y1--;
    for(;t_y1>=0;t_y1--)
    {
        if(this->map[t_x1][t_y1]==-1)
        {
            point a;
            a.x = t_x1;
            a.y = t_y1;
            this->enabelPoints.push_back(a);
        }
        else break;
    }
    t_y1 = y1+1;
    for(;t_y1<6;t_y1--)
    {
        if(this->map[t_x1][t_y1]==-1)
        {
            point a;
            a.x = t_x1;
            a.y = t_y1;
            this->enabelPoints.push_back(a);
        }
        else break;
    }
    if(point(x1,y1)==point(x2+1,y2)||
       point(x1,y1)==point(x2-1,y2)||
       point(x1,y1)==point(x2,y2+1)||
       point(x1,y1)==point(x2,y2-1))return true;
    else return false;
}

bool PlayWidget::findPoint(const point &a)
{
    int i=0;
    for(;i<this->enabelPoints.size();i++)
    {
        if(a==this->enabelPoints[i])break;
    }
    if(i==this->enabelPoints.size())return false;
    return true;
}

void PlayWidget::handlePush(int i)
{
    if(i==-1)this->currentIndex--;
    else this->currentIndex++;
    if(this->currentIndex <0)this->currentIndex = 0;
    if(this->currentIndex == 2)
    {
        this->currentIndex = 0;
        QVector< point >temp;

        for(qint8 a=0;a<14;a++)
        {
            for(qint8 b=0;b<6;b++)
            {
                if( this->picLabels[a][b]!=NULL&&this->picLabels[a][b]->isPressed() )
                {
                    this->picLabels[a][b]->setPressed(false);
                    temp.push_back(point(a,b) );
                }
            }
        }
        if(this->canExterminate(temp[0].x,temp[0].y,temp[1].x,temp[1].y))
        {
            this->map[temp[0].x][temp[0].y]=-1;
            this->map[temp[1].x][temp[1].y]=-1;
            this->picLabels[temp[0].x][temp[0].y]->hide();
            this->picLabels[temp[1].x][temp[1].y]->hide();
            if(this->isWin()) emit win();
        }
        else
        {
        }
    }
}
bool PlayWidget::isWin()
{
    for(qint8 i=0;i<14;i++)
        for(qint8 j=0;j<6;j++)
            if(this->map[i][j]!=-1)return false;
    return true;
}
