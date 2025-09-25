#include <stdio.h>
#include <math.h>
#include <Windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    double x, y;
    printf("Введите x: ");
    scanf("%lf", &x);

    if (x > 2)
        y = exp(sqrt(x));
    else if (2 >= x && x > 1)
        y = pow(cos(x), 2);
    else if (1 >= x && x > 0.5)
        y = log10(20 * x);
    else
        y = exp(0.2 * x);

    printf("y =%6.2lf\n", y);
    return 0;
}