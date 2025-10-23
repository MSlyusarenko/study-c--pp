#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
using namespace std;

const int MAX_SIZE = 20;

// Ввод массива
void inputArray(double arr[], int n, char name);

// Формирование массивов X и Y
void formX(const double a[], const double b[], double x[], int n);
void formY(const double b[], const double c[], double y[], int n);

// Вывод массива
void printArray(const double arr[], int n, char name);

#endif
