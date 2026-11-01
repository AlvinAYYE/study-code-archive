/*
 * ==========================================================================
 * UVa 11875 - Brick Game
 * Title-CN: 積木遊戲隊長年齡 (排序數列中位數)
 * Difficulty: UVa Star 1
 * Tags: sorting, array
 * URL: https://onlinejudge.org/external/118/11875.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find age of team captain (median of N sorted player ages, where N is odd).
 *
 * [中文] 題目說明:
 *     隊伍共有奇數個隊員，年齡已依升序排序，隊長為年齡居中的隊員，求隊長年齡 (中位數)。
 *
 * [EN] Approach:
 *     Median of sorted odd-length array: ages[N / 2].
 * [中文] 思路:
 *     已排序奇數長度陣列的中位數直接取索引下標 N / 2。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva11875(int n, const int *ages) {
    return ages[n / 2];
}

int main(void) {

    int a[5] = {19, 20, 21, 22, 23};
    int ok = (solve_uva11875(5, a) == 21);
    printf("%s: UVa 11875 - Brick Game\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
