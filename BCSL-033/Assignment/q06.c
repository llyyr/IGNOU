// Q6: Write a program in C to search an input data from a set of data, stored
// in an array using binary search algorithm. Also, print the number of
// comparison operations performed for searching the given data.

#include <stdio.h>

int binary_search(int arr[], int size, int target, int *comparisons) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        (*comparisons)++;
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the sorted elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int target;
    printf("Enter the element to search: ");
    scanf("%d", &target);

    int comparisons = 0;
    int result = binary_search(arr, n, target, &comparisons);

    if (result != -1) {
        printf("Element at %d\n", result);
    } else {
        printf("Element not found\n");
    }

    printf("Number of comparisons: %d\n", comparisons);

    return 0;
}
