/*
 * ==========================================================================
 * UVa 644 - Immediate Decodability
 * Title-CN: 前綴碼即時可譯性檢測 (Trie / Prefix Code)
 * Difficulty: UVa Star 1
 * Tags: string, trie, prefix-code
 * URL: https://onlinejudge.org/external/6/644.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine if a set of binary codes is immediately decodable (no code word is a prefix of any other code word).
 *
 * [中文] 題目說明:
 *     判定二進位編碼集合是否具備即時可譯性 (即任何編碼皆不可為其他編碼的前綴，前綴碼判定)。
 *
 * [EN] Approach:
 *     Pairwise prefix check: for each pair (i, j), check if strncmp(c[i], c[j], len) == 0.
 * [中文] 思路:
 *     兩兩比對字串前綴：若存在某編碼為另一編碼的開頭前綴，則判定不具即時可譯性。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva644(int n, char codes[][15]) {
    for (int i = 0; i < n; i++) {
        int li = (int)strlen(codes[i]);
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            int lj = (int)strlen(codes[j]);
            if (li <= lj && strncmp(codes[i], codes[j], li) == 0) return 0; /* Prefix collision */
        }
    }
    return 1;
}

int main(void) {

    char c1[3][15] = {"01", "10", "0010"};
    char c2[3][15] = {"01", "10", "010"};
    int ok = solve_uva644(3, c1) && !solve_uva644(3, c2);
    printf("%s: UVa 644 - Immediate Decodability\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
