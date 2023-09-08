// Q3: Write a program using linked list that accepts two polys as input
// and displays the resultant poly after performing the addition of the
// input polys.

#include <stdio.h>
#include <stdlib.h>

struct Term {
    int coeff;
    int exp;
    struct Term *next;
};

typedef struct Term Term;

void insert_term(Term** poly, int coef, int exp) {
    Term* new_term = (Term*)malloc(sizeof(Term));
    if (new_term == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    new_term->coeff = coef;
    new_term->exp = exp;
    new_term->next = *poly;
    *poly = new_term;
}

void add_polys(Term* poly1, Term* poly2, Term** result) {
    while (poly1 != NULL || poly2 != NULL) {
        int coef1 = (poly1 != NULL) ? poly1->coeff : 0;
        int coef2 = (poly2 != NULL) ? poly2->coeff : 0;
        int exp1 = (poly1 != NULL) ? poly1->exp : 0;
        int exp2 = (poly2 != NULL) ? poly2->exp : 0;

        if (exp1 == exp2) {
            insert_term(result, coef1 + coef2, exp1);
            poly1 = poly1->next;
            poly2 = poly2->next;
        } else if (exp1 > exp2) {
            insert_term(result, coef1, exp1);
            poly1 = poly1->next;
        } else {
            insert_term(result, coef2, exp2);
            poly2 = poly2->next;
        }
    }
}

void display_poly(Term* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }
    
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->exp);
        poly = poly->next;
        if (poly != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

int main() {
    Term* poly1 = NULL;
    Term* poly2 = NULL;
    Term* result = NULL;

    insert_term(&poly1, 3, 2);
    insert_term(&poly1, 2, 1);
    insert_term(&poly1, 5, 0);

    insert_term(&poly2, 4, 3);
    insert_term(&poly2, 1, 1);
    insert_term(&poly2, 2, 0);

    add_polys(poly1, poly2, &result);

    printf("polynomial 1: ");
    display_poly(poly1);

    printf("polynomial 2: ");
    display_poly(poly2);

    printf("Resultant polynomial: ");
    display_poly(result);

    return 0;
}
