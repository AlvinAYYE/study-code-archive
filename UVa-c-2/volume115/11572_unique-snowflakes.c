/*
 * ==========================================================================
 * UVa 11572 - Unique Snowflakes
 * Title-CN: 最長相異雪花連續序列
 * Difficulty: UVa Star 2
 * Tags: two-pointers, hash
 * URL: https://onlinejudge.org/external/115/11572.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the length of the longest contiguous subsegment of snowflakes with all unique IDs.
 *
 * [中文] 題目說明:
 *     給定一連串雪花編號序列，找出其中不包含任意重複編號雪花的最長連續子區間長度。
 *
 * [EN] Approach:
 *     Sliding window / two pointers with a hash table tracking the last seen index of each snowflake ID.
 * [中文] 思路:
 *     滑動視窗雙指針法：以雜湊表記錄每個雪花編號上次出現的位置，左指針動態跳躍收縮視窗，時間複雜度 O(N)。
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

int solve_uva11572(int n, int *arr) {
    int max_len = 0, left = 0;
    // Map with basic linear probing or O(N^2) small window check
    for (int right = 0; right < n; right++) {
        for (int k = left; k < right; k++) {
            if (arr[k] == arr[right]) {
                left = k + 1;
                break;
            }
        }
        int cur_len = right - left + 1;
        if (cur_len > max_len) max_len = cur_len;
    }
    return max_len;
}

int main(void) {

    int a[] = {1, 2, 3, 2, 4};
    int ans = solve_uva11572(5, a);
    int ok = (ans == 3); // {2, 3, 4} or {1, 2, 3}
    printf("%s: UVa 11572 - Unique Snowflakes\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
