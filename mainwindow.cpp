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

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter;
    int x = 50;
//    QPen red;
//    red.setColor(QColor(35,205,219));
    QBrush brush;
    brush.setColor(QColor(114,114,114));
    brush.setStyle(Qt::SolidPattern);
    painter.begin(this);

    painter.setBrush(brush);
    painter.drawEllipse(width()/2-x/2, x, x, x);
    if(temp == 1)
    {
        painter.drawEllipse(width()/2 - x/2, 2.5 * x, x, x);
    } else if(temp == 2)
    {
        painter.drawEllipse(width()/2 - 1.5*x, 2.5 * x, x, x);
        painter.drawEllipse(width()/2 + x/2, 2.5 * x, x, x);
    } else if(temp == 3)
    {
        painter.drawEllipse(width()/2 - x/2, 2.5 * x, x, x);
        painter.drawEllipse(width()/2 - 2*x, 2.5 * x, x, x);
        painter.drawEllipse(width()/2 + x, 2.5 * x, x, x);
    }

    painter.end();

    //        while (TRUE)
    //        {
//                cout << "Каким способом ввести граф?\n";
//                cout << "1 - Список смежности\n";
//                cout << "2 - Матрица смежности\n";
//                cout << "3 - Матрица инцидентности\n";
//                cout << "0 - Закрыть программу\n";
//                cout << "Ваш выбор: ";
//                int choice = ui->lineEdit->text().toInt();

//                if (choice == 0) // Закрыть программу
//                {
//                    ui->statusbar->showMessage("Программа закрывается...");
//    //                break;
//                }

//                cout << "Введите количество вершин: ";
//                int vertex = ui->lineEdit->text().toInt();
//                vector<List> adj_list(vertex);// Создание списка смежности
    //            switch (choice)
    //            {
    //                case 1: // Список смежности
    //                {
    //                    get_list(adj_list, vertex);// Ввод графа в список смежности
    //                    print_list(adj_list); // Вывод графа
    //                    menu(adj_list, vertex);
    //                    break;
    //                }
    //                case 2: // Матрица смежности
    //                {
    //                    vector<int> adj_matrix[vertex]; // Создание матрицы смежности
    //                    get_matrix(adj_matrix, vertex, vertex);// Ввод графа в матрицу смежности
    //                    print_matrix(adj_matrix, vertex, vertex, 'v');// Вывод матрицы
    //                    adjMatrix_to_adjList(adj_matrix, adj_list, vertex);// матрица смежности -> список смежности
    //                    menu(adj_list, vertex);
    //                    break;
    //                }
    //                case 3: // Матрица инцидентности
    //                {
    //                    cout << "Введите количество ребер: ";
    //                    int edge = check_input(0);
    //                    vector<int> inc_matrix[edge]; // Создание матрицы инцедентности
    //                    get_matrix(inc_matrix, edge, vertex); // Ввод графа в список смежности
    //                    print_matrix(inc_matrix, edge, vertex, 'e'); //Вывод матрицы
    //                    incMatrix_to_adjList(inc_matrix, adj_list, edge, vertex); // матрица инцидентности -> список смежности
    //                    menu(adj_list, vertex);
    //                    break;
    //                }
    //                default:
    //                    break;
    //            }
    //            for (int i = 0; i < vertex; ++i) // очистка списка смежности
    //            {
    //                adj_list[i].clearing();
    //            }
    //            adj_list.clear();
    ////        }

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

