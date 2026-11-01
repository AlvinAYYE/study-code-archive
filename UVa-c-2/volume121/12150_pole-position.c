/*
 * ==========================================================================
 * UVa 12150 - Pole Position
 * Title-CN: 桿位還原 (賽車起始排位模擬)
 * Difficulty: Easy
 * Tags: Simulation, Array
 * URL: https://onlinejudge.org/external/121/12150.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given final positions of race cars and their change in position relative to starting grid, reconstruct the initial starting grid order, or report -1 if invalid.
 *
 * [中文] 題目說明:
 *     給定賽車終點排名及每輛車相對於起始排位的排名升降幅度，還原初始發車排位；若有衝突或越界則輸出 -1。
 *
 * [EN] Approach:
 *     For each car i with position change P: initial pos = i + P. Verify 0 <= initial pos < N and no two cars claim the same starting spot.
 * [中文] 思路:
 *     第 i 位賽車的名次變化為 P，則初始位置必為 i + P。檢查該位置是否落在 [0, N-1] 內且無兩車重疊佔用同一發車格。
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

bool restore_starting_grid(int n, const int *cars, const int *diff, int *grid) {
    for (int i = 0; i < n; i++) grid[i] = 0;
    for (int i = 0; i < n; i++) {
        int orig = i + diff[i];
        if (orig < 0 || orig >= n || grid[orig] != 0) return false;
        grid[orig] = cars[i];
    }
    return true;
}

int main(void) {

    int cars[] = {1, 2}, diff[] = {1, -1}, grid[2];
    bool ok = restore_starting_grid(2, cars, diff, grid);
    ok = ok && (grid[0] == 2 && grid[1] == 1);
    printf("%s: UVa 12150 - Pole Position\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
