#include "piclabel.h"

struct PicLabel::privateData
{
    int m_index;
    bool isPressed;
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
    emit isPressed(this->data->isPressed);
    this->update();
}

bool PicLabel::isPressed()
{
    return this->data->isPressed;
}

