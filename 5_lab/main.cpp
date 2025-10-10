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
    printf("  x\t\t y(x)\n");

    // Вычисляем часть, не зависящую от x: произведение по j
    double P = 1.0;
    for (int j = 2; j <= m + 1; j++)
    {
        P *= sqrt((double)j);
    }

    for (int t = 0; t < n; t++)
    {
        double x = Xnach + t * h;

        // Сумма по i
        double S = 0.0;
        for (int i = 2; i <= m; i++)
        {
            S += (x + i * i) / (2 * x + i);
        }

        double y = x * x + S + x * P;
        printf("%.6lf\t%.6lf\n", x, y);
    }

    return 0;
}
