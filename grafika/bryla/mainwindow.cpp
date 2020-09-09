#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    obrazek = new QImage(600, 400, QImage::Format_RGB32);
    Czysc(obrazek);
    d = 100;

    QList<float> tmp;
    for(int i=0; i < 12; i++)
    {
        krawedzie.append(tmp);
    }
    float dlugosc_boku = 100.0;
    //1
    tmp.append(0);
    tmp.append(dlugosc_boku);
    tmp.append(0);

    tmp.append(0);
    tmp.append(dlugosc_boku);
    tmp.append(dlugosc_boku);
    krawedzie.replace(0, tmp);
    tmp.clear();
    //2
    tmp.append(0);
    tmp.append(dlugosc_boku);
    tmp.append(dlugosc_boku);

    tmp.append(dlugosc_boku);
    tmp.append(dlugosc_boku);
    tmp.append(dlugosc_boku);
    krawedzie.replace(1, tmp);
    tmp.clear();
    //3
    tmp.append(dlugosc_boku);
    tmp.append(dlugosc_boku);
    tmp.append(dlugosc_boku);

    tmp.append(dlugosc_boku);
    tmp.append(dlugosc_boku);
    tmp.append(0);
    krawedzie.replace(2, tmp);
    tmp.clear();
    //4
    tmp.append(0);
    tmp.append(dlugosc_boku);
    tmp.append(0);

    tmp.append(dlugosc_boku);
    tmp.append(dlugosc_boku);
    tmp.append(0);
    krawedzie.replace(3, tmp);
    tmp.clear();
    ///////////////////////////////////
    //5
    tmp.append(0);
    tmp.append(0);
    tmp.append(0);

    tmp.append(0);
    tmp.append(0);
    tmp.append(dlugosc_boku);
    krawedzie.replace(4, tmp);
    tmp.clear();
    //6
    tmp.append(0);
    tmp.append(0);
    tmp.append(dlugosc_boku);

    tmp.append(dlugosc_boku);
    tmp.append(0);
    tmp.append(dlugosc_boku);
    krawedzie.replace(5, tmp);
    tmp.clear();
    //7
    tmp.append(dlugosc_boku);
    tmp.append(0);
    tmp.append(dlugosc_boku);

    tmp.append(dlugosc_boku);
    tmp.append(0);
    tmp.append(0);
    krawedzie.replace(6, tmp);
    tmp.clear();
    //8
    tmp.append(0);
    tmp.append(0);
    tmp.append(0);

    tmp.append(dlugosc_boku);
    tmp.append(0);
    tmp.append(0);
    krawedzie.replace(7, tmp);
    tmp.clear();
    /////////////////////////////////////////////////////////////
    //9
    tmp.append(0);
    tmp.append(0);
    tmp.append(0);

    tmp.append(0);
    tmp.append(dlugosc_boku);
    tmp.append(0);
    krawedzie.replace(8, tmp);
    tmp.clear();
    //10
    tmp.append(0);
    tmp.append(0);
    tmp.append(dlugosc_boku);

    tmp.append(0);
    tmp.append(dlugosc_boku);
    tmp.append(dlugosc_boku);
    krawedzie.replace(9, tmp);
    tmp.clear();
    //11
    tmp.append(dlugosc_boku);
    tmp.append(0);
    tmp.append(dlugosc_boku);

    tmp.append(dlugosc_boku);
    tmp.append(dlugosc_boku);
    tmp.append(dlugosc_boku);
    krawedzie.replace(10, tmp);
    tmp.clear();
    //12
    tmp.append(dlugosc_boku);
    tmp.append(0);
    tmp.append(0);

    tmp.append(dlugosc_boku);
    tmp.append(dlugosc_boku);
    tmp.append(0);
    krawedzie.replace(11, tmp);
    tmp.clear();

    macierz_przeksztalcenia = new float*[4];
    t = new float*[4];
    for(int i=0; i < 4; i++)
    {
        macierz_przeksztalcenia[i] = new float[4];
        t[i] = new float[4];
    }
    macierz_przeksztalcenia[0][0] = 1.0;
    macierz_przeksztalcenia[0][1] = 0.0;
    macierz_przeksztalcenia[0][2] = 0.0;
    macierz_przeksztalcenia[0][3] = 0.0;

    macierz_przeksztalcenia[1][0] = 0.0;
    macierz_przeksztalcenia[1][1] = 1.0;
    macierz_przeksztalcenia[1][2] = 0.0;
    macierz_przeksztalcenia[1][3] = 0.0;

    macierz_przeksztalcenia[2][0] = 0.0;
    macierz_przeksztalcenia[2][1] = 0.0;
    macierz_przeksztalcenia[2][2] = 1.0;
    macierz_przeksztalcenia[2][3] = 0.0;

    macierz_przeksztalcenia[3][0] = 0.0;
    macierz_przeksztalcenia[3][1] = 0.0;
    macierz_przeksztalcenia[3][2] = 0.0;
    macierz_przeksztalcenia[3][3] = 1.0;


    przesun = 0;
    skaluj_x = 100;
    skaluj_y = 100;
    skaluj_z = 100;
    obroc = 0;

    Rysuj_Szescian();
    update();
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

