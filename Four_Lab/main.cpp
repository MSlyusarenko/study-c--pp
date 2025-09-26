#include <stdio.h>
#include <math.h>
#include <Windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    int n;
    double x;
    double sum = 0.0;
    int znak = 1;

    printf("Введите n: ");
    scanf("%d", &n);
    printf("Введите x: ");
    scanf("%lf", &x);

    double base = x / (x + 5);
    double term = 1.0;

    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            term = base;
        }
        else
        {
            term *= base; // рекуррентное вычисление степени
        }

        sum += znak * term;

        printf("Проход %2d: знак = %+d, степень = (%.6lf)^%d = %.6lf, сумма = %.6lf\n",
               i, znak, base, i, term, sum);

        znak = -znak; // смена знака
    }

    double y = -5 * x + 6 * sum;

    printf("Окончательное значение y = %.6lf\n", y);

    return 0;
}
