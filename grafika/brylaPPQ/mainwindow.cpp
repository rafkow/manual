#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    obrazek = new QImage(400, 400, QImage::Format_RGB32);
    Czysc(obrazek);
    distance = 100;

    zoomX = 1.0;
    zoomY = 1.0;
    zoomZ = 1.0;
    rotX = 0.0;
    rotY = 0.0;
    rotZ = 0.0;
    grabX = 0.0;
    grabY = 0.0;
    grabZ = 0.0;
//    QPair<QVector3D,QVector3D> krawedzie[12];

    float bok = 30.0;

    krawedzie[0] = QPair<QVector3D,QVector3D> (
                    QVector3D(-bok,bok,-bok),
                    QVector3D(-bok,bok,bok));

    krawedzie[1] = QPair<QVector3D,QVector3D> (
                    QVector3D(-bok,bok,bok),
                    QVector3D(bok,bok,bok));

    krawedzie[2] = QPair<QVector3D,QVector3D> (
                    QVector3D(bok,bok,bok),
                    QVector3D(bok,bok,-bok));

    krawedzie[3] = QPair<QVector3D,QVector3D> (
                    QVector3D(-bok,bok,-bok),
                    QVector3D(bok,bok,-bok));

    krawedzie[4] = QPair<QVector3D,QVector3D> (
                    QVector3D(-bok,-bok,-bok),
                    QVector3D(-bok,-bok, bok));

    krawedzie[5] = QPair<QVector3D,QVector3D> (
                    QVector3D(-bok,-bok,bok),
                    QVector3D(bok,-bok,bok));

    krawedzie[6] = QPair<QVector3D,QVector3D> (
                    QVector3D(bok,-bok,bok),
                    QVector3D(bok,-bok,-bok));

    krawedzie[7] = QPair<QVector3D,QVector3D> (
                    QVector3D(-bok,-bok,-bok),
                    QVector3D( bok,-bok,-bok));

    krawedzie[8] = QPair<QVector3D,QVector3D> (
                    QVector3D(-bok,-bok,-bok),
                    QVector3D(-bok, bok,-bok));

    krawedzie[9] = QPair<QVector3D,QVector3D> (
                    QVector3D(-bok,-bok, bok),
                    QVector3D(-bok, bok, bok));

    krawedzie[10] = QPair<QVector3D,QVector3D> (
                    QVector3D(bok,-bok,bok),
                    QVector3D(bok,bok,bok));

    krawedzie[11] = QPair<QVector3D,QVector3D> (
                    QVector3D(bok,-bok,-bok),
                    QVector3D(bok, bok,-bok));


    Rysuj_Szescian(
                MacierzPrzeksztalcenia(zoomX, zoomY, zoomZ,
                                       0.0, 0.0, 0.0,
                                       0.0, 0.0, 0.0)
                );
    update();
}

QMatrix4x4 MainWindow::MacierzObrotuX(float rotX)
{
    return QMatrix4x4(1,         0,          0, 0,
                      0,cosf(rotX),-sinf(rotX), 0,
                      0,sinf(rotX), cosf(rotX), 0,
                      0,         0,          0, 1);
}
QMatrix4x4 MainWindow::MacierzObrotuY(float rotY)
{
    return QMatrix4x4( cosf(rotY),         0,     sinf(rotY), 0,
                                0,         1,              0, 0,
                      -sinf(rotY),         0,     cosf(rotY), 0,
                                0,         0,              0, 1);
}
QMatrix4x4 MainWindow::MacierzObrotuZ(float rotZ)
{
    return QMatrix4x4( cosf(rotZ),-sinf(rotZ), 0,0,
                       sinf(rotZ), cosf(rotZ), 0,0,
                                0,          0, 1,0,
                                0,          0, 0,1);
}
QMatrix4x4 MainWindow::MacierzPrzesuniecia(float grabX, float grabY, float grabZ)
{
    return QMatrix4x4(1,0,0,grabX,
                      0,1,0,grabY,
                      0,0,1,grabZ,
                      0,0,0,1);
}
QMatrix4x4 MainWindow::MacierzSkalowan(float zoomX,float zoomY,float zoomZ)
{
    return QMatrix4x4(zoomX,0,0,0,
                      0,zoomY,0,0,
                      0,0,zoomZ,0,
                      0,0,0,    1);
}
QMatrix4x4 MainWindow::MacierzPrzeksztalcenia()
{
    return MacierzPrzeksztalcenia(zoomX, zoomY, zoomZ,
                                  grabX, grabY, grabZ,
                                  rotX,  rotY,  rotZ);
}

