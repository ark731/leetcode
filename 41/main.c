// https://leetcode.com/problems/first-missing-positive/

// Given an unsorted integer array nums, return the smallest missing positive integer.
// You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

// Example 1:
// Input: nums = [1,2,0]
// Output: 3
// Explanation: The numbers in the range [1,2] are all in the array.

// Example 2:
// Input: nums = [3,4,-1,1]
// Output: 2
// Explanation: 1 is in the array but 2 is missing.

// Example 3:
// Input: nums = [7,8,9,11,12]
// Output: 1
// Explanation: The smallest positive integer 1 is missing.

// THIS SOLUTION VIOLATES SPACE COMPLEXITY BUT W/E

#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    printf("ENTER ARRAY SIZE. IT WILL BE FILLED WITH RANDOM NUMBERS:\n");
    if (scanf("%d", &size) != 1) {
        printf("n/a\n");
        return 1;
    }
    int arr[size];
    int arr2[size];
    for (int i = 0; i < size; ++i) {
        *(arr + i) = rand() % (size + 1 + size / 50) - 1 - size / 50;
        *(arr2 + i) = 0;
        printf("%d ", *(arr + i));
    }
    printf("\n");
    for (int i = 0; i < size; ++i) {
        if (*(arr + i) > 0 && *(arr + i) <= size) {
            *(arr2 + *(arr + i) - 1) = *(arr + i);
        }
    }
    printf("PROCESSED ARRAY:\n");
    for (int i = 0; i < size; ++i) {
        printf("%d ", *(arr2 + i));
    }
    printf("\n");
    int result = size + 1;
    for (int i = 0; i < size; ++i) {
        if (*(arr2 + i) != i + 1) {
            result = i + 1;
            break;
        }
    }
    printf("%d IS THE SMALLEST MISSING POSITIVE INTEGER\n", result);
    return 0;
}