#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    char S1[MAX_LENGTH], S2[MAX_LENGTH];

    // Input strings S1 and S2
    printf("Enter the first string (S1): ");
    scanf("%s", S1);

    printf("Enter the second string (S2): ");
    scanf("%s", S2);

    // Concatenate strings S1 and S2
    strcat(S1, S2);

    // Output the concatenated string
    printf("Concatenated string: %s\n", S1);

    return 0;
}
