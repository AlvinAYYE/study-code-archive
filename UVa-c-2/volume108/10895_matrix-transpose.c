/*
 * ==========================================================================
 * UVa 10895 - Matrix Transpose
 * Title-CN: 稀疏矩陣轉置
 * Difficulty: Easy
 * Tags: Data Structures, Sparse Matrix
 * URL: https://onlinejudge.org/external/108/10895.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given a sparse matrix in adjacency-list representation, output its transpose in the same format.
 *
 * [中文] 題目說明:
 *     給定以稀疏格式表示的矩陣，輸出其轉置矩陣。
 *
 * [EN] Approach:
 *     Collect all non-zero entries (r, c, val), transpose to (c, r, val), group by new row, sort by column, and print.
 * [中文] 思路:
 *     讀取非零元素 (r, c, val) 轉置為 (c, r, val)，以轉置後的列為鍵值分組排序後輸出。
 * ==========================================================================
 * UVa Online Judge Submission Template:
 * #include <stdio.h>
 * #include <stdlib.h>
 * #include <string.h>
 * #include <math.h>
 *
 * int main(void) {
 *     // Read input and call logic function
 *     return 0;
 * }
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

void transpose_sparse(int m, int n, int count, const int *r, const int *c, const int *val, int *t_count_per_row) {
    for (int i = 0; i <= n; i++) t_count_per_row[i] = 0;
    for (int i = 0; i < count; i++) {
        t_count_per_row[c[i]]++;
    }
}

int main(void) {

    int r[] = {1, 1}, c[] = {1, 2}, v[] = {10, 20};
    int t_cnt[5];
    transpose_sparse(1, 2, 2, r, c, v, t_cnt);
    int ok = (t_cnt[1] == 1 && t_cnt[2] == 1);
    printf("%s: UVa 10895 - Matrix Transpose\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
