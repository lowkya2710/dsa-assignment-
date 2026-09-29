/*Develop a C program for a Doubly Linked List representing a sequence of web pages visited by a user. The program should insert a new page, 
move forward and backward, delete a specified page, and display the pages from first-to-last and last-to-first while handling beginning and 
end conditions correctly.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
// Structure for a web page node
struct Node {
    char page[MAX];
    struct Node *prev;
    struct Node *next;
};
struct Node *head = NULL;
struct Node *tail = NULL;
struct Node *current = NULL;
// Create a new node
struct Node* createNode(char page[]) {
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    strcpy(newNode->page, page);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
// Insert a new page at the end
void insertPage() {
    char page[MAX];
    struct Node *newNode;
    printf("Enter web page name: ");
    scanf("%99s", page);
    newNode = createNode(page);
    if (newNode == NULL)
        return;
    if (head == NULL) {
        head = tail = current = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        current = newNode;
    }
    printf("Page inserted successfully.\n");
}
// Move forward
void moveForward() {
    if (current == NULL) {
        printf("No pages in history.\n");
    }
    else if (current->next == NULL) {
        printf("Already at the last page.\n");
    }
    else {
        current = current->next;
        printf("Moved forward to: %s\n", current->page);
    }
}
// Move backward
void moveBackward() {
    if (current == NULL) {
        printf("No pages in history.\n");
    }
    else if (current->prev == NULL) {
        printf("Already at the first page.\n");
    }
    else {
        current = current->prev;
        printf("Moved backward to: %s\n", current->page);
    }
}
// Display first to last
void displayForward() {
    struct Node *temp = head;
    if (head == NULL) {
        printf("History is empty.\n");
        return;
    }
    printf("First to Last:\n");
    while (temp != NULL) {
        printf("%s", temp->page);
        if (temp->next != NULL)
            printf(" <-> ");
        temp = temp->next;
    }
    printf("\n");
}
// Display last to first
void displayBackward() {
    struct Node *temp = tail;
    if (tail == NULL) {
        printf("History is empty.\n");
        return;
    }
    printf("Last to First:\n");
    while (temp != NULL) {
        printf("%s", temp->page);
        if (temp->prev != NULL)
            printf(" <-> ");
        temp = temp->prev;
    }
    printf("\n");
}
// Delete a specified page
void deletePage() {
    char page[MAX];
    struct Node *temp;
    printf("Enter page to delete: ");
    scanf("%99s", page);
    temp = head;
    // Search for the page
    while (temp != NULL &&
           strcmp(temp->page, page) != 0) {
        temp = temp->next;
    }
    // Page not found
    if (temp == NULL) {
        printf("Page not found. Cannot delete.\n");
        return;
    }
    // Update previous node
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;
    // Update next node
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    else
        tail = temp->prev;
    // Move current safely
    if (temp == current) {
        if (temp->next != NULL)
            current = temp->next;
        else
            current = temp->prev;
    }
    free(temp);
    printf("Page deleted successfully.\n");
}
// Main function
int main() {
    int choice;
    while (1) {
        printf("\n--- WEB PAGE HISTORY ---\n");
        printf("1. Insert New Page\n");
        printf("2. Move Forward\n");
        printf("3. Move Backward\n");
        printf("4. Delete Page\n");
        printf("5. Display First to Last\n");
        printf("6. Display Last to First\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insertPage();
                break;
            case 2:
                moveForward();
                break;
            case 3:
                moveBackward();
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
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}