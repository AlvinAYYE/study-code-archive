/*
 * ==========================================================================
 * UVa 11507 - Bender B. Rodriguez Problem
 * Title-CN: 班德 3D 空間折彎鐵絲方向模擬
 * Difficulty: UVa Star 2
 * Tags: simulation
 * URL: https://onlinejudge.org/external/115/11507.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Track the pointing direction (+x, -x, +y, -y, +z, -z) of a flexible wire as it is bent at sequential unit positions.
 *
 * [中文] 題目說明:
 *     鐵絲初始朝向 +x，依序施加繞軸旋轉折彎指令 (+y, -y, +z, -z)，求鐵絲頂端最終的空間朝向代碼。
 *
 * [EN] Approach:
 *     Direction state machine: maintain current direction (+x, -x, +y, -y, +z, -z). Update direction on valid non-'No' bends.
 * [中文] 思路:
 *     以方向狀態機維護當前朝向：遇到 +y/-y/+z/-z 時依據三維旋轉變換更新朝向代碼，遇 'No' 則維持原方向。
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

int solve_uva11507_step(int cur, int bend) {
    // 0:+x, 1:-x, 2:+y, 3:-y, 4:+z, 5:-z
    if (bend == -1) return cur; // No
    if (cur == 0) return bend;
    if (cur == 1) return bend ^ 1;
    if (cur == 2) {
        if (bend == 2) return 1;
        if (bend == 3) return 0;
    }
    if (cur == 3) {
        if (bend == 2) return 0;
        if (bend == 3) return 1;
    }
    return cur;
}

int main(void) {

    int dir = solve_uva11507_step(0, 2); // +x bent +y -> +y
    int ok = (dir == 2);
    printf("%s: UVa 11507 - Bender B. Rodriguez Problem\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
