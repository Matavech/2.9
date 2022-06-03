#include "point.h"
#include <QDebug>
#include <QPainter>

Point::Point(int x, int y , int size)
{
    this->x=x;
    this->y=y;
    this->size=size;
}
void Point::draw(QPainter *painter)
{
    painter->drawLine(x-(size/2),y,x+(size/2),y);
    painter->drawLine(x,y-(size/2),x,y+(size)/2);
    int width = this->getWidth();
    QPen pen;
    pen.setWidth(width);
    painter->setPen(pen);

}

void Point::line(QPainter *painter, Point *point)
{
    painter->drawLine(point->x,point->y,x,y);
}

float Point::distance2(const QPoint &point)
{
    return ((point.x() - x) * (point.x() - x) + (point.y() - y) * (point.y() - y));
}

bool Point::valid()
{

}

int Point::getX() const
{
    return x;
}

void Point::setX(int newX)
{
    x = newX;
}

int Point::getY() const
{
    return y;
}

void Point::setY(int newY)
{
    y = newY;
}

int Point::getSize() const
{
    return size;
}

void Point::setSize(int newSize)
{
    size = newSize;
}

int Point::getWidth() const
{
    return width;
}

void Point::setWidth(int newWidth)
{
    width = newWidth;
}


