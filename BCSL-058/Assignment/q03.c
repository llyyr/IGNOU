#include <stdio.h>
#include <math.h>

#define TOL 1e-6
#define MAX_ITER 100

float fn(float x) {
    return x * x - 9 * x + 21;
}

int main() {
    float m, a = 0, b = 9; // Hardcoded initial bounds
    int iter = 0;

    // Ensure function changes sign in [a, b]
    if (fn(a) * fn(b) >= 0)
        return printf("Function does not change sign in the interval.\n");

    // Bisection method iteration
    while (iter < MAX_ITER) {
        m = (a + b) / 2;
        if (fabsf(fn(m)) < TOL || fabsf(b - a) <= TOL) break;
        fn(a) * fn(m) < 0 ? (b = m) : (a = m);
        iter++;
    }

    printf("The root is approximately: %.6f in %d iterations\n", m, iter);
    return 0;
}
