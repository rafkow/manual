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
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    QColor Pobierz_Kolor_Punktu(int x, int y, QImage *obrazek);
    void Rysuj_Punkt(int x, int y, QImage *obrazek);
    void Czysc(QImage*);
    int Szukaj_Punktu(QList<QPoint> lista, int x, int y);
    void Rysuj_Szescian();
    void Rysuj_Odcinek(int, int, int, int);
    void Mnozenie_macierzy_4x4(float **A, float **B); //zbedne bo za kazdym razem mnoze przez macierz identycznosciowa
    void Mnozenie_macierzy_4x1(float *wynik, float *punkt);
    
private slots:

    void on_exitButton_clicked();

    void on_czyscButton_clicked();

    void on_przesunXButton_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_przesunYButton_clicked();

    void on_przesunZButton_clicked();

    void on_horizontalSlider_4_valueChanged(int value);

    void on_horizontalSlider_5_valueChanged(int value);

    void on_horizontalSlider_6_valueChanged(int value);

    void on_skalujButton_clicked();

    void on_dial_valueChanged(int value);

    void on_obrocXButton_clicked();

    void on_obrocYButton_clicked();

    void on_obrocZButton_clicked();

private:
    Ui::MainWindow *ui;
    QImage *obrazek;
    QColor RGB;
    QList< QList<float> > krawedzie;
    float d;
    float **macierz_przeksztalcenia;
    float **t;
    int przesun;
    int skaluj_x;
    int skaluj_y;
    int skaluj_z;
    int obroc;
};

#endif // MAINWINDOW_H
