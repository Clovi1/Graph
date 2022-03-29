#include "list_window.h"
#include "function.h"
#include "ui_list_window.h"

List_Window::List_Window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::List_Window)
{
    ui->setupUi(this);
//    vertex = 0;
//    Constant::vertex = 0;

    //    vector<List> adj_list(vertex);// Создание списка смежности
    //        get_list(adj_list, vertex);// Ввод графа в список смежности
    //    print_list(adj_list); // Вывод графа
    //    menu(adj_list, vertex);
}


List_Window::~List_Window()
{
    delete ui;
}


void List_Window::on_add_vert_clicked()
{
    vertex++;
    QLabel *temp = new QLabel;
    QLineEdit *line = new QLineEdit;
    temp->setText(QString::number(vertex));
    temp->setStyleSheet("border: 1px solid red");
    temp->setFixedHeight(20);
    temp->setFixedWidth(20);
    form_layout->addRow(temp,line);
    list2.append(qMakePair(temp,line));
    ui->scrollContents->setLayout(form_layout);

}


void List_Window::on_delete_vert_clicked()
{
    if(list2.isEmpty()) return;
    QWidget *first = list2.back().first;
    QWidget *second = list2.back().second;
    list2.pop_back();
    vertex--;
    if((first) != 0){
        delete first;
        delete second;
    }
}

void List_Window::on_finish_clicked()
{
    QList<QPair<QLabel*,QLineEdit*>> ::iterator it = list2.begin();
    adj_list.resize(vertex);
    QString str;
    for (int i = 0;i <vertex; i++) {
        QString string = it->second->text();
        it++;
        str.append(QString::number(i + 1) + ":   ");
        str_to_int(string,adj_list,str,i);
        str.append("NULL\n");
    }
    ui->textBrowser->setText(str);
}

void List_Window::str_to_int(QString string,QVector<List> adj_list,QString &str,int n)
{
    QStringList temp = string.split(' ');
    for(auto i = temp.begin(); i != temp.end(); i++){
        if(i->toInt() != 0)
        {
            adj_list[n].add_back(i->toInt());
        }
    }
    for(auto &x: adj_list)
    {
        Node *p = x.get_first();
        while (p)
        {
            str.append(QString::number(p->val) + " -> ");
            p = p->next;
        }
    }
}

//int List_Window::getVertex(){
//    return vertex;
//}