QMatrix4x4 MainWindow::MacierzPrzeksztalcenia(float zoomX, float zoomY, float zoomZ,
                                   float grabX, float grabY, float grabZ,
                                   float rotX,  float rotY,  float rotZ)
{
    return  MacierzSkalowan(zoomX,zoomY,zoomZ)*
            MacierzObrotuX(rotX)*
            MacierzObrotuY(rotY)*
            MacierzObrotuZ(rotZ)*
            MacierzPrzesuniecia(grabX,grabY,grabZ);
}


MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawImage(ui->ramka->pos().x(), ui->ramka->pos().y(), *obrazek);
}
void MainWindow::Czysc(QImage *obrazek)
{
    for(int i=0; i < obrazek->height(); i++)
    {
        uchar *ptr = obrazek->scanLine(i);
        for(int j=0; j < obrazek->width(); j++)
        {
            ptr[4*j] = 200;
            ptr[4*j + 1] = 255;
            ptr[4*j + 2] = 255;
        }
    }
}
int MainWindow::Szukaj_Punktu(QList<QPoint> lista, int x, int y)
{
    for(int i=0; i < lista.length(); i++)
    {
        QPoint tmp = lista.value(i);
        if(x >= tmp.x()-5 && x <= tmp.x()+5 && y >= tmp.y()-5 && y <= tmp.y()+5)return i;
    }
    return -1;
}

