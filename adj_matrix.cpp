#include "adj_matrix.h"
#include "ui_adj_matrix.h"
#include "function.h"
#include "constants.h"
#include <QString>

adj_matrix::adj_matrix(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adj_matrix)
{
    ui->setupUi(this);
    ShowMatrix();
}

adj_matrix::~adj_matrix()
{
    delete ui;
}

void adj_matrix::ShowMatrix(){
   ui->textBrowser->setStyleSheet("border: 0px solid white");
    QString Matrix;
//    List_Window vertex;
//    ui->label->setText(QString::number(vertex));
//    ui->label->setText("zxc");
//    ui->textBrowser->setText(QString::number(adj_list[0].print()));
}
