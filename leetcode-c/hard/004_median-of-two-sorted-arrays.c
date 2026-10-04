/*
 * ==========================================================================
 * LeetCode 004. Median of Two Sorted Arrays
 * Title-CN: 尋找兩個正序數組的中位數
 * Difficulty: Hard
 * Tags: array, binary-search, divide-and-conquer
 * URL: https://leetcode.com/problems/median-of-two-sorted-arrays/
 * ==========================================================================
 * [EN] Problem (official statement, source: github mcaupybugs/leetcode-problems-db)
 *     Given two sorted arrays nums1 and nums2 of size m and n respectively,
 *     return the median of the two sorted arrays.
 *     The overall run time complexity should be O(log (m+n)).
 *
 * [中文] 題目說明 (翻譯自官方英文題面)
 *     兩個已排序陣列，找合併後的中位數，要求 O(log(m+n))。
 *
 * Examples:
 *   Example 1:
 *     Input: nums1 = [1,3], nums2 = [2]
 *     Output: 2.00000
 *     Explanation: merged array = [1,2,3] and median is 2.
 *   Example 2:
 *     Input: nums1 = [1,2], nums2 = [3,4]
 *     Output: 2.50000
 *     Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 =
 *     2.5.
 *
 * Constraints:
 *   - nums1.length == m
 *   - nums2.length == n
 *   - 0 <= m <= 1000
 *   - 0 <= n <= 1000
 *   - 1 <= m + n <= 2000
 *   - -10^6 <= nums1[i], nums2[i] <= 10^6
 *
 * LeetCode official C stub (函式簽名):
 *   double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
 *   }
 *
 * [EN] Approach: Binary search on the cut position of the shorter array: find the split where left halves cover half the elements and maxLeft<=minRight. Time O(log min(m,n)).
 * [中文] 思路: 對較短陣列的切分位置做二分搜：左半共佔 (m+n+1)/2 個元素且 maxLeft<=minRight 時取中位數。時間 O(log min(m,n))。
 * ==========================================================================
 */
#include <stdio.h>
#include <limits.h>

/* ---------- LeetCode submission / 提交區 ---------- */
static int imin(int a, int b) { return a < b ? a : b; }
static int imax(int a, int b) { return a > b ? a : b; }

double findMedianSortedArrays(int *a, int m, int *b, int n) {
    int half, lo, hi, cutA, cutB, L1, L2, R1, R2;
    if (m > n) return findMedianSortedArrays(b, n, a, m);   /* cut the shorter one */
    half = (m + n + 1) / 2;
    lo = 0; hi = m;
    while (1) {
        cutA = (lo + hi) / 2;
        cutB = half - cutA;
        L1 = (cutA == 0) ? INT_MIN : a[cutA - 1];
        R1 = (cutA == m) ? INT_MAX : a[cutA];
        L2 = (cutB == 0) ? INT_MIN : b[cutB - 1];
        R2 = (cutB == n) ? INT_MAX : b[cutB];
        if (L1 > R2) { hi = cutA - 1; }              /* too many from a */
        else if (L2 > R1) { lo = cutA + 1; }         /* too few from a */
        else {
            int leftMax = imax(L1, L2);
            if ((m + n) % 2 == 1) return (double)leftMax;
            return ((double)leftMax + (double)imin(R1, R2)) / 2.0;
        }
    }
}
/* ---------- end submission ---------- */

static int feq(double a, double b) { return a > b - 1e-9 && a < b + 1e-9; }

int main(void) {
    int ok = 1;
    int a1[] = {1, 3}, b1[] = {2};
    int a2[] = {1, 2}, b2[] = {3, 4};
    int b3[] = {1};
    int a4[] = {0, 0}, b4[] = {0, 0};
    ok = ok && feq(findMedianSortedArrays(a1, 2, b1, 1), 2.0);
    ok = ok && feq(findMedianSortedArrays(a2, 2, b2, 2), 2.5);
    ok = ok && feq(findMedianSortedArrays(NULL, 0, b3, 1), 1.0);
    ok = ok && feq(findMedianSortedArrays(a4, 2, b4, 2), 0.0);
    printf("%s: 004 median-of-two-sorted-arrays\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
