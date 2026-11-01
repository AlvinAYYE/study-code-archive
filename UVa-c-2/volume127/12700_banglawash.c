/*
 * ==========================================================================
 * UVa 12700 - Banglawash
 * Title-CN: 板球系列賽戰績判定
 * Difficulty: UVa Star 1
 * Tags: simulation, string
 * URL: https://onlinejudge.org/external/127/12700.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Tally match results ('B', 'W', 'T', 'A') and determine verdict: BANGLAWASH, WHITEWASH, BANGLADESH, WWW, DRAW, ABANDONED.
 *
 * [中文] 題目說明:
 *     統計板球賽事結果 (B孟加拉勝, W客隊勝, T平局, A腰斬)，輸出 BANGLAWASH (主隊橫掃全勝) 等評判結果。
 *
 * [EN] Approach:
 *     Count occurrences of B, W, T, A. Check conditions for whitewash (all matches won with no loss) and majority winners.
 * [中文] 思路:
 *     累計各比賽結果字元頻率，依題目優先序判定主隊全勝橫掃、客隊全勝、主隊勝場多、客隊勝場多、平手或全部腰斬。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

const char* solve_uva12700(int n, const char *s) {
    int b = 0, w = 0, t = 0, a = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'B') b++;
        else if (s[i] == 'W') w++;
        else if (s[i] == 'T') t++;
        else if (s[i] == 'A') a++;
    }
    if (a == n) return "ABANDONED";
    if (b > 0 && w == 0 && t == 0) return "BANGLAWASH";
    if (w > 0 && b == 0 && t == 0) return "WHITEWASH";
    if (b == w) return "DRAW";
    if (b > w) return "BANGLADESH";
    return "WWW";
}

int main(void) {

    int ok = (strcmp(solve_uva12700(2, "BB"), "BANGLAWASH") == 0) &&
             (strcmp(solve_uva12700(2, "AA"), "ABANDONED") == 0);
    printf("%s: UVa 12700 - Banglawash\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
