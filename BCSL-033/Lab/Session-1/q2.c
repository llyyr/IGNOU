#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 50
#define NUM_STRINGS 10

/* Function to perform lexicographic comparison for sorting */
int compare_strings(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    char strings[NUM_STRINGS][MAX_STRING_LENGTH];

    /* Input 10 strings */
    printf("Enter 10 strings:\n");
    for (int i = 0; i < NUM_STRINGS; i++) {
        printf("Enter string %d: ", i + 1);
        scanf("%s", strings[i]);
    }

    /* Sort the strings lexicographically */
    qsort(strings, NUM_STRINGS, sizeof(strings[0]), compare_strings);

    /* Display the strings in lexicographic order */
    printf("\nStrings in lexicographic order:\n");
    for (int i = 0; i < NUM_STRINGS; i++) {
        printf("%s\n", strings[i]);
    }

    return 0;
}
