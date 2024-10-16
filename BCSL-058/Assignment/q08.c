#include <stdio.h>

int main() {
    double a, b, y0;
    int n;

    printf("Enter a, b, y(a), and number of steps: ");
    scanf("%lf %lf %lf %d", &a, &b, &y0, &n);

    // Euler's method/rule
    double h = (b - a) / n, x = a, y = y0;
    for (int i = 0; i < n; i++)
        y += h * (x + y); x += h;

    printf("Approximate solution at x = %lf is y = %lf\n", b, y);
    return 0;
}
