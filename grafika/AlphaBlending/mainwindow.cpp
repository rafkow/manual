#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    s1 = new QImage(":/imgs/s1.jpg");
    s2 = new QImage(":/imgs/s2.jpg");
    s3 = new QImage(":/imgs/s3.jpg");
    s4 = new QImage(":/imgs/s4.jpg");
    result = new QImage(ui->frame->width(),ui->frame->height(),QImage::Format_RGB32);
    result->fill(QColor("white"));
    for (int i=0 ; i<4; i++)
        sliderValue[i]=0;
    opcja =1;
}

QRect MainWindow::getDrawingFrame()
{
    return QRect(ui->frame->x(),ui->frame->y(),ui->frame->width(),ui->frame->height());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void  MainWindow::paintEvent(QPaintEvent *)
{
    QPainter *p = new QPainter(this);
    p->drawImage(getDrawingFrame(),*result);
}

QRgb MainWindow::calculatePixel(QRgb s1pix, QRgb s2pix, QRgb s3pix, QRgb s4pix)
{
    int r,g,b,p1,p2,opt =1;
    switch(opcja){
    case 1:
        r =(qRed(s1pix) * sliderValue[0]) / 100.0 + (qRed(s2pix) * sliderValue[1])/100.0 + (qRed(s3pix) * sliderValue[2])/100.0 + (qRed(s4pix) * sliderValue[3])/100.0;
        g =(qGreen(s1pix) * sliderValue[0]) / 100.0 + (qGreen(s2pix) * sliderValue[1])/100.0 + (qGreen(s3pix) * sliderValue[2])/100.0 + (qGreen(s4pix) * sliderValue[3])/100.0;
        b =(qBlue(s1pix) * sliderValue[0]) / 100.0 + (qBlue(s2pix) * sliderValue[1])/100.0 + (qBlue(s3pix) * sliderValue[2])/100.0 + (qBlue(s4pix) * sliderValue[3])/100.0;

        if(sliderValue[0]>1) opt++;
        if(sliderValue[1]>1) opt++;
        if(sliderValue[2]>1) opt++;
        if(sliderValue[3]>1) opt++;
        break;

    case 2:
        r =(qRed(s1pix)*qRed(s2pix))>>8;
        g =(qGreen(s1pix)*qGreen(s2pix))>>8;
        b =(qBlue(s1pix)*qBlue(s2pix))>>8;
        break;
    case 3:
        r =(255-((255-qRed(s1pix))*(255-qRed(s2pix))))>>8;
        g =(255-((255-qGreen(s1pix))*(255-qGreen(s2pix))))>>8;
        b =(255-((255-qBlue(s1pix))*(255-qBlue(s2pix))))>>8;
        break;
    case 4:
        p1 = qRed(s1pix)+qGreen(s1pix)+qBlue(s1pix);
        p2 = qRed(s2pix)+qGreen(s2pix)+qBlue(s2pix);
        if(p1>p2)
            return QRgb(s1pix);
        return QRgb(s2pix);
        break;
    case 5:
        p1 = qRed(s1pix)+qGreen(s1pix)+qBlue(s1pix);
        p2 = qRed(s2pix)+qGreen(s2pix)+qBlue(s2pix);
        if(p1>p2)
            return QRgb(s2pix);
        return QRgb(s1pix);
        break;
    }

    r /= opt ;
    g /= opt ;
    b /= opt ;


    return qRgb(r,g,b);
}

void MainWindow::calculateImage()
{
    for(uint i=0;i<result->width();i++)
        for(uint j=0;j<result->height();j++)
    result->setPixel(i,j,
                     calculatePixel(
                         s1->pixel(i,j),
                         s2->pixel(i,j),
                         s3->pixel(i,j),
                         s4->pixel(i,j)));

}

void MainWindow::on_s1Slider_valueChanged(int value)
{
    sliderValue[0]=(value);
    calculateImage();
    update();
}

void MainWindow::on_s2Slider_valueChanged(int value)
{
    sliderValue[1]=(value);
    calculateImage();
    update();
}

void MainWindow::on_s3Slider_valueChanged(int value)
{
    sliderValue[2]=(value);
    calculateImage();
    update();
}

void MainWindow::on_s4Slider_valueChanged(int value)
{
    sliderValue[3]=(value);
    calculateImage();
    update();
}

void MainWindow::on_rMultiple_clicked(bool checked)
{
    opcja = 2;
    calculateImage();
    update();
}

void MainWindow::on_rScreen_clicked(bool checked)
{
    opcja = 3;
    calculateImage();
    update();
}

void MainWindow::on_rLighten_clicked(bool checked)
{
    opcja = 4;
    calculateImage();
    update();
}

void MainWindow::on_rDarken_clicked(bool checked)
{
    opcja = 5;
    calculateImage();
    update();
}

void MainWindow::on_rAlpha_clicked(bool checked)
{
    opcja =1;
    calculateImage();
    update();
}
