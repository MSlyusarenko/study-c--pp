#include <iostream>
#include <cmath>
#include "func.h"
using namespace std;
#include <Windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int m, n;
    double a, y;

    cout << "Введите m: ";
    cin >> m;
    cout << "Введите n: ";
    cin >> n;
    cout << "Введите a: ";
    cin >> a;

    if (m < 3 || n < 4) {
        cout << "Ошибка: m должно быть >= 3, n должно быть >= 4." << endl;
        system("pause");
        return 0;
    }

    double numerator = 5 + summa(3, m, a, 1);
    double denominator = a * a + summa(4, n, a, 2);

    if (denominator == 0) {
        cout << "Ошибка: знаменатель равен нулю. Деление невозможно." << endl;
        system("pause");
        return 0;
    }

    y = numerator / denominator;

    cout << "y = " << y << endl;
    
    system("pause");
    return 0;
}
