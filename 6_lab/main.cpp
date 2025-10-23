#include "func.h"
#include <Windows.h>
#include <iostream>
using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    int m, n;
    double a, y;

    cout << "Введите m: ";
    cin >> m;
    cout << "Введите n: ";
    cin >> n;
    cout << "Введите a: ";
    cin >> a;

    if (m < 3 || n < 4)
    {
        cout << "Ошибка: m должно быть >= 3, n должно быть >= 4." << endl;
        system("pause");
        return 0;
    }

    double numerator = 5 + summa(3, m, 1, 0, a * a + 1, 3);
    double denominator = a * a + summa(4, n, 2, 0, a + 3, 3);

    if (denominator == 0)
    {
        cout << "Ошибка: знаменатель равен нулю." << endl;
        system("pause");
        return 0;
    }

    y = numerator / denominator;

    cout << "y = " << y << endl;
    system("pause");
    return 0;
}