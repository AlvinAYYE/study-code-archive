/*
 * ==========================================================================
 * UVa 12289 - One-Two-Three
 * Title-CN: 辨識被塗抹的數字單字 (one, two, three)
 * Difficulty: UVa Star 1
 * Tags: string
 * URL: https://onlinejudge.org/external/122/12289.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Identify number word (one, two, three) where at most one letter is incorrectly recognized.
 *
 * [中文] 題目說明:
 *     幼童寫下的數字英文單字 (one, two, three) 最多有一個字母被寫錯，辨識其原本所代表的數字 1, 2, 3。
 *
 * [EN] Approach:
 *     If length is 5, it must be 'three' (3). If length is 3, count matching characters with 'one'; if >= 2 it's 1, else 2.
 * [中文] 思路:
 *     長度為 5 必為 3。長度為 3 則比對與 "one" 相同的字元數：若 >= 2 則為 1，否則為 2。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva12289(const char *s) {
    int len = (int)strlen(s);
    if (len == 5) return 3;
    int match_one = (s[0] == 'o') + (s[1] == 'n') + (s[2] == 'e');
    return (match_one >= 2) ? 1 : 2;
}

int main(void) {

    int ok = (solve_uva12289("owe") == 1) && (solve_uva12289("two") == 2) && (solve_uva12289("thtee") == 3);
    printf("%s: UVa 12289 - One-Two-Three\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
