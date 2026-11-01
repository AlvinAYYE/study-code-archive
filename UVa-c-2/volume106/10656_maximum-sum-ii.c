/*
 * ==========================================================================
 * UVa 10656 - Maximum Sum (II)
 * Title-CN: 最大非負子序列貪婪過濾
 * Difficulty: UVa Star 1
 * Tags: greedy
 * URL: https://onlinejudge.org/external/106/10656.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given a sequence of non-negative integers, output the subsequence of all strictly positive integers (or 0 if all are zeroes).
 *
 * [中文] 題目說明:
 *     給定一個非負整數序列，篩選並依序輸出所有大於 0 的正整數以形成最大和且最短的子序列 (全為 0 則印出單一 0)。
 *
 * [EN] Approach:
 *     Filter out zeroes. If no positive integers exist, output 0.
 * [中文] 思路:
 *     遍歷序列過濾所有 0，保留所有 > 0 的元素；若結果為空則輸出單個 0。
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

int solve_uva10656(int n, int *in, int *out) {
    int out_cnt = 0;
    for (int i = 0; i < n; i++) {
        if (in[i] > 0) out[out_cnt++] = in[i];
    }
    if (out_cnt == 0) out[out_cnt++] = 0;
    return out_cnt;
}

int main(void) {

    int a[] = {0, 3, 0, 5};
    int res[10];
    int cnt = solve_uva10656(4, a, res);
    int ok = (cnt == 2 && res[0] == 3 && res[1] == 5);
    printf("%s: UVa 10656 - Maximum Sum (II)\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
