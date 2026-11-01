/*
 * ==========================================================================
 * UVa 11621 - Small Numbers
 * Title-CN: 小數 (僅含質因數 2 與 3 的最小不小於 m 之數)
 * Difficulty: Easy
 * Tags: Math, Number Theory, Binary Search
 * URL: https://onlinejudge.org/external/116/11621.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the smallest number of the form 2^i * 3^j that is greater than or equal to m.
 *
 * [中文] 題目描述:
 *     求所有僅含質因數 2 與 3 的整數（形如 2^i * 3^j）中，大於等於給定正整數 m 的最小值。
 *
 * [EN] Approach:
 *     Precompute all valid products 2^i * 3^j up to 2^31, sort, and binary search upper_bound/lower_bound.
 *
 * [中文] 解題思維:
 *     預先計算所有小於 2^31 的 2^i * 3^j 數值並排序，二分搜尋大於等於 m 的首個數值。
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

static long long small_nums_arr[1005];
static int small_nums_len = 0;

static int cmp_ll11621(const void *a, const void *b) {
    long long va = *(const long long *)a, vb = *(const long long *)b;
    return (va < vb) ? -1 : (va > vb ? 1 : 0);
}

long long find_small_number(long long m) {
    if (small_nums_len == 0) {
        long long p2 = 1;
        for (int i = 0; i <= 31; i++) {
            long long p3 = 1;
            for (int j = 0; j <= 20; j++) {
                if (p2 * p3 > 0 && p2 * p3 <= 3000000000LL) {
                    small_nums_arr[small_nums_len++] = p2 * p3;
                }
                if (p3 > 3000000000LL / 3) break;
                p3 *= 3;
            }
            if (p2 > 3000000000LL / 2) break;
            p2 *= 2;
        }
        qsort(small_nums_arr, small_nums_len, sizeof(long long), cmp_ll11621);
    }
    int low = 0, high = small_nums_len - 1, ans = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (small_nums_arr[mid] >= m) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return small_nums_arr[ans];
}

int main(void) {

    int ok = (find_small_number(1) == 1) &&
             (find_small_number(5) == 6) &&
             (find_small_number(7) == 8);
    printf("%s: UVa 11621 - Small Numbers\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
