#include <stdio.h>
#include <stdlib.h>

struct node
{
    int a;
    struct node *left;
    struct node *right;
};

void createNode(struct node **, int);
void InOrder(struct node *);
void delete(struct node **);
void clearScreen();
void delay();

int main(){
    struct node *head = NULL;
    int choice = 0, num;
    
    char *options[] = {
        "Insert a new node",
        "Perform InOrder Traversal printing the Tree",
        "Exit"
    };
    int numOptions = sizeof(options) / sizeof(options[0]);

    do {
        clearScreen();
        printf("\tWelcome to \n\n");
        for (int i = 0; i < numOptions; i++) {
            printf("%d. %s\n", i + 1, options[i]);
        }
        fflush(stdin);
        printf("\nChoose an option: ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1: 
            printf("Enter element to insert: ");
            scanf("%d", &num);
            createNode(&head, num);
            clearScreen();
            break;
        case 2: 
            InOrder(head);
            printf("Enter any key to continue...");
            getchar();
            getchar();
            clearScreen();
            break;
        case 3: 
            delete(&head);
            printf("Exiting program...\n");
            delay();
            break;
        default: 
            printf("Not a valid input, try again\n");
            delay();
            break;
        }
    } while (choice != numOptions);
    return 0;
}

/**
 * Creates a new node with the given number and inserts it into the binary search tree.
 * 
 * @param head A pointer to the head of the binary search tree.
 * @param num The number to be inserted into the binary search tree.
 */
void createNode(struct node **head, int num) {
    struct node *temp = *head, *prev = *head;

    if (*head == NULL)
    {
        *head = (struct node *)malloc(sizeof(struct node));
        (*head)->a = num;
        (*head)->left = (*head)->right = NULL;
    }
    else
    {
        int choice;
        while (temp != NULL)
        {
            printf("Where do you want to add the new node?\n");
            printf("1. Left\n");
            printf("2. Right\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            if (choice == 1)
            {
                if (temp->left != NULL)
                {
                    printf("There is already a node on the left. Please choose again.\n");
                    temp = temp->left;
                    continue;
                }
                prev = temp;
                temp = temp->left;
            }
            else if (choice == 2)
            {
                if (temp->right != NULL)
                {
                    printf("There is already a node on the right. Please choose again.\n");
                    temp = temp->right;
                    continue;
                }
                prev = temp;
                temp = temp->right;
            }
            else
            {
                printf("Invalid choice. Please choose again.\n");
                continue;
            }
        }

        temp = (struct node *)malloc(sizeof(struct node));
        temp->a = num;
        if (choice == 1)
        {
            prev->left = temp;
        }
        else if (choice == 2)
        {
            prev->right = temp;
        }
    }
}

/**
 * Performs an inorder traversal of the binary search tree and prints the elements.
 * 
 * @param head A pointer to the head of the binary search tree.
 */
void InOrder(struct node *head) {
    if (head)
    {
        if (head->left)
        {
            InOrder(head->left);
        }
        printf("%d  ", head->a);
        if (head->right)
        {
            InOrder(head->right);
        }
    }
}

/**
 * Deletes all nodes in the binary search tree and frees the memory.
 * 
 * @param head A pointer to the head of the binary search tree.
 */
void delete(struct node **head) {
    if (*head != NULL)
    {
        if ((*head)->left)
        {
            delete(&(*head)->left);
        }
        if ((*head)->right)
        {
            delete(&(*head)->right);
        }
        free(*head);
    }
}

/**
 * Clear the screen
 * @return void
 * */
void clearScreen() {
#ifdef WINDOWS
    system("cls");
#else
    system("clear");
#endif
}

/**
 * Delay the program
 * @return void
 * */
void delay() {
#ifdef WINDOWS
    system("timeout 1 > nul");
#else
    system("sleep 1");
#endif
}