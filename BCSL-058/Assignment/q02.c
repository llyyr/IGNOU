#include <stdio.h>
#include <math.h>

#define MAX_ITER 100
#define TOL 1e-6

int main() {
    float a[3][3] = {
        {4, -1, 0},
        {-1, 4, -1},
        {0, -1, 3}
    }; // Hardcoded coefficients
    float b[3] = {15, 10, 10};  // Hardcoded constants
    float x[3] = {0, 0, 0}, x_old[3], sum, err;
    int iter = 0;

    // Gauss-Seidel iteration
    do {
        for (int i = 0; i < 3; i++) {
            x_old[i] = x[i];
            sum = b[i];
            for (int j = 0; j < 3; j++)
                if (i != j) sum -= a[i][j] * x[j];
            x[i] = sum / a[i][i];
        }
        err = 0.0f;
        for (int i = 0; i < 3; i++)
            err += fabsf(x[i] - x_old[i]);
        iter++;
    } while (err > TOL && iter < MAX_ITER);

    printf("Solution after %d iterations:\n", iter);
    for (int i = 0; i < 3; i++)
        printf("x[%d] = %.6f\n", i + 1, x[i]);
    printf("\nSolution %s after %d iterations\n", (err <= TOL) ? "converged" : "did not converge", MAX_ITER);
    return 0;
}
