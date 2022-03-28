#ifndef LIST_WINDOW_H
#define LIST_WINDOW_H

#include <QDialog>
#include "QLabel"
#include "QLineEdit"
#include "QVBoxLayout"
#include "QFormLayout"
#include "QList"
#include "QPair"
#include "QScrollArea"
#include "function.h"
#include "QIterator"
#include <cstring>
#include "QVector"
#include "adj_matrix.h"

namespace Ui {
class List_Window;
}

class List_Window : public QDialog
{
    Q_OBJECT

public:
    explicit List_Window(QWidget *parent = nullptr);
    int getVertex();
    ~List_Window();

private slots:
    void on_add_vert_clicked();

    void on_delete_vert_clicked();

    void on_finish_clicked();
    void str_to_int(QString string,QVector<List> adj_list,QString &str,int i);

private:
    Ui::List_Window *ui;
    int vertex = 0;
    QFormLayout *form_layout = new QFormLayout;
    QList<QPair<QLabel*,QLineEdit*>> list2;
    QVector<List> adj_list;
};

void str_to_int(QString string,vector<List> adj_list,int i);

#endif // LIST_WINDOW_H
