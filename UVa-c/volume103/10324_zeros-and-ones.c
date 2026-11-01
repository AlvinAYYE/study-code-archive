/*
 * ==========================================================================
 * UVa 10324 - Zeros and Ones
 * Title-CN: 0與1區間一致性查詢
 * Difficulty: UVa Star 1
 * Tags: string, prefix-sum
 * URL: https://onlinejudge.org/external/103/10324.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine whether all characters in string between indices min(i, j) and max(i, j) are identical.
 *
 * [中文] 題目說明:
 *     給定由 '0' 與 '1' 組成的字串，多次查詢區間 [min(i, j), max(i, j)] 內的所有字元是否完全相同。
 *
 * [EN] Approach:
 *     Precompute prefix sum of differences or run-length encoding IDs. Check id[i] == id[j] in O(1).
 * [中文] 思路:
 *     預先計算同字元區塊編號 id 陣列：若兩下標所屬區塊編號相同，代表區間內字元完全一致，O(1) 回答每次查詢。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void init_uva10324(const char *s, int *id, int len) {
    id[0] = 0;
    for (int i = 1; i < len; i++) {
        id[i] = (s[i] == s[i - 1]) ? id[i - 1] : id[i - 1] + 1;
    }
}

int main(void) {

    int id[10];
    init_uva10324("0000011", id, 7);
    int ok = (id[0] == id[4]) && (id[0] != id[5]);
    printf("%s: UVa 10324 - Zeros and Ones\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
