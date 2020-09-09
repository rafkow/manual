#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <string.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    image = new QImage(":/lenabw.bmp");
    result = new QImage(ui->frame->width(),ui->frame->height(),QImage::Format_RGB32);
}

QRect MainWindow::getDrawingFrame()
{
    return QRect(ui->frame->x(),ui->frame->y(),ui->frame->width(),ui->frame->height());
}

void  MainWindow::paintEvent(QPaintEvent *)
{
    QPainter *p = new QPainter(this);
    p->drawImage(getDrawingFrame(),*result);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int isBlack(QRgb col)
{
    if(qRed(col)<2 && qBlue(col)<2 && qGreen(col)<2)
        return 1;
    else
        return 0;
}


void MainWindow::erozja()
{

    uchar tab[ui->frame->width()][ui->frame->height()];
    memset(tab,0,sizeof(uchar)*(ui->frame->width())*(ui->frame->height()));
    for(uint i=0;i<result->width();i++)
        for(uint j=0;j<result->height();j++)
            if(isBlack(result->pixel(i,j)) &&
               isBlack(result->pixel(i-1,j)) &&
               isBlack(result->pixel(i,j-1)) &&
               isBlack(result->pixel(i+1,j)) &&
               isBlack(result->pixel(i,j+1)))
                    tab[i][j]=1;

    for(uint i=0;i<result->width();i++)
        for(uint j=0;j<result->height();j++)
            if(tab[i][j]==1)
               result->setPixel(i,j,qRgb(0,0,0));
            else result->setPixel(i,j,qRgb(255,255,255));
    update();
}

void MainWindow::dylatacja()
{
    uchar tab[ui->frame->width()][ui->frame->height()];
    memset(tab,0,sizeof(uchar)*(ui->frame->width())*(ui->frame->height()));
    for(uint i=0;i<result->width();i++)
        for(uint j=0;j<result->height();j++)
            if(isBlack(result->pixel(i-1,j+1)) ||
               isBlack(result->pixel(i-1,j)) ||
               isBlack(result->pixel(i-1,j-1)) ||
               isBlack(result->pixel(i,j-1)) ||
               isBlack(result->pixel(i,j)) ||
               isBlack(result->pixel(i,j+1)) ||
               isBlack(result->pixel(i+1,j-1)) ||
               isBlack(result->pixel(i+1,j)) ||
               isBlack(result->pixel(i+1,j+1)))
                    tab[i][j]=1;

    for(uint i=0;i<result->width();i++)
        for(uint j=0;j<result->height();j++)
            if(tab[i][j]==1)
               result->setPixel(i,j,qRgb(0,0,0));
            else result->setPixel(i,j,qRgb(255,255,255));
}

void MainWindow::calculateImage()
{
    uchar tab[ui->frame->width()-ui->frame->x()][ui->frame->height()-ui->frame->y()];
    memset(tab,0,sizeof(uchar)*(ui->frame->width()-ui->frame->x())*(ui->frame->height()-ui->frame->y()));
    for(uint i=0;i<result->width();i++)
        for(uint j=0;j<result->height();j++)
            if(isBlack(image->pixel(i,j)))
            result->setPixel(i,j,qRgb(0,0,0));
                else result->setPixel(i,j,qRgb(255,255,255));
}

void MainWindow::on_bNormal_clicked()
{
    calculateImage();
    update();
}


void MainWindow::on_bDylatacja_clicked()
{
    dylatacja();
    update();
}

void MainWindow::on_bErozja_clicked()
{
    erozja();
    update();
}

void MainWindow::on_bOtwarcie_clicked()
{
    erozja();
    dylatacja();
    update();
}

void MainWindow::on_bZamkniecie_clicked()
{
    dylatacja();
    erozja();
    update();
}
