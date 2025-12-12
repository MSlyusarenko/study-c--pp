#include <iostream>
#include "MagneticCard.h"
#include "MetroCard.h"
#include "StudentCard.h"
#include <Windows.h>
#include <iomanip>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    MetroCard M1((char *)"M-1001", (char *)"Иванов", 42, 30, (char *)"Standard");
    MetroCard M2((char *)"M-1002", (char *)"Петров", 18, 15, (char *)"Evening");
    StudentCard S1((char *)"S-2001", (char *)"Сидорова", 50, 25, (char *)"СПбГУТ", 50);
    StudentCard S2((char *)"S-2002", (char *)"Кузнецов", 12, 30, (char *)"СПбГУТ", 50);

    MagneticCard *ps[4];
    ps[0] = &M1;
    ps[1] = &M2;
    ps[2] = &S1;
    ps[3] = &S2;

    cout << left
         << setw(10) << "Type"
         << setw(10) << "CardID"
         << setw(14) << "Owner"
         << setw(8) << "Trips"
         << setw(6) << "Days"
         << setw(10) << "AvgTrips"
         << setw(24) << "Extra"
         << endl;
    cout << string(82, '-') << endl;

    for (int i = 0; i < 4; i++)
        ps[i]->Show();

    double Average = 0.0;
    for (int i = 0; i < 4; i++)
        Average += ps[i]->GetAvgTrips();

    Average /= 4.0;
    cout << "\nСреднее количество поездок: " << fixed << setprecision(2) << Average << endl;

    system("pause");
    return 0;
}