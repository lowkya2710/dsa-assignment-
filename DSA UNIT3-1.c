/*A department maintains student roll numbers dynamically. Write a C program using a Singly Linked List to create the list, 
insert at the beginning and end, search for a specified roll number, delete a specified roll number, and display the updated 
list after each operation. Handle the case when a requested roll number is not available. */
#include <stdio.h>
#include <stdlib.h>
// Structure for a node
struct Node {
    int roll;
    struct Node *next;
};
struct Node *head = NULL;
// Display the linked list
void display() {
    struct Node *temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Student Roll Numbers: ");
    while (temp != NULL) {
        printf("%d -> ", temp->roll);
        temp = temp->next;
    }
    printf("NULL\n");
}
// Create the list
void createList() {
    int n, roll, i;
    struct Node *newNode, *temp;
    printf("Enter number of students: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter roll number: ");
        scanf("%d", &roll);
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->roll = roll;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    printf("List created successfully.\n");
    display();
}
// Insert at beginning
void insertBeginning() {
    int roll;
    struct Node *newNode =(struct Node *)malloc(sizeof(struct Node));
    printf("Enter roll number: ");
    scanf("%d", &roll);
    newNode->roll = roll;
    newNode->next = head;
    head = newNode;
    printf("Inserted at beginning.\n");
    display();
}
// Insert at end
void insertEnd() {
    int roll;
    struct Node *newNode =(struct Node *)malloc(sizeof(struct Node));
    struct Node *temp;
    printf("Enter roll number: ");
    scanf("%d", &roll);
    newNode->roll = roll;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Inserted at end.\n");
    display();
}
// Search for a roll number
void search() {
    int roll, position = 1;
    struct Node *temp = head;
    printf("Enter roll number to search: ");
    scanf("%d", &roll);
    while (temp != NULL) {
        if (temp->roll == roll) {
            printf("Roll number %d found at position %d.\n",roll, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Roll number %d not found.\n", roll);
}
// Delete a specified roll number
void deleteNode() {
    int roll;
    struct Node *temp, *prev;
    printf("Enter roll number to delete: ");
    scanf("%d", &roll);
    temp = head;
    prev = NULL;
    // Search for the node
    while (temp != NULL && temp->roll != roll) {
        prev = temp;
        temp = temp->next;
    }
    // Roll number not found
    if (temp == NULL) {
        printf("Roll number %d not found. Cannot delete.\n",roll);
        return;
    }
    // Delete first node
    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    printf("Roll number %d deleted successfully.\n", roll);
    display();
}
// Main function
int main() {
    int choice;
    while (1) {
        printf("\n--- STUDENT ROLL NUMBER LIST ---\n");
        printf("1. Create List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Search Roll Number\n");
        printf("5. Delete Roll Number\n");
        printf("6. Display List\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createList();
                break;
            case 2:
                insertBeginning();
                break;
            case 3:
                insertEnd();
                break;
            case 4:
                search();
                break;
            case 5:
                deleteNode();
                break;
            case 6:
                display();
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