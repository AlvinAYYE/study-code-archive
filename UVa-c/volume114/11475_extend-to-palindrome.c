/*
 * ==========================================================================
 * UVa 11475 - Extend to Palindrome
 * Title-CN: 添加最短後綴字元形成迴文
 * Difficulty: UVa Star 2
 * Tags: string, kmp
 * URL: https://onlinejudge.org/external/114/11475.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the shortest palindrome that can be formed by appending characters to the end of a given string.
 *
 * [中文] 題目說明:
 *     在給定字串末尾添加最少數量的字元，使其擴充為一個對稱迴文字串。
 *
 * [EN] Approach:
 *     Find the longest suffix of string S that is a palindrome. Append the reverse of the remaining prefix to S.
 * [中文] 思路:
 *     尋找字串 S 中最長的回文後綴，將剩餘前綴反轉後附加至字串末尾即可構成最短回文。
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

int is_palin_suffix(const char *s, int start) {
    int i = start, j = strlen(s) - 1;
    while (i < j) {
        if (s[i] != s[j]) return 0;
        i++; j--;
    }
    return 1;
}

void solve_uva11475(const char *s, char *out) {
    int len = strlen(s);
    int pal_start = 0;
    for (int i = 0; i < len; i++) {
        if (is_palin_suffix(s, i)) { pal_start = i; break; }
    }
    strcpy(out, s);
    int o_idx = len;
    for (int i = pal_start - 1; i >= 0; i--) {
        out[o_idx++] = s[i];
    }
    out[o_idx] = '\0';
}

int main(void) {

    char buf[100];
    solve_uva11475("aman", buf); // "aman" -> "amana"
    int ok = (strcmp(buf, "amanama") == 0);
    printf("%s: UVa 11475 - Extend to Palindrome\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
