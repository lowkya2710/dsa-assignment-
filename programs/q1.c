#include <stdio.h>

int main() {
    int a[100], n;
    int i, j, key;
    int shifts = 0;

    printf("Enter number of students: ");
    scanf("%d", &n);

    printf("Enter marks:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
            shifts++;
        }

        a[j + 1] = key;

        printf("After pass %d: ", i);
        for (int k = 0; k < n; k++)
            printf("%d ", a[k]);
        printf("\n");
    }

    printf("\nFinal sorted list: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\nTotal number of shifts = %d\n", shifts);

    return 0;
}