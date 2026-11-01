/*
 * ==========================================================================
 * UVa 371 - Ackermann Functions
 * Title-CN: 考拉茲序列極大值點
 * Difficulty: UVa Star 1
 * Tags: simulation, math, collatz
 * URL: https://onlinejudge.org/external/3/371.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find integer in range [L, H] that produces the longest Collatz sequence (where f(1) continues to 4-2-1, len >= 3).
 *
 * [中文] 題目說明:
 *     尋找區間 [L, H] 內產生最長 3n+1 序列長度的整數 (注意 n=1 時依題目定義長度為 3)。
 *
 * [EN] Approach:
 *     Collatz sequence simulation. Note special case: n=1 performs 1 step to 4, taking 3 steps to return to 1.
 * [中文] 思路:
 *     模擬 3n+1 運算流程。注意此題特別規定輸入為 1 時須執行一步變成 4 再回到 1 (長度為 3)。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long long collatz_len_371(long long n) {
    long long len = 0;
    do {
        if (n % 2 == 1) n = 3 * n + 1;
        else n /= 2;
        len++;
    } while (n != 1);
    return len;
}

void solve_uva371(long long L, long long H, long long *best_num, long long *max_len) {
    if (L > H) { long long t = L; L = H; H = t; }
    *best_num = L;
    *max_len = 0;
    for (long long x = L; x <= H; x++) {
        long long clen = collatz_len_371(x);
        if (clen > *max_len) {
            *max_len = clen;
            *best_num = x;
        }
    }
}

int main(void) {

    long long bnum, mlen;
    solve_uva371(1, 20, &bnum, &mlen);
    int ok = (bnum == 18 && mlen == 20);
    printf("%s: UVa 371 - Ackermann Functions\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
