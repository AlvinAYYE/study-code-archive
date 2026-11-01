/*
 * ==========================================================================
 * UVa 10167 - Birthday Cake
 * Title-CN: 切生日蛋糕
 * Difficulty: UVa Star 1
 * Tags: geometry, math
 * ==========================================================================
 * [EN] Problem: Find A, B such that Ax + By = 0 splits 2N points equally.
 * [中文] 題目說明: 尋找整數 A, B 使得 Ax + By = 0 將 2N 點平分。
 * [EN] Approach: Brute force search A, B in [-500, 500].
 * [中文] 思路: 暴力枚舉 A, B，驗證兩側點數是否皆為 N 且無點在線上。
 * ==========================================================================
 */
#include <stdio.h>

int solve_uva10167(int n, const int pts[][2], int *ansA, int *ansB) {
    int total = 2 * n;
    for (int a = -500; a <= 500; a++) {
        for (int b = -500; b <= 500; b++) {
            if (a == 0 && b == 0) continue;
            int pos = 0, neg = 0, on = 0;
            for (int i = 0; i < total; i++) {
                int val = a * pts[i][0] + b * pts[i][1];
                if (val > 0) pos++;
                else if (val < 0) neg++;
                else { on = 1; break; }
            }
            if (!on && pos == n && neg == n) {
                *ansA = a; *ansB = b;
                return 1;
            }
        }
    }
    return 0;
}

int main(void) {
    int pts[2][2] = {{1, 1}, {-1, -1}};
    int a, b;
    int ok = solve_uva10167(1, pts, &a, &b);
    printf("%s: UVa 10167 - Birthday Cake\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
