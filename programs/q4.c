#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

void insert() {
    int value;

    if ((rear + 1) % SIZE == front) {
        printf("Queue Overflow\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    if (front == -1) {
        front = 0;
        rear = 0;
    }
    else {
        rear = (rear + 1) % SIZE;
    }

    queue[rear] = value;
    printf("Inserted successfully\n");
}

void delete() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted element: %d\n", queue[front]);

    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else {
        front = (front + 1) % SIZE;
    }
}

void display() {
    int i;

    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");

    i = front;

    while (1) {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % SIZE;
    }

    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Circular Queue ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}