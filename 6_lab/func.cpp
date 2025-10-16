#include "func.h"
#include <cmath>

double summa(int start, int end, double a, int type) {
    double s = 0;
    for (int i = start; i <= end; i++) {
        if (type == 1)
            s += pow(i * i + a * a + 1, 3);       // числитель
        else
            s += pow(a + 3 + 2 * i * i, 3);       // знаменатель
    }
    return s;
}
