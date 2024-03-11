// Q1: Implement bubblesort for sorting the following list of numbers,
// and show the list obtained at each step: 17, 25, 32, 4, 7, 19, 81, 45, 1, 33.
// Also calculate the total number of exchange operations and how many times the loop will execute.

#include <stdio.h>

void bubblesort(int arr[], int n, int *exg, int *loops) {
    for (int i = 0; i < n - 1; i++) {
        printf("Iteration %d:\n", i + 1);
        for (int j = 0; j < n - i - 1; j++) {
            (*loops)++;
            if (arr[j] > arr[j + 1]) {
                (*exg)++;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                printf("\tSwap %d and %d\n", arr[j], arr[j + 1]);
            }
        }
        printf("\tCurrent List:");
        for (int k = 0; k < n; k++) printf(" %d", arr[k]);
        printf("\n");
    }
}

int main() {
    int arr[] = {17, 25, 32, 4, 7, 19, 81, 45, 1, 33};
    int n = sizeof(arr) / sizeof(arr[0]);
    int exg = 0, loops = 0;

    printf("Initial List:");
    for (int i = 0; i < n; i++) printf(" %d", arr[i]);
    printf("\n");

    bubblesort(arr, n, &exg, &loops);

    printf("\nSorted List:");
    for (int i = 0; i < n; i++) printf(" %d", arr[i]);
    printf("\nExchanges: %d, Loops: %d\n", exg, loops);

    return 0;
}
