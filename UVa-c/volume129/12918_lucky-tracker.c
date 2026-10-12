/*
 * ==========================================================================
 * UVa 12918 - Lucky Tracker
 * Title-CN: 幸運的追蹤者
 * Difficulty: UVa Star 1
 * Tags: math
 * ==========================================================================
 * [EN] Problem: n keys and m doors (m >= n). Compute max failed attempts before matching all doors.
 * [中文] 題目說明: n 把鑰匙與 m 扇門，求在最壞情況下成功配對前嘗試失敗的最大總次數。
 * [EN] Approach: Formula n * (2*m - n - 1) / 2.
 * [中文] 思路: 等差數列求和公式：(m - 1) + (m - 2) + ... + (m - n) = n * (2*m - n - 1) / 2。
 * ==========================================================================
 */
#include <stdio.h>

long long solve_uva12918(long long n, long long m) {
    return n * (2 * m - n - 1) / 2;
}

int main(void) {
    int ok = (solve_uva12918(1, 2) == 1) && (solve_uva12918(2, 4) == 5);
    printf("%s: UVa 12918 - Lucky Tracker\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
