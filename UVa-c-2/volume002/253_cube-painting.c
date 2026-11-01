/*
 * ==========================================================================
 * UVa 253 - Cube painting
 * Title-CN: 立方體六面著色旋轉同構判定
 * Difficulty: UVa Star 1
 * Tags: simulation, geometry, brute-force
 * URL: https://onlinejudge.org/external/2/253.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine if two painted cubes can be made identical through 3D rotations.
 *
 * [中文] 題目說明:
 *     判定兩個塗有顏色的正方體能否透過空間 24 種旋轉達到六面顏色完全相同。
 *
 * [EN] Approach:
 *     Enumerate 24 valid rotations (6 choices for top face, 4 rotations around vertical axis) and compare strings.
 * [中文] 思路:
 *     枚舉立方體的 24 種空間旋轉姿態 (6 種頂面選擇，每種頂面搭配 4 種側面旋轉)，逐一比對面顏色字串。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <string.h>

int solve_uva253(const char *c1, const char *c2) {
    int rots[24][6] = {
        {0,1,2,3,4,5},{0,2,4,1,3,5},{0,4,3,2,1,5},{0,3,1,4,2,5},
        {1,5,2,3,0,4},{1,2,0,5,3,4},{1,0,3,2,5,4},{1,3,5,0,2,4},
        {2,1,5,0,4,3},{2,5,4,1,0,3},{2,4,0,5,1,3},{2,0,1,4,5,3},
        {3,1,0,5,4,2},{3,0,4,1,5,2},{3,4,5,0,1,2},{3,5,1,4,0,2},
        {4,0,2,3,5,1},{4,2,5,0,3,1},{4,5,3,2,0,1},{4,3,0,5,2,1},
        {5,4,2,3,1,0},{5,2,1,4,3,0},{5,1,3,2,4,0},{5,3,4,1,2,0}
    };
    for (int r = 0; r < 24; r++) {
        int match = 1;
        for (int i = 0; i < 6; i++) {
            if (c1[rots[r][i]] != c2[i]) { match = 0; break; }
        }
        if (match) return 1;
    }
    return 0;
}

int main(void) {

    int ok = solve_uva253("rbgggr", "rbgggr");
    printf("%s: UVa 253 - Cube painting\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
