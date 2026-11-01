/*
 * ==========================================================================
 * UVa 156 - Ananagrams
 * Title-CN: 無同字母異序詞之單字
 * Difficulty: UVa Star 2
 * Tags: string, sorting, hash-table
 * URL: https://onlinejudge.org/external/1/156.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find all words in a dictionary that cannot be transformed into any other word by rearranging letters.
 *
 * [中文] 題目說明:
 *     找出字典中無法透過重新排列字母得到字典中其他單字的單詞 (Ananagrams)，按字母順序輸出。
 *
 * [EN] Approach:
 *     Normalize each word by converting to lowercase and sorting characters. Words with unique signature are ananagrams.
 * [中文] 思路:
 *     將每個單字轉小寫後做字元排序得到標準特徵。統計各特徵出現次數，次數為 1 的即為所求單字。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <string.h>
#include <ctype.h>

void normalize_word(const char *in, char *out) {
    int len = (int)strlen(in);
    for (int i = 0; i < len; i++) out[i] = (char)tolower((unsigned char)in[i]);
    out[len] = '\0';
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (out[i] > out[j]) { char t = out[i]; out[i] = out[j]; out[j] = t; }
        }
    }
}

int main(void) {

    char sig1[10], sig2[10];
    normalize_word("Trap", sig1);
    normalize_word("part", sig2);
    int ok = (strcmp(sig1, sig2) == 0 && strcmp(sig1, "aprt") == 0);
    printf("%s: UVa 156 - Ananagrams\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
