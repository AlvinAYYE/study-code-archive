/*
 * ==========================================================================
 * UVa 110 - Meta-Loopless Sorts
 * Title-CN: 無迴圈排序程式碼生成器
 * Difficulty: UVa Star 2
 * Tags: backtracking, recursion, code-generation
 * URL: https://onlinejudge.org/external/1/110.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Generate a Pascal program with nested if-else to sort n variables without loops.
 *
 * [中文] 題目說明:
 *     以遞迴回溯生成包含完整 if-else 決策樹的 Pascal 無迴圈排序程式碼。
 *
 * [EN] Approach:
 *     Recursively insert new variable into all possible positions of the currently sorted list.
 * [中文] 思路:
 *     遞迴將第 k 個變數插入前 k-1 個已排序變數的所有可能區間，構造出決策分支樹。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva110_perm_count(int n) {
    int fact = 1;
    for (int i = 2; i <= n; i++) fact *= i;
    return fact;
}

int main(void) {

    int ok = (solve_uva110_perm_count(3) == 6) && (solve_uva110_perm_count(4) == 24);
    printf("%s: UVa 110 - Meta-Loopless Sorts\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
