/*
 * ==========================================================================
 * UVa 11385 - Da Vinci Code
 * Title-CN: 達文西密碼 (費氏數列下標解密)
 * Difficulty: Easy
 * Tags: Math, Fibonacci, String
 * URL: https://onlinejudge.org/external/113/11385.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given Fibonacci numbers and an encrypted uppercase string, place each character into the 1-based output string at position corresponding to the index of its Fibonacci number.
 *
 * [中文] 題目說明:
 *     給定一組費氏數列與大寫英文字串，將各字母放入以其費氏數列項數為下標的輸出字串中，其餘位置填空格。
 *
 * [EN] Approach:
 *     Precompute first 45 Fibonacci numbers. Map given Fibonacci values to their indices, and place corresponding letters into output array.
 * [中文] 思路:
 *     預先計算前 45 項費氏數列建立數值到項數索引的映射，將字母填入對應下標位置，末尾空白截斷。
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

void da_vinci_decode(int n, const long long *fib_nums, const char *text, char *out) {
    long long f[50];
    f[1] = 1; f[2] = 2;
    for (int i = 3; i < 45; i++) f[i] = f[i-1] + f[i-2];
    char letters[100];
    int l_cnt = 0;
    for (int i = 0; text[i]; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') letters[l_cnt++] = text[i];
    }
    for (int i = 0; i < 100; i++) out[i] = ' ';
    int max_idx = 0;
    for (int i = 0; i < n && i < l_cnt; i++) {
        int idx = 0;
        for (int j = 1; j < 45; j++) if (f[j] == fib_nums[i]) { idx = j; break; }
        if (idx > 0) {
            out[idx - 1] = letters[i];
            if (idx > max_idx) max_idx = idx;
        }
    }
    out[max_idx] = '\0';
}

int main(void) {

    long long fn[] = {13, 2, 89, 3, 5};
    char out[100];
    da_vinci_decode(5, fn, "OPA KLMNO", out);
    int ok = (out[0] == 'P' || out[1] == 'P');
    printf("%s: UVa 11385 - Da Vinci Code\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
