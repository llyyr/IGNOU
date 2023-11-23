#include <stdio.h>

struct element {
    int row;
    int col;
    int value;
};

struct Sparse_Matrix {
    int rows;
    int cols;
    int n;
    struct element data[100];
};

void input_matrix(struct Sparse_Matrix *matrix)
{
    printf("Enter the number of rows and columns of the matrix (5 5): ");
    scanf("%d %d", &matrix->rows, &matrix->cols);

    matrix->n = 0;

    printf("Enter the elements of the matrix (row, column, value):\n");
    for (int i = 0; i < matrix->rows; ++i) {
        for (int j = 0; j < matrix->cols; ++j) {
            int value;
            scanf("%d", &value);
            if (value != 0) {
                matrix->data[matrix->n].row = i;
                matrix->data[matrix->n].col = j;
                matrix->data[matrix->n].value = value;
                matrix->n++;
            }
        }
    }
}

void print_matrix(struct Sparse_Matrix matrix)
{
    printf("Sparse Matrix:\n");
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < matrix.n; ++i)
        printf("%d\t%d\t%d\n", matrix.data[i].row, matrix.data[i].col, matrix.data[i].value);
}

void multiply_matrices(struct Sparse_Matrix matrix1, struct Sparse_Matrix matrix2, struct Sparse_Matrix *result)
{
    if (matrix1.cols != matrix2.rows) {
        printf("Number of columns in the first matrix must be equal "
               "to the number of rows in the second matrix.\n");
        return;
    }

    result->rows = matrix1.rows;
    result->cols = matrix2.cols;
    result->n = 0;

    for (int i = 0; i < matrix1.rows; ++i) {
        for (int j = 0; j < matrix2.cols; ++j) {
            int sum = 0;
            for (int k = 0; k < matrix1.cols; ++k)
                for (int l = 0; l < matrix1.n; ++l)
                    if (matrix1.data[l].row == i && matrix1.data[l].col == k)
                        for (int m = 0; m < matrix2.n; ++m) {
                            if (matrix2.data[m].row == k && matrix2.data[m].col == j)
                                sum += matrix1.data[l].value * matrix2.data[m].value;
            }

            if (sum != 0) {
                result->data[result->n].row = i;
                result->data[result->n].col = j;
                result->data[result->n].value = sum;
                result->n++;
            }
        }
    }
}

int main()
{
    struct Sparse_Matrix matrix1, matrix2, result;

    printf("Enter the first matrix:\n");
    input_matrix(&matrix1);

    printf("Enter the second matrix:\n");
    input_matrix(&matrix2);

    multiply_matrices(matrix1, matrix2, &result);

    printf("\nResult of Matrix Multiplication:\n");
    print_matrix(result);

    return 0;
}
