// Q1: Write a program to multiply two matrices using array.

#include <stdio.h>

int main() {
    int mat1[3][3] = {
        {2, 3, 4},
        {5, 6, 7},
        {8, 9, 10}
    };
    int mat2[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int result[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    printf("Result of matrix multiplication:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}
