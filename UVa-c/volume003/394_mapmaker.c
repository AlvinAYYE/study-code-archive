/*
 * ==========================================================================
 * UVa 394 - Mapmaker
 * Title-CN: 地圖製作者 (數組定址計算)
 * Difficulty: Medium
 * Tags: Data Structures, Array Addressing
 * URL: https://onlinejudge.org/external/3/394.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Compute memory address of multi-dimensional array elements given base address, element size, and dimension bounds.
 *
 * [中文] 題目概述:
 *     給定多維數組的起始基底位址、元素大小及各維度上下界，計算指定下標的記憶體位址。
 *
 * [EN] Approach:
 *     Use the standard row-major addressing formula: C_D = size, C_i = C_{i+1} * (U_{i+1} - L_{i+1} + 1), C_0 = B - sum(C_i * L_i). Address = C_0 + sum(C_i * i_k).
 * [中文] 解題思路:
 *     依照以列為主 (row-major) 映射公式計算常數 C_0 至 C_D，再代入下標求得記憶體位址。
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

int compute_address(int base, int elem_size, int d, const int *lower, const int *upper, const int *indices) {
    int c[15];
    c[d] = elem_size;
    for (int i = d - 1; i >= 1; i--) {
        c[i] = c[i + 1] * (upper[i] - lower[i] + 1);
    }
    int c0 = base;
    for (int i = 1; i <= d; i++) {
        c0 -= c[i] * lower[i - 1];
    }
    int addr = c0;
    for (int i = 1; i <= d; i++) {
        addr += c[i] * indices[i - 1];
    }
    return addr;
}

int main(void) {

    int lower[] = {1, 1}, upper[] = {10, 10}, idx[] = {2, 3};
    int ok = (compute_address(1000, 4, 2, lower, upper, idx) == 1048);
    printf("%s: UVa 394 - Mapmaker\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
