// Q4. Write interactive C programs to perform the following on strings:
// (a) To check if two strings are Anagram.
// (b) To check whether the given alphabet is a vowel or consonant.
// (c) To convert the given string from lower case to upper case without using the inbuilt
// function in <string.h>

// (b)
#include <stdio.h>
 
int main()
{
    char ch;
    printf("Input a character: ");
    scanf("%c", &ch);

    switch(ch) {
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U':
            printf("%c is a vowel.\n", ch);
            break;
        default:
            printf("%c isn't a vowel.\n", ch);
    }
    return 0;
}
