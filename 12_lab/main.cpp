#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

class School {
private:
    int number;               // ˜˜˜˜˜ ˜˜˜˜˜
    string name;              // ˜˜˜˜˜˜˜˜ ˜˜˜˜˜
    string specialization;    // ˜˜˜˜˜˜˜˜˜˜˜˜˜
    int studentsCount;        // ˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜

public:
    School() : number(0), studentsCount(0) {}

    void input() {
        cout << "˜˜˜˜˜ ˜˜˜˜˜: ";
        cin >> number;
        cin.ignore(1000, '\n');

        cout << "˜˜˜˜˜˜˜˜ ˜˜˜˜˜: ";
        getline(cin, name);

        cout << "˜˜˜˜˜˜˜˜˜˜˜˜˜: ";
        getline(cin, specialization);

        cout << "˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜: ";
        cin >> studentsCount;
        cin.ignore(1000, '\n');
    }

    int getStudentsCount() const {
        return studentsCount;
    }

    void printRow() const {
        cout << left
             << setw(14) << number
             << setw(25) << name
             << setw(25) << specialization
             << setw(10) << studentsCount << endl;
    }
};

int main() {
    SetConsoleCP(1251);   
    SetConsoleOutputCP(1251);
    const int ROWS = 3;
    School schools[ROWS];

    cout << "˜˜˜˜˜˜˜ ˜˜˜˜˜˜ ˜˜˜ " << ROWS << " ˜˜˜˜:\n";
    for (int i = 0; i < ROWS; i++) {
        cout << "\n--- ˜˜˜˜˜ " << (i + 1) << " ---\n";
        schools[i].input();
    }

    cout << "\n˜˜˜˜˜˜˜:\n";
    cout << left
         << setw(14) << "˜˜˜˜˜"
         << setw(25) << "˜˜˜˜˜˜˜˜"
         << setw(25) << "˜˜˜˜˜˜˜˜˜˜˜˜˜"
         << setw(10) << "˜˜˜˜˜˜˜˜" << endl;
    cout << string(74, '-') << endl;

    int total = 0;
    for (int i = 0; i < ROWS; i++) {
        schools[i].printRow();
        total += schools[i].getStudentsCount();
    }

    cout << "\n˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜: " << total << endl;

    system("pause");
    return 0;
}