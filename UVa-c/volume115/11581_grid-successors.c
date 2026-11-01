/*
 * ==========================================================================
 * UVa 11581 - Grid Successors
 * Title-CN: 網格後繼運算 (有限元週期與收斂步數)
 * Difficulty: Easy
 * Tags: Simulation, Matrix, Floyd Cycle
 * URL: https://onlinejudge.org/external/115/11581.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Apply cell transition f(g)[i][j] = sum of 4 neighbors mod 2 until grid is all zeros. Find index of last non-zero step.
 *
 * [中文] 題目說明:
 *     對 3x3 網格反覆執行相鄰 4 格之和取模 2 的變換，求全 0 網格出現前的最大步數索引（初態即為全 0 則為 -1）。
 *
 * [EN] Approach:
 *     Simulate f(g) iteratively. All initial states converge to all 0s in at most 10 steps.
 * [中文] 思路:
 *     迭代模擬鄰居異或和變換，檢查網格是否全為 0，至多 10 步內必收斂至全 0。
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

int grid_successor_steps(int g[3][3]) {
    int steps = -1;
    while (1) {
        bool all_zero = true;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (g[i][j]) all_zero = false;
        if (all_zero) return steps;
        steps++;
        int next_g[3][3];
        int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < 3; c++) {
                int sum = 0;
                for (int k = 0; k < 4; k++) {
                    int nr = r + dr[k], nc = c + dc[k];
                    if (nr >= 0 && nr < 3 && nc >= 0 && nc < 3) sum += g[nr][nc];
                }
                next_g[r][c] = sum % 2;
            }
        }
        for (int r = 0; r < 3; r++)
            for (int c = 0; c < 3; c++) g[r][c] = next_g[r][c];
    }
}

int main(void) {

    int g[3][3] = {{0,0,0}, {0,0,0}, {0,0,0}};
    int ok = (grid_successor_steps(g) == -1);
    printf("%s: UVa 11581 - Grid Successors\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
