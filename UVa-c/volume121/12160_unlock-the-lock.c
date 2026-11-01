/*
 * ==========================================================================
 * UVa 12160 - Unlock the Lock
 * Title-CN: 密碼鎖解鎖 (模10000最短路BFS)
 * Difficulty: Easy
 * Tags: Graph, BFS, Shortest Path
 * URL: https://onlinejudge.org/external/121/12160.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given a 4-digit lock current code L and unlock code U, press R available buttons (each adds a value modulo 10000). Find minimum button presses.
 *
 * [中文] 題目說明:
 *     四位數密碼鎖初態為 L，目標為 U，有 R 個可按的加法按鈕（每次相加模 10000），求最少按鍵次數。
 *
 * [EN] Approach:
 *     BFS on state space 0..9999. dist array initialized to -1. Expand by (cur + button[i]) % 10000.
 * [中文] 思路:
 *     在 0~9999 狀態空間上進行標準 BFS：每次嘗試所有按鈕值相加並取模 10000，求到達終點 U 的最少步數。
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

int min_unlock_presses(int L, int U, int R, const int *buttons) {
    if (L == U) return 0;
    int dist[10000];
    for (int i = 0; i < 10000; i++) dist[i] = -1;
    dist[L] = 0;
    int q[10000], head = 0, tail = 0;
    q[tail++] = L;
    while (head < tail) {
        int u = q[head++];
        if (u == U) return dist[u];
        for (int i = 0; i < R; i++) {
            int v = (u + buttons[i]) % 10000;
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q[tail++] = v;
            }
        }
    }
    return -1; // Permanently Locked
}

int main(void) {

    int btns[] = {1, 2};
    int res = min_unlock_presses(0, 3, 2, btns); // 0 -> 2 -> 3 (2 presses)
    int ok = (res == 2);
    printf("%s: UVa 12160 - Unlock the Lock\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
