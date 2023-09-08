#include <stdlib.h>
#include <stdio.h>

#define PI 3.14159265358979323846

int main()
{
    int opt, a, b;
    while (1) {
        printf("Choose one:\n");
        printf("\t(1) Area and Perimeter of Rectangle\n");
        printf("\t(2) Area and Perimeter of Square\n");
        printf("\t(3) Area and Perimeter of Circle\n");
        printf("\t(4) Natural number between 1 to 150\n");
        printf("\t(5) Odd number between 1 to 150\n");
        printf("\t(6) Even number between 1 to 150\n");
        printf("\t(7) Quit\n");
        scanf("%d", &opt);
        switch (opt) {
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
                printf("Area: %f\nPerimeter: %f\n", PI*a, 2*PI*a);
                break;
            case 4:
                for (int i=0; i<=150; ++i) {
                    printf("%d\n", i);
                }
                break;
            case 5:
                for (int i=0; i<=150; ++i) {
                    if (i%2 != 0)
                        printf("%d\n", i);
                }
                break;
            case 6:
                for (int i=0; i<=150; ++i) {
                    if (i%2 == 0)
                        printf("%d\n", i);
                }
                break;
            case 7:
                return 0;
            default:
                printf("Invalid opt\n");
                return 0;
        }
        system("read -p 'Press enter to continue'");
        system("clear");
    }
}
