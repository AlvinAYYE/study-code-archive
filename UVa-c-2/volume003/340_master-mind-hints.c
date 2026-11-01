/*
 * ==========================================================================
 * UVa 340 - Master-Mind Hints
 * Title-CN: 猜數字密碼提示 (幾A幾B)
 * Difficulty: UVa Star 1
 * Tags: simulation, array, game
 * URL: https://onlinejudge.org/external/3/340.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given secret code and guesses, determine (A, B) hints: A = correct position and digit, B = correct digit but wrong position.
 *
 * [中文] 題目說明:
 *     經典 Master-Mind 幾 A 幾 B 遊戲：A 表示數字與位置皆正確；B 表示數字正確但位置不對。
 *
 * [EN] Approach:
 *     First pass: match exact positions (A). Second pass: count frequency of remaining digits to compute B.
 * [中文] 思路:
 *     第一輪先比對位置與數值皆相等的個數計為 A，並標記已匹配；第二輪統計未匹配剩餘數字的頻率交集計為 B。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void solve_uva340(int n, const int *sec, const int *gue, int *out_a, int *out_b) {
    int a = 0, b = 0;
    int s_cnt[10] = {0}, g_cnt[10] = {0};
    for (int i = 0; i < n; i++) {
        if (sec[i] == gue[i]) a++;
        else {
            s_cnt[sec[i]]++;
            g_cnt[gue[i]]++;
        }
    }
    for (int d = 1; d <= 9; d++) {
        b += (s_cnt[d] < g_cnt[d]) ? s_cnt[d] : g_cnt[d];
    }
    *out_a = a;
    *out_b = b;
}

int main(void) {

    int s[4] = {1, 2, 3, 4};
    int g[4] = {1, 3, 2, 5};
    int a, b;
    solve_uva340(4, s, g, &a, &b);
    int ok = (a == 1 && b == 2);
    printf("%s: UVa 340 - Master-Mind Hints\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
