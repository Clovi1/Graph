#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <adj_matrix.h>
#include "constants.h"
#include "QPainter"
#include "QObject"
#include "QWidget"
#include "QPoint"
#include "QFont"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    int temp;
    int drawCircle = 0;


protected:
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void DrawVertex();
    void paintEvent(QPaintEvent*) override;
//    void on_pushButton_4_clicked();
};
#endif // MAINWINDOW_H
