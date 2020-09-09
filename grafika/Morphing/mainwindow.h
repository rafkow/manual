#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void mousePressEvent(QMouseEvent *event);
    bool isInTraiangle();
    void teksturowanie();
    void triangle(QPoint* tab[]);
    QRect getDrawingFrame();
    void insetImage();
    QRgb barycentryczne(int,int,double);
    void clearField();
    void countImage(double);

private slots:


    void on_sAlpha_valueChanged(int action);

private:
    QPoint *pPoint[4];
    QPoint *tPoint[4];
    int tx[4] = {0,0,0,0},ty[4] = {0,0,0,0};
    int t2x[4] = {0,0,0,0},t2y[4] = {0,0,0,0};
    int pi=0, ti=0;
    Ui::MainWindow *ui;
    QImage *face1;
    QImage *face2;
    QImage *result;
};

#endif // MAINWINDOW_H
