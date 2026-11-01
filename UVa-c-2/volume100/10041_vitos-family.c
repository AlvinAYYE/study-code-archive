/*
 * ==========================================================================
 * UVa 10041 - Vito's Family
 * Title-CN: 維多的家族 (中位數最佳解)
 * Difficulty: UVa Star 1 / CPE 49 顆星經典題
 * Tags: math, sorting, median
 * URL: https://onlinejudge.org/external/100/10041.pdf
 * ==========================================================================
 * [EN] Problem Statement:
 *     Vito Deadstone is moving to New York. He has a very big family there, all
 *     of them living in Lamafia Avenue. Since he will visit all his relatives
 *     frequently, he wants to find a house such that the sum of distances to
 *     all his relatives is minimal.
 *     Given the street numbers of all his relatives, find the minimal sum of
 *     distances Vito has to travel to visit each relative.
 *
 * [中文] 題目說明:
 *     維多即將搬到紐約的黑手黨大道（Lamafia Avenue）。他在那裡有很多親戚，
 *     因為他常常需要拜訪所有的親戚，因此他希望能找一間房子，使得他去拜訪每位
 *     親戚所需要走的距離總和最小。
 *     給定每位親戚居住的門牌號碼，求出維多拜訪所有親戚所需移動的最小距離總和。
 *
 * Examples:
 *   Input:
 *     2
 *     2 2 4
 *     3 2 4 6
 *   Output:
 *     2
 *     4
 *
 * Constraints:
 *   - Number of relatives r: 0 < r < 500
 *   - Street numbers s_i: 0 < s_i < 30000
 *
 * [EN] Approach:
 *     Mathematical property: the point that minimizes the sum of absolute
 *     differences (distances) on a 1D line is the median of the coordinates.
 *     Sort the street numbers and pick the middle element as Vito's house.
 *     Then sum |s[i] - median|. Time O(r log r), Space O(r).
 * [中文] 思路:
 *     一維坐標上使各點絕對距離和最小的點為「中位數（Median）」。
 *     將親戚門牌號碼排序後取中位數，計算所有親戚到中位數的距離差絕對值總和。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>

static int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int solve_uva10041(int r, int *streets) {
    qsort(streets, (size_t)r, sizeof(int), cmp);
    int median = streets[r / 2];
    int total_dist = 0;
    for (int i = 0; i < r; i++) {
        total_dist += abs(streets[i] - median);
    }
    return total_dist;
}

int main(void) {
    int test1[] = {2, 4};
    int ans1 = solve_uva10041(2, test1);

    int test2[] = {2, 4, 6};
    int ans2 = solve_uva10041(3, test2);

    int ok = (ans1 == 2) && (ans2 == 4);
    printf("%s: UVa 10041 - Vito's Family\n", ok ? "PASS" : "FAIL");

    /*
     * For UVa Online Judge submission / UVa 送出模式：
     *
     * int t;
     * if (scanf("%d", &t) == 1) {
     *     while (t--) {
     *         int r, streets[505];
     *         scanf("%d", &r);
     *         for (int i = 0; i < r; i++) scanf("%d", &streets[i]);
     *         printf("%d\n", solve_uva10041(r, streets));
     *     }
     * }
     */
    return ok ? 0 : 1;
}
