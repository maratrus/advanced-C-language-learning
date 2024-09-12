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

// Функция для нахождения минимального элемента в дереве
int findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

// Функция для нахождения максимального элемента в дереве
int findMax(Node* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root->data;
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

    // Нахождение минимального и максимального элемента
    int minValue = findMin(root);
    int maxValue = findMax(root);
    int difference = maxValue - minValue;

    // Вывод разницы
    printf("Минимальный элемент: %d\n", minValue);
    printf("Максимальный элемент: %d\n", maxValue);
    printf("Разница между максимальным и минимальным элементом: %d\n", difference);

    // Освобождение памяти
    freeTree(root);

    return 0;
}
