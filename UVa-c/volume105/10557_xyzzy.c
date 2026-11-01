/*
 * ==========================================================================
 * UVa 10557 - XYZZY
 * Title-CN: 魔法迷宮冒險 (帶正權環的最長路徑/SPFA)
 * Difficulty: Medium
 * Tags: Graph, Bellman-Ford, SPFA
 * URL: https://onlinejudge.org/external/105/10557.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Start with 100 energy. Traverse rooms with energy changes to reach exit n without energy dropping to 0 or below.
 *
 * [中文] 題目說明:
 *     初始擁有 100 點能量，穿越各房間獲得或消耗能量，在能量始終大於 0 的前提下抵達終點 n。
 *
 * [EN] Approach:
 *     Modified Bellman-Ford. If an energy cycle can reach exit n and energy > 0, player can reach n with infinite energy.
 * [中文] 思路:
 *     變形 Bellman-Ford：若存在可無限增加能量的正環且該環能抵達終點，則必定可達終點；否則求最大能量路徑判斷是否 > 0。
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

bool can_escape_xyzzy(int n, const int *room_energy, const int adj[10][10]) {
    int energy[10];
    for (int i = 0; i < n; i++) energy[i] = -1;
    energy[0] = 100;
    for (int it = 0; it < n - 1; it++) {
        for (int u = 0; u < n; u++) {
            if (energy[u] <= 0) continue;
            for (int v = 0; v < n; v++) {
                if (adj[u][v] && energy[u] + room_energy[v] > energy[v]) {
                    energy[v] = energy[u] + room_energy[v];
                }
            }
        }
    }
    return energy[n - 1] > 0;
}

int main(void) {

    int e[] = {0, -50, 10};
    int adj[10][10] = {{0,1,0}, {0,0,1}, {0,0,0}};
    int ok = can_escape_xyzzy(3, e, adj);
    printf("%s: UVa 10557 - XYZZY\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
