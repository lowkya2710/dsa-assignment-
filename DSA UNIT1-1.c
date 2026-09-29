/*A company stores employee IDs in ascending order. Write a C program that accepts n employee IDs, searches for a required ID using 
Binary Search, displays its position when found, reports when it is absent, and counts the number of comparisons. Test the program for 
both successful and unsuccessful searches. */
#include <stdio.h>
int main() {
    int n, a[100], key;
    int low, high, mid;
    int comparisons = 0;
    int found = 0;
    printf("Enter number of employees: ");
    scanf("%d", &n);
    printf("Enter employee IDs in ascending order:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("Enter employee ID to search: ");
    scanf("%d", &key);
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        comparisons++;
        if (a[mid] == key) {
            printf("Employee ID found at position %d\n", mid + 1);
            found = 1;
            break;
        }
        else if (key < a[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    if (found == 0) {
        printf("Employee ID not found\n");
    }
    printf("Number of comparisons: %d\n", comparisons);
    return 0;
}