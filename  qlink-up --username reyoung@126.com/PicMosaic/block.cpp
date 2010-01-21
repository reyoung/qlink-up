#include "block.h"

Block::Block(const QRect &rect, const QColor &color)
{
    this->m_rect = rect;
    this->m_color = color;
}
Block::Block()
{

}
Block::Block(const Block &other)
{
    this->m_rect = other.m_rect;
    this->m_color = other.m_color;
}

QRect Block::rect()const
{
    return this->m_rect;
}
QColor Block::color()const
{
    return this->m_color;
}
Block::~Block()
{

}
