// Q3. Write interactive programs in C using recursion for the following:
// (a) To find the HCF of two given numbers.
// (b) To find the GCD of two given numbers.
// (c) To find the factorial of a given number.

// (c)
#include <stdio.h>

unsigned long int factorial(unsigned int n)
{
    if (n >= 1) {
        return n * factorial(n-1);
    } else {
        return 1;
    }
}

int main()
{
    unsigned int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    printf("Factorial of %d is %ld.\n", n, factorial(n));
    return 0;
}
