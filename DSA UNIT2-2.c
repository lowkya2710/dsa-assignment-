/*A service centre uses a fixed-size request buffer in which released positions must be reused. Write a C program to implement a 
Circular Queue using an array with insertion, deletion, display, overflow and underflow operations. Demonstrate that positions freed 
after deletion can be reused for new requests. */
#include <stdio.h>
#define MAX 5
int queue[MAX];
int front = -1;
int rear = -1;
// Insert an element
void enqueue() {
    int value;
    if ((rear + 1) % MAX == front) {
        printf("Queue Overflow! Buffer is full.\n");
        return;
    }
    printf("Enter request ID to insert: ");
    scanf("%d", &value);
    if (front == -1) {
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    queue[rear] = value;
    printf("Request %d inserted successfully.\n", value);
}
// Delete an element
void dequeue() {
    int value;
    if (front == -1) {
        printf("Queue Underflow! Buffer is empty.\n");
        return;
    }
    value = queue[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
    printf("Request %d deleted successfully.\n", value);
}
// Display queue elements
void display() {
    int i;
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}
int main() {
    int choice;
    while (1) {
        printf("\n--- SERVICE CENTRE REQUEST BUFFER ---\n");
        printf("1. Insert (Enqueue)\n");
        printf("2. Delete (Dequeue)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}