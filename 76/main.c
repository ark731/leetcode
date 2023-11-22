// https://leetcode.com/problems/minimum-window-substring/

// Given two strings s and t of lengths m and n respectively, return the minimum window substring
// of s such that every character in t (including duplicates) is included in the window.
// If there is no such substring, return the empty string "".

// s and t consist of uppercase and lowercase English letters.

// Follow up: Could you find an algorithm that runs in O(m + n) time?

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 70

int main() {
    srand(time(NULL));
    char *string, *subStr;
    string = malloc(sizeof(char) * (SIZE + 1));
    if (string == NULL) {
        printf("MALLOC 1 ERROR\n");
        return 1;
    }
    for (int i = 0; i < SIZE; ++i) {
        *(string + i) = rand() % 26 + 65 + 32 * (rand() % 2);
    }
    printf("%s\n", string);
    int subStrSize = rand() % 4 + 2;
    subStr = malloc(sizeof(char) * (subStrSize + 1));
    if (subStr == NULL) {
        printf("MALLOC 2 ERROR\n");
        free(string);
        return 1;
    }
    int *subStrMap;
    subStrMap = calloc(58, sizeof(int));
    if (subStrMap == NULL) {
        printf("CALLOC 3 ERROR\n");
        free(subStr);
        free(string);
        return 1;
    }
    short uniq = 0;
    for (int i = 0; i < subStrSize; ++i) {
        *(subStr + i) = rand() % 26 + 65 + 32 * (rand() % 2);
        if (!(*(subStrMap + *(subStr + i) - 65))) {
            ++uniq;
        }
        ++(*(subStrMap + *(subStr + i) - 65));
    }
    printf("%s\n", subStr);

    int j = 0;
    int minWinSize = SIZE + 1;
    char *winPtr = NULL;
    for (int i = 0; i < SIZE; ++i) {
        --(*(subStrMap + *(string + i) - 65));
        if (!*(subStrMap + *(string + i) - 65)) {
            --uniq;
            if (!uniq) {
                while (*(subStrMap + *(string + j) - 65) < 0) {
                    ++(*(subStrMap + *(string + j++) - 65));
                }
                if (i - j + 1 < minWinSize) {
                    winPtr = string + j;
                    minWinSize = i - j + 1;
                }
                ++(*(subStrMap + *(string + j++) - 65));
                ++uniq;
            }
        }
    }

    if (winPtr != NULL) {
        printf("%.*s", minWinSize, winPtr);
    } else {
        printf("n/a\n");
    }

    free(subStrMap);
    free(subStr);
    free(string);
    return 0;
}