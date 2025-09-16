#include <math.h>
#include <stdio.h>
    
int main (onelab) {
    double x, a, b;
    double y, z;
    double s;

    printf("Введите x:");
    scanf("x = %lf", &x);
    printf("Введите a:");
    scanf("a = %lf", &a);
    printf("Введите b:");
    scanf("b = %lf", &b);

    s = (0.75 * fabs(cos(b)));
    y = (exp(x - 2.7) + 3) / (x + 1.3);
    z = (y + s + a) / (y * y + s);

    printf("f1 = %.6lf\n", y);
    printf("f2 = %.6lf\n", z);
    
    return 0;
}