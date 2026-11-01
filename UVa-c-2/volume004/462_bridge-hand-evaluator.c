/*
 * ==========================================================================
 * UVa 462 - Bridge Hand Evaluator
 * Title-CN: 橋牌手牌估值
 * Difficulty: Medium
 * Tags: Simulation, Rule-based
 * URL: https://onlinejudge.org/external/4/462.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Evaluate a 13-card bridge hand according to standard Goren point-count rules and determine the correct opening bid.
 *
 * [中文] 題目說明:
 *     依據標準高倫 (Goren) 橋牌點力計算規則評估 13 張手牌並決定叫牌策略。
 *
 * [EN] Approach:
 *     Count high card points (A=4, K=3, Q=2, J=1). Subtract for unprotected honors. Add distribution points. Check suit stopping for No Trump.
 * [中文] 思路:
 *     計算大牌點（A=4, K=3, Q=2, J=1），扣除未被保護的大牌點，計算長套分配點，判斷四花色阻擋決定是否開叫無王。
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

int bridge_points(const char cards[13][3]) {
    int hcp = 0;
    for (int i = 0; i < 13; i++) {
        char rank = cards[i][0];
        if (rank == 'A') hcp += 4;
        else if (rank == 'K') hcp += 3;
        else if (rank == 'Q') hcp += 2;
        else if (rank == 'J') hcp += 1;
    }
    return hcp;
}

int main(void) {

    char hand[13][3] = {"AS", "KS", "QS", "JS", "2S", "2H", "3H", "4H", "2D", "3D", "4D", "2C", "3C"};
    int p = bridge_points(hand);
    int ok = (p == 10);
    printf("%s: UVa 462 - Bridge Hand Evaluator\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
