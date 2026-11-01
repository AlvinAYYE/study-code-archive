/*
 * ==========================================================================
 * UVa 10591 - Happy Number
 * Title-CN: 快樂數判定 (數位平方和循環檢測)
 * Difficulty: UVa Star 1
 * Tags: math, simulation
 * URL: https://onlinejudge.org/external/105/10591.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine if a number is Happy (repeatedly summing squares of its digits terminates at 1).
 *
 * [中文] 題目說明:
 *     判定整數是否為快樂數：將各位數的平方相加形成新數，若最終收斂至 1 則為快樂數，陷入死循環則為不快樂數。
 *
 * [EN] Approach:
 *     Simulate sum of squared digits. Cycle detection via visited array or Floyd tortoise and hare.
 * [中文] 思路:
 *     反覆計算各數位平方和，以陣列標記造訪過的中間數值以檢測是否陷入循環，若抵達 1 則回傳為快樂數。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int next_happy_step(int n) {
    int s = 0;
    while (n) { int d = n % 10; s += d * d; n /= 10; }
    return s;
}

int solve_uva10591(int n) {
    int visited[1000] = {0};
    while (n != 1 && n != 4) {
        if (n < 1000) {
            if (visited[n]) return 0;
            visited[n] = 1;
        }
        n = next_happy_step(n);
    }
    return n == 1;
}

int main(void) {

    int ok = solve_uva10591(7) && !solve_uva10591(4);
    printf("%s: UVa 10591 - Happy Number\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
