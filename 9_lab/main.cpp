#include <stdio.h>
#include <string.h>

#define MAXN 20     // максимум строк
#define MAXLEN 129  // длина строки (128 + '\0')
#define MAXWORDS 20 // максимум слов в строке

// trim - удаление ведущих и хвостовых пробелов
void trim(char *s) {
    int start = 0;
    int end = strlen(s) - 1;

    while (s[start] == ' ' && s[start] != '\0')
        start++;

    while (end >= start && s[end] == ' ')
        end--;

    int j = 0;
    for (int i = start; i <= end; i++)
        s[j++] = s[i];
    s[j] = '\0';
}

// form_arr_word - выделение слов из строки
// Возвращает количество слов
int form_arr_word(const char *from, char to[][MAXLEN]) {
    char buf[MAXLEN];
    strcpy(buf, from);

    int count = 0;
    char *p = strtok(buf, " ");
    while (p) {
        strcpy(to[count++], p);
        p = strtok(NULL, " ");
    }
    return count;
}

// input_strings - ввод n строк
void input_strings(char arr[][MAXLEN], int n) {
    getchar(); // убираем \n после scanf

    for (int i = 0; i < n; i++) {
        printf("Строка %d: ", i + 1);

        fgets(arr[i], MAXLEN, stdin);

        char *p = strchr(arr[i], '\n');
        if (p) *p = '\0';

        trim(arr[i]);
    }
}

// process_line - обработка одной строки (через буфер str)
void process_line(char *line) {
    char str[MAXLEN];          // буферная строка
    char words[MAXWORDS][MAXLEN];
    strcpy(str, line);         // копируем строку в буфер
    trim(str);                 // удаляем пробелы в буфере
    int count = form_arr_word(str, words); // выделяем слова
    char add[10];
    sprintf(add, " %d", count);

    strcat(line, add);
}

// process_all - обработка всех строк массива
void process_all(char arr[][MAXLEN], int n) {
    for (int i = 0; i < n; i++)
        process_line(arr[i]);
}

void print_strings(char arr[][MAXLEN], int n) {
    printf("\nРезультат:\n");
    for (int i = 0; i < n; i++)
        puts(arr[i]);
}

int main() {
    char text[MAXN][MAXLEN];
    int n;

    printf("Введите количество строк (<= 20): ");
    scanf("%d", &n);

    input_strings(text, n);
    process_all(text, n);
    print_strings(text, n);

    return 0;
}





