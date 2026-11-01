/*
 * ==========================================================================
 * UVa 10067 - Playing with Wheels
 * Title-CN: 數字轉輪密碼鎖避障最短步數 BFS
 * Difficulty: UVa Star 2
 * Tags: graph, bfs
 * URL: https://onlinejudge.org/external/100/10067.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the minimum button presses to reach target 4-digit wheel configuration from initial, avoiding forbidden states.
 *
 * [中文] 題目說明:
 *     四位數字轉輪每步可將任一位往上或往下轉動一格 (0-9 循環)，求避開所有禁手狀態到達目標密碼之最少步數。
 *
 * [EN] Approach:
 *     Breadth-First Search on state graph of 10000 configurations. Each configuration has 8 transitions (+1 and -1 on each of 4 dials).
 * [中文] 思路:
 *     在 10000 個狀態空間上執行 BFS：每個狀態有 8 種轉動後繼狀態，以陣列標記禁手與走訪步數。
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

int solve_uva10067(int start, int target, int *forbidden, int f_cnt) {
    int dist[10000];
    for (int i = 0; i < 10000; i++) dist[i] = -1;
    for (int i = 0; i < f_cnt; i++) dist[forbidden[i]] = -2;
    if (dist[start] == -2 || dist[target] == -2) return -1;
    if (start == target) return 0;

    int q[10000], head = 0, tail = 0;
    q[tail++] = start;
    dist[start] = 0;

    int weights[] = {1000, 100, 10, 1};
    while (head < tail) {
        int cur = q[head++];
        if (cur == target) return dist[cur];
        for (int d = 0; d < 4; d++) {
            int w = weights[d];
            int digit = (cur / w) % 10;
            // +1
            int nxt1 = cur + ((digit == 9 ? -9 : 1) * w);
            if (dist[nxt1] == -1) { dist[nxt1] = dist[cur] + 1; q[tail++] = nxt1; }
            // -1
            int nxt2 = cur + ((digit == 0 ? 9 : -1) * w);
            if (dist[nxt2] == -1) { dist[nxt2] = dist[cur] + 1; q[tail++] = nxt2; }
        }
    }
    return -1;
}

int main(void) {

    int forb[] = {8057};
    int steps = solve_uva10067(8056, 8058, forb, 1);
    int ok = (steps == 4);
    printf("%s: UVa 10067 - Playing with Wheels\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
