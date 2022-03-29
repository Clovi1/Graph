#include "function.h"

using namespace std;

//// * Меню
//void menu(const vector<List> &adj_list, int vertex)
//{
//    int choise = -1;
//    while (choise != 2)
//    {
//        cout << "\nВыберите дальнейшие действия:\n";
//        cout << "1 - Вывести\n";
//        cout << "2 - Ввести новый граф\n";
//        cout << "3 - Обход в глубину\n";
//        cout << "4 - Обход в ширину\n";z
//        cout << "0 - Закрыть программу\n";
//        cout << "Ваш выбор: ";
//        choise = check_input(0, 4);
//        cout << endl;
//        switch (choise)
//        {
//            case 1:
//                print_menu(adj_list, vertex);
//                break;
//            case 3:
//            {
//                cout << "С какой вершины начать обход: ";
//                int i = check_input(1, vertex) - 1; // выбор вершины с которой начнется обход
//                vector<bool> visited(vertex, false); //просмотренные вершины
//                for (; i < vertex; ++i)
//                {
//                    if (!visited[i])//если ребро не пройдено, то продолжаем
//                    {
//                        dfs(adj_list, visited, i);//обход в глубину
//                        if (!visited[0]) i = -1;//если первый элемент не пройден, то продолжаем с него
//                    }
//                }
//                break;
//            }
//            case 4:
//            {
//                cout << "В процессе...\n";
//                break;
//            }
//            case 0:
//                cout << "\nПрограмма закрывается...";
//                exit(0);
//            default:;
//        }
//    }
//}


//// *Меню вывода
//void print_menu(vector<List> adj_list, int vertex)
//{
//    while (true)
//    {
//        cout << "\nВыберите вид вывода:\n";
//        cout << "1 - Список смежности\n";
//        cout << "2 - Матрица смежности\n";
//        cout << "3 - Матрица инцидентности\n";
//        cout << "0 - Вернуться назад\n";
//        cout << "Ваш выбор: ";
//        int choice = check_input(0, 3);
//        switch (choice)
//        {
//            case 1: // Список смежности
//                print_list(adj_list);
//                break;
//            case 2: // Матрица смежности
//            {
//                vector<int> adj_matrix[vertex]; // создание матрицы смежности
//                adjList_to_adjMatrix(adj_list, adj_matrix, vertex); //список смежности -> матрица смежности
//                print_matrix(adj_matrix, vertex, vertex, 'v'); //вывод матрицы
//                break;
//            }
//            case 3: // Матрица инцидентности
//            {
//                int edge = 0;//кол-во ребер
//                for (int i = 0; i < vertex; ++i)
//                {
//                    edge += adj_list[i].size();
//                }
//                vector<int> inc_matrix[edge]; // создание матрицы инцидентности
//                adjList_to_incMatrix(adj_list, inc_matrix, edge, vertex); //список смежности -> матрица инцидентности
//                print_matrix(inc_matrix, edge, vertex, 'e'); //вывод матрицы
//                break;
//            }
//            default:
//                break;
//        }
//        if (choice == 0) break; //Вернуться назад
//    }
//}


//// *Обход в глубину
//void dfs(vector<List> adj_list, vector<bool> &visited, int index)
//{
//    if (visited[index]) return;
//    cout << index + 1 << " ";
//    visited[index] = true;
//    Node *temp = adj_list[index].get_first();
//    while (temp)
//    {
//        if (!visited[temp->val - 1])
//        {
//            dfs(adj_list, visited, temp->val - 1);
//        }
//        temp = temp->next;
//    }
//}


//// *Ввод списка смежности
//void get_list(vector<List> &adj_list, int vertex)
//{
//    for (int i = 0; i < vertex; ++i)
//    {
//        cout << "Введите смежные вершины для вершины " << i + 1 << ": ";
//        int j = check_input(0, vertex);
//        while (j != 0)
//        {
//            adj_list[i].add_back(j); //Добавление вершин в список смежности
//            j = check_input(0, vertex);
//        }
//    }
//}


//// *Вывод списка смежности
void print_list(vector<List> adj_list)
{
    int count = 1;
    for (auto &i: adj_list)
    {
        cout << count++ << " - ";
        i.print();
    }
}


