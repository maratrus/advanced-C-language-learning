#include <stdio.h>
#include <stdbool.h>

void find_first_and_last_word(char *input) {
    char *first_word_start = NULL;
    char *last_word_start = NULL;
    char *current = input;

    // ���������� ������� �������
    while (*current != '\0' && (*current & 0x20) == 0x20) { // ������ � ASCII - 0x20
        current++;
    }

    // ������� ������ �����
    first_word_start = current;

    // ���� ������ �����
    while (*current != '\0') {
        // ���� ������� ������ - �� ������
        if ((*current & 0x20) != 0x20) {
            if (last_word_start == NULL) {
                last_word_start = current; // ������� ������ �����
            }
        } else {
            // ���������� �� ������, ������, ����� �����������
            if (last_word_start) {
                *current = '\0'; // ��������� �����
                break;
            }
        }
        current++;
    }

    // ���� �������� ��������� �����
    if (last_word_start && *last_word_start != '\0') {
        // ���� ����� ���������� �����
        current = last_word_start;
        while (*current != '\0') {
            if ((*current & 0x20) == 0x20) {
                *current = '\0'; // ��������� ��������� �����
                break;
            }
            current++;
        }
    }

    // �������� ������ � ��������� �����
    if (first_word_start && *first_word_start != '\0') {
        printf("������ �����: %s\n", first_word_start);
    }
    if (last_word_start && *last_word_start != '\0') {
        printf("��������� �����: %s\n", last_word_start);
    }
}

int main() {
    char input1[100] = "  efg abcd zzz.  ";
    char input2[100] = " fffff kkkkkk a. ";

    printf("������ �� �����: '%s'\n", input1);
    find_first_and_last_word(input1);

    printf("������ �� �����: '%s'\n", input2);
    find_first_and_last_word(input2);

    return 0;
}
