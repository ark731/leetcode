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
    // printf("%d, %d : %d", i, j, depth);
    return depth;
}