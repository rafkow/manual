#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QMouseEvent>
#include <QMatrix>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    face1 = new QImage(":/images/face1.jpg");
    face2 = new QImage(":/images/face2.jpg");
    result = new QImage(ui->frame_2->x() + ui->frame_2->width(),ui->frame_2->y()+ ui->frame_2->height() ,QImage::Format_RGB32);
    insetImage();
}

QRect MainWindow::getDrawingFrame()
{
    return QRect(0,0,ui->frame_2->x() + ui->frame_2->width(),ui->frame_2->y()+ ui->frame_2->height());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter *p = new QPainter(this);
    p->drawImage(getDrawingFrame(),*result);
}
double determinant(int x11,int x12,int x21,int x22)
{
    return ((x11*x22)-(x12*x21));
}


QRgb MainWindow::barycentryczne(int x, int y,double alpha)
{
    int x0 = tPoint[0]->x();
    int y0 = tPoint[0]->y();
    int x1 = tPoint[1]->x();
    int y1 = tPoint[1]->y();
    int x2 = tPoint[2]->x();
    int y2 = tPoint[2]->y();
        double u,v,w;

        v=determinant(x-x0 ,y-y0,
                      x2-x0,y2-y0)/
          determinant(x1-x0,y1-y0,
                      x2-x0,y2-y0);
        w=determinant(x1-x0,y1-y0,
                       x-x0, y-y0)/
          determinant(x1-x0,y1-y0,
                      x2-x0,y2-y0);
        u=1.0-v-w;

    x0 = pPoint[0]->x();
    y0 = pPoint[0]->y();
    x1 = pPoint[1]->x();
    y1 = pPoint[1]->y();
    x2 = pPoint[2]->x();
    y2 = pPoint[2]->y();

    int ii=x-ui->frame_2->x();
    int jj=y-ui->frame_2->y();

    update();

    QPoint resPoint;
    if(u>=0 && v>=0 && w>=0 && u<=1 && v<=1 && w<=1)
       resPoint = QPoint(x0+v*(x1-x0)+w*(x2-x0),
                            y0+v*(y1-y0)+w*(y2-y0));
    else
    {
        int r = ((double)qRed(face1->pixel(ii,jj)))*(1.0-alpha)+
                ((double)qRed(face2->pixel(ii,jj)))*alpha;
        int g = ((double)qGreen(face1->pixel(ii,jj)))*(1.0-alpha)+
                ((double)qGreen(face2->pixel(ii,jj)))*alpha;
        int b = ((double)qBlue(face1->pixel(ii,jj)))*(1.0-alpha)+
                ((double)qBlue(face2->pixel(ii,jj)))*alpha;
        return qRgb(r,g,b);
    }

    if(face1->rect().contains(resPoint))
    {
        int r = ((double)qRed(face1->pixel(resPoint)))*(1.0-alpha)+
                ((double)qRed(face2->pixel(ii,jj)))*alpha;
        int g = ((double)qGreen(face1->pixel(resPoint)))*(1.0-alpha)+
                ((double)qGreen(face2->pixel(ii,jj)))*alpha;
        int b = ((double)qBlue(face1->pixel(resPoint)))*(1.0-alpha)+
                ((double)qBlue(face2->pixel(ii,jj)))*alpha;
        return qRgb(r,g,b);
    }
}

void MainWindow::countImage(double alpha){
        for(uint i=ui->frame_2->x();i<ui->frame_2->x()+ui->frame_2->width();i++)
            for(uint j=ui->frame_2->y();j<ui->frame_2->y()+ui->frame_2->height();j++)
                result->setPixel(i,j,barycentryczne(i,j,alpha));

}

void MainWindow::triangle(QPoint *tab[])
{

   for (int i=0;i<=4;i++){
        int x0=tab[i%3]->x();
        int y0=tab[i%3]->y();
        int x1=tab[(i+1)%3]->x();
        int y1=tab[(i+1)%3]->y();

        for (double t=0;t<=1;t=t+0.001)
            result->setPixel((1-t)*x0+t*x1,(1-t)*y0+t*y1,qRgb(255,0,0));
}
    update();
}
void MainWindow::insetImage()
{
    for(uint i=0;i<ui->frame->width();i++)
        for(uint j=0;j<ui->frame->height();j++){
            result->setPixel(i+ui->frame->x(),
                             j+ui->frame->y(),
                             face1->pixel(i,j));
        }

    for(uint i=0;i<ui->frame->width();i++)
        for(uint j=0;j<ui->frame->height();j++){
            result->setPixel(i+ui->frame_2->x(),
                             j+ui->frame_2->y(),
                             face2->pixel(i,j));

        }
}
void MainWindow::clearField()
{
    for(uint i=ui->frame_2->x();i<ui->frame_2->y()+ui->frame_2->width();i++)
        for(uint j=ui->frame_2->y();j<ui->frame_2->y()+ui->frame_2->height();j++)
            result->setPixel(i,j,qRgb(0,0,0));
    update();
}

void  MainWindow::mousePressEvent(QMouseEvent *event){
    int x = event->x();
    int y = event->y();

        if(y>ui->frame->y() && y<ui->frame->rect().bottomRight().y()){
            if(x>ui->frame->x() && x<ui->frame->x()+ui->frame->width()){
                pPoint[pi%3] =new QPoint(x,y);
                if(pi>1){
                    insetImage();
                    triangle(pPoint);
                    //if(ti>=2)countImage();
                }
                pi++;
            }
            if(x>ui->frame_2->x() &&  x<ui->frame_2->x()+ui->frame_2->width()){
                tPoint[ti%3] =new QPoint(x,y);
                if(ti>1){
                    triangle(tPoint);
                    //if(pi>=2) countImage();
                    triangle(tPoint);
                }
                ti++;
            }
        }
}


void MainWindow::on_sAlpha_valueChanged(int action)
{
    countImage((double)(action)/100.0);
    update();
}
