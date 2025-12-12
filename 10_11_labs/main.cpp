#include <iostream>
#include <cstdio>      // FILE, fopen, fgets, fputs, fclose
#include <cstring>     // strlen, strtok
#include <cstdlib>     // strtod
#include <Windows.h>

using namespace std;

const int MAX_STUDENTS = 20;
const int MARKS_COUNT  = 4;
const int MAX_LINE_LEN = 256;

// Структура студента (ЛР 10)
struct Student {
    char group[10];
    char surname[30];
    char name[30];
    char patronymic[30];
    int  marks[MARKS_COUNT];
    double avg;
};

// ---- Прототипы функций для работы со студентами (ЛР 10) ----
void init_students(Student arr[], int &n);
void compute_averages(Student arr[], int n);
void print_group(const Student arr[], int n, const char *group_code);
void write_group_to_file(const Student arr[], int n, const char *group_code, const char *filename);

// ---- Прототип функции обработки файла (ЛР 11) ----
void process_file(FILE *fin, FILE *fout);

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    Student students[MAX_STUDENTS];
    int n = 0;

    // 1. "Ввод" массива структур: заполняем в коде
    init_students(students, n);

    // 2. Обработка массива структур: подсчёт среднего балла
    compute_averages(students, n);

    // 3. Вывод сведений о конкретной группе
    const char target_group[] = "СП-71";
    cout << "Студенты группы " << target_group << ":" << endl;
    print_group(students, n, target_group);

    // 4. Запись студентов этой группы в файл (подготовка данных для 11-й лабы)
    const char input_file_name[]  = "students.txt";
    const char output_file_name[] = "students_out.txt";

    write_group_to_file(students, n, target_group, input_file_name);

    // 5. Открытие файлов и вызов обработки (ЛР 11)
    FILE *fin  = fopen(input_file_name, "r");
    FILE *fout = fopen(output_file_name, "w");

    if (!fin || !fout) {
        cout << "Ошибка открытия файлов." << endl;
        if (fin) fclose(fin);
        if (fout) fclose(fout);
        return 1;
    }

    process_file(fin, fout);

    fclose(fin);
    fclose(fout);

    cout << "Обработка файла завершена. Результат в " << output_file_name << endl;

    return 0;
}

// ---------------- Функции для 10-й лабораторной ----------------

// Заполняем массив студентов
void init_students(Student arr[], int &n)
{
    n = 5; // пример, 5 студентов

    // 1
    strcpy(arr[0].group, "СП-71");
    strcpy(arr[0].surname, "Иванов");
    strcpy(arr[0].name, "Петр");
    strcpy(arr[0].patronymic, "Андреевич");
    arr[0].marks[0] = 3;
    arr[0].marks[1] = 5;
    arr[0].marks[2] = 4;
    arr[0].marks[3] = 4;

    // 2
    strcpy(arr[1].group, "СП-71");
    strcpy(arr[1].surname, "Сидоров");
    strcpy(arr[1].name, "Иван");
    strcpy(arr[1].patronymic, "Игоревич");
    arr[1].marks[0] = 4;
    arr[1].marks[1] = 4;
    arr[1].marks[2] = 5;
    arr[1].marks[3] = 3;

    // 3
    strcpy(arr[2].group, "СП-91");
    strcpy(arr[2].surname, "Петров");
    strcpy(arr[2].name, "Алексей");
    strcpy(arr[2].patronymic, "Олегович");
    arr[2].marks[0] = 5;
    arr[2].marks[1] = 5;
    arr[2].marks[2] = 4;
    arr[2].marks[3] = 5;

    // 4
    strcpy(arr[3].group, "СП-61");
    strcpy(arr[3].surname, "Смирнова");
    strcpy(arr[3].name, "Мария");
    strcpy(arr[3].patronymic, "Сергеевна");
    arr[3].marks[0] = 3;
    arr[3].marks[1] = 3;
    arr[3].marks[2] = 4;
    arr[3].marks[3] = 3;

    // 5
    strcpy(arr[4].group, "СП-71");
    strcpy(arr[4].surname, "Кузнецов");
    strcpy(arr[4].name, "Дмитрий");
    strcpy(arr[4].patronymic, "Алексеевич");
    arr[4].marks[0] = 5;
    arr[4].marks[1] = 4;
    arr[4].marks[2] = 5;
    arr[4].marks[3] = 5;
}

// Подсчёт среднего балла для каждого студента
void compute_averages(Student arr[], int n)
{
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < MARKS_COUNT; j++) {
            sum += arr[i].marks[j];
        }
        arr[i].avg = (double)sum / MARKS_COUNT;
    }
}

// Вывод студентов заданной группы на экран
void print_group(const Student arr[], int n, const char *group_code)
{
    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i].group, group_code) == 0) {
            cout << arr[i].group << " "
                 << arr[i].surname << " "
                 << arr[i].name << " "
                 << arr[i].patronymic << " Оценки: ";
            for (int j = 0; j < MARKS_COUNT; j++) {
                cout << arr[i].marks[j] << " ";
            }
            cout << " Ср.балл: " << arr[i].avg << endl;
        }
    }
}

// Запись студентов заданной группы в текстовый файл
// Формат строки: <оценки> (4 числа) через пробел
void write_group_to_file(const Student arr[], int n, const char *group_code, const char *filename)
{
    FILE *f = fopen(filename, "w");
    if (!f) {
        cout << "Не удалось открыть файл для записи: " << filename << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i].group, group_code) == 0) {
            // В файл пишем только числа, как требует 11-я ЛР
            // (произвольное количество чисел в каждой строке)
            for (int j = 0; j < MARKS_COUNT; j++) {
                fprintf(f, "%d ", arr[i].marks[j]);
            }
            fprintf(f, "\n");
        }
    }

    fclose(f);
}

// ---------------- Функция для 11-й лабораторной ----------------

// В каждой строке входного файла произвольное количество чисел (формат f).
// В выходной файл записываем сумму чисел и исходную строку.
void process_file(FILE *fin, FILE *fout)
{
    char line[MAX_LINE_LEN];

    while (fgets(line, MAX_LINE_LEN, fin) != NULL) {
        // Уберём перевод строки в конце, если есть
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }

        // Считаем сумму чисел в строке
        double sum = 0.0;
        const char *p = line;
        char *endptr;

        while (*p != '\0') {
            // Пробуем считать число
            double val = strtod(p, &endptr);
            if (endptr == p) {
                // Здесь число не найдено, двигаем p на один символ
                p++;
            } else {
                sum += val;
                p = endptr;
            }
        }

        // Формируем новую строку: "сумма исходная_строка"
        char out_line[MAX_LINE_LEN * 2];
        sprintf(out_line, "%.2f %s\n", sum, line);

        fputs(out_line, fout);
    }
}
