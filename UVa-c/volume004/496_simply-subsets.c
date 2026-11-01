/*
 * ==========================================================================
 * UVa 496 - Simply Subsets
 * Title-CN: 集合關係判定 (子集、真子集、互斥、重疊)
 * Difficulty: UVa Star 1
 * Tags: set, simulation
 * URL: https://onlinejudge.org/external/4/496.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine relationship between sets A and B: 'A equals B', 'A is a proper subset of B', 'B is proper subset', 'disjoint', or 'overlap'.
 *
 * [中文] 題目說明:
 *     判定集合 A 與 B 的五種文氏圖關係：完全相等、A為B真子集、B為A真子集、互斥不相交或部分重疊相交。
 *
 * [EN] Approach:
 *     Calculate size of intersection |A ∩ B|. Compare with |A| and |B| to determine exact set relationship.
 * [中文] 思路:
 *     統計交集大小 inter。若 inter == |A| == |B| 則相等；inter == |A| 則 A 為子集；inter == 0 則互斥，其餘為相交重疊。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva496(int sizeA, int sizeB, int inter) {
    if (inter == sizeA && inter == sizeB) return 1; /* A equals B */
    if (inter == sizeA) return 2; /* A is proper subset of B */
    if (inter == sizeB) return 3; /* B is proper subset of A */
    if (inter == 0) return 4;     /* Disjoint */
    return 5;                     /* Confused / Overlap */
}

int main(void) {

    int ok = (solve_uva496(3, 3, 3) == 1) && (solve_uva496(2, 4, 2) == 2);
    printf("%s: UVa 496 - Simply Subsets\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
