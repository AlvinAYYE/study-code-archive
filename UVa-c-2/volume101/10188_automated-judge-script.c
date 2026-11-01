/*
 * ==========================================================================
 * UVa 10188 - Automated Judge Script
 * Title-CN: 自動評判系統狀態判定 (AC, PE, WA)
 * Difficulty: UVa Star 1
 * Tags: string, simulation
 * URL: https://onlinejudge.org/external/101/10188.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Compare standard output and team output: Accepted if exact match, Presentation Error if only numeric characters match, else Wrong Answer.
 *
 * [中文] 題目說明:
 *     評判程式輸出：若完全吻合輸出 Accepted；若僅字串中抽取出的數字完全相同輸出 Presentation Error；否則輸出 Wrong Answer。
 *
 * [EN] Approach:
 *     First strcmp full text. If mismatch, extract only digit characters and compare digit strings.
 * [中文] 思路:
 *     先比對完整字串是否完全相等；若不符則過濾抽出雙方所有數字字元比對，數字相同即為 PE，否則為 WA。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva10188(const char *s1, const char *s2) {
    if (strcmp(s1, s2) == 0) return 1; /* AC */
    char d1[500], d2[500];
    int p1 = 0, p2 = 0;
    for (int i = 0; s1[i]; i++) if (s1[i] >= '0' && s1[i] <= '9') d1[p1++] = s1[i];
    d1[p1] = '\0';
    for (int i = 0; s2[i]; i++) if (s2[i] >= '0' && s2[i] <= '9') d2[p2++] = s2[i];
    d2[p2] = '\0';
    if (strcmp(d1, d2) == 0) return 2; /* PE */
    return 3; /* WA */
}

int main(void) {

    int ok = (solve_uva10188("Run 1", "Run 1") == 1) &&
             (solve_uva10188("Run 1", "Run   1") == 2) &&
             (solve_uva10188("Run 1", "Run 2") == 3);
    printf("%s: UVa 10188 - Automated Judge Script\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
