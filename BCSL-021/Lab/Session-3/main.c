#include <stdio.h>
#include <assert.h>

unsigned int invert(unsigned int x, int p, int n)
{
    if (n == 0)
        return x;
    unsigned const mask = (~0u >> (sizeof(x)*8 - n)) << (p-1);
    int ret = x ^ mask;
    printf("%b - Original\n", x);
    printf("%b - Bitshifted\n", ret);
    return ret;
}

int q9()
{
    unsigned int x;
    int p, n;
    printf("Enter x p n: ");
    scanf("%d %d %d", &x, &p, &n);
    printf("%d\n", invert(x, p, n));
    return 0;
}

float comp_int_calc(float int_amt, float rate, int years) {
    float comp_amt = int_amt;
    for (int i = 0; i < years; i++) {
        comp_amt *= (1 + rate);
    }
    return comp_amt - int_amt;
}

int q10()
{
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

int q12()
{
    int num1, num2;
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    printf("Minimum: %d\n", MIN(num1, num2));
    printf("Maximum: %d\n", MAX(num1, num2));
    return 0;
}

int main()
{
    q9();
}
