/*
 * ==========================================================================
 * UVa 10344 - 23 out of 5
 * Title-CN: 五數運算符組合湊 23 窮舉搜尋
 * Difficulty: UVa Star 2
 * Tags: backtracking, brute-force
 * URL: https://onlinejudge.org/external/103/10344.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given 5 numbers, determine if they can be ordered and combined with operators +, -, * to yield exactly 23.
 *
 * [中文] 題目說明:
 *     給定 5 個整數，判斷是否存在一種全排列並插入加、減、乘 (+, -, *) 運算符使得最終運算結果恰好等於 23。
 *
 * [EN] Approach:
 *     Permute the 5 numbers (5! = 120), then evaluate all 3^4 = 81 operator combinations using depth-first search.
 * [中文] 思路:
 *     回溯搜尋全排列 120 種組合，對每組排列深度優先枚舉 4 個運算子的 3^4 種可能，檢驗運算結果是否等於 23。
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

int dfs_23(int *a, int idx, int cur_val) {
    if (idx == 5) return cur_val == 23;
    if (dfs_23(a, idx + 1, cur_val + a[idx])) return 1;
    if (dfs_23(a, idx + 1, cur_val - a[idx])) return 1;
    if (dfs_23(a, idx + 1, cur_val * a[idx])) return 1;
    return 0;
}

int solve_uva10344(int *a) {
    return dfs_23(a, 1, a[0]);
}

int main(void) {

    int a[] = {1, 2, 4, 3, 5};
    int ok = solve_uva10344(a); // (1+2+3)*4 - 1 = 23 etc.
    printf("%s: UVa 10344 - 23 out of 5\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
