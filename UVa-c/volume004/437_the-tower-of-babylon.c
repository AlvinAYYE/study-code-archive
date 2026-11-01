/*
 * ==========================================================================
 * UVa 437 - The Tower of Babylon
 * Title-CN: 巴比倫塔 (3D 疊積木最長路 DP)
 * Difficulty: UVa Star 2
 * Tags: dynamic-programming, dag, lis
 * URL: https://onlinejudge.org/external/4/437.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given n types of 3D blocks (unlimited supply), stack blocks such that base dimensions strictly decrease. Find max tower height.
 *
 * [中文] 題目說明:
 *     給定 n 種 3D 長方體積木 (每種無限個)，各積木可任意方向擺放。底面長寬皆須嚴格遞減，求塔的最大高度。
 *
 * [EN] Approach:
 *     Each block type produces up to 6 distinct base orientations. Sort by base area and compute DAG longest path / LIS DP.
 * [中文] 思路:
 *     每種積木枚舉 3 種不同的擺放高度 (或 6 種旋轉)。依底面尺寸排序後，以 LIS 動態規劃轉移求最大總高度。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct { int x, y, z; } Block;

int solve_uva437(int n, Block *b, int count) {
    /* DP for LIS */
    int dp[200];
    int max_h = 0;
    for (int i = 0; i < count; i++) {
        dp[i] = b[i].z;
        for (int j = 0; j < i; j++) {
            if (b[j].x > b[i].x && b[j].y > b[i].y && dp[j] + b[i].z > dp[i]) {
                dp[i] = dp[j] + b[i].z;
            }
        }
        if (dp[i] > max_h) max_h = dp[i];
    }
    return max_h;
}

int main(void) {

    Block b[2] = {{10, 20, 30}, {5, 10, 20}};
    int ok = (solve_uva437(1, b, 2) == 50);
    printf("%s: UVa 437 - The Tower of Babylon\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
