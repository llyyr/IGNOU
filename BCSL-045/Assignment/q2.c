// Q2: Implement quicksort for the following array: 5, 70, 44, 39, 25, 25, 7, 12, 27, 6. And calculate the number of compariosn and swaps.

#include <stdio.h>

void swap(int v[], int i, int j) {
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void quicksort(int v[], int left, int right, int *comps, int *swaps) {
    int i, last;
    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++) {
        (*comps)++;
        if (v[i] < v[left]) {
            (*swaps)++;
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    quicksort(v, left, last - 1, comps, swaps);
    quicksort(v, last + 1, right, comps, swaps);
}

int main() {
    int arr[] = {5, 70, 44, 39, 25, 25, 7, 12, 27, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int comps = 0, swaps = 0;

    quicksort(arr, 0, n - 1, &comps, &swaps);

    printf("Sorted Array:");
    for (int i = 0; i < n; i++) printf(" %d", arr[i]);
    printf("\nComparisons: %d, Swaps: %d\n", comps, swaps);

    return 0;
}
