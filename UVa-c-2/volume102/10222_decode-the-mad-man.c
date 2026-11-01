/*
 * ==========================================================================
 * UVa 10222 - Decode the Mad man
 * Title-CN: 破解瘋子密碼 (鍵盤左移兩格解密)
 * Difficulty: UVa Star 1 / CPE 49 顆星必考題
 * Tags: string, simulation, keyboard-mapping
 * URL: https://onlinejudge.org/external/102/10222.pdf
 * ==========================================================================
 * [EN] Problem Statement:
 *     A mad man has written a message using a standard QWERTY keyboard.
 *     However, while typing each character, his hands were placed two keys to
 *     the right!
 *     Your task is to decode the message by shifting each character two keys
 *     to the left on the keyboard. Spaces and newlines remain unchanged.
 *
 * [中文] 題目說明:
 *     一個瘋子在標準 QWERTY 鍵盤上輸入訊息，但他打字時雙手都往右偏了兩格！
 *     請將密文還原：將每個字元替換為鍵盤上向左移兩格對應的鍵。
 *     英文字母不分大小寫，解密後全部轉為小寫；空白鍵與換行維持不變。
 *
 * Examples:
 *   Input:
 *     k[r dyt I[o
 *   Output:
 *     how are you
 *
 * [EN] Approach:
 *     Define a constant string containing the QWERTY keyboard layout in order.
 *     Convert input to lowercase, find position in the keyboard string, and
 *     output character at index - 2.
 * [中文] 思路:
 *     建立鍵盤字串表，包含數字列與三行字母列。
 *     將讀入字元轉小寫，在鍵盤表中查詢位置並替換為往前 2 格的字元。
 * ==========================================================================
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

static const char *kbd = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";

char decode_char(char c) {
    char lower = (char)tolower((unsigned char)c);
    const char *pos = strchr(kbd, lower);
    if (pos && (pos - kbd) >= 2) {
        return *(pos - 2);
    }
    return c;
}

void solve_uva10222(const char *in, char *out) {
    int i = 0;
    while (in[i]) {
        out[i] = decode_char(in[i]);
        i++;
    }
    out[i] = '\0';
}

int main(void) {
    const char *cipher = "k[r dyt I[o";
    char plain[64];
    solve_uva10222(cipher, plain);
    int ok = (strcmp(plain, "how are you") == 0);
    printf("%s: UVa 10222 - Decode the Mad man\n", ok ? "PASS" : "FAIL");

    /*
     * UVa Submission:
     * int ch;
     * while ((ch = getchar()) != EOF) {
     *     putchar(decode_char(ch));
     * }
     */
    return ok ? 0 : 1;
}
