/*
 * ==========================================================================
 * UVa 10928 - My Dear Neighbours
 * Title-CN: 親愛的鄰居
 * Difficulty: Easy
 * Tags: Graph, Degree
 * URL: https://onlinejudge.org/external/109/10928.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find all places that have the minimum number of neighbours in a neighborhood graph.
 *
 * [中文] 題目說明:
 *     求社區圖中鄰居數量最少（度數最小）的所有地點編號。
 *
 * [EN] Approach:
 *     Parse lines to count neighbors (degrees) for each place. Find minimum degree, then print all places with that degree.
 * [中文] 思路:
 *     讀取每戶鄰居清單統計節點度數，求最小度數並升序輸出所有度數最小的節點。
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

int find_min_degree_nodes(int n, const int *deg, int *out) {
    int mn = 1000000;
    for (int i = 0; i < n; i++) if (deg[i] < mn) mn = deg[i];
    int cnt = 0;
    for (int i = 0; i < n; i++) if (deg[i] == mn) out[cnt++] = i + 1;
    return cnt;
}

int main(void) {

    int deg[] = {2, 1, 3, 1};
    int out[4];
    int cnt = find_min_degree_nodes(4, deg, out);
    int ok = (cnt == 2 && out[0] == 2 && out[1] == 4);
    printf("%s: UVa 10928 - My Dear Neighbours\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
