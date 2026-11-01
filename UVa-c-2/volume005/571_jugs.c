/*
 * ==========================================================================
 * UVa 571 - Jugs
 * Title-CN: 倒水問題
 * Difficulty: Medium
 * Tags: BFS, State Machine, Simulation
 * URL: https://onlinejudge.org/external/5/571.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given two jugs of capacity Ca and Cb and target N, output a sequence of fill, empty, and pour operations to measure N liters in jug B.
 *
 * [中文] 題目說明:
 *     給定容量為 Ca 與 Cb 的水壺及目標水量 N，求裝滿、倒空、互倒等操作序列，使 B 壺內恰有 N 升水。
 *
 * [EN] Approach:
 *     State BFS (a, b) with 6 transitions: fill A, fill B, empty A, empty B, pour A->B, pour B->A. Trace parent pointers.
 * [中文] 思路:
 *     狀態圖 BFS：記錄 (a, b) 狀態與父節點路徑，進行 6 種水壺轉換操作，直至 b == N 時回溯操作步驟。
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

int min_jug_steps(int ca, int cb, int n) {
    int vis[100][100] = {0};
    int q[10000][2], head = 0, tail = 0;
    int dist[100][100] = {0};
    q[tail][0] = 0; q[tail++][1] = 0;
    vis[0][0] = 1;
    while (head < tail) {
        int a = q[head][0], b = q[head++][1];
        if (b == n) return dist[a][b];
        int next_states[6][2] = {
            {ca, b}, {a, cb}, {0, b}, {a, 0},
            {a - (cb - b < a ? cb - b : a), b + (cb - b < a ? cb - b : a)},
            {a + (ca - a < b ? ca - a : b), b - (ca - a < b ? ca - a : b)}
        };
        for (int i = 0; i < 6; i++) {
            int na = next_states[i][0], nb = next_states[i][1];
            if (!vis[na][nb]) {
                vis[na][nb] = 1;
                dist[na][nb] = dist[a][b] + 1;
                q[tail][0] = na; q[tail++][1] = nb;
            }
        }
    }
    return -1;
}

int main(void) {

    int steps = min_jug_steps(3, 5, 4);
    int ok = (steps == 6);
    printf("%s: UVa 571 - Jugs\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
