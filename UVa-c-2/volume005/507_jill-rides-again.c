/*
 * ==========================================================================
 * UVa 507 - Jill Rides Again
 * Title-CN: 最佳單車騎行區段 (最大連續子序列和 Kadane)
 * Difficulty: UVa Star 1
 * Tags: dynamic-programming, kadane, max-subarray
 * URL: https://onlinejudge.org/external/5/507.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find contiguous route segment maximizing Jill's niceness sum; break ties by longest segment, then earliest start.
 *
 * [中文] 題目說明:
 *     求單車路線中風景評價總和最大的連續區段。若有多組最大和，優先選區間長度最長者，再選起點最早者。
 *
 * [EN] Approach:
 *     Kadane's algorithm tracking (start, end) indices. Update best if current_sum > max_sum or (current_sum == max_sum and length > best_length).
 * [中文] 思路:
 *     Kadane 演算法擴展：動態維護當前起點。在數值嚴格大於最大值或數值相等且區間跨度更長時更新全局最佳解。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void solve_uva507(int n, const int *val, int *out_start, int *out_end, int *out_max) {
    int max_sum = 0, cur_sum = 0;
    int best_s = 1, best_e = 1, cur_s = 1;
    for (int i = 1; i < n; i++) {
        cur_sum += val[i - 1];
        if (cur_sum < 0) {
            cur_sum = 0;
            cur_s = i + 1;
        } else if (cur_sum > max_sum || (cur_sum == max_sum && (i + 1 - cur_s > best_e - best_s))) {
            max_sum = cur_sum;
            best_s = cur_s;
            best_e = i + 1;
        }
    }
    *out_start = best_s;
    *out_end = best_e;
    *out_max = max_sum;
}

int main(void) {

    int v[4] = {4, -5, 4, -3};
    int s, e, m;
    solve_uva507(5, v, &s, &e, &m);
    int ok = (m == 4 && s == 1 && e == 2);
    printf("%s: UVa 507 - Jill Rides Again\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
