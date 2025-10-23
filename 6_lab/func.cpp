#include "func.h"

double summa(int start, int end, double A, double B, double C, int p) {
    double s = 0;
    for (int i = start; i <= end; i++) {
        s += pow(A * i * i + B * i + C, p);
    }
    return s;
}