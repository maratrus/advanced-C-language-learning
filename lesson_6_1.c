#include <stdio.h>
#include <stdbool.h>

void find_first_and_last_word(char *input) {
    char *first_word_start = NULL;
    char *last_word_start = NULL;
    char *current = input;

    // Ïðîïóñêàåì âåäóùèå ïðîáåëû
    while (*current != '\0' && (*current & 0x20) == 0x20) { // ïðîáåë â ASCII - 0x20
        current++;
    }

    // Íàõîäèì ïåðâîå ñëîâî
    first_word_start = current;

    // Èùåì ïåðâîå ñëîâî
    while (*current != '\0') {
        // Åñëè òåêóùèé ñèìâîë - íå ïðîáåë
        if ((*current & 0x20) != 0x20) {
            if (last_word_start == NULL) {
                last_word_start = current; // Íàõîäèì íà÷àëî ñëîâà
            }
        } else {
            // Ïðèõîäèòñÿ íà ïðîáåë, çíà÷èò, ñëîâî çàêîí÷èëîñü
            if (last_word_start) {
                *current = '\0'; // Çàâåðøàåì ñëîâî
                break;
            }
        }
        current++;
    }

    // Åñëè îñòàëîñü ïîñëåäíåå ñëîâî
    if (last_word_start && *last_word_start != '\0') {
        // Èùåì êîíåö ïîñëåäíåãî ñëîâà
        current = last_word_start;
        while (*current != '\0') {
            if ((*current & 0x20) == 0x20) {
                *current = '\0'; // Çàâåðøèòü ïîñëåäíåå ñëîâî
                break;
            }
            current++;
        }
    }

    // Ïå÷àòàåì ïåðâîå è ïîñëåäíåå ñëîâà
    if (first_word_start && *first_word_start != '\0') {
        printf("Ïåðâîå ñëîâî: %s\n", first_word_start);
    }
    if (last_word_start && *last_word_start != '\0') {
        printf("Ïîñëåäíåå ñëîâî: %s\n", last_word_start);
    }
}

int main() {
    char input1[100] = "  efg abcd zzz.  ";
    char input2[100] = " fffff kkkkkk a. ";

    printf("Äàííûå íà âõîäå: '%s'\n", input1);
    find_first_and_last_word(input1);

    printf("Äàííûå íà âõîäå: '%s'\n", input2);
    find_first_and_last_word(input2);

    return 0;
}
