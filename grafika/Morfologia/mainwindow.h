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

private slots:
    void paintEvent(QPaintEvent *);
    void on_bNormal_clicked();
    void calculateImage();
    QRect getDrawingFrame();

    void on_bDylatacja_clicked();

    void on_bErozja_clicked();

    void on_bOtwarcie_clicked();

    void erozja();
    void dylatacja();

    void on_bZamkniecie_clicked();

private:
    Ui::MainWindow *ui;
    QImage *image;
    QImage *result;
};

#endif // MAINWINDOW_H
