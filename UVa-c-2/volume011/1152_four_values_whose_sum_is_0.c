/*
 * ==========================================================================
 * UVa 1152 - 4 Values whose Sum is 0
 * Title-CN: 四數之和為零的元組數
 * Difficulty: Medium
 * Tags: Hash Table, Two Pointers, Binary Search
 * URL: https://onlinejudge.org/external/11/1152.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count quadruples (a, b, c, d) chosen from four lists of integers such that a + b + c + d = 0.
 *
 * [中文] 題目描述:
 *     給定四個整數列表 A, B, C, D，求有多少個四元組 (a, b, c, d) 滿足 a + b + c + d = 0。
 *
 * [EN] Approach:
 *     Compute all sums of A[i] + B[j], sort the array, and binary search count of -(C[k] + D[l]).
 *
 * [中文] 解題思維:
 *     雙向枚舉：計算 A 與 B 的所有兩兩和並排序，遍歷 C 與 D 的和並在排序陣列中二分搜尋 -(c+d) 的出現次數。
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

static int cmp_int1152(const void *a, const void *b) {
    int va = *(const int *)a, vb = *(const int *)b;
    return (va < vb) ? -1 : (va > vb ? 1 : 0);
}

int count_four_zeros(int n, int *A, int *B, int *C, int *D) {
    int *ab = (int *)malloc(sizeof(int) * n * n);
    int ab_sz = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ab[ab_sz++] = A[i] + B[j];
        }
    }
    qsort(ab, ab_sz, sizeof(int), cmp_int1152);

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int target = -(C[i] + D[j]);
            // Binary search range [low, high]
            int l = 0, r = ab_sz - 1, first = -1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (ab[mid] >= target) {
                    if (ab[mid] == target) first = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            if (first != -1) {
                l = 0; r = ab_sz - 1;
                int last = -1;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if (ab[mid] <= target) {
                        if (ab[mid] == target) last = mid;
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                count += (last - first + 1);
            }
        }
    }
    free(ab);
    return count;
}

int main(void) {

    int A[] = {-45, -41};
    int B[] = {-27, 23};
    int C[] = {42, -28};
    int D[] = {43, 46};
    // -45 + 23 + 42 - 20 ? Test with known zero pair
    int A1[] = {1}; int B1[] = {2}; int C1[] = {-1}; int D1[] = {-2};
    int res = count_four_zeros(1, A1, B1, C1, D1); // 1 + 2 - 1 - 2 = 0 -> count 1
    int ok = (res == 1);
    printf("%s: UVa 1152 - 4 Values whose Sum is 0\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
