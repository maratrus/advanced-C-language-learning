#include <stdio.h>
#include <stdlib.h>

// Определение структуры узла дерева
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Функция для создания нового узла дерева
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Функция для вставки элемента в бинарное дерево
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Функция для вычисления суммы всех элементов в дереве
int sum(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return root->data + sum(root->left) + sum(root->right);
}

// Функция для освобождения памяти, занятой деревом
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    Node* root = NULL;

    // Вставка элементов в дерево
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 3);
    insert(root, 7);
    insert(root, 12);
    insert(root, 18);

    // Вычисление суммы всех элементов
    int totalSum = sum(root);
    printf("Сумма всех элементов в дереве: %d\n", totalSum);

    // Освобождение памяти
    freeTree(root);

    return 0;
}
