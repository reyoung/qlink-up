#include "piclabel.h"
#include <QDebug>
struct PicLabel::privateData
{
    int m_index;
    bool isPressed;
    QImage origin;
    QImage gray;
    bool isEnableClick;
};

PicLabel::PicLabel(QWidget *parent,const int& index) :
    QLabel(parent)
{
    this->data = new privateData;
    this->data->isPressed = false;
    this->data->isEnableClick = true;
    this->setIndex(index);
    this->setCursor(Qt::PointingHandCursor);
    this->setMinimumSize(50,80);
    this->setMaximumSize(50,80);

}
void PicLabel::setIndex(const int &index)
{
    this->data->m_index = index;
    this->data->origin = QImage(tr("PIC/%1.bmp").arg(index));
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
    if(!this->data->isEnableClick)return;

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
void PicLabel::setPressed(bool pressed)
{
    this->data->isPressed = pressed;
    this->f_paint();
}

bool PicLabel::isEnableClick()const
{
    return this->data->isEnableClick;
}

void PicLabel::setEnableClick(bool en)
{
    this->data->isEnableClick = en;
}
