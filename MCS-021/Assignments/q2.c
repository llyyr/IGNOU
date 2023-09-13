// Q2: Write a program that accepts two polynomials as input and displays the
// resultant polynomial after multiplication of input polynomials.

#include <stdio.h>

#define MAX_DEGREE 100

typedef struct {
    int degree;
    double coeffs[MAX_DEGREE + 1];
} Poly;

void multiply(Poly p1, Poly p2, Poly *result) {
    int i, j;

    result->degree = p1.degree + p2.degree;

    for (i = 0; i <= result->degree; i++)
        result->coeffs[i] = 0.0;

    for (i = 0; i <= p1.degree; i++)
        for (j = 0; j <= p2.degree; j++)
            result->coeffs[i + j] += p1.coeffs[i] * p2.coeffs[j];
}

void input_poly(Poly *p) {
    printf("Enter coefficients, separated by spaces (e.g., 3.0 0.0 2.5 for 3.0 + 0.0x + 2.5x^2): ");
    p->degree = -1;
    do {
        p->degree++;
        scanf("%lf", &p->coeffs[p->degree]);
    } while (getchar() != '\n' && p->degree < MAX_DEGREE);
}

int main() {
    Poly p1, p2, result;
    int i;
    input_poly(&p1);
    input_poly(&p2);
    multiply(p1, p2, &result);
    printf("Result: ");
    for (i = 0; i <= result.degree; i++) {
        printf("%.2lfx^%d", result.coeffs[i], result.degree - i);
        if (i < result.degree)
            printf(" + ");
    }
    printf("\n");

    return 0;
}
