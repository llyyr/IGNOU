// Q4. Write interactive C programs to perform the following on strings:
// (a) To check if two strings are Anagram.
// (b) To check whether the given alphabet is a vowel or consonant.
// (c) To convert the given string from lower case to upper case without using the inbuilt
// function in <string.h>

// (c)
#include <stdio.h>

int main()
{
    char str[100];
    int i;
    printf("Enter your text: ");
    scanf("%s", str);
    for (i=0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }
    printf("Uppercase string: %s\n", str);
    return 0;
}
