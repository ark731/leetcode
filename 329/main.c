// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

// Given an m x n integers matrix, return the length of the longest increasing path in matrix.

// From each cell, you can either move in four directions: left, right, up, or down.
// You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

// Example 1:
// Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
// Output: 4
// Explanation: The longest increasing path is [1, 2, 6, 9].

// Example 2:
// Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
// Output: 4
// Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

// Example 3:
// Input: matrix = [[1]]
// Output: 1

#include <stdio.h>

int dive_in(int rows, int cols, int (*matrix)[cols], int i, int j, int depth);

int main() {
    int rows, cols;
    if (scanf("%d %d", &rows, &cols) != 2 || rows < 1 || cols < 1) {
        printf("n/a");
        return 1;
    }
    int matrix[rows][cols];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("n/a");
                return 1;
            }
        }
    }
    int max_depth = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int tmp = dive_in(rows, cols, matrix, i, j, 0);
            if (tmp > max_depth) {
                max_depth = tmp;
            }
        }
    }
    printf("%d\n", max_depth);
    return 0;
}

int dive_in(int rows, int cols, int (*matrix)[cols], int i, int j, int depth) {
    int tmp_u, tmp_d, tmp_l, tmp_r;
    tmp_u = tmp_d = tmp_l = tmp_r = 0;
    ++depth;
    if (i > 0 && matrix[i - 1][j] > matrix[i][j]) {
        tmp_u = dive_in(rows, cols, matrix, i - 1, j, depth);
    }
    if (j > 0 && matrix[i][j - 1] > matrix[i][j]) {
        tmp_l = dive_in(rows, cols, matrix, i, j - 1, depth);
    }
    if (j < (cols - 1) && matrix[i][j + 1] > matrix[i][j]) {
        tmp_r = dive_in(rows, cols, matrix, i, j + 1, depth);
    }
    if (i < (rows - 1) && matrix[i + 1][j] > matrix[i][j]) {
        tmp_d = dive_in(rows, cols, matrix, i + 1, j, depth);
    }
    if (tmp_l > depth) {
        depth = tmp_l;
    }
    if (tmp_r > depth) {
        depth = tmp_r;
    }
    if (tmp_u > depth) {
        depth = tmp_u;
    }
    if (tmp_d > depth) {
        depth = tmp_d;
    }
    return depth;
}