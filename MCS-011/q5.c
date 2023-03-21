// Q5. Using arrays in C write a program to input 2 arrays consisting of 
// 10 numbers each and display all the numbers those are common to 
// both the arrays and display their count.

#include <stdio.h>

int main()
{
    int a[10], b[10], n=10, same[10];
    printf("Enter the 10 elements of the first array\n");
    for (int i=0; i<n; i++) {
        printf("%d: ", i+1);
        scanf("%d", &a[i]);
    }
    printf("Enter the 10 elements of the second array\n");
    for (int i=0; i<n; i++) {
        printf("%d: ", i+1);
        scanf("%d", &b[i]);
    }
    printf("The common elements are: ");
    for (int x=0; x < n; x++) {
        for (int y=0; y < n; y++) {
            if (a[x] == b[y]) {
                printf("%d ", a[x]);
            }
        }
    }
    printf("\n");
    return 0;
}
