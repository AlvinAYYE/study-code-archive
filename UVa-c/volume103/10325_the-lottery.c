/*
 * ==========================================================================
 * UVa 10325 - The Lottery
 * Title-CN: 彩票 (容斥原理未整除計數)
 * Difficulty: Medium
 * Tags: Math, Inclusion-Exclusion, LCM
 * URL: https://onlinejudge.org/external/103/10325.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count numbers in 1..N that are not divisible by any of M given integers.
 *
 * [中文] 題目說明:
 *     計算 1 到 N 之間不能被給定 M 個整數中任何一個整除的數字數量。
 *
 * [EN] Approach:
 *     Inclusion-Exclusion Principle over subsets of size 1 to M: subtract single multiples, add pairwise LCM multiples, etc.
 * [中文] 思路:
 *     利用排容原理：枚舉 2^M 種子集狀態，奇數個數的 LCM 倍數減去，偶數個數的 LCM 倍數加上。
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

long long gcd_lot(long long a, long long b) { return b == 0 ? a : gcd_lot(b, a % b); }
long long lcm_lot(long long a, long long b) { return (a / gcd_lot(a, b)) * b; }

long long count_not_divisible(long long n, int m, const long long *a) {
    long long div_count = 0;
    for (int mask = 1; mask < (1 << m); mask++) {
        long long cur_lcm = 1;
        int bits = 0;
        bool overflow = false;
        for (int i = 0; i < m; i++) {
            if ((mask >> i) & 1) {
                bits++;
                cur_lcm = lcm_lot(cur_lcm, a[i]);
                if (cur_lcm > n) { overflow = true; break; }
            }
        }
        if (overflow) continue;
        long long cnt = n / cur_lcm;
        if (bits % 2 == 1) div_count += cnt;
        else div_count -= cnt;
    }
    return n - div_count;
}

int main(void) {

    long long a[] = {2, 3};
    long long res = count_not_divisible(10, 2, a); // 1..10 not div by 2 or 3: 1, 5, 7 -> 3 numbers
    int ok = (res == 3);
    printf("%s: UVa 10325 - The Lottery\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
