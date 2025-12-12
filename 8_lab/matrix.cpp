#include "matrix.h"

void inputMatrix(double *arr, int N, int M)
{
    cout << "\nВведите элементы матрицы (" << N << "x" << M << "):\n";

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> *(arr + i * M + j);
        }
    }
}

void computeColumnProducts(double *arr, int N, int M, double *result)
{
    for (int col = 0; col < M; col++)
    {
        double prod = 1.0;

        for (int row = 0; row < N; row++)
        {
            prod *= *(arr + row * M + col);
        }

        *(result + col) = prod;
    }
}

void printMatrix(const double *arr, int N, int M)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << *(arr + i * M + j) << " ";
        }
        cout << endl;
    }
}

void printArray(const double *arr, int size, char name)
{
    cout << name << ": ";
    for (int i = 0; i < size; i++)
    {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}
