#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int words = rand() % 50 + 15;
    char **wordList;
    wordList = malloc(sizeof(char *) * words);
    if (wordList != NULL) {
        for (int i = 0; i < words; ++i) {
            int tmp = rand() % 14 + 3;
            *(wordList + i) = malloc(sizeof(char) * tmp);
            for (int j = 0; j < tmp - 1; ++j) {
                *(*(wordList + i) + j) = rand() % 58 + 65;
            }
            *(*(wordList + i) + tmp - 1) = '\0';
        }

        for (int i = 0; i < words; ++i) {
            if (*(wordList + i) != NULL) {
                printf("%s | ", *(wordList + i));
            }
        }
        printf("\nWORDS TOTAL: %d\n", words);
        char **justified;
        justified = malloc(sizeof(char *));
        int k = 0;
        int rows = 0;
        int limit = words;

        while (words) {
            void *tmp = realloc(justified, sizeof(char *) * (rows + 1));
            if (tmp != NULL) {
                justified = tmp;
                *(justified + rows) = calloc(26, sizeof(char));
            }
            int current = 0;
            while ((current + strlen(*(wordList + k))) < 26) {
                current += strlen(*(wordList + k));
                strcat(*(justified + rows), *(wordList + k));
                free(*(wordList + k));
                --words;
                ++k;
                if (k == limit) {
                    goto nahui;
                }
                if ((current + strlen(*(wordList + k))) < 25) {
                    *(*(justified + rows) + current++) = ' ';
                }
            }

            int wordsInString = 1;
            for (int i = 0; i < current; ++i) {
                if (*(*(justified + rows) + i) == ' ') ++wordsInString;
            }
            if (wordsInString == 1) {
                ++rows;
                continue;
            }
            while (current < 25) {
                char *ptr = strchr(*(justified + rows), ' ');
                for (int z = 0; z < wordsInString - 1; ++z) {
                    for (int j = current + 1; j > ptr - *(justified + rows); --j) {
                        *(*(justified + rows) + j) = *(*(justified + rows) + j - 1);
                    }
                    ++current;
                    if (current > 24) {
                        break;
                    }
                    while (*ptr == ' ') {
                        ++ptr;
                        if (ptr - *(justified + rows) > current) {
                            break;
                        }
                    }
                    while (*ptr != ' ') {
                        ++ptr;
                        if (ptr - *(justified + rows) > current) {
                            break;
                        }
                    }
                }
            }
            ++rows;
        }
    nahui:
        printf("\n");
        for (int i = 0; i < rows + 1; ++i) {
            if (*(justified + i) != NULL) {
                printf("%s\n", *(justified + i));
                free(*(justified + i));
            }
        }
        free(wordList);
        free(justified);
    }
    return 0;
}