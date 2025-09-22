#include <stdio.h>
#include <math.h>
#include <Windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    double x, y;
    printf("Введите x: ");
    scanf("%lf", &x);

    if (x > 4)
        y = 1 / x;
    else if (x > 2 && x < 5)
        y = exp(-x);
    else if (x > -1)
        y = x * x;
    else
        y = fabs(x - 1) / (2 * x);

    printf("y =%6.2lf\n", y);
    return 0;
}