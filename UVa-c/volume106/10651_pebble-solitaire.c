/*
 * ==========================================================================
 * UVa 10651 - Pebble Solitaire
 * Title-CN: 卵石單人紙牌棋
 * Difficulty: Medium
 * Tags: Bitmask DP, DFS
 * URL: https://onlinejudge.org/external/106/10651.pdf
 * ==========================================================================
 * [EN] Problem:
 *     A 12-hole board has pebbles. A pebble can jump over an adjacent pebble into an empty hole, removing the jumped pebble. Find min remaining pebbles.
 *
 * [中文] 題目說明:
 *     12 個格子的棋盤上有卵石。卵石可跳過相鄰卵石進入空格並移除被跳過者，求最少剩下幾顆卵石。
 *
 * [EN] Approach:
 *     Bitmask DFS with memoization on 2^12 states. For each pattern 'oo-' or '-oo', make the move and recurse.
 * [中文] 思路:
 *     狀態壓縮 DFS：12 位二進位遮罩配合記憶化搜索，枚舉所有 'oo-' 或 '-oo' 跳躍操作，取殘留卵石數最小值。
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

int memo_pebble[4096];
int solve_pebble(int mask) {
    if (memo_pebble[mask] != -1) return memo_pebble[mask];
    int count = 0;
    for (int i = 0; i < 12; i++) if ((mask >> i) & 1) count++;
    int min_rem = count;
    for (int i = 0; i < 10; i++) {
        // pattern: bit i, i+1 set, i+2 unset -> jump right
        if (((mask >> i) & 1) && ((mask >> (i+1)) & 1) && !((mask >> (i+2)) & 1)) {
            int next_m = mask ^ (1 << i) ^ (1 << (i+1)) ^ (1 << (i+2));
            int rem = solve_pebble(next_m);
            if (rem < min_rem) min_rem = rem;
        }
        // pattern: bit i unset, i+1, i+2 set -> jump left
        if (!((mask >> i) & 1) && ((mask >> (i+1)) & 1) && ((mask >> (i+2)) & 1)) {
            int next_m = mask ^ (1 << i) ^ (1 << (i+1)) ^ (1 << (i+2));
            int rem = solve_pebble(next_m);
            if (rem < min_rem) min_rem = rem;
        }
    }
    return memo_pebble[mask] = min_rem;
}
int min_pebbles_left(const char *board) {
    int mask = 0;
    for (int i = 0; i < 12; i++) if (board[i] == 'o') mask |= (1 << i);
    memset(memo_pebble, -1, sizeof(memo_pebble));
    return solve_pebble(mask);
}

int main(void) {

    int res = min_pebbles_left("---oo-------");
    int ok = (res == 1);
    printf("%s: UVa 10651 - Pebble Solitaire\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
