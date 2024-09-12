#include <stdio.h>
#include <stdlib.h>

// ����������� ��������� ���� ������
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// ������� ��� �������� ������ ���� ������
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// ������� ��� ������� �������� � �������� ������
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

// ������� ��� ���������� ������������ �������� � ������
int findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

// ������� ��� ���������� ������������� �������� � ������
int findMax(Node* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root->data;
}

// ������� ��� ������������ ������, ������� �������
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    Node* root = NULL;

    // ������� ��������� � ������
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 3);
    insert(root, 7);
    insert(root, 12);
    insert(root, 18);

    // ���������� ������������ � ������������� ��������
    int minValue = findMin(root);
    int maxValue = findMax(root);
    int difference = maxValue - minValue;

    // ����� �������
    printf("����������� �������: %d\n", minValue);
    printf("������������ �������: %d\n", maxValue);
    printf("������� ����� ������������ � ����������� ���������: %d\n", difference);

    // ������������ ������
    freeTree(root);

    return 0;
}
