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
    QRect getDrawingFrame();
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void paintEvent(QPaintEvent *);
    void on_s1Slider_valueChanged(int value);

    void on_s2Slider_valueChanged(int value);

    void on_s3Slider_valueChanged(int value);

    void on_s4Slider_valueChanged(int value);

    void on_rMultiple_clicked(bool checked);

    void on_rScreen_clicked(bool checked);

    void on_rLighten_clicked(bool checked);

    void on_rDarken_clicked(bool checked);

    void on_rAlpha_clicked(bool checked);

private:

    QImage *s1;
    QImage *s2;
    QImage *s3;
    QImage *s4;
    QImage *result;

    int opcja;

    int sliderValue[4];
    void calculateImage();
    QRgb calculatePixel(QRgb s1pix, QRgb s2pix, QRgb s3pix, QRgb s4pix);
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
