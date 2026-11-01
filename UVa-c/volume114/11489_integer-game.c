/*
 * ==========================================================================
 * UVa 11489 - Integer Game
 * Title-CN: 整數博弈 (數位和與模3分析)
 * Difficulty: Easy
 * Tags: Game Theory, Math
 * URL: https://onlinejudge.org/external/114/11489.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Two players take turns removing a digit such that the remaining sum of digits is divisible by 3. First unable to move loses.
 *
 * [中文] 題目說明:
 *     兩人輪流從大整數中拿走一個數位，使剩下所有數位之和能被 3 整除，無法操作者輸，判定先手 S 是否獲勝。
 *
 * [EN] Approach:
 *     Let total sum mod 3 be R. If R == 0: player can only pick a multiple of 3 (each pick keeps sum % 3 == 0). Number of 3-multiples determines win/loss parity. If R != 0: player must pick a digit == R mod 3, leaving R=0.
 * [中文] 思路:
 *     數位總和模 3 為 R。若 R=0，只能取 3 的倍數，取 3 的倍數個數的奇偶性決定勝負；若 R!=0，先手必須且只能取走一個模 3 等於 R 的數使局面變為 R=0。
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

bool first_player_wins_integer_game(const char *num) {
    int count[3] = {0}, sum = 0;
    for (int i = 0; num[i]; i++) {
        int d = num[i] - '0';
        count[d % 3]++;
        sum += d;
    }
    int r = sum % 3;
    if (r == 0) {
        return (count[0] % 2 == 1);
    } else {
        if (count[r] > 0) {
            return (count[0] % 2 == 0); // after taking r, remaining count[0] turns follow
        } else {
            return false; // cannot make first move
        }
    }
}

int main(void) {

    int ok = first_player_wins_integer_game("333") && !first_player_wins_integer_game("33");
    printf("%s: UVa 11489 - Integer Game\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
