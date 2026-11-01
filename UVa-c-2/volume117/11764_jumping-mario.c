/*
 * ==========================================================================
 * UVa 11764 - Jumping Mario
 * Title-CN: 跳躍瑪莉歐 (高跳與低跳次數統計)
 * Difficulty: UVa Star 1
 * Tags: simulation, array
 * URL: https://onlinejudge.org/external/117/11764.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count number of high jumps (wall[i] > wall[i-1]) and low jumps (wall[i] < wall[i-1]) in Mario's run.
 *
 * [中文] 題目說明:
 *     瑪莉歐在不同高度的城牆間奔跑跳躍，統計由左至右跳越時的高跳 (往高處跳) 與低跳 (往低處跳) 的次數。
 *
 * [EN] Approach:
 *     Compare adjacent wall heights: if w[i] > w[i-1] high++, if w[i] < w[i-1] low++.
 * [中文] 思路:
 *     單次線性掃描比對相鄰牆高：後者大於前者則高跳次數 +1，小於則低跳次數 +1，相等不計。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void solve_uva11764(int n, const int *walls, int *high_jumps, int *low_jumps) {
    int h = 0, l = 0;
    for (int i = 1; i < n; i++) {
        if (walls[i] > walls[i - 1]) h++;
        else if (walls[i] < walls[i - 1]) l++;
    }
    *high_jumps = h;
    *low_jumps = l;
}

int main(void) {

    int w[8] = {1, 4, 2, 2, 3, 5, 3, 4};
    int h, l;
    solve_uva11764(8, w, &h, &l);
    int ok = (h == 4 && l == 2);
    printf("%s: UVa 11764 - Jumping Mario\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
