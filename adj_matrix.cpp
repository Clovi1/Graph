#include "adj_matrix.h"
#include "ui_adj_matrix.h"

adj_matrix::adj_matrix(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adj_matrix)
{
    ui->setupUi(this);
}

adj_matrix::~adj_matrix()
{
    delete ui;
}
