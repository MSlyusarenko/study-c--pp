#include <stdio.h>
#include <math.h>
#include <Windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    int m, n;
    double Xnach, Xkon;

    printf("Введите m: ");
    scanf("%d", &m);
    printf("Введите Xнач: ");
    scanf("%lf", &Xnach);
    printf("Введите Xкон: ");
    scanf("%lf", &Xkon);
    printf("Введите n (число точек): ");
    scanf("%d", &n);

    double h = (Xkon - Xnach) / (n - 1);

    printf("  x\t\t  y(x)\n");
    for (int t = 0; t < n; t++)
    {
        double x = Xnach + t * h;
        double sum = 0.0;
        for (int i = 2; i <= m; i++)
        {
            sum += (x + (double)(i * i)) / (2.0 * x + (double)i);
        }
        double prod = 1.0;
        for (int j = 2; j <= m + 1; j++)
        {
            prod *= pow((double)j, 0.5);
        }
        double y = x * x + sum + x * prod;
        printf("%.6lf\t%.6lf\n", x, y);
    }

    return 0;
}
