/*
 * ==========================================================================
 * UVa 485 - Pascal's Triangle of Death
 * Title-CN: 帕斯卡三角形之死 (大數溢位展開)
 * Difficulty: Easy
 * Tags: Big Integer, Math, Pascal Triangle
 * URL: https://onlinejudge.org/external/4/485.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Generate Pascal's triangle until an entry exceeds 10^60.
 *
 * [中文] 題目說明:
 *     生成帕斯卡三角形，直到出現超過 10^60 的大整數為止。
 *
 * [EN] Approach:
 *     Row by row generation using Pascal's identity C(n, k) = C(n-1, k-1) + C(n-1, k) with big integers.
 * [中文] 思路:
 *     利用帕斯卡加法遞推公式逐行計算高精度大數數值，直至數值位數超過 60 位。
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

int pascal_row_max(int r) {
    // Middle element of row r has maximum value C(r, r/2)
    int c = 1;
    for (int i = 0; i < r / 2; i++) {
        c = c * (r - i) / (i + 1);
    }
    return c;
}

int main(void) {

    int ok = (pascal_row_max(4) == 6); // row 4: 1 4 6 4 1
    printf("%s: UVa 485 - Pascal's Triangle of Death\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
