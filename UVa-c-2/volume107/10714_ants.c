/*
 * ==========================================================================
 * UVa 10714 - Ants
 * Title-CN: 木竿上的螞蟻 (最早與最晚掉落時間)
 * Difficulty: UVa Star 1
 * Tags: greedy, brain-teaser
 * URL: https://onlinejudge.org/external/107/10714.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Ants walk along a pole of length L. When two collide, they reverse directions. Find min and max time for all ants to fall off.
 *
 * [中文] 題目說明:
 *     螞蟻在長度為 L 的木竿上移動，兩蟻碰撞時各自掉頭。求所有螞蟻全部掉落的最早時間與最晚時間。
 *
 * [EN] Approach:
 *     Colliding ants passing through each other is physically equivalent to reversing. Min time = max(min(x, L-x)). Max time = max(max(x, L-x)).
 * [中文] 思路:
 *     思維轉換：兩蟻相撞掉頭等價於彼此穿透而過！每隻螞蟻各自走向最近端的時間最大值即為最早時間，走向最遠端的時間最大值即為最晚時間。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void solve_uva10714(int l, int n, const int *pos, int *earliest, int *latest) {
    int min_t = 0, max_t = 0;
    for (int i = 0; i < n; i++) {
        int x = pos[i];
        int to_near = (x < l - x) ? x : (l - x);
        int to_far = (x > l - x) ? x : (l - x);
        if (to_near > min_t) min_t = to_near;
        if (to_far > max_t) max_t = to_far;
    }
    *earliest = min_t;
    *latest = max_t;
}

int main(void) {

    int p[3] = {2, 6, 7};
    int e, l;
    solve_uva10714(10, 3, p, &e, &l);
    int ok = (e == 4 && l == 8);
    printf("%s: UVa 10714 - Ants\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
