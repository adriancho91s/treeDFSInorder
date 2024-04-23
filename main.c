#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("Error creating a new node.\n");
        exit(0);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

Node* insertNode(Node* root, int data, char direction) {
    if(root == NULL) {
        return createNode(data);
    }

    if(direction == 'L' || direction == 'l') {
        if(root->left == NULL) {
            root->left = createNode(data);
        } else {
            printf("Node already exists at the left. Moving to the next level.\n");
            insertNode(root->left, data, direction);
        }
    } else if(direction == 'R' || direction == 'r') {
        if(root->right == NULL) {
            root->right = createNode(data);
        } else {
            printf("Node already exists at the right. Moving to the next level.\n");
            insertNode(root->right, data, direction);
        }
    }

    return root;
}

void displayInorder(Node* node) {
    if(node != NULL) {
        displayInorder(node->left);
        printf("%d ", node->data);
        displayInorder(node->right);
    }
}

int main() {
    Node* root = NULL;
    int choice, data;
    char direction;

    while(1) {
        printf("\n1. Insert node\n2. Display Inorder\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: printf("Enter data: ");
                    scanf("%d", &data);
                    printf("Enter direction (L/R): ");
                    scanf(" %c", &direction);
                    root = insertNode(root, data, direction);
                    break;

            case 2: displayInorder(root);
                    break;

            case 3: exit(0);

            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}