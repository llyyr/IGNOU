// Q4: Implement binary search to seach for 29 in the given array: 
// 14, 7, 22, 24, 39, 20, 90, 10, 15, 6. 
// And calculate the number of comparisons and division operations.

#include <stdio.h>

int binary_search(int arr[], int len, int target, int *comps, int *divs) {
    int lo = 0, hi = len - 1, mid;
    while (lo <= hi) {
        (*divs)++;
        mid = (lo + hi) / 2;
        if (arr[mid] == target) {
            (*comps)++;
            return mid;
        } else if (arr[mid] < target) {
            (*comps) += 2;
            lo = mid + 1;
        } else {
            (*comps) += 2;
            hi = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {14, 7, 22, 24, 39, 20, 90, 10, 15, 6};
    int len = sizeof(arr) / sizeof(arr[0]);
    int target = 29, comps = 0, divs = 0;
    int result = binary_search(arr, len, target, &comps, &divs);
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");
    printf("Comparisons: %d, Divisions: %d\n", comps, divs);
    return 0;
}
