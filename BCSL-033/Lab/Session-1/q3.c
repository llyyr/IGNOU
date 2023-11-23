#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int find_substring_positions(const char *main_str, const char *substring, int positions[]) {
    int count = 0;
    int main_length = strlen(main_str);
    int sub_length = strlen(substring);

    for (int i = 0; i <= main_length - sub_length; i++) {
        int j;
        for (j = 0; j < sub_length; j++) {
            if (main_str[i + j] != substring[j]) {
                break;
            }
        }

        if (j == sub_length) {
            positions[count++] = i;
        }
    }

    return count;
}

int main() {
    char S1[MAX_LENGTH], S2[MAX_LENGTH];
    int positions[MAX_LENGTH];
    int count, i;

    // Input strings S1 and S2
    printf("Enter the main string (S1): ");
    scanf("%s", S1);

    printf("Enter the substring (S2): ");
    scanf("%s", S2);

    // Find and output the starting and ending locations of S2 in S1
    count = find_substring_positions(S1, S2, positions);

    if (count > 0) {
        printf("'%s' is a substring of '%s' at the following positions:\n", S2, S1);
        for (i = 0; i < count; i++) {
            printf("Instance %d: Starting location: %d, Ending location: %lu\n", i + 1, positions[i], positions[i] + strlen(S2) - 1);
        }
    } else {
        printf("'%s' is not a substring of '%s'.\n", S2, S1);
    }

    return 0;
}
