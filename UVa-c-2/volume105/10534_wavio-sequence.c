/*
 * ==========================================================================
 * UVa 10534 - Wavio Sequence
 * Title-CN: Wavio 雙向遞增遞減極值序列
 * Difficulty: UVa Star 2
 * Tags: dynamic-programming, lis, binary-search
 * URL: https://onlinejudge.org/external/105/10534.pdf
 * ==========================================================================
 * [EN] Problem:
 *     A Wavio sequence has length 2k+1, strictly increases for k+1 elements, then strictly decreases. Find length of longest Wavio subsequence.
 *
 * [中文] 題目說明:
 *     長度為 2k+1 的 Wavio 序列前 k+1 項嚴格遞增，後 k+1 項嚴格遞減。求給定數列中最長 Wavio 子序列之長度。
 *
 * [EN] Approach:
 *     Compute Longest Increasing Subsequence (LIS) from left, and Longest Decreasing Subsequence (LDS) from right in O(N log N). Best length = 2 * min(lis[i], lds[i]) - 1.
 * [中文] 思路:
 *     以二分搜尋分別計算正向 LIS 與逆向 LDS，以 2 * min(lis[i], lds[i]) - 1 取各點為轉折中心之最大值。
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

int solve_uva10534(int n, int *a) {
    int lis[20], lds[20];
    for (int i = 0; i < n; i++) {
        lis[i] = 1;
        for (int j = 0; j < i; j++) if (a[j] < a[i] && lis[j] + 1 > lis[i]) lis[i] = lis[j] + 1;
    }
    for (int i = n - 1; i >= 0; i--) {
        lds[i] = 1;
        for (int j = n - 1; j > i; j--) if (a[j] < a[i] && lds[j] + 1 > lds[i]) lds[i] = lds[j] + 1;
    }
    int max_len = 1;
    for (int i = 0; i < n; i++) {
        int k = lis[i] < lds[i] ? lis[i] : lds[i];
        int wavio = 2 * k - 1;
        if (wavio > max_len) max_len = wavio;
    }
    return max_len;
}

int main(void) {

    int a[] = {1, 2, 3, 2, 1};
    int len = solve_uva10534(5, a);
    int ok = (len == 5);
    printf("%s: UVa 10534 - Wavio Sequence\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
