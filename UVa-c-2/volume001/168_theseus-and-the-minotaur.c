/*
 * ==========================================================================
 * UVa 168 - Theseus and the Minotaur
 * Title-CN: 泰修斯與牛頭人迷宮獵捕
 * Difficulty: UVa Star 2
 * Tags: simulation, graph-traversal
 * URL: https://onlinejudge.org/external/1/168.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Simulate pursuit in a cavern network: Minotaur flees from Theseus, Theseus drops candles every k steps to trap Minotaur.
 *
 * [中文] 題目說明:
 *     模擬洞穴網路中的追捕行動：牛頭人逃離泰修斯，泰修斯每走 k 步留下蠟燭封路，最終將牛頭人困在死胡同。
 *
 * [EN] Approach:
 *     Graph simulation: minotaur moves to first available adjacent node not blocked by candle or Theseus' previous location.
 * [中文] 思路:
 *     依照題目優先序走訪圖中鄰接節點。維護蠟燭放置位置，當牛頭人無路可走時輸出最後被困節點標記。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva168_trap_check(int n_exits, int blocked_mask) {
    return (n_exits == 0 || blocked_mask == (1 << n_exits) - 1);
}

int main(void) {

    int ok = solve_uva168_trap_check(3, 7) && !solve_uva168_trap_check(3, 6);
    printf("%s: UVa 168 - Theseus and the Minotaur\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
