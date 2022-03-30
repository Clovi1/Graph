#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "list_window.h"
#include "function.h"
#include "adj_matrix.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(DrawVertex()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    List_Window adj_list;
    adj_list.setModal(true);
    adj_list.exec();
}


void MainWindow::on_pushButton_2_clicked()
{
    adj_matrix adj_matrix;
    adj_matrix.setModal(true);
    adj_matrix.exec();
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->statusbar->showMessage(QString::number(vertex));
}


void MainWindow::DrawVertex(){

    drawCircle = 1;
    update();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    if(drawCircle){
        QPainter paint;
        paint.begin(this);
        paint.setFont(QFont("times",22));
//        QFont font = paint.font();
//        font.setPointSize(50);
        vertex = 4;
        if(vertex == 4){
            int x = 17;
            int y = 32;
            QVector <int> x_temp;
            QVector <int> y_temp;
            paint.drawEllipse(365,50,50,50);
            paint.drawText(QPoint(365+x,50+y),"1");
            paint.drawEllipse(365,150,50,50);
            paint.drawText(QPoint(365+x,150+y),"2");
            paint.drawEllipse(465,105,50,50);
            paint.drawText(QPoint(465 + x,105 + y),"3");
            paint.drawEllipse(265,105,50,50);
            paint.drawText(QPoint(265 + x,105 + y),"4");
        }

        paint.end();
    }
}

