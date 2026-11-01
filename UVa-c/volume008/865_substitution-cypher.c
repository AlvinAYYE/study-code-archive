/*
 * ==========================================================================
 * UVa 865 - Substitution Cypher
 * Title-CN: 單表替換式密碼轉換
 * Difficulty: UVa Star 1
 * Tags: string, simulation
 * URL: https://onlinejudge.org/external/8/865.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Decode text using custom substitution alphabet mapping.
 *
 * [中文] 題目說明:
 *     給定明文字母表與密文字母表，建立單字元對應映射表進行全文替換解密。
 *
 * [EN] Approach:
 *     Construct direct 256-entry ASCII mapping table. Unmapped characters map to themselves.
 * [中文] 思路:
 *     建立大小為 256 的 ASCII 查找陣列，將明文字元映射至密文字元，未出現的字元保持原樣。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void build_cypher_865(const char *plain, const char *cipher, char table[256]) {
    for (int i = 0; i < 256; i++) table[i] = (char)i;
    for (int i = 0; plain[i] && cipher[i]; i++) {
        table[(unsigned char)plain[i]] = cipher[i];
    }
}

int main(void) {

    char tbl[256];
    build_cypher_865("abc", "xyz", tbl);
    int ok = (tbl['a'] == 'x' && tbl['b'] == 'y' && tbl['d'] == 'd');
    printf("%s: UVa 865 - Substitution Cypher\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
