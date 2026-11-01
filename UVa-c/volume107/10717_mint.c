/*
 * ==========================================================================
 * UVa 10717 - Mint
 * Title-CN: 造幣廠桌腳墊片 (4幣LCM倍數逼近)
 * Difficulty: Medium
 * Tags: Math, Number Theory, LCM
 * URL: https://onlinejudge.org/external/107/10717.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given coin thicknesses, choose 4 coins and find table leg heights achievable by stacking 4 coins (multiples of LCM(c1,c2,c3,c4)) closest below and above target height T.
 *
 * [中文] 題目說明:
 *     給定硬幣厚度，選取 4 種硬幣求其厚度最小公倍數的整數倍，最接近目標桌腳高度 T 的不超過與不低於高度值。
 *
 * [EN] Approach:
 *     Generate all C(n, 4) combinations of 4 coins. Compute L = lcm(c1, c2, c3, c4). Update best_below = max(L * (T / L)) and best_above = min(L * ceil(T / L)).
 * [中文] 思路:
 *     枚舉所有 4 枚硬幣組合求 LCM，用 T / L 逼近不高於 T 的最大倍數，(T + L - 1) / L 逼近不低於 T 的最小倍數。
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

long long gcd_mint(long long a, long long b) { return b == 0 ? a : gcd_mint(b, a % b); }
long long lcm_mint(long long a, long long b) { return (a / gcd_mint(a, b)) * b; }

void leg_height_bounds(long long t, long long c1, long long c2, long long c3, long long c4, long long *below, long long *above) {
    long long L = lcm_mint(lcm_mint(c1, c2), lcm_mint(c3, c4));
    *below = (t / L) * L;
    *above = ((t + L - 1) / L) * L;
}

int main(void) {

    long long b, a;
    leg_height_bounds(50, 2, 3, 4, 5, &b, &a); // lcm(2,3,4,5) = 60 -> below 0, above 60
    int ok = (b == 0 && a == 60);
    printf("%s: UVa 10717 - Mint\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
