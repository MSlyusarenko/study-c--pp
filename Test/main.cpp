#include <cmath>
#include <iostream>
using namespace std;

double mdf(double a, double y)
{
    double res = y * pow(a, 1 / 5);
    return res;
}

double fn1(double rnd)
{
    double res;
    res = (pow(cos(rnd), 2) + 2) / 3;
    return res;
}

double fn2(double y, double a, double b)
{
    double newa;
    newa = mdf(a, y);
    double res = (newa + 1) / (sin(b) + newa);
    return res;
}

int main()
{
    double x, y, a, b, z;
    cout << "x = ";
    cin >> x;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    y = fn1(x);
    z = fn2(y, a, b);
    cout << endl
         << "result -" << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;
}