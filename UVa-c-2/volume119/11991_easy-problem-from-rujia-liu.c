/*
 * ==========================================================================
 * UVa 11991 - Easy Problem from Rujia Liu?
 * Title-CN: 特定數值第 K 次出現位置查詢
 * Difficulty: UVa Star 2
 * Tags: hash, array
 * URL: https://onlinejudge.org/external/119/11991.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given an array of integers, answer queries asking for the 1-based index of the k-th occurrence of value v.
 *
 * [中文] 題目說明:
 *     給定一個整數陣列，多次查詢數值 v 在陣列中第 k 次出現時的下標位置 (從 1 開始計數)。
 *
 * [EN] Approach:
 *     Store indices of occurrences for each value in dynamic lists or query via direct scanning.
 * [中文] 思路:
 *     對每個出現數值維護出現下標列表，若查詢之第 k 次超出總次數則回傳 0，否則回傳第 k 個下標。
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

int solve_uva11991(int n, int *arr, int k, int v) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == v) {
            cnt++;
            if (cnt == k) return i + 1;
        }
    }
    return 0;
}

int main(void) {

    int a[] = {1, 3, 2, 2, 4, 3, 2, 1};
    int ans = solve_uva11991(8, a, 3, 2); // 3rd occurrence of 2 is at index 7
    int ok = (ans == 7);
    printf("%s: UVa 11991 - Easy Problem from Rujia Liu?\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
