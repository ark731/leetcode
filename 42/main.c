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
        printf("NEXT POS: %d ", *pos);
        endPos = getEndPos(map, *pos, level);
        if (endPos != -1) {
            break;
        }
        --level;
    }
    if (endPos != -1) {
        trapped = collect(map, *pos, endPos, level);
        printf("ACTUAL NEXTPOS: %d", endPos);
        *pos = endPos - 1;
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
    printf("NEXT ENDPOS: %d\n", endPos);
    return endPos;
}

int collect(int *map, int pos, int endPos, int level) {
    int trapped = 0;
    printf("COLLECTING FROM %d TO %d, LEVEL %d : ", pos, endPos, level);

    while (pos <= endPos) {
        printf("%d ", level - *(map + pos));
        if ((level - *(map + pos)) > 0) {
            printf("^;  ");
            trapped += level - *(map + pos++);
        } else {
            ++pos;
        }
    }
    printf("\n");
    return trapped;
}