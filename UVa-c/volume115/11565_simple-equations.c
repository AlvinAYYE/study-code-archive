/*
 * ==========================================================================
 * UVa 11565 - Simple Equations
 * Title-CN: 三元二次方程整數解窮舉搜尋
 * Difficulty: UVa Star 2
 * Tags: brute-force, math
 * URL: https://onlinejudge.org/external/115/11565.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find distinct integers x < y < z satisfying x + y + z = A, x*y*z = B, and x^2 + y^2 + z^2 = C.
 *
 * [中文] 題目說明:
 *     尋找相異整數解 x < y < z 滿足聯立方程：x + y + z = A、xyz = B 與 x^2 + y^2 + z^2 = C。
 *
 * [EN] Approach:
 *     Enumerate x in [-100, 100] and y in [x+1, 100]. Then z = A - x - y. Verify xyz == B and sum of squares == C.
 * [中文] 思路:
 *     由於 x^2 <= C 且 C <= 10000，x 與 y 的範圍在 [-100, 100] 內，雙重迴圈枚舉 x 與 y，計算 z 並驗證其餘兩等式。
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

int solve_uva11565(int A, int B, int C, int *ox, int *oy, int *oz) {
    for (int x = -100; x <= 100; x++) {
        if (x * x > C) continue;
        for (int y = x + 1; y <= 100; y++) {
            if (x * x + y * y > C) continue;
            int z = A - x - y;
            if (z > y && (x * y * z == B) && (x * x + y * y + z * z == C)) {
                *ox = x; *oy = y; *oz = z;
                return 1;
            }
        }
    }
    return 0;
}

int main(void) {

    int x, y, z;
    int ok = solve_uva11565(6, 6, 14, &x, &y, &z); // 1, 2, 3 -> 1+2+3=6, 1*2*3=6, 1+4+9=14
    ok = ok && (x == 1 && y == 2 && z == 3);
    printf("%s: UVa 11565 - Simple Equations\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
