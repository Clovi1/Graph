#ifndef FUNCTION_H
#define FUNCTION_H

#include <windows.h>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int val;
    Node *next;

    Node(int _val) : val(_val), next(nullptr){}
};

class List {
private:
    Node *first;
    Node *last;
public:
    List()
    {
        first = nullptr;
        last = nullptr;
    }

    Node *get_first()
    {
        return first;
    }

    bool is_empty()
    {
        return first == nullptr;
    }

    void add_back(int val)
    {
        Node *p = new Node(val);
        if (is_empty())
        {
            first = p;
            last = p;
            return;
        }
        last->next = p;
        last = p;
    }

    int size()
    {
        int count = 0;
        Node *p = first;
        while (p)
        {
            count++;
            p = p->next;
        }
        return count;
    }

    void print()
    {
        Node *p = first;
        while (p)
        {
            cout << p->val << " -> ";
            p = p->next;
        }
        cout << "NULL\n";
    }

    void clearing()
    {
        Node *p;
        while (first)
        {
            p = first;
            first = first->next;
            delete p;
        }
    }
};


// *Меню
void menu(const vector<List>& adj_list, int vertex);

// *Меню вывода
void print_menu(vector<List> adj_list, int vertex);

// *Обход в глубину
void dfs(vector<List> adj_list, vector<bool> &visited, int index);


//! Ввод/вывод
// *Ввод списка смежности
void get_list(vector<List> &adj_list, int vertex);

// *Ввод матриц
void get_matrix(vector<int> matrix[], int edge, int vertex);

// *Вывод списка смежности
void print_list(vector<List> adj_list);

// *Вывод матриц
void print_matrix(vector<int> matrix[], int edge, int vertex, char letter);


//! Преобразования
// *список смежности -> матрица смежности
void adjList_to_adjMatrix(vector<List> adj_list, vector<int> adj_matrix[], int vertex);

// *список смежности -> матрица инцидентности
void adjList_to_incMatrix(vector<List> adj_list, vector<int> inc_matrix[], int edge, int vertex);

// *матрица смежности -> список смежности
void adjMatrix_to_adjList(vector<int> adj_matrix[], vector<List> &adj_list, int vertex);

// *матрица инцидентности -> список смежности
void incMatrix_to_adjList(vector<int> inc_matrix[], vector<List> &adj_list, int edge, int vertex);


//! Доп функции
// *заполнение нулями
void zero(vector<int> matrix[], int edge, int vertex);

// *Проверка ввода
int check_input(int min, int max = 32767);



#endif // FUNCTION_H
