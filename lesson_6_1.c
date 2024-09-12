#include <stdio.h>
#include <stdbool.h>

void find_first_and_last_word(char *input) {
    char *first_word_start = NULL;
    char *last_word_start = NULL;
    char *current = input;

    // Пропускаем ведущие пробелы
    while (*current != '\0' && (*current & 0x20) == 0x20) { // пробел в ASCII - 0x20
        current++;
    }

    // Находим первое слово
    first_word_start = current;

    // Ищем первое слово
    while (*current != '\0') {
        // Если текущий символ - не пробел
        if ((*current & 0x20) != 0x20) {
            if (last_word_start == NULL) {
                last_word_start = current; // Находим начало слова
            }
        } else {
            // Приходится на пробел, значит, слово закончилось
            if (last_word_start) {
                *current = '\0'; // Завершаем слово
                break;
            }
        }
        current++;
    }

    // Если осталось последнее слово
    if (last_word_start && *last_word_start != '\0') {
        // Ищем конец последнего слова
        current = last_word_start;
        while (*current != '\0') {
            if ((*current & 0x20) == 0x20) {
                *current = '\0'; // Завершить последнее слово
                break;
            }
            current++;
        }
    }

    // Печатаем первое и последнее слова
    if (first_word_start && *first_word_start != '\0') {
        printf("Первое слово: %s\n", first_word_start);
    }
    if (last_word_start && *last_word_start != '\0') {
        printf("Последнее слово: %s\n", last_word_start);
    }
}

int main() {
    char input1[100] = "  efg abcd zzz.  ";
    char input2[100] = " fffff kkkkkk a. ";

    printf("Данные на входе: '%s'\n", input1);
    find_first_and_last_word(input1);

    printf("Данные на входе: '%s'\n", input2);
    find_first_and_last_word(input2);

    return 0;
}
