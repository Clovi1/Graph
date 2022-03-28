#ifndef ADJ_MATRIX_H
#define ADJ_MATRIX_H

#include <QDialog>
#include <function.h>
#include <mainwindow.h>

namespace Ui {
class adj_matrix;
}

class adj_matrix : public QDialog
{
    Q_OBJECT

public:
    explicit adj_matrix(QWidget *parent = nullptr);
    ~adj_matrix();

private:
    Ui::adj_matrix *ui;
};

#endif // ADJ_MATRIX_H
