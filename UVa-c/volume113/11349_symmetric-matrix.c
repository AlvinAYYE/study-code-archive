/*
 * ==========================================================================
 * UVa 11349 - Symmetric Matrix
 * Title-CN: 對稱矩陣檢驗
 * Difficulty: UVa Star 1
 * Tags: 2d-array
 * ==========================================================================
 * [EN] Problem: Check center-symmetric non-negative matrix.
 * [中文] 題目說明: 檢查中心點對稱且元素皆非負的矩陣。
 * [EN] Approach: Validate mat[i][j] >= 0 and mat[i][j] == mat[n-1-i][n-1-j].
 * [中文] 思路: 雙重迴圈比對點對稱位置元素。
 * ==========================================================================
 */
#include <stdio.h>

int solve_uva11349(int n, const long long mat[105][105]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] < 0) return 0;
            if (mat[i][j] != mat[n - 1 - i][n - 1 - j]) return 0;
        }
    }
    return 1;
}

int main(void) {
    long long m[2][105] = {{5, 1}, {1, 5}};
    int ok = solve_uva11349(2, m);
    printf("%s: UVa 11349 - Symmetric Matrix\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
