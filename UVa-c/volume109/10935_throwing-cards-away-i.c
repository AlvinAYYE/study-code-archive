/*
 * ==========================================================================
 * UVa 10935 - Throwing cards away I
 * Title-CN: 丟紙牌模擬 I (佇列拋牌與底牌)
 * Difficulty: UVa Star 1
 * Tags: data-structures, queue, simulation
 * URL: https://onlinejudge.org/external/109/10935.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given deck of n cards (1 on top, n on bottom). Discard top card, move next top to bottom. Output discarded sequence and last card.
 *
 * [中文] 題目說明:
 *     依序丟棄牌頂第 1 張牌，並將接下來的頂牌移至牌底，重複執行直到剩下最後 1 張牌。輸出丟棄序列與最後底牌。
 *
 * [EN] Approach:
 *     Queue simulation: dequeue discarded, dequeue next and enqueue to back, repeat while size > 1.
 * [中文] 思路:
 *     標準環狀佇列模擬：每次出隊一張加入被棄列表，再將下一張牌出隊並壓入隊尾，直到佇列僅剩 1 張牌。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva10935(int n, int *discarded, int *rem_card) {
    int q[150], head = 0, tail = 0;
    for (int i = 1; i <= n; i++) q[tail++] = i;
    int d_cnt = 0;
    while (tail - head > 1) {
        discarded[d_cnt++] = q[head++];
        q[tail++] = q[head++];
    }
    *rem_card = q[head];
    return d_cnt;
}

int main(void) {

    int disc[50], rem;
    int cnt = solve_uva10935(7, disc, &rem);
    int ok = (cnt == 6 && rem == 6 && disc[0] == 1 && disc[1] == 3);
    printf("%s: UVa 10935 - Throwing cards away I\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
