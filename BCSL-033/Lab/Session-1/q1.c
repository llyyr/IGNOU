#include <stdio.h>

void input_matrix(int rows, int cols, int matrix[rows][cols]) {
    printf("Enter the elements of the matrix:\n");

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element at position [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void multiply_matrices(int rows1, int cols1, int matrix1[rows1][cols1],
                       int rows2, int cols2, int matrix2[rows2][cols2],
                       int result[rows1][cols2]) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void display_matrix(int rows, int cols, int matrix[rows][cols]) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows1, cols1, rows2, cols2;

    printf("Enter the number of rows and columns for the first matrix: ");
    scanf("%d %d", &rows1, &cols1);

    printf("Enter the number of rows and columns for the second matrix: ");
    scanf("%d %d", &rows2, &cols2);

    if (cols1 != rows2) {
        printf("Matrices cannot be multiplied due to incompatible dimensions.\n");
        return 1;
    }

    int matrix1[rows1][cols1], matrix2[rows2][cols2], result[rows1][cols2];

    input_matrix(rows1, cols1, matrix1);
    input_matrix(rows2, cols2, matrix2);

    multiply_matrices(rows1, cols1, matrix1, rows2, cols2, matrix2, result);

    display_matrix(rows1, cols2, result);

    return 0;
}
