/*A teacher wants to arrange student marks in ascending order and also measure how much rearrangement is necessary. 
Write a C program using Insertion Sort that accepts n marks, displays the array after every pass, counts the total number of element shifts, 
and displays the final sorted list and shift count.*/ 
#include <stdio.h>
int main() {
    int n, a[100];
    int i, j, key;
    int shifts = 0;
    printf("Enter number of students: ");
    scanf("%d", &n);
    printf("Enter student marks:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("\nArray after every pass:\n");
    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
        // Shift elements greater than key
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
            shifts++;
        }
        // Insert key in correct position
        a[j + 1] = key;
        printf("Pass %d: ", i);
        for (j = 0; j < n; j++) {
            printf("%d ", a[j]);
        }
        printf("\n");
    }
    printf("\nFinal sorted list: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\nTotal number of shifts: %d\n", shifts);
    return 0;
}