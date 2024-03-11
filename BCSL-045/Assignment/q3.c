// Q3: Write a program to reverse the following string: "ABCDEFGHIJ" and calculate
// (i) Total number of swaps
// (ii) Total number of comparisons
// (iii) Total number of times the loop will execute.

#include <stdio.h>
#include <string.h>

void reverse(char str[], int *swaps, int *comps, int *loops) {
    unsigned int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        (*loops)++;
        (*comps)++;
        (*swaps)++;
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int main() {
    char str[] = "ABCDEFGHIJ";
    int swaps = 0, comps = 0, loops = 0;
    reverse(str, &swaps, &comps, &loops);
    printf("Reversed string: %s\n(i) Swaps: %d\n(ii) Comparisons: %d\n(iii) Loops: %d\n", str, swaps, comps, loops);
    return 0;
}
