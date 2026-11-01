/*
 * ==========================================================================
 * UVa 10718 - Bit Mask
 * Title-CN: 位元遮罩貪心構造
 * Difficulty: Medium
 * Tags: Greedy, Bit Manipulation
 * URL: https://onlinejudge.org/external/107/10718.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given N, L, U, find M in range [L, U] such that (N OR M) is maximized, breaking ties by choosing smallest M.
 *
 * [中文] 題目說明:
 *     給定 N, L, U，在 [L, U] 區間內構造 M 使得 N OR M 最大，若有多個使 M 最小。
 *
 * [EN] Approach:
 *     Bitwise greedy from bit 31 down to 0: if N has bit 0, set bit in M if M + bit <= U. If N has bit 1, set bit in M only if required so M stays >= L.
 * [中文] 思路:
 *     由最高位 31 向 0 貪心決策：若 N 的該位為 0，則在不超過 U 的前提下盡量置 1；若 N 該位為 1，則僅在防止 M 跌破 L 時才置 1。
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

unsigned int solve_bit_mask(unsigned int n, unsigned int l, unsigned int u) {
    unsigned int m = 0;
    for (int i = 31; i >= 0; i--) {
        unsigned int bit = 1U << i;
        if ((n & bit) == 0) {
            if ((m | bit) <= u) m |= bit;
        } else {
            if ((m | (bit - 1)) < l) m |= bit;
        }
    }
    return m;
}

int main(void) {

    unsigned int m = solve_bit_mask(100, 50, 60);
    int ok = (m >= 50 && m <= 60);
    printf("%s: UVa 10718 - Bit Mask\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
