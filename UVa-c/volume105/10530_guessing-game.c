/*
 * ==========================================================================
 * UVa 10530 - Guessing Game
 * Title-CN: 猜數字作弊檢測 (區間收縮一致性)
 * Difficulty: UVa Star 1
 * Tags: simulation, intervals
 * URL: https://onlinejudge.org/external/105/10530.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine if Stan is dishonest during guessing game given sequence of guesses and responses (too high, too low, right on).
 *
 * [中文] 題目說明:
 *     猜 1 到 10 的數字：依據 'too high'、'too low' 與最終 'right on' 回應，判定回答者是否誠實無矛盾。
 *
 * [EN] Approach:
 *     Maintain valid range [low, high] initialized to [1, 10]. 'too high' sets high = min(high, g - 1); 'too low' sets low = max(low, g + 1). Check final guess in [low, high].
 * [中文] 思路:
 *     維護合法解區間 [low, high]。太高縮小上限，太低提高下限，最終猜中數字必須落在該區間內，否則判定說謊。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva10530(int final_guess, int low, int high) {
    return (final_guess >= low && final_guess <= high);
}

int main(void) {

    int ok = solve_uva10530(5, 4, 7) && !solve_uva10530(5, 6, 7);
    printf("%s: UVa 10530 - Guessing Game\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