void MainWindow::Rysuj_Punkt(int x, int y, QImage *obrazek)
{
    if(x < 0 || y < 0)return;
    if(x > obrazek->width() || y > obrazek->height())return;
    uchar *ptr = obrazek->scanLine(y);
    ptr[4*x] = RGB.blue(); //BLUE
    ptr[4*x + 1] = RGB.green(); //GREEN
    ptr[4*x + 2] = RGB.red();
}
QColor MainWindow::Pobierz_Kolor_Punktu(int x, int y, QImage *obrazek)
{
    QColor tmp;
    uchar *ptr = obrazek->scanLine(y);
    tmp.setBlue(ptr[4*x]);
    tmp.setGreen(ptr[4*x + 1]);
    tmp.setRed(ptr[4*x + 2]);
    return tmp;
}
void MainWindow::Rysuj_Odcinek(int x0, int y0, int x1, int y1)
{
    int kx, ky;
    int dx, dy;
    int err;
    x0 < x1 ? kx = 1 : kx = -1;
    y0 < y1 ? ky = 1 : ky = -1;
    dx = abs(x1 - x0);
    dy = abs(y1 - y0);
    Rysuj_Punkt(x0, y0, obrazek);
    if(dx >= dy)
    {
        err = dx / 2;
        for(int i=0; i < dx; i++)
        {
            x0 = x0 + kx;
            err = err - dy;
            if(err >= 0)Rysuj_Punkt(x0, y0, obrazek);
            else
            {
                y0 = y0 + ky;
                err = err + dx;
                Rysuj_Punkt(x0, y0, obrazek);
            }
        }
    }
    else
    {
        err = dy / 2;
        for(int i = 0; i < dy; i++)
        {
            y0 = y0 + ky;
            err = err - dx;
            if(err >= 0)Rysuj_Punkt(x0, y0, obrazek);
            else
            {
                x0 = x0 + kx;
                err = err + dy;
                Rysuj_Punkt(x0, y0, obrazek);
            }
        }
    }
}
void MainWindow::Rysuj_Szescian(QMatrix4x4 TMatrix)
{
    Czysc(obrazek);
    //przemnozenie punktow przez translacje
    for(int i=0; i < 12; i++)
    {
       QPair<QVector3D,QVector3D> krawedz = krawedzie[i];

       QVector4D pkt1 = Mnozenie_macierzy_4x1(TMatrix,
                                              QVector4D(krawedz.first,1.0));

       QVector4D pkt2 = Mnozenie_macierzy_4x1(TMatrix,
                                              QVector4D(krawedz.second,1.0));

    //rysowanie

        float x1 = (pkt1.x()*distance)/(pkt1.z()+distance);
        float y1 = (pkt1.y()*distance)/(pkt1.z()+distance);
        float x2 = (pkt2.x()*distance)/(pkt2.z()+distance);
        float y2 = (pkt2.y()*distance)/(pkt2.z()+distance);
        //std::cout<<"("<<x1<<","<<y1<<") ("<<x2<<","<<y2<<");\n";
        Rysuj_Odcinek((int)x1 + 200, (int)y1 + 200, (int)x2 + 200, (int)y2 + 200);
    }
    repaint();
}
QVector4D MainWindow::Mnozenie_macierzy_4x1(QMatrix4x4 MatrixT, QVector4D punkt)
{
    double x=0.0,
           y=0.0,
           z=0.0;
    for(int i=0; i < 4; i++)
    {
        x += MatrixT.row(0)[i]*punkt[i];
        y += MatrixT.row(1)[i]*punkt[i];
        z += MatrixT.row(2)[i]*punkt[i];
    }
    return QVector4D(x,y,z,1);
}


void MainWindow::on_grabXSlide_valueChanged(int value)
{
    grabX = (double) value;
    Rysuj_Szescian(MacierzPrzeksztalcenia());
    update();
}

void MainWindow::on_grabYSlide_valueChanged(int value)
{
    grabY = (double) value;
    Rysuj_Szescian(MacierzPrzeksztalcenia());
    update();
}

void MainWindow::on_grabZSlide_valueChanged(int value)
{
    grabZ = (double) value;
    Rysuj_Szescian(MacierzPrzeksztalcenia());
    update();
}

void MainWindow::on_rotXSlide_valueChanged(int value)
{
    rotX = (double) value * 3.14 /180.0;
    Rysuj_Szescian(MacierzPrzeksztalcenia());
    update();
}

void MainWindow::on_rotYSlide_valueChanged(int value)
{
    rotY = (double) value * 3.14 /180.0;
    Rysuj_Szescian(MacierzPrzeksztalcenia());
    update();
}

void MainWindow::on_rotZSlide_valueChanged(int value)
{
    rotZ = (double) value * 3.14 /180.0;
    Rysuj_Szescian(MacierzPrzeksztalcenia());
    update();
}

void MainWindow::on_zoomXSlide_valueChanged(int value)
{
    zoomX = (double) value /100.0;
    Rysuj_Szescian(MacierzPrzeksztalcenia());
    update();
}
void MainWindow::on_zoomYSlide_valueChanged(int value)
{
    zoomY = (double) value /100.0;
    Rysuj_Szescian(MacierzPrzeksztalcenia());
    update();
}
void MainWindow::on_zoomZSlide_valueChanged(int value)
{
    zoomZ = (double) value /100.0;
    Rysuj_Szescian(MacierzPrzeksztalcenia());
    update();
}

void MainWindow::on_distanceSlide_valueChanged(int value)
{
    distance = (double)value;
    Rysuj_Szescian(MacierzPrzeksztalcenia());
    update();
}
