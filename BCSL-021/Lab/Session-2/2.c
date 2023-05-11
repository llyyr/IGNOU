// Write Program in C:
// Area & Perimeter of (1) Rectangle, (2) Square, (3) Circle.
// (4) Generate natural number 1 to 150.
// (5) Generate odd number 1 to 150.
// (6) Generate even number 1 to 150.

#include <stdio.h>
#include <math.h>

int main() {
    int choice, a, b;
    printf("Choose one:\n");
    printf("(1) Area and Perimeter of Rectangle\n");
    printf("(2) Area and Perimeter of Square\n");
    printf("(3) Area and Perimeter of Circle\n");
    printf("(4) Natural number between 1 to 150\n");
    printf("(5) Odd number between 1 to 150\n");
    printf("(6) Even number between 1 to 150\n");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Enter the length and width of the rectange: ");
            scanf("%d %d", &a, &b);
            printf("Area: %d\nPerimeter: %d\n", a*b, 2*(a+b));
            break;
        case 2:
            printf("Enter the length of side of square: ");
            scanf("%d", &a);
            printf("Area: %d\nPerimeter: %d\n", a*a, 4*a);
            break;
        case 3:
            printf("Enter the radius of circle: ");
            scanf("%d", &a);
            printf("Area: %f\nPerimeter: %f\n", M_PI * a, 2 * M_PI * a);
            break;
        case 4:
            for (int i = 0; i<=150; ++i) {
                printf("%d\n", i);
            }
            break;
        case 5:
            for (int i = 0; i<=150; ++i) {
                if (i % 2 != 0)
                    printf("%d\n", i);
            }
            break;
        case 6:
            for (int i = 0; i<=150; ++i) {
                if (i % 2 == 0)
                    printf("%d\n", i);
            }
            break;
        default:
            printf("Invalid choice\n");
            return 0;
    }
}
