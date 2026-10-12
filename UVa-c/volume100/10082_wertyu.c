/*
 * ==========================================================================
 * UVa 10082 - WERTYU
 * Title-CN: WERTYU 鍵盤左移一格解碼
 * Difficulty: UVa Star 1
 * Tags: string, simulation
 * URL: https://onlinejudge.org/external/100/10082.pdf
 * ==========================================================================
 * [EN] Problem:
 *     A typist mistakenly shifted hands one position to the right on a QWERTY
 *     keyboard. Decode the message by shifting each character one position left.
 *
 * [中文] 題目說明:
 *     打字者雙手向右偏了一格，將所有字元替換為鍵盤上向左偏一格的鍵。空格與換行保持不變。
 *
 * [EN] Approach: Linear search in constant keyboard string, output char at index - 1.
 * [中文] 思路: 建立鍵盤字串常量，查表將字元替換為左邊相鄰的一個字元。
 * ==========================================================================
 */
#include <stdio.h>
#include <string.h>

static const char *kbd = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

char decode_wertyu_char(char c) {
    const char *p = strchr(kbd, c);
    if (p && (p - kbd) >= 1) return *(p - 1);
    return c;
}

void solve_uva10082(const char *in, char *out) {
    int i = 0;
    while (in[i]) {
        out[i] = decode_wertyu_char(in[i]);
        i++;
    }
    out[i] = '\0';
}

int main(void) {
    char out[64];
    solve_uva10082("O S, GOMR YPFSU/", out);
    int ok = (strcmp(out, "I AM FINE TODAY.") == 0);
    printf("%s: UVa 10082 - WERTYU\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
