#include "functions.h"
#include <algorithm> // для max()

void inputArray(double arr[], int n, char name) {
    cout << "Введите элементы последовательности " << name << " (" << n << " элементов): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void formX(const double a[], const double b[], double x[], int n) {
    for (int i = 0; i < n; i++) {
        x[i] = max(a[i], b[i]) / 2.0;
    }
}

void formY(const double b[], const double c[], double y[], int n) {
    for (int i = 0; i < n; i++) {
        y[i] = max(b[i], c[i]) / 2.0;
    }
}

void printArray(const double arr[], int n, char name) {
    cout << name << ": ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
