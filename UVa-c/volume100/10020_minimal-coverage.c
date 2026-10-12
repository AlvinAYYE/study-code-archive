/*
 * ==========================================================================
 * UVa 10020 - Minimal coverage
 * Title-CN: 最小區間覆蓋
 * Difficulty: UVa Star 2
 * Tags: greedy, sorting
 * URL: https://onlinejudge.org/external/100/10020.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given segment [0, M], select minimal number of given segments to completely cover it.
 *
 * [中文] 題目說明:
 *     選取最少數量的線段以完全覆蓋區間 [0, M]。若無法完全覆蓋則輸出 0。
 *
 * [EN] Approach:
 *     Sort segments by left endpoint. At each step, pick the segment starting <= current right
 *     with maximal right extension.
 * [中文] 思路:
 *     依左端點排序。每次在左端點 <= 目前覆蓋終點的線段中，貪婪選取右端點最遠的線段。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int l, r;
} Seg;

static int cmp_seg(const void *a, const void *b) {
    return ((const Seg *)a)->l - ((const Seg *)b)->l;
}

int solve_uva10020(int m, int n, Seg *segs, Seg *chosen) {
    qsort(segs, (size_t)n, sizeof(Seg), cmp_seg);
    int cur_r = 0, count = 0, i = 0;

    while (cur_r < m) {
        int best_r = cur_r;
        int best_idx = -1;
        while (i < n && segs[i].l <= cur_r) {
            if (segs[i].r > best_r) {
                best_r = segs[i].r;
                best_idx = i;
            }
            i++;
        }
        if (best_idx == -1) return 0; /* Cannot cover */
        chosen[count++] = segs[best_idx];
        cur_r = best_r;
    }
    return count;
}

int main(void) {
    Seg s[4] = {{-1, 0}, {-5, -3}, {2, 5}, {0, 3}};
    Seg chosen[4];
    /* To cover [0, 1], segment [0, 3] covers it alone */
    int cnt = solve_uva10020(1, 4, s, chosen);
    int ok = (cnt == 1 && chosen[0].l == 0 && chosen[0].r == 3);
    printf("%s: UVa 10020 - Minimal coverage\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
