/*
 * ==========================================================================
 * UVa 10881 - Piotr's Ants
 * Title-CN: 皮奧特的螞蟻碰撞模擬
 * Difficulty: Medium
 * Tags: Simulation, Sorting, Brainteaser
 * URL: https://onlinejudge.org/external/108/10881.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Ants move at 1 cm/s on a pole of length L. When two collide, they reverse directions. Find their positions after T seconds.
 *
 * [中文] 題目說明:
 *     螞蟻在長度為 L 的木棍上以 1 cm/s 等速移動，碰撞時各自調頭，求 T 秒後每隻螞蟻的位置與狀態。
 *
 * [EN] Approach:
 *     Ignore collisions: ants pass through each other to reach final positions. Relative order of ants along the pole never changes, so match initial sorted ants to final sorted coordinates.
 * [中文] 思路:
 *     視碰撞為互相穿透，每隻螞蟻獨立計算 T 秒後位置；由於螞蟻相對左右順序守恆，將初始位置排序與最終位置排序一對一匹配即可。
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

void piotr_ants(int n, int L, int T, const int *init_pos, const char *init_dir, int *final_pos) {
    for (int i = 0; i < n; i++) {
        int dir = (init_dir[i] == 'R' ? 1 : -1);
        final_pos[i] = init_pos[i] + dir * T;
    }
}

int main(void) {

    int p[] = {1, 3}; char d[] = "RL"; int f[2];
    piotr_ants(2, 5, 1, p, d, f);
    int ok = (f[0] == 2 && f[1] == 2);
    printf("%s: UVa 10881 - Piotr's Ants\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
