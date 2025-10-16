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

    double numerator = 5 + summa(3, m, a, 1);
    double denominator = a * a + summa(4, n, a, 2);

    y = numerator / denominator;

    cout << "y = " << y << endl;
    system("pause");
    return 0;
}
