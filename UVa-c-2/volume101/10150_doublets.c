/*
 * ==========================================================================
 * UVa 10150 - Doublets
 * Title-CN: 雙詞階梯 (字詞變換最短路徑)
 * Difficulty: Medium
 * Tags: Graph, BFS, Shortest Path
 * URL: https://onlinejudge.org/external/101/10150.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the shortest sequence of dictionary words from start to end where each word differs by exactly one letter from the previous word.
 *
 * [中文] 題目說明:
 *     求字典中從起點單字到終點單字的最短變換序列，每次只允許改變一個字母。
 *
 * [EN] Approach:
 *     Build graph connecting words of identical length differing by 1 character. Run BFS from start to target.
 * [中文] 思路:
 *     為長度相同且恰好相差一個字母的單字連邊建圖，使用 BFS 尋找最短路徑並回溯輸出路徑。
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

bool is_doublet(const char *a, const char *b) {
    int diff = 0;
    for (int i = 0; a[i] && b[i]; i++) {
        if (a[i] != b[i]) { diff++; if (diff > 1) return false; }
    }
    return diff == 1;
}
int doublet_dist(int n, const char dict[10][10], int src, int dst) {
    int dist[10];
    for (int i = 0; i < n; i++) dist[i] = -1;
    dist[src] = 0;
    int q[10], head = 0, tail = 0;
    q[tail++] = src;
    while (head < tail) {
        int u = q[head++];
        if (u == dst) return dist[u];
        for (int v = 0; v < n; v++) {
            if (dist[v] == -1 && is_doublet(dict[u], dict[v])) {
                dist[v] = dist[u] + 1;
                q[tail++] = v;
            }
        }
    }
    return -1;
}

int main(void) {

    char dict[3][10] = {"cat", "cot", "cog"};
    int d = doublet_dist(3, dict, 0, 2);
    int ok = (d == 2);
    printf("%s: UVa 10150 - Doublets\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
