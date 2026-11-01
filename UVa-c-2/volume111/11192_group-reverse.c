/*
 * ==========================================================================
 * UVa 11192 - Group Reverse
 * Title-CN: 分組字串原地翻轉
 * Difficulty: UVa Star 1
 * Tags: string, simulation
 * URL: https://onlinejudge.org/external/111/11192.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given string and number of groups G, reverse characters in each group of length len/G.
 *
 * [中文] 題目說明:
 *     將長度為 L 的字串平均分為 G 組 (每組長度 L/G)，將每組內部的字元各自原地反轉。
 *
 * [EN] Approach:
 *     Group length k = L / G. For each group from start i = 0, k, 2k..., reverse slice [i, i + k - 1].
 * [中文] 思路:
 *     計算每組長度 k = strlen(s) / G。以步長 k 巡訪各分組起點，對 [i, i+k-1] 區間實施雙向對調翻轉。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void solve_uva11192(int g, char *s) {
    int len = (int)strlen(s);
    int k = len / g;
    for (int i = 0; i < len; i += k) {
        int l = i, r = i + k - 1;
        while (l < r) {
            char t = s[l]; s[l] = s[r]; s[r] = t;
            l++; r--;
        }
    }
}

int main(void) {

    char s[20] = "TOOR";
    solve_uva11192(2, s); /* Group size 2: TO -> OT, OR -> RO => OTRO */
    int ok = (strcmp(s, "OTRO") == 0);
    printf("%s: UVa 11192 - Group Reverse\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
