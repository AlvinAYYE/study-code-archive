/*
 * ==========================================================================
 * UVa 10142 - Australian Voting
 * Title-CN: 澳洲排序複選制即時決選投票
 * Difficulty: UVa Star 2
 * Tags: simulation
 * URL: https://onlinejudge.org/external/101/10142.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Simulate Australian preferential voting: count 1st preferences; if no candidate has > 50%, eliminate candidate(s) with lowest votes and redistribute.
 *
 * [中文] 題目說明:
 *     模擬澳洲偏好投票制 (排序複選制)：統計首選票數，若無人過半則淘汰最低得票者並將選票依序遞補，重複直到勝出或平手。
 *
 * [EN] Approach:
 *     Maintain candidate elimination flags. In each round, tally active first preferences. If max > 50% or all remaining tied, terminate.
 * [中文] 思路:
 *     以陣列記錄淘汰狀態，每輪統計有效選票之第一偏好，若最高票過半或所有剩餘候選人同票則宣告獲勝，否則淘汰最低票並循環。
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

int solve_uva10142_round(int c_cnt, int v_cnt, int votes[10][5], int *elim, int *winner) {
    int tally[10] = {0};
    for (int i = 0; i < v_cnt; i++) {
        for (int p = 0; p < c_cnt; p++) {
            int cand = votes[i][p];
            if (!elim[cand]) { tally[cand]++; break; }
        }
    }
    int max_v = -1, min_v = 1e9, win_c = -1;
    for (int c = 1; c <= c_cnt; c++) {
        if (!elim[c]) {
            if (tally[c] > max_v) { max_v = tally[c]; win_c = c; }
            if (tally[c] < min_v) min_v = tally[c];
        }
    }
    if (max_v * 2 > v_cnt) { *winner = win_c; return 1; }
    if (max_v == min_v) { *winner = 0; return 1; } // tie
    for (int c = 1; c <= c_cnt; c++) {
        if (tally[c] == min_v) elim[c] = 1;
    }
    return 0;
}

int main(void) {

    int v[3][5] = {{1, 2, 3}, {1, 3, 2}, {2, 1, 3}};
    int elim[10] = {0}, w;
    int done = solve_uva10142_round(3, 3, v, elim, &w);
    int ok = (done == 1 && w == 1); // 2 out of 3 votes for 1
    printf("%s: UVa 10142 - Australian Voting\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
