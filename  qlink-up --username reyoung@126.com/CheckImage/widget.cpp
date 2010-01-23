#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QImage image("Image/1.png");
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
    QImage* num[4];

    for(qint8 i =0;i<4;i++)
    {
        num[i]=new QImage((image.width()-20)/4,image.height(),QImage::Format_RGB888);
        QPainter numPainter(num[i]);
        numPainter.drawImage(0,0,image2,20+i*(image.width()-20)/4,0,(image.width()-20)/4,image.height());
        numPainter.end();
        for(qint8 j=0;j<num[i]->width();j++)
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

        QLabel* a;
        a = new QLabel(this);
        a->setPixmap(QPixmap::fromImage(*num[i]));
        this->ui->verticalLayout->addWidget(a);
        a->show();
    }
    for(qint8 i =0;i<4;i++)
    {
        delete num[i];
    }

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
