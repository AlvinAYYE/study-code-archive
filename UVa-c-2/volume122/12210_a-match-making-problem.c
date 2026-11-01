/*
 * ==========================================================================
 * UVa 12210 - A Match Making Problem
 * Title-CN: 相親配對問題
 * Difficulty: Easy
 * Tags: Greedy, Sorting
 * URL: https://onlinejudge.org/external/122/12210.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given B bachelors and S spinsters with ages, match each bachelor with the spinster closest in age. If bachelors remain, report count and youngest age.
 *
 * [中文] 題目說明:
 *     B 位單身漢與 S 位單身女子相親，每位單身漢配對年齡最相近的女性。若有單身漢剩餘，輸出剩餘人數與最年輕者的年齡。
 *
 * [EN] Approach:
 *     If B <= S, all bachelors can be matched (0 left). If B > S, remaining count is B - S, and the youngest bachelor is always unmatched.
 * [中文] 思路:
 *     若 B <= S 則所有人皆可配對（剩餘 0 人）；若 B > S 則必定剩餘 B - S 人，且剩餘者中必包含最年輕的單身漢。
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

void match_making(int b, const int *bachelors, int s, int *leftover, int *youngest) {
    if (b <= s) {
        *leftover = 0;
        *youngest = 0;
    } else {
        *leftover = b - s;
        int mn = 1000;
        for (int i = 0; i < b; i++) if (bachelors[i] < mn) mn = bachelors[i];
        *youngest = mn;
    }
}

int main(void) {

    int b[] = {25, 30};
    int rem, yng;
    match_making(2, b, 1, &rem, &yng);
    int ok = (rem == 1 && yng == 25);
    printf("%s: UVa 12210 - A Match Making Problem\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
