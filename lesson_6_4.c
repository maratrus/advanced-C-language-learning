#include <stdio.h>
#include <stdlib.h>

// Определение структуры узла для списка
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Функция для создания нового узла
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Функция для добавления узла в конец списка
void append(Node** head_ref, int new_data) {
    Node* new_node = createNode(new_data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

// Функция для удаления узлов с нечетным порядковым номером
void removeOddPosition(Node** head_ref) {
    if (*head_ref == NULL) {
        return;
    }

    Node* current = *head_ref;
    Node* prev = NULL;
    int position = 1;

    // Удаляем узлы на нечетных позициях
    while (current != NULL) {
        if (position % 2 != 0) { // Нечетная позиция
            if (prev != NULL) {
                prev->next = current->next;
            } else {
                *head_ref = current->next; // Удаляем первый узел
            }
            Node* temp = current;
            current = current->next; // Переходим к следующему узлу
            free(temp); // Освобождаем память
        } else {
            prev = current; // Запоминаем предыдущий узел на четной позиции
            current = current->next; // Переходим к следующему узлу
        }
        position++;
    }
}

// Функция для печати списка
void printList(Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Освобождение памяти, занятой списком
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;

    // Добавление элементов в список
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);
    append(&head, 6);

    printf("Исходный список: ");
    printList(head);

    // Удаление узлов с нечетными позициями
    removeOddPosition(&head);

    printf("Список после удаления нечетных элементов: ");
    printList(head);

    // Освобождение памяти
    freeList(head);

    return 0;
}
