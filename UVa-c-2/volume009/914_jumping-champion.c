/*
 * ==========================================================================
 * UVa 914 - Jumping Champion
 * Title-CN: 跳躍冠軍 (相鄰質數差眾數)
 * Difficulty: Easy
 * Tags: Math, Prime, Sieve, Frequency
 * URL: https://onlinejudge.org/external/9/914.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the most frequent difference between adjacent primes in range [L, U]. If a tie exists, there is no jumping champion.
 *
 * [中文] 題目說明:
 *     求區間 [L, U] 內相鄰質數差值的眾數，若有並列第一則輸出無跳躍冠軍。
 *
 * [EN] Approach:
 *     Sieve primes up to U. Collect primes in [L, U], calculate consecutive differences diff = p[i+1] - p[i], count frequencies.
 * [中文] 思路:
 *     埃氏篩預處理質數，統計 [L, U] 內相鄰質數差值出現頻率，檢查最高頻率是否嚴格唯一。
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

int jumping_champ(int l, int u) {
    bool is_p[1000];
    for (int i = 0; i < 1000; i++) is_p[i] = (i >= 2);
    for (int p = 2; p * p < 1000; p++)
        if (is_p[p]) for (int i = p * p; i < 1000; i += p) is_p[i] = false;
    int primes[200], cnt = 0;
    for (int i = l; i <= u; i++) if (is_p[i]) primes[cnt++] = i;
    if (cnt < 2) return -1;
    int diff_cnt[100] = {0};
    for (int i = 0; i < cnt - 1; i++) {
        int d = primes[i+1] - primes[i];
        if (d < 100) diff_cnt[d]++;
    }
    int mx = 0, best = -1, ties = 0;
    for (int d = 1; d < 100; d++) {
        if (diff_cnt[d] > mx) { mx = diff_cnt[d]; best = d; ties = 1; }
        else if (diff_cnt[d] == mx && mx > 0) ties++;
    }
    return ties == 1 ? best : -1;
}

int main(void) {

    int champ = jumping_champ(2, 11); // primes: 2, 3, 5, 7, 11 -> diffs: 1, 2, 2, 4 -> champ is 2
    int ok = (champ == 2);
    printf("%s: UVa 914 - Jumping Champion\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
