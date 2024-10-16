#include <stdio.h>

int main() {
    int n = 5; // Number of data points
    float x[5] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f}; // x values
    // Corresponding y values: {f(1), f(2), f(3), f(4), f(5)}
    float y[5][5] = {{2.0f}, {3.0f}, {4.0f}, {5.0f}, {6.0f}};
    float val = 2.5f, res = y[0][0];  // Initialize result with f[x0]

    // Calculate divided differences table
    for (int j = 1; j < n; j++)
        for (int i = 0; i < n - j; i++)
            y[i][j] = (y[i + 1][j - 1] - y[i][j - 1]) / (x[i + j] - x[i]);

    // Apply the divided difference formula to interpolate
    for (int i = 1; i < n; i++) {
        float t = 1.0f;
        for (int j = 0; j < i; j++)
            t *= (val - x[j]);
        res += t * y[0][i];
    }

    printf("The interpolated value at x = %f is: %f\n", val, res);
    return 0;
}
