// Q3. Write interactive programs in C using recursion for the following:
// (a) To find the HCF of two given numbers.
// (b) To find the GCD of two given numbers.
// (c) To find the factorial of a given number.

// (b)
#include <stdio.h>

int gcd(int n1, int n2)
{
    if (n2 != 0) {
        return gcd(n2, n1 % n2);
    } else {
        return n1;
    }
}

int main()
{
    int n1, n2;
    printf("Find GCD of two given numbers.\n");
    printf("Please input the numbers separated by space: ");
    scanf("%d %d", &n1, &n2);
    printf("GCD of %d and %d is %d.\n", n1, n2, gcd(n1, n2));
    return 0;
}
