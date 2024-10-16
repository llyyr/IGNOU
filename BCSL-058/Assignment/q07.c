#include <stdio.h>
#include <math.h>

double simpsons_one_third(double a, double b, int n) {
    double h = (b - a) / n, sum = tan(a) + tan(b);
    for (int i = 1; i < n; i++)
        sum += (i % 2 == 0 ? 2 : 4) * tan(a + i * h);
    return (h / 3) * sum;
}

int main() {
    double a = 0.0, b = M_PI / 4;  // Limits of integration
    int n;

    printf("Enter the number of subintervals (even number): ");
    scanf("%d", &n);

    if (n % 2)
        return printf("Must be even.");

    printf("The approximate value of the integral is: %lf\n", simpsons_one_third(a, b, n));
    return 0;
}
