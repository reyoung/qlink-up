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
    srand(time(0));
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
    this->resetMap();
    switch(level)
    {
    case 0:
        this->picInit(3,1,9,5);
        break;
    case 1:
        this->picInit(4,1,10,5);
        break;
    case 2:
        this->picInit(3,1,11,5);
        break;
    case 3:
        this->picInit(2,1,12,5);
        break;
    case 4:
        this->picInit(1,1,12,6);
        break;
    }

    this->levelInit();
    this->currentIndex = 0;
    if(this->needSwitch())this->toSwitch();
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
            int rand1 = rand()%count;
            if(current[rand1]->getIndex()==-1)
            {
                current[rand1]->setIndex(i);
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
    /*****For Debug Only
    qDebug()<<"***********************";
    qDebug()<<x1<<" "<<y1;
    qDebug()<<x2<<" "<<y2;
    qDebug()<<"In Points";
    qDebug()<<endl;
    ****************************/

    if(x1==x2&&y1==y2)return false;
    else if(this->picLabels[x1][y1]==0||this->picLabels[x2][y2]==0)return false;
    else if(this->picLabels[x1][y1]->getIndex()!=this->picLabels[x2][y2]->getIndex())return false;
    else if(point(x1,y1)==point(x2+1,y2)||
       point(x1,y1)==point(x2-1,y2)||
       point(x1,y1)==point(x2,y2+1)||
       point(x1,y1)==point(x2,y2-1))return true;
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
    for(;t_y1<6;t_y1++)
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

    if( x2==x1&&(this->findPoint( point( x2,y2-1 ) )
        ||this->findPoint( point( x2,y2+1 ) )))
    {
        return true;
    }
    else if( y2==y1&&(this->findPoint( point( x2-1,y2 ) )
        ||this->findPoint( point( x2+1,y2 ) )))
    {
        return true;
    }
    else
    {
        QVector <point>points;
        qint8 t_x2 = x2;
        qint8 t_y2 = y2;

        t_x2--;
        for(;t_x2>=0;t_x2--)
        {
            if(this->map[t_x2][t_y2]==-1)
            {
                point a;
                a.x = t_x2;
                a.y = t_y2;
                points.push_back(a);
            }
            else break;
        }
        t_x2 = x2+1;
        for(;t_x2<14;t_x2++)
        {
            if(this->map[t_x2][t_y2]==-1)
            {
                point a;
                a.x = t_x2;
                a.y = t_y2;
                points.push_back(a);
            }
            else break;
        }
        t_x2 = x2;
        t_y2--;
        for(;t_y2>=0;t_y2--)
        {
            if(this->map[t_x2][t_y2]==-1)
            {
                point a;
                a.x = t_x2;
                a.y = t_y2;
                points.push_back(a);
            }
            else break;
        }
        t_y2 = y2+1;
        for(;t_y2<6;t_y2++)
        {
            if(this->map[t_x2][t_y2]==-1)
            {
                point a;
                a.x = t_x2;
                a.y = t_y2;
                points.push_back(a);
            }
            else break;
        }
        foreach(point a,points)
        {

            if(this->findPoint(a))return true;
        }
        foreach(point a,points)
        {
            if(this->canExterminateAssist(a))
            {
                return true;
            }
        }
        return false;
    }
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
    if(i==-1&&this->currentIndex!=0)
    {
        this->currentIndex--;
    }
    else this->currentIndex++;
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
            QSound sound("Sound/Right.wav",this);
            sound.play();
            this->map[temp[0].x][temp[0].y]=-1;
            this->map[temp[1].x][temp[1].y]=-1;
            delete this->picLabels[temp[0].x][temp[0].y];
            this->picLabels[temp[0].x][temp[0].y] = 0;
            delete this->picLabels[temp[1].x][temp[1].y];
            this->picLabels[temp[1].x][temp[1].y] = 0;
            emit exterminate();
            if(this->isWin()) emit win();
            else
            {
                if(this->needSwitch())this->toSwitch();
            }
        }
        else
        {
            QSound sound("Sound/Wrong.wav",this);
            sound.play();
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

void PlayWidget::resetMap()
{
    for(qint8 i = 0;i<14;i++)
        for(qint8 j = 0;j<6;j++)
            this->map[i][j]=-1;
}

bool PlayWidget::canExterminateAssist(point a)
{
    qint8 x,y;
    x = a.x-1;
    y = a.y;
    for(;x>=0;x--)
    {
        if(this->map[x][y]==-1)
        {
            if(this->findPoint(point(x,y)))
            {
                return true;
            }
        }
        else
        {
            break;
        }
    }
    x = a.x+1;
    for(;x<14;x++)
    {
        if(this->map[x][y]==-1)
        {
            if(this->findPoint(point(x,y)))
            {
                return true;
            }
        }
        else break;
    }
    x =a.x;
    for(y--;y>=0;y--)
    {

        if(this->map[x][y]==-1)
        {
            if(this->findPoint(point(x,y)))
            {
                return true;
            }
        }
        else break;
    }
    y = a.y;
    for(y++;y<6;y++)
    {
        if(this->map[x][y]==-1)
        {
            if(this->findPoint(point(x,y)))
            {
                return true;
            }
        }
        else break;
    }
    return false;
}

bool PlayWidget::needSwitch()
{
    for(qint8 i = 0; i< 14;i++)
    {
        for(qint8 j = 0; j<6;j++)
        {
            for(qint8 k = 0;k<14;k++)
            {
                for(qint8 l=0;l<6;l++)
                {
                    if(this->canExterminate(i,j,k,l))return false;
                }
            }
        }
    }
    return true;
}

void PlayWidget::toSwitch()
{
    do{
        PicLabel* a;
        PicLabel* b;
        qint8 ax,ay,bx,by;
        do
        {
            ax = rand()%14;
            ay = rand()%6;
        }while(map[ax][ay]==-1);
        a = picLabels[ax][ay];
        do
        {
            bx = rand()%14;
            by = rand()%6;
            if(bx==ax&&by==ay)continue;
        }while(map[bx][by]==-1);
        b = picLabels[bx][by];
        this->map[bx][by] = b->getIndex();
        this->map[ax][ay] = a->getIndex();
        QPoint temp;
        temp = a->pos();
        a->move(b->pos());
        b->move(temp);
        this->picLabels[ax][ay] = b;
        this->picLabels[bx][by] = a;
    }while(this->needSwitch());
}

void PlayWidget::pause()
{

    for(qint8 i=0;i<14;i++ )
    {
        for(qint8 j=0;j<6;j++)
        {
            if(this->picLabels[i][j]!=NULL)
                this->picLabels[i][j]->setEnableClick(!this->picLabels[i][j]->isEnableClick());
        }
    }
}
