/*
 * ==========================================================================
 * UVa 429 - Word Transformation
 * Title-CN: 單字變換最短梯路 BFS
 * Difficulty: UVa Star 2
 * Tags: graph, bfs, string
 * URL: https://onlinejudge.org/external/4/429.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find minimum transformations to change start word to target word, changing one letter at a time through words in the dictionary.
 *
 * [中文] 題目說明:
 *     在單字庫中每次僅允許改變一個字母，求由起始單字變換至目標單字的最少變換步數 (單字梯 BFS 最短路)。
 *
 * [EN] Approach:
 *     Construct graph where words of equal length differing by exactly 1 character share an edge. Run BFS from start to target.
 * [中文] 思路:
 *     同長度且恰好差一個字母的單字間連邊，自起點單字啟動廣度優先搜尋 (BFS) 求至終點單字之最短步數。
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

int diff_one(const char *a, const char *b) {
    if (strlen(a) != strlen(b)) return 0;
    int diff = 0;
    for (int i = 0; a[i]; i++) {
        if (a[i] != b[i]) {
            diff++;
            if (diff > 1) return 0;
        }
    }
    return diff == 1;
}

int solve_uva429(int n, char words[][20], int src, int dst) {
    int dist[50], q[50], head = 0, tail = 0;
    for (int i = 0; i < n; i++) dist[i] = -1;
    q[tail++] = src; dist[src] = 0;
    while (head < tail) {
        int u = q[head++];
        if (u == dst) return dist[u];
        for (int v = 0; v < n; v++) {
            if (dist[v] == -1 && diff_one(words[u], words[v])) {
                dist[v] = dist[u] + 1;
                q[tail++] = v;
            }
        }
    }
    return -1;
}

int main(void) {

    char dict[3][20] = {"cat", "cot", "cog"};
    int d = solve_uva429(3, dict, 0, 2); // cat -> cot -> cog (2 steps)
    int ok = (d == 2);
    printf("%s: UVa 429 - Word Transformation\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
