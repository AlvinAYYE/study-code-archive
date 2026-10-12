/*
 * ==========================================================================
 * UVa 11498 - Division of Nlogonia
 * Title-CN: 恩羅戈尼亞的分界
 * Difficulty: UVa Star 1
 * Tags: simulation, geometry
 * ==========================================================================
 * [EN] Problem: Determine quadrant relative to division point.
 * [中文] 題目說明: 根據分割點判定座標所在區域。
 * [EN] Approach: Direct coordinate comparison.
 * [中文] 思路: 依 X 與 Y 相比判定象限或邊界。
 * ==========================================================================
 */
#include <stdio.h>
#include <string.h>

const char *solve_uva11498(int ox, int oy, int x, int y) {
    if (x == ox || y == oy) return "divisa";
    if (x > ox && y > oy) return "NE";
    if (x > ox && y < oy) return "SE";
    if (x < ox && y > oy) return "NO";
    return "SO";
}

int main(void) {
    int ok = (strcmp(solve_uva11498(10, 10, 10, 15), "divisa") == 0) &&
             (strcmp(solve_uva11498(10, 10, 11, 11), "NE") == 0);
    printf("%s: UVa 11498 - Division of Nlogonia\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
