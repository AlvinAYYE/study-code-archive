/*
 * ==========================================================================
 * UVa 846 - Steps
 * Title-CN: 步數跨度最小化 (兩端遞增遞減步長)
 * Difficulty: UVa Star 1
 * Tags: math, greedy
 * URL: https://onlinejudge.org/external/8/846.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find minimum number of steps to travel distance diff, where step length changes by at most 1 and first/last steps are 1.
 *
 * [中文] 題目說明:
 *     從座標 x 走到 y，相鄰步長變化量最多為 1，首步與尾步長度皆必須為 1，求最少總步數。
 *
 * [EN] Approach:
 *     Pair identical step lengths: 1, 1, 2, 2, 3, 3... Count how many terms are needed to reach or exceed diff.
 * [中文] 思路:
 *     最佳策略為由兩側向中間對稱增大：步長為 1, 1, 2, 2, 3, 3... 累加步長總和直到達到或超過目標距離 diff。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva846(int x, int y) {
    int diff = (y > x) ? (y - x) : (x - y);
    if (diff == 0) return 0;
    int steps = 0, step_len = 1;
    while (diff > 0) {
        diff -= step_len;
        steps++;
        if (diff <= 0) break;
        diff -= step_len;
        steps++;
        step_len++;
    }
    return steps;
}

int main(void) {

    int ok = (solve_uva846(45, 48) == 3) && (solve_uva846(45, 49) == 3) && (solve_uva846(45, 50) == 4);
    printf("%s: UVa 846 - Steps\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
