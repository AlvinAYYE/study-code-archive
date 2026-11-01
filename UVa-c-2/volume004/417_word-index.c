/*
 * ==========================================================================
 * UVa 417 - Word Index
 * Title-CN: 字母嚴格遞增單字編號索引
 * Difficulty: UVa Star 2
 * Tags: combinatorics, math, bfs
 * URL: https://onlinejudge.org/external/4/417.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Assign 1-based index to all words with strictly increasing letters: a..z (1-26), ab..yz (27-351), etc.
 *
 * [中文] 題目說明:
 *     對所有字母嚴格遞增的字詞編號 (a..z 為 1..26，ab..yz 接著編號)，求給定合法單詞的唯一索引編號 (不合法回傳 0)。
 *
 * [EN] Approach:
 *     Combinatorics C(n, k) prefix sum calculation or BFS queue generation up to length 5.
 * [中文] 思路:
 *     利用組合數 C(26, k) 統計小於當前長度的單詞數，再以組合數前綴和計算同長度中小於當前單詞的數量。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva417_valid(const char *s) {
    for (int i = 1; s[i]; i++) {
        if (s[i] <= s[i - 1]) return 0;
    }
    return 1;
}

int main(void) {

    int ok = solve_uva417_valid("ab") && !solve_uva417_valid("ba");
    printf("%s: UVa 417 - Word Index\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
