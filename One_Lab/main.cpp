#include <math.h>
#include <stdio.h>
#include <Windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    double x, a, b;
    double y, z;
    double s;

    printf("Введите x: ");
    scanf("%lf", &x);
    printf("Введите a: ");
    scanf("%lf", &a);
    printf("Введите b: ");
    scanf("%lf", &b);

    s = (0.75 * fabs(cos(b)));
    y = (exp(x - 2.7) + 3) / (x + 1.3);
    z = (y + s + a) / (y * y + s);

    printf("f1 = %.6lf\n", y);
    printf("f2 = %.6lf\n", z);

    return 0;
}
