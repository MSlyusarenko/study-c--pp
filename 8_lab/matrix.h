#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
using namespace std;

const int MAX_N = 10;
const int MAX_M = 5;

// Ввод двумерного массива
void inputMatrix(double* arr, int N, int M);

// Вычисление произведения по столбцам
void computeColumnProducts(double* arr, int N, int M, double* result);

void printMatrix(const double* arr, int N, int M);

// Печать одномерного массива
void printArray(const double* arr, int size, char name);

#endif
