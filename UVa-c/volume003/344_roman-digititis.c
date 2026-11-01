/*
 * ==========================================================================
 * UVa 344 - Roman Digititis
 * Title-CN: 羅馬數字字母頻率統計
 * Difficulty: UVa Star 1
 * Tags: simulation, string, math
 * URL: https://onlinejudge.org/external/3/344.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count cumulative total occurrences of i, v, x, l, c across all page numbers 1 through N written in Roman numerals.
 *
 * [中文] 題目說明:
 *     統計 1 到 N 所有頁碼寫成羅馬數字時，字母 i, v, x, l, c 累計出現的總次數 (N <= 100)。
 *
 * [EN] Approach:
 *     Convert integer to Roman numeral by greedy subtraction of standard values, then tally character frequencies.
 * [中文] 思路:
 *     將整數依貪婪減法規則轉為羅馬數字字串，統計每個數的字元個數並建立前綴和陣列以快速回答。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void solve_uva344(int n, int *out_i, int *out_v, int *out_x, int *out_l, int *out_c) {
    int cnt_i = 0, cnt_v = 0, cnt_x = 0, cnt_l = 0, cnt_c = 0;
    int val[13] = {100, 90, 50, 40, 10, 9, 5, 4, 1};
    const char *sym[13] = {"c", "xc", "l", "xl", "x", "ix", "v", "iv", "i"};
    for (int k = 1; k <= n; k++) {
        int cur = k;
        for (int idx = 0; idx < 9; idx++) {
            while (cur >= val[idx]) {
                for (int p = 0; sym[idx][p]; p++) {
                    if (sym[idx][p] == 'i') cnt_i++;
                    else if (sym[idx][p] == 'v') cnt_v++;
                    else if (sym[idx][p] == 'x') cnt_x++;
                    else if (sym[idx][p] == 'l') cnt_l++;
                    else if (sym[idx][p] == 'c') cnt_c++;
                }
                cur -= val[idx];
            }
        }
    }
    *out_i = cnt_i; *out_v = cnt_v; *out_x = cnt_x; *out_l = cnt_l; *out_c = cnt_c;
}

int main(void) {

    int i, v, x, l, c;
    solve_uva344(5, &i, &v, &x, &l, &c);
    int ok = (i == 7 && v == 2 && x == 0);
    printf("%s: UVa 344 - Roman Digititis\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
