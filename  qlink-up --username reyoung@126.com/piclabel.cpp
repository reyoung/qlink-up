#include "piclabel.h"
#include <QDebug>
struct PicLabel::privateData
{
    int m_index;
    bool isPressed;
    QImage origin;
    QImage gray;
};

PicLabel::PicLabel(QWidget *parent) :
    QLabel(parent)
{
    this->data = new privateData;

}
void PicLabel::setIndex(const int &index)
{
    this->data->m_index = index;
    this->setPixmap(QPixmap(tr("PIC/%1.bmp").arg(index)));
    this->data->origin = this->pixmap()->toImage();

    this->data->gray = this->data->origin;
    for(int i=0;i<this->data->gray.width();i++)
    {
        for(int j=0;j<this->data->gray.height();j++)
        {
            unsigned int gray = qGray(this->data->gray.pixel(i,j));
            gray = gray*256*256 +gray*256+gray;
            this->data->gray.setPixel(i,j,gray);
        }
    }
    this->f_paint();
}

PicLabel::~PicLabel()
{
    delete this->data;
}

int PicLabel::getIndex()const
{
    return this->data->m_index;
}

void PicLabel::mousePressEvent(QMouseEvent *ev)
{

    this->data->isPressed = !this->data->isPressed;

    this->f_paint();
}

bool PicLabel::isPressed()
{
    return this->data->isPressed;
}
inline void PicLabel::f_paint()
{

    if(!this->data->isPressed)
    {

        this->setPixmap(QPixmap::fromImage(this->data->gray));
        emit pressIndex(-1);
    }
    else
    {
        this->setPixmap(QPixmap::fromImage(this->data->origin));
        emit pressIndex(this->data->m_index);
    }
}
