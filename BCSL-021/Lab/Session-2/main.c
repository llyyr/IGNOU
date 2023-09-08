#include <stdio.h>
#include <math.h>

int q5()
{
    int n, digit, sum;

    printf("Armstrong numbers between 0 and 999 are: ");

    for (n = 0; n <= 999; ++n) {
        int temp = n;
        sum = 0;

        while (temp != 0) {
            digit = temp % 10;
            sum += pow(digit, 3);
            temp /= 10;
        }

        if (sum == n)
            printf("%d ", n);
    }
    printf("\n");

    return 0;
}


int q6()
{
    int n, sum = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    for (int i = 1; i < n; ++i) {
        if (n % i == 0)
            sum += i;
    }

    if (sum == n) {
        printf("%d is a perfect number.\n", n);
    } else {
        printf("%d is not a perfect number.\n", n);
    }

    return 0;
}

int sum_of_divisors(int n)
{
    int sum = 0;

    for (int i = 1; i < n; ++i) {
        if (n % i == 0)
            sum += i;
    }
    
    return sum;
}

int q7()
{
    int n1, n2;

    printf("Enter the first and second number: ");
    scanf("%d %d", &n1, &n2);

    if (sum_of_divisors(n1) == n2 && sum_of_divisors(n2) == n1) {
        printf("%d and %d are amicable numbers.\n", n1, n2);
    } else {
        printf("%d and %d are not amicable numbers.\n", n1, n2);
    }

    return 0;
}


int q8()
{
    double a, b, c;
    double discriminant, root1, root2, real_part, imaginary_part;

    printf("Enter the coefficients of the quadratic equation (a, b, c): ");
    scanf("%lf %lf %lf", &a, &b, &c);

    discriminant = pow(b, 2) - 4 * a * c;
    root1 = (-b + sqrt(discriminant)) / (2 * a);
    root2 = (-b - sqrt(discriminant)) / (2 * a);

    if (discriminant > 0) {
        // Two distinct real roots
        printf("Roots are real and distinct:\n");
        printf("Root 1 = %.2lf\n", root1);
        printf("Root 2 = %.2lf\n", root2);
    } else if (discriminant == 0) {
        // One real root (repeated)
        printf("Roots are real and repeated:\n");
        printf("Root 1 = Root 2 = %.2lf\n", root1);
    } else {
        // Complex roots (imaginary)
        real_part = -b / (2 * a);
        imaginary_part = sqrt(-discriminant) / (2 * a);
        printf("Roots are complex and imaginary:\n");
        printf("Root 1 = %.2lf + %.2lfi\n", real_part, imaginary_part);
        printf("Root 2 = %.2lf - %.2lfi\n", real_part, imaginary_part);
    }

    return 0;
}

int main()
{
    // q5();
    // q6();
    // q7();
    q8();
    return 0;
}
