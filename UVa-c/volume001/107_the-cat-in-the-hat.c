/*
 * ==========================================================================
 * UVa 107 - The Cat in the Hat
 * Title-CN: 戴帽子的貓
 * Difficulty: UVa Star 2
 * Tags: math, binary-search, logarithms
 * URL: https://onlinejudge.org/external/1/107.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Initial cat height H, final 1-height cats W. Each cat has N cats of height H/(N+1). Find non-working cats and total height.
 *
 * [中文] 題目說明:
 *     初始貓高 H，最後高度為 1 的貓有 W 隻。每隻貓帽子裡有 N 隻高 H/(N+1) 的小貓。求不工作的貓數量與總高度。
 *
 * [EN] Approach:
 *     Solve (N+1)^k = H and N^k = W for integers N and k. Then non-working cats sum = (N^k - 1)/(N - 1).
 * [中文] 思路:
 *     求解方程 (N+1)^k = H 且 N^k = W。特判 W=1 時 N=1, k=0。等比級數求不工作貓與總高度。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <math.h>

void solve_uva107(long long H, long long W, long long *out_lazy, long long *out_height) {
    if (H == 1 && W == 1) { *out_lazy = 0; *out_height = 1; return; }
    if (W == 1) {
        long long k = 0, cur = 1;
        while (cur < H) { cur *= 2; k++; }
        *out_lazy = (H == 1) ? 0 : 1;
        *out_height = 2 * H - 1;
        return;
    }
    long long N = 1;
    for (N = 1; ; N++) {
        long long h = 1, w = 1;
        while (h < H && w < W) { h *= (N + 1); w *= N; }
        if (h == H && w == W) break;
    }
    long long lazy = 0, total_h = 0;
    long long cur_h = H, cur_w = 1;
    while (cur_h > 1) {
        lazy += cur_w;
        total_h += cur_w * cur_h;
        cur_w *= N;
        cur_h /= (N + 1);
    }
    total_h += cur_w; /* Height 1 cats */
    *out_lazy = lazy;
    *out_height = total_h;
}

int main(void) {

    long long lazy, th;
    solve_uva107(216, 125, &lazy, &th);
    int ok = (lazy == 31 && th == 671);
    printf("%s: UVa 107 - The Cat in the Hat\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
