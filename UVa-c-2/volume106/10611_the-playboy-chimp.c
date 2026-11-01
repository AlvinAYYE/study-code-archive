/*
 * ==========================================================================
 * UVa 10611 - The Playboy Chimp
 * Title-CN: 花花公子黑猩猩身高二分查找
 * Difficulty: UVa Star 1
 * Tags: binary-search
 * URL: https://onlinejudge.org/external/106/10611.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given heights of N female chimps sorted in non-decreasing order, find the tallest chimp strictly shorter than Q and shortest chimp strictly taller than Q.
 *
 * [中文] 題目說明:
 *     給定由小到大排列的 N 隻母猩猩身高，對於查詢身高 Q，找出嚴格小於 Q 的最高者與嚴格大於 Q 的最矮者。
 *
 * [EN] Approach:
 *     Binary search: find lower_bound - 1 for strictly shorter chimp, and upper_bound for strictly taller chimp.
 * [中文] 思路:
 *     利用二分搜尋查找嚴格小於 Q 的最大元素與嚴格大於 Q 的最小元素，無解時回傳 -1。
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

void solve_uva10611(int n, int *h, int q, int *shorter, int *taller) {
    *shorter = -1; *taller = -1;
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (h[mid] < q) {
            *shorter = h[mid];
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    low = 0; high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (h[mid] > q) {
            *taller = h[mid];
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
}

int main(void) {

    int a[] = {1, 4, 5, 7};
    int s, t;
    solve_uva10611(4, a, 4, &s, &t);
    int ok = (s == 1 && t == 5);
    printf("%s: UVa 10611 - The Playboy Chimp\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
