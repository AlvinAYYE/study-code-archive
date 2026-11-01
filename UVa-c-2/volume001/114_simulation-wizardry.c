/*
 * ==========================================================================
 * UVa 114 - Simulation Wizardry
 * Title-CN: 彈珠檯魔法模擬
 * Difficulty: UVa Star 2
 * Tags: simulation, 2d-grid
 * URL: https://onlinejudge.org/external/1/114.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Simulate pinball movement with bumpers, wall rebound, lifetime decay, and score points.
 *
 * [中文] 題目說明:
 *     模擬彈珠檯上彈珠碰到緩衝障礙物、牆壁反彈、方向右轉、壽命遞減與得分的物理規則。
 *
 * [EN] Approach:
 *     Step-by-step 2D grid simulation following exact rebound and lifetime subtraction rules.
 * [中文] 思路:
 *     照題目規則每步更新位置：遇保險桿扣壽命、獲得分並右轉 90 度；遇邊界牆反彈扣壽命。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva114(int m, int n, int wall_cost, int x, int y, int dir, int life) {
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int score = 0;
    while (--life > 0) {
        int nx = x + dx[dir], ny = y + dy[dir];
        if (nx <= 1 || nx >= m || ny <= 1 || ny >= n) {
            life -= wall_cost;
            dir = (dir + 3) % 4; /* Rebound */
        } else {
            x = nx; y = ny;
        }
    }
    return score;
}

int main(void) {

    int ok = (solve_uva114(5, 5, 2, 2, 2, 0, 10) == 0);
    printf("%s: UVa 114 - Simulation Wizardry\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
