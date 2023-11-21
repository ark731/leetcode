// https://leetcode.com/problems/trapping-rain-water/

// Given n non-negative integers representing an elevation map where the width of each bar is 1,
// compute how much water it can trap after raining.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8

int trap(int *map, int *pos);
int getEndPos(int *map, int pos, int level);
int collect(int *map, int pos, int endPos, int level);

int main() {
    srand(time(NULL));
    int map[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        *(map + i) = rand() % 6;
        printf("%d", i);
        for (int j = 0; j <= *(map + i); ++j) {
            printf("#");
        }
        printf("\n");
    }

    int trapped = 0;
    for (int pos = 0; pos < SIZE - 1; ++pos) {
        if (*(map + pos) <= *(map + pos + 1)) {
            continue;
        }
        trapped += trap(map, &pos);
    }
    printf("\nWATER TRAPPED: %d\n", trapped);
    return 0;
}

int trap(int *map, int *pos) {
    int trapped = 0;
    int endPos = -1;
    int level = *(map + *pos);
    while (level) {
        endPos = getEndPos(map, *pos, level);
        if (endPos != -1) {
            break;
        }
        --level;
    }
    if (endPos != -1) {
        trapped = collect(map, *pos, endPos, level);
        *pos = endPos - 1;
    } else {
        *pos = SIZE;
    }
    return trapped;
}

int getEndPos(int *map, int pos, int level) {
    int endPos = -1;
    while (pos < SIZE) {
        if (*(map + ++pos) >= level) {
            endPos = pos;
            break;
        }
    }
    return endPos;
}

int collect(int *map, int pos, int endPos, int level) {
    int trapped = 0;
    while (pos <= endPos) {
        if ((level - *(map + pos)) > 0) {
            trapped += level - *(map + pos++);
        } else {
            ++pos;
        }
    }
    return trapped;
}