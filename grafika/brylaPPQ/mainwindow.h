#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QPainter>
#include <QMouseEvent>
#include <QPoint>
#include <QColor>
#include <QDebug>
#include <QList>
#include <cmath>
#include <algorithm>
#include <QFileDialog>
#include <qthread.h>
#include <QVector3D>
#include <QVector4D>
#include <QMatrix4x4>




namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *);

    QColor Pobierz_Kolor_Punktu(int x, int y, QImage *obrazek);
    void Rysuj_Punkt(int x, int y, QImage *obrazek);
    void Czysc(QImage*);
    int Szukaj_Punktu(QList<QPoint> lista, int x, int y);
    void Rysuj_Szescian(QMatrix4x4 TMatrix);
    void Rysuj_Odcinek(int, int, int, int);

    QVector4D Mnozenie_macierzy_4x1(QMatrix4x4 MatrixT, QVector4D punkt);

    QMatrix4x4 MacierzObrotuX(float rotX);
    QMatrix4x4 MacierzObrotuY(float rotY);
    QMatrix4x4 MacierzObrotuZ(float rotZ);
    QMatrix4x4 MacierzPrzesuniecia(float grabX, float grabY, float grabZ);
    QMatrix4x4 MacierzSkalowan(float zoomX,float zoomY,float zoomZ);
    QMatrix4x4 MacierzPrzeksztalcenia();
    QMatrix4x4 MacierzPrzeksztalcenia(float zoomX, float zoomY, float zoomZ,
                                       float grabX, float grabY, float grabZ,
                                       float rotX,  float rotY,  float rotZ);
private slots:

    void on_grabXSlide_valueChanged(int value);

    void on_grabYSlide_valueChanged(int value);

    void on_grabZSlide_valueChanged(int value);

    void on_rotXSlide_valueChanged(int value);

    void on_rotYSlide_valueChanged(int value);

    void on_rotZSlide_valueChanged(int value);

    void on_zoomXSlide_valueChanged(int value);

    void on_zoomYSlide_valueChanged(int value);

    void on_zoomZSlide_valueChanged(int value);

    void on_distanceSlide_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    QImage *obrazek;
    QColor RGB;
    QPair<QVector3D,QVector3D> krawedzie[18];
    float d;
    double  zoomX, zoomY, zoomZ,
            grabX, grabY, grabZ,
            rotX,  rotY,  rotZ;
    double distance;
};

#endif // MAINWINDOW_H
