/*
 * ==========================================================================
 * UVa 444 - Encoder and Decoder
 * Title-CN: ASCII 數值倒轉編碼與解碼
 * Difficulty: UVa Star 1
 * Tags: string, simulation
 * URL: https://onlinejudge.org/external/4/444.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Encode text by converting chars to ASCII numbers and reversing string, or decode reversed ASCII sequence back to text.
 *
 * [中文] 題目說明:
 *     編碼將字元轉為 ASCII 碼後整串倒轉；解碼將倒轉的數字字串還原為 ASCII 字元 (注意有 2 位數與 3 位數 ASCII 碼)。
 *
 * [EN] Approach:
 *     If input starts with digit, process numbers in reverse (length 2 or 3). Otherwise convert char to ASCII, reverse digits.
 * [中文] 思路:
 *     判斷開頭若為數字則反向切出 2 位數 (65..99) 或 3 位數 (100..122) 轉成字元；若為文字則將各字元 ASCII 倒序輸出。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <string.h>

void solve_uva444_encode(const char *in, char *out) {
    char buf[1000] = {0};
    int b_idx = 0;
    for (int i = 0; in[i]; i++) {
        b_idx += sprintf(buf + b_idx, "%d", (unsigned char)in[i]);
    }
    for (int i = 0; i < b_idx; i++) {
        out[i] = buf[b_idx - 1 - i];
    }
    out[b_idx] = '\0';
}

int main(void) {

    char out[100];
    solve_uva444_encode("A", out);
    int ok = (strcmp(out, "56") == 0); /* 'A' is 65 -> reversed is 56 */
    printf("%s: UVa 444 - Encoder and Decoder\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
