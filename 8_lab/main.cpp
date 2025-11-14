#include <iostream>
#include <Windows.h>
#include "matrix.h"
using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    int N, M;
    cout << "Введите количество строк (N <= 10): ";
    cin >> N;
    cout << "Введите количество столбцов (M <= 5): ";
    cin >> M;

    if (N <= 0 || N > MAX_N || M <= 0 || M > MAX_M)
    {
        cout << "Ошибка: неверные размеры массива." << endl;
        system("pause");
        return 1;
    }

    double a[MAX_N][MAX_M];

    inputMatrix((double*)a, N, M);

    double products[MAX_M];
    computeColumnProducts((double*)a, N, M, products);

    cout << "\nИсходная матрица:\n";
    printMatrix((double*)a, N, M);

    cout << "\nПроизведение элементов по каждому столбцу:\n";
    printArray(products, M, 'P');

    system("pause");
    return 0;
}
