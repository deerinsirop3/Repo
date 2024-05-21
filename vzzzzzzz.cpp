#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h>
using namespace std;



class Matrix
{
protected:
    int rows, colums;
    int m, n;
    int& m = rows;
    int& n = colums;
    int** data;
public:
    int a;
    int b;
    Matrix(int rows, int colums) :rows(rows), colums(colums)
    {
        data = (int**)malloc(rows * sizeof(int*)); //создаем массив ровс на колумс
        for (int i = 0; i < rows; i++) //освобождаем место для строк
        {
            data[i] = (int*)malloc(colums * sizeof(int)); //освобождаем место для колонок
        }
        a = rows;
        b = colums;
    }


    int& operator[](int indexRows) //перегрузка оператора [] (ок)
    {
        return *data[indexRows];

    }

    void Rand() //делаем функцию рандом для заполнения массива рандомными числами (ok)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < colums; j++)
            {
                data[i][j] = rand() % 10;
            }
        }
    }

    void print() //функция для вывода (Ок)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < colums; j++)
            {
                cout << data[i][j] << "\t";
            }
        }
    }

    int operator () (int a, int b)
    {
        return this->data[a][b];
    }


    ~Matrix()//деструктор функции
    {
        for (int i = 0; i < rows; i++)
        {
            free(data[i]);
        }
        free(data);
    }

    Matrix operator + (Matrix R)
    {
        if (rows == R.m && colums == R.n)
        {
            Matrix Plus(m, n);
            Plus = R + data;
        }
    }
};

ostream& operator << (ostream& os, Matrix data)//перегрузка
{
    for (int i = 0; i < data.a; i++)
    {
        for (int j = 0; j < data.b; j++)
        {
            //os << data(i, j);
            os << setw(10) << data(i, j) << endl;
        }
    }
    return os;
}

int main()
{
    Matrix matrix(5, 5);
    matrix.Rand();
    cout << matrix;
    return 0;
}
