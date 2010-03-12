#ifndef NODE_H
#define NODE_H

#include <QGraphicsItem>
#include <QGraphicsWidget>
#include "graphwidget.h"

class Node : public QGraphicsItem
{
public:
    Node(GraphWidget *graphWidget);
private:
    GraphWidget* m_widget;
};

#endif // NODE_H