//// *Ввод матриц
//void get_matrix(vector<int> matrix[], int edge, int vertex)
//{
//    for (int i = 0; i < edge; ++i)
//    {
//        for (int j = 0; j < vertex; ++j)
//        {
//            cout << "Матрица[" << i + 1 << "][" << j + 1 << "]=";
//            int value = check_input(-1, 1);
//            matrix[i].push_back(value); //Добавление чисел в матрицы
//        }
//    }
//}


//// *Вывод матриц
//void print_matrix(vector<int> matrix[], int edge, int vertex, char letter)
//{
//    cout << "\n      ";
//    for (int v = 0; v < vertex; ++v)
//    {
//        cout << "v" << v + 1 << "  ";
//    }
//    cout << endl;
//    for (int i = 0; i < edge; ++i)
//    {
//        cout << letter << i + 1 << "|";
//        for (int j = 0; j < vertex; ++j)
//        {
//            cout.width(4);
//            cout << matrix[i][j];
//        }
//        cout << endl;
//    }
//}


//// *список смежности -> матрица смежности
//void adjList_to_adjMatrix(vector<List> adj_list, vector<int> adj_matrix[], int vertex)
//{
//    zero(adj_matrix, vertex, vertex); //заполнение нулями
//    for (int i = 0; i < vertex; ++i)
//    {
//        Node *p = adj_list[i].get_first();
//        while (p)
//        {
//            adj_matrix[i][p->val - 1] = 1;
//            p = p->next;
//        }
//    }
//}


//// *список смежности -> матрица инцидентности
//void adjList_to_incMatrix(vector<List> adj_list, vector<int> inc_matrix[], int edge, int vertex)
//{
//    zero(inc_matrix, edge, vertex); //заполнение нулями
//    for (int i = 0, e = 0; i < vertex; ++i)
//    {
//        Node *p = adj_list[i].get_first();
//        while (p)
//        {
//            inc_matrix[e][i] = -1;
//            inc_matrix[e][p->val - 1] = 1;
//            e++;
//            p = p->next;
//        }
//    }
//}


//// *матрица смежности -> список смежности
//void adjMatrix_to_adjList(vector<int> adj_matrix[], vector<List> &adj_list, int vertex)
//{
//    for (int i = 0; i < vertex; ++i)
//    {
//        for (int j = 0; j < vertex; ++j)
//        {
//            if (adj_matrix[i][j] == 1)
//            {
//                adj_list[i].add_back(j + 1);
//            }
//        }
//    }
//}


//// *матрица инцидентности -> список смежности
//void incMatrix_to_adjList(vector<int> inc_matrix[], vector<List> &adj_list, int edge, int vertex)
//{
//    for (int e = 0; e < edge; ++e)
//    {
//        int row = 0, column = 0;
//        for (int i = 0, j = 0; i < vertex; ++i, ++j)
//        {
//            if (inc_matrix[e][i] == -1) row = i;
//            if (inc_matrix[e][j] == 1) column = j;
//        }
//        adj_list[row].add_back(column + 1);
//    }
//}


//// *заполнение нулями
//void zero(vector<int> matrix[], int edge, int vertex)
//{
//    for (int i = 0; i < edge; ++i)
//    {
//        for (int j = 0; j < vertex; ++j)
//        {
//            matrix[i].push_back(0);
//        }
//    }
//}


//// *Проверка ввода
//int check_input(int min, int max)
//{
//    while (true)
//    {
//        int num;
//        cin >> num;
//        if (cin.fail()) // если предыдущее извлечение не выполнилось или произошло переполнение,
//        {
//            cin.clear(); // то возвращаем cin в 'обычный' режим работы
//            cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
//            cout << "Ой, недопустимый символ, попробуй еще раз :)" << endl;
//        } else if ((num < min) || (num > max)) // проверка диапазона ввода
//        {
//            cout << "Ой, число не влезает в границы от " << min << " до " << max << ", попробуй еще раз  :)" << endl;
//        } else
//        {
//            return num;
//        }
//    }
//}
