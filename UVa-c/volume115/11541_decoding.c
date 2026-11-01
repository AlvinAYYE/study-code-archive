/*
 * ==========================================================================
 * UVa 11541 - Decoding
 * Title-CN: 行程長度編碼字串解碼
 * Difficulty: UVa Star 1
 * Tags: string
 * URL: https://onlinejudge.org/external/115/11541.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Decode run-length encoded string consisting of letters followed by repeat counts (e.g. A3B4 -> AAABBBB).
 *
 * [中文] 題目說明:
 *     將簡化的行程長度壓縮字串 (如 A3B4C2) 還原解碼為原始完整字串 (AAABBBBCC)。
 *
 * [EN] Approach:
 *     Scan string: read letter, parse integer repeat count k, append k copies of the letter to the output buffer.
 * [中文] 思路:
 *     依序掃描字串：提取字母與緊隨其後的整數計數 k，將該字母重複填入緩衝區 k 次。
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

void solve_uva11541(const char *in, char *out) {
    int out_idx = 0;
    for (int i = 0; in[i]; ) {
        char ch = in[i++];
        int cnt = 0;
        while (in[i] && isdigit(in[i])) {
            cnt = cnt * 10 + (in[i++] - '0');
        }
        for (int k = 0; k < cnt; k++) out[out_idx++] = ch;
    }
    out[out_idx] = '\0';
}

int main(void) {

    char buf[100];
    solve_uva11541("A2B3", buf);
    int ok = (strcmp(buf, "AABBB") == 0);
    printf("%s: UVa 11541 - Decoding\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
