/*
 * ==========================================================================
 * UVa 10912 - Simple Minded Hashing
 * Title-CN: 簡單字串雜湊計數 (嚴格遞增字元DP)
 * Difficulty: Medium
 * Tags: DP, Combinatorics
 * URL: https://onlinejudge.org/external/109/10912.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count the number of strings of length L with strictly increasing alphabetical characters whose character value sum equals S.
 *
 * [中文] 題目說明:
 *     計算長度為 L 且字元嚴格遞增的字串中，所有字母序號之和（a=1..z=26）恰好等於 S 的字串數量。
 *
 * [EN] Approach:
 *     3D DP state dp[len][last_char][sum]. dp[i][c][s] = sum(dp[i-1][prev_c][s - c]) for prev_c < c.
 * [中文] 思路:
 *     三維動態規劃：dp[len][last][sum] 表示當前長度為 len、最後字母為 last、權重和為 sum 的方案數，轉移保證字母嚴格遞增。
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

int count_simple_hashes(int L, int S) {
    if (L > 26 || S > 351) return 0;
    int dp[27][27][355] = {0};
    dp[0][0][0] = 1;
    for (int i = 0; i < L; i++) {
        for (int c = 0; c <= 26; c++) {
            for (int s = 0; s <= S; s++) {
                if (dp[i][c][s] == 0) continue;
                for (int nxt = c + 1; nxt <= 26; nxt++) {
                    if (s + nxt <= S) {
                        dp[i + 1][nxt][s + nxt] += dp[i][c][s];
                    }
                }
            }
        }
    }
    int total = 0;
    for (int c = 1; c <= 26; c++) total += dp[L][c][S];
    return total;
}

int main(void) {

    int ok = (count_simple_hashes(1, 3) == 1) && (count_simple_hashes(2, 3) == 1); // 'c' (3), 'ab' (1+2=3)
    printf("%s: UVa 10912 - Simple Minded Hashing\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
