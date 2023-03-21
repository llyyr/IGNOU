// Q1. Write an algorithm, draw corresponding flow chart and write an 
// interactive program in C which prompts the user with the following options 
// on the opening menu:
//
// 1) To reverse a 5-digit number
// 2) To check whether the 5-digit number is a palindrome or not
// 3) To find the sum of all the digits of the 5-digit number
// 4) Quit
//
// Enter your choice:
//
// Note: Use SWITCH..CASE statement.

#include <stdio.h>

int reverse_num(int n)
{
    int reversed = 0, remainder;
    while (n != 0) {
        remainder = n % 10;
        reversed = reversed * 10 + remainder;
        n /= 10;
    }
    return reversed;
}

int main()
{
    int choice;
    int n, reversed;
    int sum = 0, y;
    printf("1) To reverse a 5-digit number\n");
    printf("2) To check whether the 5-digit number is a palindrome or not\n");
    printf("3) To find the sum of all the digits of the 5-digit number\n");
    printf("4) Quit\n");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);
    printf("Enter a 5 digit integer: ");
    scanf("%d", &n);
    switch (choice) {
        case 1:
            reversed = reverse_num(n);
            printf("Reversed integer is %d\n", reversed);
            break;
        case 2:
            reversed = reverse_num(n);
            if (n == reversed) {
                printf("%d is a palindrome.\n", n);
            } else {
                printf("%d is not a palindrome.\n", n);
            }
            break;
        case 3:
            while (n > 0) {
                y = n % 10;
                sum += y;
                n /= 10;
            }
            printf("Sum is %d\n", sum);
            break;
        case 4:
            break;
        default:
            printf("Please choose a valid option.\n");
            break;
    }
}
