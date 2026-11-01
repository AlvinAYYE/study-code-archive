/*
 * ==========================================================================
 * UVa 333 - Recognizing Good ISBNs
 * Title-CN: 辨識合法 ISBN 書號
 * Difficulty: Easy
 * Tags: String, Validation, Checksum
 * URL: https://onlinejudge.org/external/3/333.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine if a string represents a valid 10-character ISBN according to cumulative prefix sum checksum.
 *
 * [中文] 題目描述:
 *     依據兩次前綴和累加校驗規則（s2[9] mod 11 == 0），檢驗字串是否為合法的 10 位 ISBN 書號。
 *
 * [EN] Approach:
 *     Trim whitespace. Extract exactly 10 digits/letters. 'X' is only valid as the 10th digit with value 10. Compute s1 then s2; valid iff s2[9] % 11 == 0.
 *
 * [中文] 解題思維:
 *     去除頭尾空格，驗證剛好含 10 個有效位元（數字或末位 'X'=10），計算兩次前綴和檢驗最終模 11 是否為 0。
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

bool is_valid_isbn_333(const char *raw) {
    int digits[10], cnt = 0;
    for (int i = 0; raw[i]; i++) {
        if (raw[i] == '-' || raw[i] == ' ') continue;
        if (raw[i] >= '0' && raw[i] <= '9') {
            if (cnt >= 10) return false;
            digits[cnt++] = raw[i] - '0';
        } else if (raw[i] == 'X') {
            if (cnt != 9) return false;
            digits[cnt++] = 10;
        } else {
            return false;
        }
    }
    if (cnt != 10) return false;
    int s1 = 0, s2 = 0;
    for (int i = 0; i < 10; i++) {
        s1 += digits[i];
        s2 += s1;
    }
    return (s2 % 11 == 0);
}

int main(void) {
    int ok = is_valid_isbn_333("0-13-162959-X") && !is_valid_isbn_333("0-201-01412-4");
    printf("%s: UVa 333 - Recognizing Good ISBNs\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
