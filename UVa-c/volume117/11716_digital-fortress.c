/*
 * ==========================================================================
 * UVa 11716 - Digital Fortress
 * Title-CN: 數位堡壘矩陣轉置解密
 * Difficulty: UVa Star 1
 * Tags: string, math
 * URL: https://onlinejudge.org/external/117/11716.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given ciphertext of length L, if L is a perfect square K*K, decode by reading the K x K matrix column by column; otherwise output INVALID.
 *
 * [中文] 題目說明:
 *     給定長度為 L 的密文字串，若 L 為完全平方數 K*K，則依縱行優先 (轉置) 還原出原始明文字串；否則判定為 INVALID。
 *
 * [EN] Approach:
 *     Check if integer root K = round(sqrt(L)) satisfies K * K == L. Read row-major matrix in column-major order.
 * [中文] 思路:
 *     驗證 L 是否為完全平方數 K^2，若是則將字串填入 K x K 矩陣，並以雙重迴圈逐行 (先列後欄) 讀取輸出解密字串。
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

int solve_uva11716(const char *cipher, char *plain) {
    int len = strlen(cipher);
    int k = (int)(sqrt(len) + 0.5);
    if (k * k != len) return 0; // INVALID
    int idx = 0;
    for (int c = 0; c < k; c++) {
        for (int r = 0; r < k; r++) {
            plain[idx++] = cipher[r * k + c];
        }
    }
    plain[idx] = '\0';
    return 1;
}

int main(void) {

    char p[100];
    int ok = solve_uva11716("WECRLTEERDSOEEFEA", p);
    ok = ok && (strlen(p) == 0 || ok); // non-square (len 17) -> 0
    int ok2 = solve_uva11716("142536", p); // non-square (len 6) -> 0
    int ok3 = solve_uva11716("1324", p); // square (len 4, k=2) -> "1234"
    ok = ok3 && (strcmp(p, "1234") == 0);
    printf("%s: UVa 11716 - Digital Fortress\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
