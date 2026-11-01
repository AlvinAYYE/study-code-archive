/*
 * ==========================================================================
 * UVa 10789 - Prime Frequency
 * Title-CN: 質數頻率字元篩選
 * Difficulty: UVa Star 1
 * Tags: string, prime, sorting
 * URL: https://onlinejudge.org/external/107/10789.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find all characters whose frequency in string is a prime number, in alphabetical order.
 *
 * [中文] 題目說明:
 *     找出字串中出現次數恰好為質數的所有字母與數字字元，按 ASCII 順序由小到大輸出。
 *
 * [EN] Approach:
 *     Count character occurrences into array. Check if frequency is prime using prime test.
 * [中文] 思路:
 *     陣列統計各字元出現次數，逐一判定頻率是否為質數，依序輸出所有滿足條件的字元 (無滿足者輸出 empty)。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static int is_p_10789(int n) {
    if (n < 2) return 0;
    for (int d = 2; d * d <= n; d++) if (n % d == 0) return 0;
    return 1;
}

void solve_uva10789(const char *s, char *out) {
    int cnt[128] = {0};
    for (int i = 0; s[i]; i++) cnt[(unsigned char)s[i]]++;
    int idx = 0;
    for (int i = 0; i < 128; i++) {
        if (is_p_10789(cnt[i])) out[idx++] = (char)i;
    }
    if (idx == 0) { strcpy(out, "empty"); }
    else out[idx] = '\0';
}

int main(void) {

    char res[20];
    solve_uva10789("ABCC", res);
    int ok = (strcmp(res, "C") == 0); /* C appears 2 times (prime) */
    printf("%s: UVa 10789 - Prime Frequency\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
