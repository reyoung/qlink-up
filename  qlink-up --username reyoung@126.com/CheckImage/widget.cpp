#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#define RATIO 0.78
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    for(qint8 i =0;i<4;i++)
    {
        num[i]=0;
    }
    this->loadImage("Image/1.png");
    for(qint8 i =0;i<10;i++)
    {
        FeatureVector a;
        this->featureVectors.push_back(a);
    }
    this->connect(this->ui->createVector,SIGNAL(clicked()),this,SLOT(createVectorSlot()));
    this->connect(this->ui->openFile,SIGNAL(clicked()),this,SLOT(openFile()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeEvent(QEvent *e)
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


FeatureVector::FeatureVector()
{
    this->time = 0;
    this->stage1 = 0;
    for(qint8 i =0;i<2;i++)
    {
        for(qint8 j=0;j<2;j++)
        {
            this->stage2[i][j]=0;
        }
    }
    for(qint8 i=0;i<4;i++)
    {
        for(qint8 j=0;j<4;j++)
        {
            this->stage3[i][j]=0;
        }
    }
}


void FeatureVector::addFeatureVectorBool(FeatureVectorBool a)
{
    this->stage1 = qreal(this->stage1*this->time + a.stage1)/(time+1);

    for(qint8 i = 0;i<2;i++)
    {
        for(qint8 j = 0;j<2;j++)
        {
            this->stage2[i][j] = qreal(this->stage2[i][j]*time+a.stage2[i][j])/(time+1);
        }
    }
    for(qint8 i = 0;i<4;i++)
    {
        for(qint8 j = 0;j<4;j++)
        {
            this->stage3[i][j] = qreal(this->stage3[i][j]*time+a.stage3[i][j])/(time+1);
        }
    }
    time++;
}

void Widget::loadImage(QString fn)
{
    QImage image(fn);
    for(qint8 i =0;i<4;i++)
    {
        if(num[i]!=0)
             delete num[i];
    }
    image = image.scaled(image.width()*4,image.height()*4);
    this->ui->image1->setMinimumSize(image.width(),image.height());
    this->ui->image1->setPixmap(QPixmap::fromImage(image));
    QImage image2(image.width(),image.height(),QImage::Format_RGB888);
    QPainter painter(&image2);
    painter.setBrush(QBrush(QColor::fromRgb(255,255,255)));
    painter.drawRect(0,0,image.width(),image.height());
    painter.setBrush(QBrush(QColor::fromRgb(0,0,0)));
    for(int i=0;i<image2.width();i++)
    {
        for(int j=0;j<image2.height();j++)
        {
            QColor temp = image.pixel(i,j);
            if(i<5)continue;
            else if(j<4)continue;
            else if(image2.width()-1-i<4)continue;
            else if(image2.height()-1-j<4)continue;
            else if(temp.red()<120&&temp.green()<120&&temp.blue()<120)
            {
                painter.drawPoint(i,j);
            }
        }
    }
    this->ui->image2->setMinimumSize(image.width(),image.height());
    this->ui->image2->setPixmap(QPixmap::fromImage(image2));
    for(qint8 i =0;i<4;i++)
    {
        num[i]=new QImage((image.width()-20)/4,image.height(),QImage::Format_RGB888);
        QPainter numPainter(num[i]);
        numPainter.drawImage(0,0,image2,20+i*(image.width()-20)/4,0,(image.width()-20)/4,image.height());
        numPainter.end();
        for(qint8 j=3;j<num[i]->width();j++)
        {
            qint8 k =5;
            for(;k<num[i]->height();k++)
            {
                QColor tColor = num[i]->pixel(j,k);
                if(tColor != Qt::black)
                {
                    continue;
                }
                else break;
            }
            if(k==num[i]->height()){
                j=0;
                int width = num[i]->width()-1;
                delete num[i];
                num[i] = new QImage(width,image.height(),QImage::Format_RGB888);
                QPainter tPainter(num[i]);
                tPainter.drawImage(0,0,image2,20+i*(image.width()-20)/4+(image.width()-20)/4-width,0,width,image.height());
                tPainter.end();
            }
            else
            {
                break;
            }
        }
        qint8 j;
        for(j=num[i]->width()-3;j>0;j--)
        {

            qint8 k =3;
            for(;k<num[i]->height();k++)
            {
                QColor tColor = num[i]->pixel(j,k);
                if(tColor == Qt::black)
                {
                    break;
                }
                else continue;
            }
            if(k!=num[i]->height()){
                break;
            }
        }
        QImage* temp = num[i];
        num[i] = new QImage(j,image.height(),QImage::Format_RGB888);
        {
            QPainter tPainter(num[i]);
            tPainter.drawImage(0,0,*temp,0,0,j,image.height());
            delete temp;
            tPainter.end();
        }
        for(j = num[i]->height()-1;j>0;j--)
        {
            qint8 k;
            for(k=0;k<num[i]->width();k++)
            {
                QColor tColor = num[i]->pixel(k,j);
                if(tColor==Qt::black)break;
            }
            if(k!=num[i]->width())break;
        }
        temp = num[i];
        num[i] = new QImage(temp->width(),j,QImage::Format_RGB888);
        {
            QPainter tPainter(num[i]);
            tPainter.drawImage(0,0,*temp,0,0,num[i]->width(),num[i]->height());
            delete temp;
            tPainter.end();
        }
        for(j =4;j<num[i]->height();j++)
        {
            qint8 k;
            for(k=0;k<num[i]->width();k++)
            {
                QColor tColor = num[i]->pixel(k,j);
                if(tColor==Qt::black)break;
            }
            if(k!=num[i]->width())break;
        }
        temp = num[i];
        num[i]  = new QImage(temp->width(),temp->height()-j,QImage::Format_RGB888);
        {
            QPainter tPainter(num[i]);
            tPainter.drawImage(0,0,*temp,0,j,num[i]->width(),num[i]->height());
            delete temp;
            tPainter.end();
        }
/*
        QLabel* a;
        a = new QLabel(this);
        a->setPixmap(QPixmap::fromImage(*num[i]));
        this->ui->verticalLayout->addWidget(a);
        a->show();
        */
    }
}

void Widget::createVectorSlot()
{
    bool a;
    int numInt = this->ui->numValue->text().toInt(&a,10);
    if(!a)return;
    int _numInt[4];
    _numInt[0] = numInt/1000;
    numInt -= _numInt[0]*1000;
    _numInt[1] = numInt /100;
    numInt -= _numInt[1]*100;
    _numInt[2] = numInt/10;
    numInt -= _numInt[2]*10;
    _numInt[3] = numInt;
    for(qint8 i=0;i<4;i++)
    {
        this->createVector(*num[i],_numInt[i]);
    }
}


void Widget::createVector(QImage image, int num)
{
    FeatureVectorBool a;
    int numCount = 0,colorCount = 0;
    for(qint8 i=0;i<image.width();i++)
    {
        for(qint8 j = 0; j<image.height();j++)
        {
            numCount ++;
            colorCount += qGray(image.pixel(i,j));
        }
    }
    if(colorCount/numCount>=255*RATIO)
    {
        a.stage1 = false;
    }
    else
    {
        a.stage1 = true;
    }

    for(qint8 i=0;i<2;i++)
    {
        for(qint8 j=0;j<2;j++)
        {
            numCount = 0 ;colorCount = 0;
            for(qint8 x = i*image.width()/2;x<(i+1)*image.width()/2;x++)
            {
                for(qint8 y = j*image.height()/2;y<(j+1)*image.height()/2;y++)
                {
                    numCount ++;
                    colorCount += qGray(image.pixel(x,y));
                }
            }
            if(colorCount/numCount>=255*RATIO)
            {
                a.stage2[i][j] = false;
            }
            else
            {
                a.stage2[i][j] = true;
            }
        }
    }
    for(qint8 i=0;i<4;i++)
    {
        for(qint8 j=0;j<4;j++)
        {
            numCount = 0 ;colorCount = 0;
            for(qint8 x = i*image.width()/4;x<(i+1)*image.width()/4;x++)
            {
                for(qint8 y = j*image.height()/4;y<(j+1)*image.height()/4;y++)
                {
                    numCount ++;
                    colorCount += qGray(image.pixel(x,y));
                }
            }
            if(colorCount/numCount>=255*RATIO)
            {
                a.stage3[i][j] = false;
            }
            else
            {
                a.stage3[i][j] = true;
            }
        }
    }
    this->featureVectors[num].addFeatureVectorBool(a);
}

void Widget::openFile()
{
    this->loadImage(QFileDialog::getOpenFileName(this,tr("Open File"),QDir::currentPath(),"*.jpg *.png *.bmp"));
}

void Widget::closeEvent(QCloseEvent *e)
{
    QFile * file;
    file = new QFile("FeatureVector.dat");
    file->open(QFile::WriteOnly);
    QTextStream fout(file);
    foreach(FeatureVector a,this->featureVectors)
    {
        fout<<a.time<<"\r\n";
        fout<<a.stage1<<"\r\n";
        for(qint8 i=0;i<2;i++)
            for(qint8 j=0;j<2;j++)
                fout<<a.stage2[i][j]<<" ";
        fout<<"\r\n";
        for(qint8 i=0;i<4;i++)
            for(qint8 j=0;j<4;j++)
                fout<<a.stage3[i][j]<<" ";
        fout<<"\r\n";
    }
}
