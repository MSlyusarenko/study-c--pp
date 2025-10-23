#include <iostream>
#include "array.h"
#include <Windows.h>
using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    int n;
    cout << "Введите количество элементов (n <= 20): ";
    cin >> n;

    if (n <= 0 || n > MAX_SIZE)
    {
        cout << "Ошибка: неверное значение n." << endl;
        system("pause");
        return 1;
    }

    double a[MAX_SIZE], b[MAX_SIZE], c[MAX_SIZE];
    double x[MAX_SIZE], y[MAX_SIZE];

    // Ввод исходных массивов
    inputArray(a, n, 'a');
    inputArray(b, n, 'b');
    inputArray(c, n, 'c');

    // Формирование новых массивов
    formX(a, b, x, n);
    formY(b, c, y, n);

    // Вывод результатов
    cout << "\nРезультаты вычислений:\n";
    printArray(a, n, 'a');
    printArray(b, n, 'b');
    printArray(c, n, 'c');
    printArray(x, n, 'x');
    printArray(y, n, 'y');

    system("pause");
    return 0;
}
