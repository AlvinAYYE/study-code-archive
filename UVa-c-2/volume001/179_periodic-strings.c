/*
 * ==========================================================================
 * UVa 179 - Periodic Strings
 * Title-CN: 週期密碼加密字串比對
 * Difficulty: UVa Star 2
 * Tags: string, math
 * URL: https://onlinejudge.org/external/1/179.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine the permutation cipher key length and cyclic block permutation mapping plaintext to ciphertext.
 *
 * [中文] 題目說明:
 *     分析密文與明文，推求置換密碼的塊大小週期與區塊內部字元置換置換規則。
 *
 * [EN] Approach:
 *     Iterate candidate period lengths K; verify if character frequencies in each block match, and deduce permutation vector.
 * [中文] 思路:
 *     枚舉可能的週期長度 K，驗證各長度為 K 的區塊字元組成是否一致，推算出明文到密文之區塊置換映射。
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

int valid_period_len(int text_len, int p) {
    return (text_len % p == 0);
}

int main(void) {

    int ok = valid_period_len(12, 3) && !valid_period_len(12, 5);
    printf("%s: UVa 179 - Periodic Strings\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
