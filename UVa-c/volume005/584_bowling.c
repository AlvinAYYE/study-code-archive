/*
 * ==========================================================================
 * UVa 584 - Bowling
 * Title-CN: 保齡球計分系統模擬
 * Difficulty: Medium
 * Tags: Simulation, Rule-based
 * URL: https://onlinejudge.org/external/5/584.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Calculate total bowling score from a roll sequence with strikes ('X'), spares ('/'), and numeric pinfall counts.
 *
 * [中文] 題目說明:
 *     依據標準保齡球 10 格規則計算全中 ('X')、補中 ('/') 與一般擲球的總得分。
 *
 * [EN] Approach:
 *     Parse sequence into individual roll pinfall values. For each of the first 10 frames: add frame score, add next 2 rolls if strike, add next 1 roll if spare.
 * [中文] 思路:
 *     將擊球序列轉為每次擊倒瓶數數組。計算前 10 格分數：Strike 加後兩次投球分，Spare 加後一次投球分，其餘為兩球相加。
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

int bowling_score(const char *rolls) {
    int pins[30], p_cnt = 0;
    for (int i = 0; rolls[i]; i++) {
        if (rolls[i] == ' ') continue;
        if (rolls[i] == 'X') pins[p_cnt++] = 10;
        else if (rolls[i] == '/') pins[p_cnt++] = 10 - pins[p_cnt - 1];
        else pins[p_cnt++] = rolls[i] - '0';
    }
    int total = 0, p = 0;
    for (int frame = 0; frame < 10; frame++) {
        if (pins[p] == 10) { // strike
            total += 10 + pins[p + 1] + pins[p + 2];
            p++;
        } else if (pins[p] + pins[p + 1] == 10) { // spare
            total += 10 + pins[p + 2];
            p += 2;
        } else {
            total += pins[p] + pins[p + 1];
            p += 2;
        }
    }
    return total;
}

int main(void) {

    // 12 strikes = perfect game 300
    int ok = (bowling_score("X X X X X X X X X X X X") == 300);
    printf("%s: UVa 584 - Bowling\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
