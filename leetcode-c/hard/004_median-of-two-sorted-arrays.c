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
 *     給定兩個長度分別為 m 與 n、皆依非遞減順序排列的整數陣列 nums1
 *     與 nums2，請回傳兩個陣列合併後的中位數。演算法的整體時間複雜度
 *     必須是 O(log(m+n))。
 *
 * [中文] 範例：
 *   範例 1：
 *     輸入：nums1 = [1,3], nums2 = [2]
 *     輸出：2.00000
 *     說明：合併後為 [1,2,3]，中位數是 2。
 *   範例 2：
 *     輸入：nums1 = [1,2], nums2 = [3,4]
 *     輸出：2.50000
 *     說明：合併後為 [1,2,3,4]，中位數是 (2 + 3) / 2 = 2.5。
 *
 * [中文] 限制：
 *   - nums1.length == m，nums2.length == n
 *   - 0 <= m, n <= 1000
 *   - 1 <= m + n <= 2000（兩個陣列不會同時為空）
 *   - -10^6 <= nums1[i], nums2[i] <= 10^6
 *
 * LeetCode official C stub (函式簽名):
 *   double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
 *   }
 *
 * [EN] Approach: Binary search on the cut position of the shorter array: find the split where left halves cover half the elements and maxLeft<=minRight. Time O(log min(m,n)).
 * [中文] 直觀解題思路：
 *   1. 不必真的合併陣列；只要在兩個陣列各切一刀，讓左半部恰好包含
 *      (m+n+1)/2 個元素，就能直接由切口旁的數字決定中位數。
 *   2. 固定 nums1 的切口 cutA 後，nums2 的切口 cutB 也隨之確定。
 *      為了縮小搜尋範圍，永遠在較短的陣列上二分搜尋 cutA。
 *   3. 若 nums1 左側最大值大於 nums2 右側最小值，代表 cutA 太靠右；
 *      反之若 nums2 左側最大值大於 nums1 右側最小值，cutA 太靠左。
 *   4. 當兩側都沒有交錯錯序時，分割有效。總長度為奇數時答案是左半
 *      最大值；為偶數時是「左半最大值」與「右半最小值」的平均。
 *   5. 切在陣列端點時，以 INT_MIN／INT_MAX 當虛擬邊界，避免額外分支。
 *
 * 複雜度：時間 O(log min(m,n))，額外空間 O(1)。
 * ==========================================================================
 */
#include <stdio.h>
#include <limits.h>

/* ---------- LeetCode submission / 提交區 ---------- */
static int imin(int a, int b) { return a < b ? a : b; }
static int imax(int a, int b) { return a > b ? a : b; }

double findMedianSortedArrays(int *a, int m, int *b, int n) {
    int half, lo, hi, cutA, cutB, L1, L2, R1, R2;
    /* 只在較短陣列上二分，並保證由 half 算出的 cutB 一定合法。 */
    if (m > n) return findMedianSortedArrays(b, n, a, m);
    half = (m + n + 1) / 2;
    lo = 0; hi = m;
    while (1) {
        cutA = (lo + hi) / 2;
        cutB = half - cutA;
        /* 切口在端點時，用正負無限大的概念表示「沒有元素」。 */
        L1 = (cutA == 0) ? INT_MIN : a[cutA - 1];
        R1 = (cutA == m) ? INT_MAX : a[cutA];
        L2 = (cutB == 0) ? INT_MIN : b[cutB - 1];
        R2 = (cutB == n) ? INT_MAX : b[cutB];
        if (L1 > R2) { hi = cutA - 1; }              /* a 的切口太靠右 */
        else if (L2 > R1) { lo = cutA + 1; }         /* a 的切口太靠左 */
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
