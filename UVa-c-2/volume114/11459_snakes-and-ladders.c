/*
 * ==========================================================================
 * UVa 11459 - Snakes and Ladders
 * Title-CN: 蛇與梯子棋盤遊戲模擬
 * Difficulty: Easy
 * Tags: Simulation
 * URL: https://onlinejudge.org/external/114/11459.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Simulate players moving along a 100-cell board with dice rolls, climbing ladders or sliding down snakes until a player reaches 100.
 *
 * [中文] 題目說明:
 *     模擬多名玩家擲骰子在 100 格棋盤上前進，遇到梯子上升、遇到蛇下滑，最先抵達 100 格者獲勝。
 *
 * [EN] Approach:
 *     Maintain positions of players. Advance current player's pos by roll, teleport if pos is a ladder/snake. Stop advancing if someone hits 100.
 * [中文] 思路:
 *     維護各玩家位置，按擲骰點數移動，若停在蛇或梯子起點則跳躍至終點；一旦有玩家抵達 100 格遊戲立即結束。
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

void simulate_snakes_ladders(int num_players, const int *jumps, int num_rolls, const int *rolls, int *final_pos) {
    for (int i = 0; i < num_players; i++) final_pos[i] = 1;
    bool game_over = false;
    for (int i = 0; i < num_rolls; i++) {
        if (game_over) continue;
        int p = i % num_players;
        int nxt = final_pos[p] + rolls[i];
        if (nxt > 100) nxt = 100;
        if (jumps[nxt] != 0) nxt = jumps[nxt];
        final_pos[p] = nxt;
        if (nxt >= 100) game_over = true;
    }
}

int main(void) {

    int jumps[105] = {0};
    jumps[5] = 20; // ladder from 5 to 20
    int rolls[] = {4}; // from 1 + 4 = 5 -> jumps to 20
    int pos[1];
    simulate_snakes_ladders(1, jumps, 1, rolls, pos);
    int ok = (pos[0] == 20);
    printf("%s: UVa 11459 - Snakes and Ladders\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
