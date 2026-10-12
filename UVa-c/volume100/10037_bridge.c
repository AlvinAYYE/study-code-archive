/*
 * ==========================================================================
 * UVa 10037 - Bridge
 * Title-CN: 過橋問題
 * Difficulty: UVa Star 2
 * Tags: greedy, math
 * URL: https://onlinejudge.org/external/100/10037.pdf
 * ==========================================================================
 * [EN] Problem:
 *     N people must cross a bridge at night with one flashlight. At most 2 can cross together.
 *     Find minimum total crossing time.
 *
 * [中文] 題目說明:
 *     N 個人夜間過橋，求所有人過橋所需之最小時間與策略步驟。
 *
 * [EN] Approach:
 *     Sort speeds. For largest two people (Z, Y):
 *     Strategy 1: Fast A escorts Y and Z individually -> A + 2*B? No: 2*A + Y + Z.
 *     Strategy 2: Fast A and B cross, A returns, Y and Z cross, B returns -> A + 2*B + Z.
 *     Compare min(2*A + Y + Z, A + 2*B + Z).
 * [中文] 思路:
 *     速度排序後，針對最慢的兩人，在「最快者個別護送」與「兩最快者先過、兩最慢者同行」中取較小者。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>

static int cmp_int(const void *a, const void *b) {
    return (*(const int *)a - *(const int *)b);
}

static inline int min_val(int a, int b) { return a < b ? a : b; }

int solve_uva10037(int n, int *t) {
    qsort(t, (size_t)n, sizeof(int), cmp_int);
    int total = 0;
    while (n > 3) {
        int opt1 = t[0] + 2 * t[1] + t[n - 1];
        int opt2 = 2 * t[0] + t[n - 2] + t[n - 1];
        total += min_val(opt1, opt2);
        n -= 2;
    }
    if (n == 3) total += t[0] + t[1] + t[2];
    else if (n == 2) total += t[1];
    else if (n == 1) total += t[0];
    return total;
}

int main(void) {
    int t[4] = {1, 2, 5, 10};
    int res = solve_uva10037(4, t);
    int ok = (res == 17);
    printf("%s: UVa 10037 - Bridge\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
