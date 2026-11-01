/*
 * ==========================================================================
 * UVa 11549 - Calculator Conundrum
 * Title-CN: 計算機難題 (平方取中法與Floyd判圈)
 * Difficulty: Medium
 * Tags: Floyd Cycle, Simulation, Math
 * URL: https://onlinejudge.org/external/115/11549.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Simulate repeated squaring and keeping first n digits on an n-digit calculator. Find the maximum value that appears before looping.
 *
 * [中文] 題目說明:
 *     在 n 位數計算機上重複執行「平方並保留前 n 位數」，求進入循環前出現過的最大數值。
 *
 * [EN] Approach:
 *     Floyd's cycle detection algorithm (tortoise and hare). Track global maximum value encountered along the trajectory.
 * [中文] 思路:
 *     以 Floyd 判圈演算法（快慢指針）檢測偽隨機數循環，沿途更新並記錄軌跡上出現過的最大數字。
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

long long next_calc_state(int n, long long k) {
    long long sq = k * k;
    char buf[30];
    sprintf(buf, "%lld", sq);
    buf[n] = '\0';
    return atoll(buf);
}
long long max_calc_cycle(int n, long long k) {
    long long slow = k, fast = k, max_v = k;
    do {
        slow = next_calc_state(n, slow);
        if (slow > max_v) max_v = slow;
        fast = next_calc_state(n, next_calc_state(n, fast));
        if (fast > max_v) max_v = fast;
    } while (slow != fast);
    return max_v;
}

int main(void) {

    long long mx = max_calc_cycle(1, 6); // 6^2 = 36 -> 3; 3^2 = 9 -> 9; 9^2 = 81 -> 8 -> ...
    int ok = (mx == 9);
    printf("%s: UVa 11549 - Calculator Conundrum\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
