#ifndef POINT_H
#define POINT_H
class QPoint;
class QPainter;
class Point

{
public:
    Point(int x=0, int y=0, int size=3);
    bool valid();
    int getX() const;
    void setX(int newX);

    int getY() const;
    void setY(int newY);

    int getSize() const;
    void setSize(int newSize);

    int getWidth() const;
    void setWidth(int newWidth);

    void draw(QPainter *painter);
    void line(QPainter *painter,Point *point);
    float distance2(const QPoint &point);


private:
    int x,y,size, width=1;
};

#endif // POINT_H
