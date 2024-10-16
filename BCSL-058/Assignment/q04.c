#include <stdio.h>

int fact(int n) {
    int f = 1;
    for (int i = 2; i <= n; i++)
        f *= i;
    return f;
}

int main() {
    int n = 5; // Number of data points
    float x[5] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f}; // x values
    // Corresponding y values: {f(1), f(2), f(3), f(4), f(5)}
    float y[5][5] = {{2.0f}, {3.0f}, {4.0f}, {5.0f}, {6.0f}};
    float val = 2.5f, u, h, p, sum;

    // Calculate backward differences
    for (int j = 1; j < n; j++)
        for (int i = n - 1; i >= j; i--)
            y[i][j] = y[i][j - 1] - y[i - 1][j - 1];

    h = x[1] - x[0];
    u = (val - x[n - 1]) / h;

    // Apply Newton's Backward Interpolation formula
    sum = y[n - 1][0];
    for (int i = 1; i < n; i++) {
        p = 1;
        for (int j = 0; j < i; j++)
            p *= (u + j);
        sum += (p * y[n - 1][i]) / fact(i);
    }

    printf("Interpolated value at x = %f is: %f\n", val, sum);
    return 0;
}
