/*
 * ==========================================================================
 * UVa 941 - Permutations
 * Title-CN: 字典序第 N 個排列 (康托逆展開)
 * Difficulty: Easy
 * Tags: Math, Combinatorics, Permutations
 * URL: https://onlinejudge.org/external/9/941.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the N-th (0-indexed) lexicographical permutation of a given string of up to 20 distinct characters.
 *
 * [中文] 題目說明:
 *     求給定字串的所有字元依字典序排列後，第 N 個（0-indexed）排列字串（康托逆展開）。
 *
 * [EN] Approach:
 *     Sort characters. Precompute factorials up to 20!. Compute each digit index = N / (n-1)!, N %= (n-1)!, and extract used characters.
 * [中文] 思路:
 *     將字元升序排序，利用階乘基底（康托逆展開）：商數決定當前選取的未用字元索引，餘數作為下一輪數值繼續展開。
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

void nth_permutation(char *s, long long n, char *out) {
    int len = strlen(s);
    for (int i = 0; i < len - 1; i++)
        for (int j = i + 1; j < len; j++)
            if (s[i] > s[j]) { char t = s[i]; s[i] = s[j]; s[j] = t; }
    long long fact[21];
    fact[0] = 1;
    for (int i = 1; i <= len; i++) fact[i] = fact[i - 1] * i;
    int used[21] = {0};
    for (int i = 0; i < len; i++) {
        long long f = fact[len - 1 - i];
        int idx = n / f;
        n %= f;
        int count = 0;
        for (int j = 0; j < len; j++) {
            if (!used[j]) {
                if (count == idx) {
                    out[i] = s[j];
                    used[j] = 1;
                    break;
                }
                count++;
            }
        }
    }
    out[len] = '\0';
}

int main(void) {

    char s[] = "abc", out[5];
    nth_permutation(s, 0, out);
    int ok = (strcmp(out, "abc") == 0);
    nth_permutation(s, 5, out);
    ok = ok && (strcmp(out, "cba") == 0);
    printf("%s: UVa 941 - Permutations\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