void MainWindow::mousePressEvent(QMouseEvent *e)
{
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

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
}

void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
}

void MainWindow::on_exitButton_clicked()
{
    qApp->quit();
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

void MainWindow::on_czyscButton_clicked(){
    QList<float> tmp;
    for(int i=0; i < 12; i++)
    {
        krawedzie.append(tmp);
    }
    float dlugosc_boku = 100.0;
    //1
    tmp.append(0);
    tmp.append(dlugosc_boku);
    tmp.append(0);

    tmp.append(0);
    tmp.append(dlugosc_boku);
    tmp.append(dlugosc_boku);
    krawedzie.replace(0, tmp);
    tmp.clear();
    //2
    tmp.append(0);
    tmp.append(dlugosc_boku);
    tmp.append(dlugosc_boku);

    tmp.append(dlugosc_boku);
    tmp.append(dlugosc_boku);
    tmp.append(dlugosc_boku);
    krawedzie.replace(1, tmp);
    tmp.clear();
    //3
    tmp.append(dlugosc_boku);
    tmp.append(dlugosc_boku);
    tmp.append(dlugosc_boku);

    tmp.append(dlugosc_boku);
    tmp.append(dlugosc_boku);
    tmp.append(0);
    krawedzie.replace(2, tmp);
    tmp.clear();
    //4
    tmp.append(0);
    tmp.append(dlugosc_boku);
    tmp.append(0);

    tmp.append(dlugosc_boku);
    tmp.append(dlugosc_boku);
    tmp.append(0);
    krawedzie.replace(3, tmp);
    tmp.clear();
    ///////////////////////////////////
    //5
    tmp.append(0);
    tmp.append(0);
    tmp.append(0);

    tmp.append(0);
    tmp.append(0);
    tmp.append(dlugosc_boku);
    krawedzie.replace(4, tmp);
    tmp.clear();
    //6
    tmp.append(0);
    tmp.append(0);
    tmp.append(dlugosc_boku);

    tmp.append(dlugosc_boku);
    tmp.append(0);
    tmp.append(dlugosc_boku);
    krawedzie.replace(5, tmp);
    tmp.clear();
    //7
    tmp.append(dlugosc_boku);
    tmp.append(0);
    tmp.append(dlugosc_boku);

    tmp.append(dlugosc_boku);
    tmp.append(0);
    tmp.append(0);
    krawedzie.replace(6, tmp);
    tmp.clear();
    //8
    tmp.append(0);
    tmp.append(0);
    tmp.append(0);

    tmp.append(dlugosc_boku);
    tmp.append(0);
    tmp.append(0);
    krawedzie.replace(7, tmp);
    tmp.clear();
    /////////////////////////////////////////////////////////////
    //9
    tmp.append(0);
    tmp.append(0);
    tmp.append(0);

    tmp.append(0);
    tmp.append(dlugosc_boku);
    tmp.append(0);
    krawedzie.replace(8, tmp);
    tmp.clear();
    //10
    tmp.append(0);
    tmp.append(0);
    tmp.append(dlugosc_boku);

    tmp.append(0);
    tmp.append(dlugosc_boku);
    tmp.append(dlugosc_boku);
    krawedzie.replace(9, tmp);
    tmp.clear();
    //11
    tmp.append(dlugosc_boku);
    tmp.append(0);
    tmp.append(dlugosc_boku);

    tmp.append(dlugosc_boku);
    tmp.append(dlugosc_boku);
    tmp.append(dlugosc_boku);
    krawedzie.replace(10, tmp);
    tmp.clear();
    //12
    tmp.append(dlugosc_boku);
    tmp.append(0);
    tmp.append(0);

    tmp.append(dlugosc_boku);
    tmp.append(dlugosc_boku);
    tmp.append(0);
    krawedzie.replace(11, tmp);
    tmp.clear();

    macierz_przeksztalcenia[0][0] = 1;
    macierz_przeksztalcenia[0][1] = 0;
    macierz_przeksztalcenia[0][2] = 0;
    macierz_przeksztalcenia[0][3] = 0;

    macierz_przeksztalcenia[1][0] = 0;
    macierz_przeksztalcenia[1][1] = 1;
    macierz_przeksztalcenia[1][2] = 0;
    macierz_przeksztalcenia[1][3] = 0;

    macierz_przeksztalcenia[2][0] = 0;
    macierz_przeksztalcenia[2][1] = 0;
    macierz_przeksztalcenia[2][2] = 1;
    macierz_przeksztalcenia[2][3] = 0;

    macierz_przeksztalcenia[3][0] = 0;
    macierz_przeksztalcenia[3][1] = 0;
    macierz_przeksztalcenia[3][2] = 0;
    macierz_przeksztalcenia[3][3] = 1;

    Czysc(obrazek);
    Rysuj_Szescian();
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

void MainWindow::Rysuj_Szescian()
{
    Czysc(obrazek);
    //przemnozenie punktow przez translacje
    for(int i=0; i < 12; i++)
    {
       QList<float> krawedz = krawedzie.value(i);
       float *pkt_prim = new float[4];
       float *pkt = new float[4];

       for(int i=0; i < 6; i++){
           std::cout << krawedz.value(i) << " ";
       }
       std::cout << "\n";

       pkt[0] = krawedz.value(0);
       pkt[1] = krawedz.value(1);
       pkt[2] = krawedz.value(2);
       pkt[3] = 1;

       pkt_prim[0] = 0;
       pkt_prim[1] = 0;
       pkt_prim[2] = 0;
       pkt_prim[3] = 1;

       Mnozenie_macierzy_4x1(pkt_prim, pkt);
       krawedz.replace(0, pkt_prim[0]);
       krawedz.replace(1, pkt_prim[1]);
       krawedz.replace(2, pkt_prim[2]);
       ///
       pkt[0] = krawedz.value(3);
       pkt[1] = krawedz.value(4);
       pkt[2] = krawedz.value(5);
       pkt[3] = 1;

       pkt_prim[0] = 0;
       pkt_prim[1] = 0;
       pkt_prim[2] = 0;
       pkt_prim[3] = 1;

       Mnozenie_macierzy_4x1(pkt_prim, pkt);
       krawedz.replace(3, pkt_prim[0]);
       krawedz.replace(4, pkt_prim[1]);
       krawedz.replace(5, pkt_prim[2]);

       for(int i=0; i < 6; i++){
           std::cout << krawedz.value(i) << " ";
       }
       std::cout << " b\n";

       krawedzie.replace(i, krawedz);
    }
    //rysowanie
    for(int i=0; i < 12; i++)
    {
        QList<float> krawedz = krawedzie.value(i);
        float x = krawedz.value(0);
        float y = krawedz.value(1);
        float z = krawedz.value(2);
        if(z + d == 0)z++;
        float x1 = (x*d)/(z+d);
        float y1 = (y*d)/(z+d);
        x = krawedz.value(3);
        y = krawedz.value(4);
        z = krawedz.value(5);
        if(z + d == 0)z++;
        float x2 = (x*d)/(z+d);
        float y2 = (y*d)/(z+d);
        Rysuj_Odcinek((int)x1 + 300, (int)y1 + 200, (int)x2 + 300, (int)y2 + 200);
    }
    repaint();
}




void MainWindow::on_przesunXButton_clicked()
{
    //
    macierz_przeksztalcenia[0][0] = 1;
    macierz_przeksztalcenia[0][1] = 0;
    macierz_przeksztalcenia[0][2] = 0;
    macierz_przeksztalcenia[0][3] = 0;

    macierz_przeksztalcenia[1][0] = 0;
    macierz_przeksztalcenia[1][1] = 1;
    macierz_przeksztalcenia[1][2] = 0;
    macierz_przeksztalcenia[1][3] = 0;

    macierz_przeksztalcenia[2][0] = 0;
    macierz_przeksztalcenia[2][1] = 0;
    macierz_przeksztalcenia[2][2] = 1;
    macierz_przeksztalcenia[2][3] = 0;

    macierz_przeksztalcenia[3][0] = 0;
    macierz_przeksztalcenia[3][1] = 0;
    macierz_przeksztalcenia[3][2] = 0;
    macierz_przeksztalcenia[3][3] = 1;
    //
    t[0][0] = 1;
    t[0][1] = 0;
    t[0][2] = 0;
    t[0][3] = przesun;

    t[1][0] = 0;
    t[1][1] = 1;
    t[1][2] = 0;
    t[1][3] = 0;

    t[2][0] = 0;
    t[2][1] = 0;
    t[2][2] = 1;
    t[2][3] = 0;

    t[3][0] = 0;
    t[3][1] = 0;
    t[3][2] = 0;
    t[3][3] = 1;

    Mnozenie_macierzy_4x4(macierz_przeksztalcenia, t);
    std::cout << "\nprzesun+x =" << przesun << "\n";
    Rysuj_Szescian();
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    przesun = value;
}

void MainWindow::Mnozenie_macierzy_4x4(float **A, float **B)
{
    float C[4][4];
    for(int i= 0; i < 4; i++)
    {
        for(int j=0; j < 4; j++)
        {
            float suma = 0;
            for(int k=0; k < 4; k++)
            {
                suma += A[i][k] * B[k][j];
            }
            C[i][j] = suma;
        }
    }
    for(int i=0; i < 4; i++)
    {
        for(int j=0; j < 4; j++)
        {
            macierz_przeksztalcenia[i][j] = C[i][j];
        }
    }
}

void MainWindow::Mnozenie_macierzy_4x1(float *wynik, float *punkt)
{
    for(int i=0; i < 4; i++)
    {
        wynik[0] += macierz_przeksztalcenia[0][i]*punkt[i];
    }
    for(int i=0; i < 4; i++)
    {
        wynik[1] += macierz_przeksztalcenia[1][i]*punkt[i];
    }
    for(int i=0; i < 4; i++)
    {
        wynik[2] += macierz_przeksztalcenia[2][i]*punkt[i];
    }
}


void MainWindow::on_przesunYButton_clicked()
{
    //
    macierz_przeksztalcenia[0][0] = 1;
    macierz_przeksztalcenia[0][1] = 0;
    macierz_przeksztalcenia[0][2] = 0;
    macierz_przeksztalcenia[0][3] = 0;

    macierz_przeksztalcenia[1][0] = 0;
    macierz_przeksztalcenia[1][1] = 1;
    macierz_przeksztalcenia[1][2] = 0;
    macierz_przeksztalcenia[1][3] = 0;

    macierz_przeksztalcenia[2][0] = 0;
    macierz_przeksztalcenia[2][1] = 0;
    macierz_przeksztalcenia[2][2] = 1;
    macierz_przeksztalcenia[2][3] = 0;

    macierz_przeksztalcenia[3][0] = 0;
    macierz_przeksztalcenia[3][1] = 0;
    macierz_przeksztalcenia[3][2] = 0;
    macierz_przeksztalcenia[3][3] = 1;
    //
    t[0][0] = 1;
    t[0][1] = 0;
    t[0][2] = 0;
    t[0][3] = 0;

    t[1][0] = 0;
    t[1][1] = 1;
    t[1][2] = 0;
    t[1][3] = przesun;

    t[2][0] = 0;
    t[2][1] = 0;
    t[2][2] = 1;
    t[2][3] = 0;

    t[3][0] = 0;
    t[3][1] = 0;
    t[3][2] = 0;
    t[3][3] = 1;

    Mnozenie_macierzy_4x4(macierz_przeksztalcenia, t);
    std::cout << "\nprzesun_y =" << przesun << "\n";
    Rysuj_Szescian();
}

void MainWindow::on_przesunZButton_clicked()
{
    //
    macierz_przeksztalcenia[0][0] = 1;
    macierz_przeksztalcenia[0][1] = 0;
    macierz_przeksztalcenia[0][2] = 0;
    macierz_przeksztalcenia[0][3] = 0;

    macierz_przeksztalcenia[1][0] = 0;
    macierz_przeksztalcenia[1][1] = 1;
    macierz_przeksztalcenia[1][2] = 0;
    macierz_przeksztalcenia[1][3] = 0;

    macierz_przeksztalcenia[2][0] = 0;
    macierz_przeksztalcenia[2][1] = 0;
    macierz_przeksztalcenia[2][2] = 1;
    macierz_przeksztalcenia[2][3] = 0;

    macierz_przeksztalcenia[3][0] = 0;
    macierz_przeksztalcenia[3][1] = 0;
    macierz_przeksztalcenia[3][2] = 0;
    macierz_przeksztalcenia[3][3] = 1;
    //
    t[0][0] = 1;
    t[0][1] = 0;
    t[0][2] = 0;
    t[0][3] = 0;

    t[1][0] = 0;
    t[1][1] = 1;
    t[1][2] = 0;
    t[1][3] = 0;

    t[2][0] = 0;
    t[2][1] = 0;
    t[2][2] = 1;
    t[2][3] = przesun;

    t[3][0] = 0;
    t[3][1] = 0;
    t[3][2] = 0;
    t[3][3] = 1;

    Mnozenie_macierzy_4x4(macierz_przeksztalcenia, t);
    std::cout << "\nprzesun_z =" << przesun << "\n";
    Rysuj_Szescian();
}

void MainWindow::on_horizontalSlider_4_valueChanged(int value)
{
    skaluj_x = value;
}

void MainWindow::on_horizontalSlider_5_valueChanged(int value)
{
    skaluj_y = value;
}

void MainWindow::on_horizontalSlider_6_valueChanged(int value)
{
    skaluj_z = value;
}

void MainWindow::on_skalujButton_clicked()
{
    //
    macierz_przeksztalcenia[0][0] = 1;
    macierz_przeksztalcenia[0][1] = 0;
    macierz_przeksztalcenia[0][2] = 0;
    macierz_przeksztalcenia[0][3] = 0;

    macierz_przeksztalcenia[1][0] = 0;
    macierz_przeksztalcenia[1][1] = 1;
    macierz_przeksztalcenia[1][2] = 0;
    macierz_przeksztalcenia[1][3] = 0;

    macierz_przeksztalcenia[2][0] = 0;
    macierz_przeksztalcenia[2][1] = 0;
    macierz_przeksztalcenia[2][2] = 1;
    macierz_przeksztalcenia[2][3] = 0;

    macierz_przeksztalcenia[3][0] = 0;
    macierz_przeksztalcenia[3][1] = 0;
    macierz_przeksztalcenia[3][2] = 0;
    macierz_przeksztalcenia[3][3] = 1;
    //
    t[0][0] = skaluj_x/100.0;
    t[0][1] = 0;
    t[0][2] = 0;
    t[0][3] = 0;

    t[1][0] = 0;
    t[1][1] = skaluj_y/100.0;
    t[1][2] = 0;
    t[1][3] = 0;

    t[2][0] = 0;
    t[2][1] = 0;
    t[2][2] = skaluj_z/100.0;
    t[2][3] = 0;

    t[3][0] = 0;
    t[3][1] = 0;
    t[3][2] = 0;
    t[3][3] = 1;

    Mnozenie_macierzy_4x4(macierz_przeksztalcenia, t);
    std::cout << "\nskalowanie " << skaluj_x << "\n";
    Rysuj_Szescian();
}

void MainWindow::on_dial_valueChanged(int value)
{
    obroc = value;
}

void MainWindow::on_obrocXButton_clicked()
{
    //
    macierz_przeksztalcenia[0][0] = 1;
    macierz_przeksztalcenia[0][1] = 0;
    macierz_przeksztalcenia[0][2] = 0;
    macierz_przeksztalcenia[0][3] = 0;

    macierz_przeksztalcenia[1][0] = 0;
    macierz_przeksztalcenia[1][1] = 1;
    macierz_przeksztalcenia[1][2] = 0;
    macierz_przeksztalcenia[1][3] = 0;

    macierz_przeksztalcenia[2][0] = 0;
    macierz_przeksztalcenia[2][1] = 0;
    macierz_przeksztalcenia[2][2] = 1;
    macierz_przeksztalcenia[2][3] = 0;

    macierz_przeksztalcenia[3][0] = 0;
    macierz_przeksztalcenia[3][1] = 0;
    macierz_przeksztalcenia[3][2] = 0;
    macierz_przeksztalcenia[3][3] = 1;
    //
    t[0][0] = 1;
    t[0][1] = 0;
    t[0][2] = 0;
    t[0][3] = 0;

    t[1][0] = 0;
    t[1][1] = cos(obroc);
    t[1][2] = -sin(obroc);
    t[1][3] = 0;

    t[2][0] = 0;
    t[2][1] = sin(obroc);
    t[2][2] = cos(obroc);
    t[2][3] = 0;

    t[3][0] = 0;
    t[3][1] = 0;
    t[3][2] = 0;
    t[3][3] = 1;

    Mnozenie_macierzy_4x4(macierz_przeksztalcenia, t);
    std::cout << "\nobracanie_x\n\n";
    Rysuj_Szescian();
}

void MainWindow::on_obrocYButton_clicked()
{
    //
    macierz_przeksztalcenia[0][0] = 1;
    macierz_przeksztalcenia[0][1] = 0;
    macierz_przeksztalcenia[0][2] = 0;
    macierz_przeksztalcenia[0][3] = 0;

    macierz_przeksztalcenia[1][0] = 0;
    macierz_przeksztalcenia[1][1] = 1;
    macierz_przeksztalcenia[1][2] = 0;
    macierz_przeksztalcenia[1][3] = 0;

    macierz_przeksztalcenia[2][0] = 0;
    macierz_przeksztalcenia[2][1] = 0;
    macierz_przeksztalcenia[2][2] = 1;
    macierz_przeksztalcenia[2][3] = 0;

    macierz_przeksztalcenia[3][0] = 0;
    macierz_przeksztalcenia[3][1] = 0;
    macierz_przeksztalcenia[3][2] = 0;
    macierz_przeksztalcenia[3][3] = 1;
    //
    t[0][0] = cos(obroc);
    t[0][1] = 0;
    t[0][2] = sin(obroc);
    t[0][3] = 0;

    t[1][0] = 0;
    t[1][1] = 1;
    t[1][2] = 0;
    t[1][3] = 0;

    t[2][0] = -sin(obroc);
    t[2][1] = 0;
    t[2][2] = cos(obroc);
    t[2][3] = 0;

    t[3][0] = 0;
    t[3][1] = 0;
    t[3][2] = 0;
    t[3][3] = 1;

    Mnozenie_macierzy_4x4(macierz_przeksztalcenia, t);
    std::cout << "\nobracanie_y\n\n";
    Rysuj_Szescian();
}

void MainWindow::on_obrocZButton_clicked()
{
    //
    macierz_przeksztalcenia[0][0] = 1;
    macierz_przeksztalcenia[0][1] = 0;
    macierz_przeksztalcenia[0][2] = 0;
    macierz_przeksztalcenia[0][3] = 0;

    macierz_przeksztalcenia[1][0] = 0;
    macierz_przeksztalcenia[1][1] = 1;
    macierz_przeksztalcenia[1][2] = 0;
    macierz_przeksztalcenia[1][3] = 0;

    macierz_przeksztalcenia[2][0] = 0;
    macierz_przeksztalcenia[2][1] = 0;
    macierz_przeksztalcenia[2][2] = 1;
    macierz_przeksztalcenia[2][3] = 0;

    macierz_przeksztalcenia[3][0] = 0;
    macierz_przeksztalcenia[3][1] = 0;
    macierz_przeksztalcenia[3][2] = 0;
    macierz_przeksztalcenia[3][3] = 1;
    //
    t[0][0] = cos(obroc);
    t[0][1] = -sin(obroc);
    t[0][2] = 0;
    t[0][3] = 0;

    t[1][0] = sin(obroc);
    t[1][1] = cos(obroc);
    t[1][2] = 0;
    t[1][3] = 0;

    t[2][0] = 0;
    t[2][1] = 0;
    t[2][2] = 1;
    t[2][3] = 0;

    t[3][0] = 0;
    t[3][1] = 0;
    t[3][2] = 0;
    t[3][3] = 1;

    Mnozenie_macierzy_4x4(macierz_przeksztalcenia, t);
    std::cout << "\nobracanie_z\n\n";
    Rysuj_Szescian();
}
