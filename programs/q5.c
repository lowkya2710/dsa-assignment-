#include <stdio.h>
#include <stdlib.h>

struct Node {
    int roll;
    struct Node *next;
};

struct Node *head = NULL;

/* Insert at beginning */
void insertBeginning() {
    int roll;

    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter roll number: ");
    scanf("%d", &roll);

    newNode->roll = roll;
    newNode->next = head;
    head = newNode;

    printf("Inserted at beginning\n");
}

/* Insert at end */
void insertEnd() {
    int roll;

    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter roll number: ");
    scanf("%d", &roll);

    newNode->roll = roll;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    }
    else {
        struct Node *temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    printf("Inserted at end\n");
}

/* Search */
void search() {
    int roll, position = 1;
    struct Node *temp = head;

    printf("Enter roll number to search: ");
    scanf("%d", &roll);

    while (temp != NULL) {
        if (temp->roll == roll) {
            printf("Roll number found at position %d\n", position);
            return;
        }

        temp = temp->next;
        position++;
    }

    printf("Roll number not found\n");
}

/* Delete */
void deleteNode() {
    int roll;
    struct Node *temp = head;
    struct Node *prev = NULL;

    printf("Enter roll number to delete: ");
    scanf("%d", &roll);

    while (temp != NULL && temp->roll != roll) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Roll number not found\n");
        return;
    }

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    free(temp);

    printf("Deleted successfully\n");
}

/* Display */
void display() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Roll numbers: ");

    while (temp != NULL) {
        printf("%d -> ", temp->roll);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Singly Linked List ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Search\n");
        printf("4. Delete\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertBeginning();
                break;

            case 2:
                insertEnd();
                break;

            case 3:
                search();
                break;

            case 4:
                deleteNode();
                break;

            case 5:
                display();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}