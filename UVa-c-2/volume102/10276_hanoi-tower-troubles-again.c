/*
 * ==========================================================================
 * UVa 10276 - Hanoi Tower Troubles Again!
 * Title-CN: 河內之塔完全平方數插球上限
 * Difficulty: UVa Star 2
 * Tags: greedy, math
 * URL: https://onlinejudge.org/external/102/10276.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Place sequentially numbered balls 1, 2, 3... on N pegs such that adjacent balls sum to a perfect square. Find maximum balls placed.
 *
 * [中文] 題目說明:
 *     將編號 1, 2, 3... 的小球依序放置在 N 根柱子上，規定相鄰小球編號之和必須為完全平方數，求最多可放置之球數。
 *
 * [EN] Approach:
 *     Greedy simulation or closed-form formula: max_balls = (N + 1)^2 / 2 - 1.
 * [中文] 思路:
 *     貪婪模擬或數學公式：N 根柱子最多可放置球數為 (N + 1)^2 / 2 - 1。
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

int solve_uva10276(int n) {
    return (n + 1) * (n + 1) / 2 - 1;
}

int main(void) {

    int ok = (solve_uva10276(4) == 11 && solve_uva10276(1) == 1);
    printf("%s: UVa 10276 - Hanoi Tower Troubles Again!\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
