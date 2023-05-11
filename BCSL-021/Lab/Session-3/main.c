#include <stdio.h>
#include <assert.h>
#include <limits.h>

unsigned invert(unsigned x, int p, int n)
{
    int const n_bits = sizeof(x) * CHAR_BIT;
    assert(p >= 0 && p < n_bits);
    assert(n >= 0 && n + p <= n_bits);
    if (n == 0)
        return x;
    unsigned const mask = (~0u >> (n_bits - n)) << p;
    return x ^ mask;
}

int q9()
{
    int x, p, n;
    printf("Enter x p n: ");
    scanf("%d %d %d", &x, &p, &n);
    printf("%d\n", invert(x, p, n));
    return 0;
}

float comp_int_calc(float int_amt, float rate, int years) {
    float compounded_amount = int_amt;
    for (int i = 0; i < years; i++) {
        compounded_amount *= (1 + rate);
    }
    float interest_amount = compounded_amount - int_amt;
    return interest_amount;
}

int q10() {
    float int_amt, rate;
    int years;
    printf("Enter the initial amount: ");
    scanf("%f", &int_amt);
    printf("Enter the interest rate (in decimal): ");
    scanf("%f", &rate);
    printf("Enter the number of years: ");
    scanf("%d", &years);
    printf("The interest amount is: %.2f\n", comp_int_calc(int_amt, rate, years));
    return 0;
}

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int q12() {
    int num1, num2;
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    printf("Minimum: %d\n", MIN(num1, num2));
    printf("Maximum: %d\n", MAX(num1, num2));
    return 0;
}
