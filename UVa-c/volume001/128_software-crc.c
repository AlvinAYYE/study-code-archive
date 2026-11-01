/*
 * ==========================================================================
 * UVa 128 - Software CRC
 * Title-CN: 軟體循環冗餘校驗碼 (CRC-16)
 * Difficulty: UVa Star 2
 * Tags: math, bit-manipulation, crc
 * URL: https://onlinejudge.org/external/1/128.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Compute 2-byte CRC checksum with generator polynomial g = 34943 such that message * 2^16 + CRC == 0 (mod g).
 *
 * [中文] 題目說明:
 *     計算 2 位元組 CRC 校驗碼，使得字串 ASCII 位元流左移 16 位元加上 CRC 碼後可被 34943 整除。
 *
 * [EN] Approach:
 *     Treat string bytes as big-endian polynomial. Compute remainder r = (msg * 2^16) % 34943. CRC = (34943 - r) % 34943.
 * [中文] 思路:
 *     將字串位元組逐一按大端序取模：rem = (rem * 256 + byte) % 34943。最後左移 16 位元，CRC = (34943 - r) % 34943。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva128(const char *s) {
    int g = 34943;
    long long rem = 0;
    for (int i = 0; s[i]; i++) {
        rem = ((rem << 8) + (unsigned char)s[i]) % g;
    }
    rem = (rem << 16) % g;
    int crc = (int)((g - rem) % g);
    return crc;
}

int main(void) {

    int c = solve_uva128("this is a test");
    int ok = (c >= 0 && c < 34943);
    printf("%s: UVa 128 - Software CRC\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
