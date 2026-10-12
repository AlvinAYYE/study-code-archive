/*
 * ==========================================================================
 * UVa 12289 - One-Two-Three
 * Title-CN: 一二三
 * Difficulty: UVa Star 1
 * Tags: string
 * ==========================================================================
 * [EN] Problem: Identify 'one', 'two', or 'three' with at most 1 typo.
 * [中文] 題目說明: 容錯比對單字對應的數值 1, 2, 3。
 * [EN] Approach: Length 5 is 3. Length 3 compare mismatch count with "one".
 * [中文] 思路: 長度為 5 必為 3；長度為 3 若與 "one" 不匹配數 <= 1 則為 1，否則為 2。
 * ==========================================================================
 */
#include <stdio.h>
#include <string.h>

int solve_uva12289(const char *s) {
    if (strlen(s) == 5) return 3;
    int diff_one = (s[0] != 'o') + (s[1] != 'n') + (s[2] != 'e');
    return (diff_one <= 1) ? 1 : 2;
}

int main(void) {
    int ok = (solve_uva12289("owe") == 1) && (solve_uva12289("too") == 2) && (solve_uva12289("theee") == 3);
    printf("%s: UVa 12289 - One-Two-Three\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
