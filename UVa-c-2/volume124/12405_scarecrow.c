/*
 * ==========================================================================
 * UVa 12405 - Scarecrow
 * Title-CN: 稻草人農田覆蓋貪婪佈置
 * Difficulty: UVa Star 1
 * Tags: greedy
 * URL: https://onlinejudge.org/external/124/12405.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given a field string of '.' (crops) and '#' (infertility), place minimum scarecrows (each covers i-1, i, i+1) to protect all crops.
 *
 * [中文] 題目說明:
 *     給定由農作物 '.' 與貧瘠土地 '#' 組成的農田，每個稻草人可覆蓋其自身及左右各一格，求保護所有農作物所需的最少稻草人數目。
 *
 * [EN] Approach:
 *     Greedy scan from left to right: upon encountering a '.', place a scarecrow at i + 1 (covering i, i+1, i+2) and advance index by 3.
 * [中文] 思路:
 *     貪婪法從左至右掃描：遇到未覆蓋的農作物 '.'，在 i+1 處放置稻草人並一口氣跳過 3 格 (i+3)。
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

int solve_uva12405(int n, const char *field) {
    int count = 0;
    for (int i = 0; i < n; ) {
        if (field[i] == '.') {
            count++;
            i += 3;
        } else {
            i++;
        }
    }
    return count;
}

int main(void) {

    int ans = solve_uva12405(3, ".#.");
    int ok = (ans == 1);
    printf("%s: UVa 12405 - Scarecrow\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
