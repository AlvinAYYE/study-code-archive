/*
 * ==========================================================================
 * UVa 740 - Baudot Data Communication Code
 * Title-CN: 博多通信電碼解碼 (移位鍵模擬)
 * Difficulty: Easy
 * Tags: Simulation, String
 * URL: https://onlinejudge.org/external/7/740.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Decode 5-bit Baudot teleprinter characters with downshift (lowercase/letters) and upshift (figures/symbols) mode switches.
 *
 * [中文] 題目說明:
 *     解碼 5 位元博多電碼：具有字母下檔 (Down-shift) 與符號上檔 (Up-shift) 模式切換碼。
 *
 * [EN] Approach:
 *     Maintain shift state: downshift (0) vs upshift (1). Code 27 switches to downshift, code 31 switches to upshift. Map other codes directly.
 * [中文] 思路:
 *     維護當前上下檔狀態（代碼 27 切換下檔，代碼 31 切換上檔），依 5 位元二進位整數查表轉換為字元。
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

void decode_baudot(const char *down_table, const char *up_table, const char *stream, char *out) {
    int mode = 0; // 0: down, 1: up
    int o_idx = 0;
    int len = strlen(stream);
    for (int i = 0; i + 4 < len; i += 5) {
        int code = 0;
        for (int b = 0; b < 5; b++) code = (code << 1) | (stream[i + b] - '0');
        if (code == 27) mode = 0;
        else if (code == 31) mode = 1;
        else {
            out[o_idx++] = (mode == 0 ? down_table[code] : up_table[code]);
        }
    }
    out[o_idx] = '\0';
}

int main(void) {

    char down[33] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ012345";
    char up[33]   = "abcdefghijklmnopqrstuvwxyz012345";
    char out[10];
    // 00000 = 0 -> 'A'
    decode_baudot(down, up, "00000", out);
    int ok = (out[0] == 'A');
    printf("%s: UVa 740 - Baudot Data Communication Code\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
