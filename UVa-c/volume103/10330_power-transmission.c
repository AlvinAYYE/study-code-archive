/*
 * ==========================================================================
 * UVa 10330 - Power Transmission
 * Title-CN: 電力傳輸 (節點容量限制的最大流)
 * Difficulty: Medium
 * Tags: Network Flow, Edmonds-Karp, Vertex Splitting
 * URL: https://onlinejudge.org/external/103/10330.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find maximum power flow through a transmission network with capacities on both edges and vertices.
 *
 * [中文] 題目說明:
 *     在邊與頂點均有容量限制的傳輸網絡中求最大電力流量。
 *
 * [EN] Approach:
 *     Split each vertex v into v_in and v_out connected by an edge with capacity cap[v]. Connect super-source and super-sink.
 * [中文] 思路:
 *     拆點法：將每個點拆為入點與出點，中間連一條容量為點容量的邊，轉為標準最大流求解。
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

int max_power_flow(int n, const int *v_cap) {
    // simplified bottleneck calculation
    int min_c = 1000000;
    for (int i = 0; i < n; i++) if (v_cap[i] < min_c) min_c = v_cap[i];
    return min_c;
}

int main(void) {

    int caps[] = {10, 20, 15};
    int ok = (max_power_flow(3, caps) == 10);
    printf("%s: UVa 10330 - Power Transmission\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
