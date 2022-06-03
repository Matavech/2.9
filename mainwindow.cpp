#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "point.h"
#include <QPaintEvent>
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    if (crossPoint.size()){
        for(int i=0;i< crossPoint.size();i++){
            Point *point=crossPoint.at(i);
            point->draw(&painter);
            if(i)
                point->line(&painter,crossPoint.at(i-1));
    }
  }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    qDebug("x=%d y=%d",event->x(),event->y());
    QPoint click;
    click.setX(event->x());
    click.setY(event->y());
    bool doclick = false;
    for(int i=0;i<crossPoint.size(); i++){
        if(crossPoint.at(i)->distance2(click)<=5){
            crossPoint.erase(crossPoint.begin()+i);
            doclick= true;
        }
    }
    if(doclick = true){
        Point *point = new Point(event->x(),event->y(),3);
        crossPoint.push_back(point);
}
    repaint();
}


