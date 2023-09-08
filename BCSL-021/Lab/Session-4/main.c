#include <stdio.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int q13()
{
    int n, num, largest, smallest;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Invalid input. Number of elements must be positive.\n");
        return 0;
    }
    printf("Enter element 1: ");
    scanf("%d", &largest);
    smallest = largest;
    for (int i = 2; i <= n; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &num);
        largest = MAX(num, largest);
        smallest = MIN(num, smallest);
    }
    printf("The largest value is: %d\n", largest);
    printf("The smallest value is: %d\n", smallest);
    return 0;
}

#define ARRAY_LENGTH 20

int q14()
{
    int numbers[ARRAY_LENGTH];
    printf("Enter %d integers:\n", ARRAY_LENGTH);
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }
    printf("Reversed array:\n");
    for (int i = ARRAY_LENGTH - 1; i >= 0; i--) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    return 0;
}

#define MAX_SIZE 10

int q15()
{
    int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE], rows1, columns1, rows2, columns2, operation;
    printf("Enter the number of rows and columns for matrix 1: ");
    scanf("%d %d", &rows1, &columns1);
    printf("Enter the elements of matrix 1: ");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }
    printf("Enter the number of rows and columns for matrix 2: ");
    scanf("%d %d", &rows2, &columns2);
    printf("Enter the elements of matrix 2: ");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < columns2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }
    printf("Choose the operation to perform:\n");
    printf("1. Add matrices\n");
    printf("2. Subtract matrices\n");
    printf("3. Multiply matrices\n");
    scanf("%d", &operation);
    switch (operation) {
        case 1: // Addition
            if (rows1 != rows2 || columns1 != columns2) {
                printf("Matrix sizes are incompatible for addition.\n");
                return 0;
            }
            for (int i = 0; i < rows1; i++) {
                for (int j = 0; j < columns1; j++) {
                    result[i][j] = matrix1[i][j] + matrix2[i][j];
                }
            }
            printf("Result of matrix addition:\n");
            break;
        case 2: // Subtraction
            if (rows1 != rows2 || columns1 != columns2) {
                printf("Matrix sizes are incompatible for subtraction.\n");
                return 0;
            }
            for (int i = 0; i < rows1; i++) {
                for (int j = 0; j < columns1; j++) {
                    result[i][j] = matrix1[i][j] - matrix2[i][j];
                }
            }
            printf("Result of matrix subtraction:\n");
            break;
        case 3: // Multiplication
            if (columns1 != rows2) {
                printf("Matrix sizes are incompatible for multiplication.\n");
                return 0;
            }
            for (int i = 0; i < rows1; i++) {
                for (int j = 0; j < columns2; j++) {
                    result[i][j] = 0;
                    for (int k = 0; k < columns1; k++) {
                        result[i][j] += matrix1[i][k] * matrix2[k][j];
                    }
                }
            }
            printf("Result of matrix multiplication:\n");
            break;
        default:
            printf("Invalid operation.\n");
            return 0;
    }
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int main()
{
    // q13();
    // q14();
    q15();
}
