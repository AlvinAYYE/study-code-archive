/*
 * ==========================================================================
 * UVa 11734 - Big Number of Teams will Solve This
 * Title-CN: 評測系統空格格式錯誤判別
 * Difficulty: UVa Star 1
 * Tags: string
 * URL: https://onlinejudge.org/external/117/11734.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Compare team submission with judge output: Yes if identical; Output Format Error if identical after removing all spaces; else Wrong Answer.
 *
 * [中文] 題目概述:
 *     比對參賽者輸出與裁判標準輸出：完全相同為 Yes；若去除所有空格後相同則為 Output Format Error；否則為 Wrong Answer。
 *
 * [EN] Approach:
 *     Check exact strcmp. If not equal, strip all spaces from both strings and compare.
 * [中文] 解題思路:
 *     先以 strcmp 比較完全相等；若不相等則分別去除所有空格字元再行比較，相等判定為格式錯誤，否則為解答錯誤。
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

int solve_uva11734(const char *team, const char *judge) {
    if (strcmp(team, judge) == 0) return 1; // Yes
    char t1[50], t2[50];
    int idx1 = 0, idx2 = 0;
    for (int i = 0; team[i]; i++) if (team[i] != ' ') t1[idx1++] = team[i];
    t1[idx1] = '\0';
    for (int i = 0; judge[i]; i++) if (judge[i] != ' ') t2[idx2++] = judge[i];
    t2[idx2] = '\0';
    if (strcmp(t1, t2) == 0) return 2; // Output Format Error
    return 3; // Wrong Answer
}

int main(void) {

    int ok = (solve_uva11734("1 2", "1 2") == 1 &&
              solve_uva11734("12", "1 2") == 2 &&
              solve_uva11734("13", "1 2") == 3);
    printf("%s: UVa 11734 - Big Number of Teams will Solve This\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
