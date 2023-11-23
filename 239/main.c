// https://leetcode.com/problems/sliding-window-maximum/

// You are given an array of integers nums, there is a sliding window of size k
// which is moving from the very left of the array to the very right.
// You can only see the k numbers in the window. Each time the sliding window moves
// right by one position.

// Return the max sliding window.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 30
#define WINSIZE 4

int main() {
    if (WINSIZE < 1 || WINSIZE > SIZE) {
        printf("n/a\n");
        return 1;
    }
    srand(time(NULL));
    int arr[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        *(arr + i) = rand() % 59 - 29;  // filling array with random numbers from -29 to 29
        printf("%d ", *(arr + i));
    }
    printf("\n");

    int queue[WINSIZE];
    int qSize = 0;
    int qPos = 0;  // offset for cycling queue front wrapped around queue array
    for (int i = 0; i < SIZE; ++i) {
        while (qSize > 0 && *(queue + (qSize + qPos - 1) % WINSIZE) < *(arr + i)) {
            --qSize;  // cleaning queue front from numbers lower than new one
        }
        *(queue + (qSize++ + qPos) % WINSIZE) = *(arr + i);  // put next one in queue
        if (i + 1 >= WINSIZE) {  // initial window passed, cycle queue and print result
            printf("%d ", *(queue + qPos));
            if (*(arr + i - WINSIZE + 1) == *(queue + qPos)) {
                ++qPos;
                qPos %= WINSIZE;  // cycle queue front
                --qSize;
            }
        }
    }

    return 0;
}