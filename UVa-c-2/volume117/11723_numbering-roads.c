/*
 * ==========================================================================
 * UVa 11723 - Numbering Roads
 * Title-CN: 道路門牌後綴英文字母指派
 * Difficulty: UVa Star 1
 * Tags: math
 * URL: https://onlinejudge.org/external/117/11723.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given R roads and N base numbers with 26 letters (A-Z) available as suffixes, find minimum letters needed (0 to 26), or report impossible.
 *
 * [中文] 題目說明:
 *     給定 R 條道路與 N 個基本整數編號，可搭配 26 個英文字母 (A-Z) 作為後綴，求最少需要動用幾個英文字母，若超過 26 則無解。
 *
 * [EN] Approach:
 *     Number of suffixes needed = ceil((R - N) / N) = (R - 1) / N. If > 26 return -1.
 * [中文] 思路:
 *     除了 N 個純整數外，其餘道路需後綴字母，計算 (R - 1) / N，若 <= 26 回傳該整數，否則判定無解回傳 -1。
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

int solve_uva11723(int r, int n) {
    int suffixes = (r - 1) / n;
    return (suffixes <= 26) ? suffixes : -1;
}

int main(void) {

    int ok = (solve_uva11723(8, 5) == 1 && solve_uva11723(100, 2) == -1);
    printf("%s: UVa 11723 - Numbering Roads\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
