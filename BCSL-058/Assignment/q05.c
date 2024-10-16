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
    float val = 3.5f, p;
    int mid = n / 2;
    float h = x[1] - x[0];
    float u = (val - x[mid]) / h;
    float sum = (y[mid][0] + y[mid - 1][0]) / 2;

    // Calculate central differences
    for (int j = 1; j < n; j++)
        for (int i = 0; i < n - j; i++)
            y[i][j] = y[i + 1][j - 1] - y[i][j - 1];

    // Apply Bessel's Interpolation Formula
    for (int i = 1; i < n; i++) {
        p = 1;
        for (int k = 0; k < i; k++)
            p *= (u - (k - 0.5f)) * (u + (k - 0.5f));
        sum += (p * y[mid - (i / 2) + (i % 2)][i]) / fact(i);
    }

    printf("Interpolated value at x = %f is: %f\n", val, sum);
    return 0;
}
