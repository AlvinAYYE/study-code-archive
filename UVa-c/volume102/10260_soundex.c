/*
 * ==========================================================================
 * UVa 10260 - Soundex
 * Title-CN: 語音編碼 Soundex 演算法
 * Difficulty: UVa Star 1
 * Tags: string, simulation
 * URL: https://onlinejudge.org/external/102/10260.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Encode words using Soundex phonetic algorithm: map letters to digits 1..6, drop adjacent duplicate codes and vowels.
 *
 * [中文] 題目說明:
 *     模擬 Soundex 語音編碼：將字母映射至 1-6 數字編碼，相鄰相同編碼只保留一次，忽略母音與特殊字母。
 *
 * [EN] Approach:
 *     Direct character code mapping. Emit digit only if it is non-zero and differs from immediately preceding character's code.
 * [中文] 思路:
 *     依題目查表將字母映射為 0-6。遍歷字串，僅當字元編碼大於 0 且不等於前一字元編碼時輸出該數字。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static const char soundex_map[26] = {
    0, 1, 2, 3, 0, 1, 2, 0, 0, 2, 2, 4, 5, 5, 0, 1, 2, 6, 2, 3, 0, 1, 0, 2, 0, 2
};

void solve_uva10260(const char *in, char *out) {
    int idx = 0;
    int last_code = 0;
    for (int i = 0; in[i]; i++) {
        int code = soundex_map[in[i] - 'A'];
        if (code != 0 && code != last_code) {
            out[idx++] = code + '0';
        }
        last_code = code;
    }
    out[idx] = '\0';
}

int main(void) {

    char out[20];
    solve_uva10260("KHAWN", out);
    int ok = (strcmp(out, "25") == 0);
    printf("%s: UVa 10260 - Soundex\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
