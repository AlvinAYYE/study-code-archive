/*
 * ==========================================================================
 * UVa 213 - Message Decoding
 * Title-CN: 二進位編碼解碼
 * Difficulty: Medium
 * Tags: String, Bit Manipulation, Decoding
 * URL: https://onlinejudge.org/external/2/213.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Decode a binary message where headers define characters corresponding to binary codes of increasing length (0, 1; 00, 01, 10; etc.).
 *
 * [中文] 題目說明:
 *     解碼二進位訊息：首行標頭依長度對應二進位碼（長度 1: 0；長度 2: 00, 01, 10；長度 3: 000..110，全 1 為長度終止符）。
 *
 * [EN] Approach:
 *     Read 3-bit length prefix L. If L == 0, terminate. Otherwise read L-bit segments until segment of all 1s. Map to header index.
 * [中文] 思路:
 *     讀取 3 位長度 L，若 L=0 則結束；否則讀取 L 位二進位碼直至全 1 結束碼，依字典序映射回標頭對應字元。
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

int decode_header_index(int len, int code) {
    // Offset for length len: sum(2^k - 1) for k=1..len-1
    int offset = 0;
    for (int k = 1; k < len; k++) offset += (1 << k) - 1;
    return offset + code;
}

int main(void) {

    // len 1: code 0 -> idx 0
    // len 2: code 0 -> idx 1, code 1 -> idx 2, code 2 -> idx 3
    int ok = (decode_header_index(1, 0) == 0) && (decode_header_index(2, 0) == 1) && (decode_header_index(2, 1) == 2);
    printf("%s: UVa 213 - Message Decoding\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
