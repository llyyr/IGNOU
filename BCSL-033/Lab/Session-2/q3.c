#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_LENGTH 50

struct Word {
    char word[MAX_LENGTH];
    int cnt;
};

int main()
{
    char paragraph[1000];
    struct Word word_list[MAX_WORDS];

    printf("Enter a paragraph of text:\n");
    fgets(paragraph, sizeof(paragraph), stdin);

    char current_word[MAX_LENGTH];
    int word_index = 0;

    for (int i = 0; i < MAX_WORDS; i++)
        word_list[i].cnt = 0;

    for (int i = 0; paragraph[i]; i++) {
        int j = 0;
        while (!ispunct(paragraph[i]) && !isspace(paragraph[i]) && paragraph[i] != '\0')
            current_word[j++] = paragraph[i++];

        if (j > 0) {
            current_word[j] = '\0';
            for (int i = 0; current_word[i]; i++)
                current_word[i] = tolower(current_word[i]);

            bool found = false;
            for (int k = 0; k < word_index; k++) {
                if (strcmp(word_list[k].word, current_word) == 0) {
                    word_list[k].cnt++;
                    found = true;
                    break;
                }
            }

            if (!found) {
                strcpy(word_list[word_index].word, current_word);
                word_list[word_index].cnt = 1;
                word_index++;

                if (word_index >= MAX_WORDS) {
                    printf("Maximum number of words exceeded.\n");
                    break;
                }
            }
        }
    }

    printf("\nList of Words and Count:\n");
    for (int i = 0; i < word_index; i++)
        printf("%s = %d\n", word_list[i].word, word_list[i].cnt);

    return 0;
}
