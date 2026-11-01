/*
 * ==========================================================================
 * UVa 11173 - Grey Codes
 * Title-CN: 格雷碼
 * Difficulty: Easy
 * Tags: Bit Manipulation, Gray Code
 * URL: https://onlinejudge.org/external/111/11173.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the k-th entry in an n-bit binary reflected Gray code sequence.
 *
 * [中文] 題目說明:
 *     求 n 位二進位反射格雷碼序列中的第 k 個數值。
 *
 * [EN] Approach:
 *     Standard Gray code conversion formula: G(k) = k ^ (k >> 1).
 * [中文] 思路:
 *     利用二進位格雷碼轉換公式直接求得：G(k) = k ^ (k >> 1)。
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

unsigned int gray_code(unsigned int k) {
    return k ^ (k >> 1);
}

int main(void) {

    int ok = (gray_code(0) == 0) && (gray_code(1) == 1) && (gray_code(2) == 3) && (gray_code(3) == 2);
    printf("%s: UVa 11173 - Grey Codes\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
