/*
 * ==========================================================================
 * UVa 1121 - Subsequence
 * Title-CN: 連續子數組最小長度
 * Difficulty: Medium
 * Tags: Two Pointers, Sliding Window
 * URL: https://onlinejudge.org/external/11/1121.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the minimal length of a contiguous subarray of positive integers whose sum is greater than or equal to S.
 *
 * [中文] 題目說明:
 *     求和不小於 S 的連續正整數子數組的最短長度。
 *
 * [EN] Approach:
 *     Two pointers (sliding window): expand right pointer to increase sum; shrink left pointer while sum >= S.
 * [中文] 思路:
 *     雙指針滑動窗口：右指針向右擴展累計和，當總和 >= S 時嘗試向右收縮左指針以尋找最小窗口長度。
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

int min_subsequence_len(int n, int s, const int *a) {
    int l = 0, sum = 0, min_len = n + 1;
    for (int r = 0; r < n; r++) {
        sum += a[r];
        while (sum >= s) {
            if (r - l + 1 < min_len) min_len = r - l + 1;
            sum -= a[l++];
        }
    }
    return min_len == n + 1 ? 0 : min_len;
}

int main(void) {

    int a[] = {5, 1, 3, 5, 10, 7, 4, 9, 2, 8};
    int res = min_subsequence_len(10, 15, a);
    int ok = (res == 2); // e.g. [10, 7] or [7, 9]
    printf("%s: UVa 1121 - Subsequence\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
