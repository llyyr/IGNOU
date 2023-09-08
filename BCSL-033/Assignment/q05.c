// Q5: Write a program in C to sort user input data using quick sort method.
// Also, print the number of swaps and comparison operations performed for
// sorting the given data set.


#include <stdio.h>

#define MAX_SIZE 100
#define SWAP(a, b) do { int temp = a; a = b; b = temp; } while (0)

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                SWAP(arr[i], arr[j]);
            }
        }

        SWAP(arr[i + 1], arr[high]);

        quickSort(arr, low, i);
        quickSort(arr, i + 2, high);
    }
}

int main() {
    int arr[MAX_SIZE];
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n > MAX_SIZE) {
        printf("Array size exceeds the maximum limit.\n");
        return 1;
    }

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    quickSort(arr, 0, n - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
