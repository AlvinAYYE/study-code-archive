/*
 * ==========================================================================
 * UVa 11464 - Even Parity
 * Title-CN: 偶數奇偶校驗矩陣變換
 * Difficulty: Hard
 * Tags: Bitmask, Brute Force, Parity
 * URL: https://onlinejudge.org/external/114/11464.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given an N x N binary matrix, transform it by flipping only 0s to 1s with minimal flips so every cell has an even number of 1-neighbors.
 *
 * [中文] 題目描述:
 *     給定一個 N x N 二元矩陣，只能將 0 改為 1，求最少翻轉次數使得每個格子的四鄰居 1 之總數均為偶數。
 *
 * [EN] Approach:
 *     Enumerate all 2^N possible states for the first row. Subsequent rows are uniquely determined by parity requirements. Return minimum valid flips.
 *
 * [中文] 解題思維:
 *     二進制枚舉第一列所有可能的 2^N 種狀態；後續每一列皆由上一列及其左右鄰居的奇偶性唯一決定，檢查並取最小翻轉數。
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

int min_flips_even_parity(int n, int orig[15][15]) {
    int ans = 1000000;
    int cur[15][15];

    for (int mask = 0; mask < (1 << n); mask++) {
        int valid = 1, flips = 0;
        for (int c = 0; c < n; c++) {
            cur[0][c] = (mask >> c) & 1;
            if (orig[0][c] == 1 && cur[0][c] == 0) { valid = 0; break; }
            if (orig[0][c] == 0 && cur[0][c] == 1) flips++;
        }
        if (!valid) continue;

        for (int r = 1; r < n; r++) {
            for (int c = 0; c < n; c++) {
                int sum = 0;
                if (r - 2 >= 0) sum += cur[r - 2][c];
                if (c - 1 >= 0) sum += cur[r - 1][c - 1];
                if (c + 1 < n)  sum += cur[r - 1][c + 1];
                cur[r][c] = sum % 2;
                if (orig[r][c] == 1 && cur[r][c] == 0) { valid = 0; break; }
                if (orig[r][c] == 0 && cur[r][c] == 1) flips++;
            }
            if (!valid) break;
        }
        if (!valid) continue;

        // Check last row parity
        for (int c = 0; c < n; c++) {
            int sum = 0;
            if (n - 2 >= 0) sum += cur[n - 2][c];
            if (c - 1 >= 0) sum += cur[n - 1][c - 1];
            if (c + 1 < n)  sum += cur[n - 1][c + 1];
            if (sum % 2 != 0) { valid = 0; break; }
        }
        if (valid && flips < ans) ans = flips;
    }
    return ans == 1000000 ? -1 : ans;
}

int main(void) {

    int g[15][15] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int ok = (min_flips_even_parity(3, g) == 0); // all zeros is already even
    printf("%s: UVa 11464 - Even Parity\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
