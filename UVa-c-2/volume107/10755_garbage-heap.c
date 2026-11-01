/*
 * ==========================================================================
 * UVa 10755 - Garbage Heap
 * Title-CN: 三維最大子長方體和
 * Difficulty: Medium
 * Tags: DP, 3D Maximum Subarray
 * URL: https://onlinejudge.org/external/107/10755.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the maximum sub-block sum in an A x B x C 3D array of integers.
 *
 * [中文] 題目說明:
 *     在 A x B x C 的三維整數矩陣中，尋找元素之和最大的子長方體。
 *
 * [EN] Approach:
 *     Fix 2D bounds for dimensions 1 and 2, compress to 1D along dimension 3, and apply Kadane's algorithm in O(A^2 * B^2 * C).
 * [中文] 思路:
 *     二維前綴和枚舉長寬兩維邊界，將三維問題壓縮為 1 維數列後運行 Kadane 演算法，求最大子段和。
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

long long max_3d_subsum(int A, int B, int C, long long arr[5][5][5]) {
    long long max_s = -1000000000000LL;
    for (int a1 = 0; a1 < A; a1++)
        for (int a2 = a1; a2 < A; a2++)
            for (int b1 = 0; b1 < B; b1++)
                for (int b2 = b1; b2 < B; b2++) {
                    long long cur = 0;
                    for (int c = 0; c < C; c++) {
                        long long slice = 0;
                        for (int i = a1; i <= a2; i++)
                            for (int j = b1; j <= b2; j++) slice += arr[i][j][c];
                        cur += slice;
                        if (cur > max_s) max_s = cur;
                        if (cur < 0) cur = 0;
                    }
                }
    return max_s;
}

int main(void) {

    long long a[5][5][5] = {0};
    a[0][0][0] = 5; a[0][0][1] = -2;
    int ok = (max_3d_subsum(1, 1, 2, a) == 5);
    printf("%s: UVa 10755 - Garbage Heap\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
