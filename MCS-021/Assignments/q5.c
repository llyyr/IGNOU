// Q5: Write a program in C for insertion sort. Write the step-by-step working
// of the insertion sort for the following set of data: 
// 10, 25, 86, 1, 16, 95, 37, 56, 5, 15, 20, 4. Also count the number of swaps 
// and comparison operations performed for it.

#include <stdio.h>

int main() {
    int arr[] = {10, 25, 86, 1, 16, 95, 37, 56, 5, 15, 20, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int swap = 0, comp = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        comp++;
        while (j >= 0 && arr[j] > key) {
            swap++;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\nSwaps: %d\n", swap);
    printf("Comparisons: %d\n", comp);
    return 0;
}
