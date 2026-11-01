/*
 * ==========================================================================
 * UVa 440 - Eeny Meeny Moo
 * Title-CN: 點名斷電模擬 (特定城市最後淘汰)
 * Difficulty: UVa Star 1
 * Tags: simulation, josephus
 * URL: https://onlinejudge.org/external/4/440.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find smallest step m such that in Josephus elimination starting at 1, city 2 is the very last one eliminated.
 *
 * [中文] 題目說明:
 *     求最小間隔 m 使得約瑟夫環從 1 號開始斷電淘汰時，2 號城市恰好是最後一個被斷電的 (存活至最後)。
 *
 * [EN] Approach:
 *     City 1 is immediately eliminated first. Simulate Josephus on remaining n-1 cities for m = 2, 3, ... until survivor is 2.
 * [中文] 思路:
 *     1 號首先出圈，對剩下的 n-1 個城市模擬約瑟夫過程，由 m = 2 開始遞增嘗試，直到最後留下的城市為 2。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva440(int n) {
    for (int m = 2; ; m++) {
        int survivor = 0; /* 0-based index for n-1 items */
        for (int i = 2; i <= n - 1; i++) {
            survivor = (survivor + m) % i;
        }
        /* City 2 corresponds to index 0 among remaining cities [2, 3, ..., n] */
        if (survivor == 0) return m;
    }
}

int main(void) {

    int ok = (solve_uva440(3) == 2) && (solve_uva440(4) == 5);
    printf("%s: UVa 440 - Eeny Meeny Moo\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
