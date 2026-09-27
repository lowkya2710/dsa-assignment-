#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char page[50];
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *current = NULL;

/* Insert page */
void insertPage() {
    char name[50];

    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter page name: ");
    scanf("%s", name);

    strcpy(newNode->page, name);
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        current = newNode;
    }
    else {
        struct Node *temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    printf("Page inserted\n");
}

/* Forward */
void forward() {
    if (current == NULL) {
        printf("No pages available\n");
        return;
    }

    if (current->next == NULL) {
        printf("Already at last page\n");
    }
    else {
        current = current->next;
        printf("Current page: %s\n", current->page);
    }
}

/* Backward */
void backward() {
    if (current == NULL) {
        printf("No pages available\n");
        return;
    }

    if (current->prev == NULL) {
        printf("Already at first page\n");
    }
    else {
        current = current->prev;
        printf("Current page: %s\n", current->page);
    }
}

/* Delete page */
void deletePage() {
    char name[50];
    struct Node *temp = head;

    printf("Enter page to delete: ");
    scanf("%s", name);

    while (temp != NULL && strcmp(temp->page, name) != 0)
        temp = temp->next;

    if (temp == NULL) {
        printf("Page not found\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (current == temp) {
        if (temp->next != NULL)
            current = temp->next;
        else
            current = temp->prev;
    }

    free(temp);

    printf("Page deleted\n");
}

/* Display first to last */
void displayForward() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("No pages available\n");
        return;
    }

    printf("Pages: ");

    while (temp != NULL) {
        printf("%s <-> ", temp->page);
        temp = temp->next;
    }

    printf("NULL\n");
}

/* Display last to first */
void displayBackward() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("No pages available\n");
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    printf("Pages reverse: ");

    while (temp != NULL) {
        printf("%s <-> ", temp->page);
        temp = temp->prev;
    }

    printf("NULL\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Browser History ---\n");
        printf("1. Insert Page\n");
        printf("2. Forward\n");
        printf("3. Backward\n");
        printf("4. Delete Page\n");
        printf("5. Display Forward\n");
        printf("6. Display Backward\n");
        printf("7. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertPage();
                break;

            case 2:
                forward();
                break;

            case 3:
                backward();
                break;

            case 4:
                deletePage();
                break;

            case 5:
                displayForward();
                break;

            case 6:
                displayBackward();
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}