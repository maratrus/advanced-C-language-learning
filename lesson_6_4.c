#include <stdio.h>
#include <stdlib.h>

// ����������� ��������� ���� ��� ������
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// ������� ��� �������� ������ ����
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// ������� ��� ���������� ���� � ����� ������
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

// ������� ��� �������� ����� � �������� ���������� �������
void removeOddPosition(Node** head_ref) {
    if (*head_ref == NULL) {
        return;
    }

    Node* current = *head_ref;
    Node* prev = NULL;
    int position = 1;

    // ������� ���� �� �������� ��������
    while (current != NULL) {
        if (position % 2 != 0) { // �������� �������
            if (prev != NULL) {
                prev->next = current->next;
            } else {
                *head_ref = current->next; // ������� ������ ����
            }
            Node* temp = current;
            current = current->next; // ��������� � ���������� ����
            free(temp); // ����������� ������
        } else {
            prev = current; // ���������� ���������� ���� �� ������ �������
            current = current->next; // ��������� � ���������� ����
        }
        position++;
    }
}

// ������� ��� ������ ������
void printList(Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// ������������ ������, ������� �������
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

    // ���������� ��������� � ������
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);
    append(&head, 6);

    printf("�������� ������: ");
    printList(head);

    // �������� ����� � ��������� ���������
    removeOddPosition(&head);

    printf("������ ����� �������� �������� ���������: ");
    printList(head);

    // ������������ ������
    freeList(head);

    return 0;
}
