/*
 * ==========================================================================
 * UVa 272 - TeX Quotes
 * Title-CN: TeX 雙引號替換
 * Difficulty: UVa Star 1 / CPE 49 顆星必考題
 * Tags: string, simulation
 * URL: https://onlinejudge.org/external/2/272.pdf
 * ==========================================================================
 * [EN] Problem Statement:
 *     TeX is a typesetting system developed by Donald Knuth. TeX uses `` to open
 *     quotes and '' to close quotes.
 *     Your task is to replace each pair of standard double quotes (") with
 *     the TeX style: the first quote of each pair becomes ``, and the second
 *     becomes ''.
 *
 * [中文] 題目說明:
 *     TeX 是一套著名的排版系統。在 TeX 中，左雙引號用兩個反引號 `` 表示，
 *     右雙引號用兩個單引號 '' 表示。
 *     請將輸入文本中的一般雙引號（"）依序替換為 TeX 風格：
 *     每對引號的第一個換成 ``，第二個換成 ''。
 *
 * Examples:
 *   Input:
 *     "To be or not to be," quoth the Bard, "that
 *     is the question".
 *   Output:
 *     ``To be or not to be,'' quoth the Bard, ``that
 *     is the question''.
 *
 * [EN] Approach:
 *     Scan character by character. Maintain a boolean flag `in_quote`.
 *     When encountering '"': if !in_quote print "``" and toggle, else print "''" and toggle.
 * [中文] 思路:
 *     逐字元讀取，維護布林變數紀錄目前是否在引號內。遇到雙引號時交替輸出 `` 與 ''。
 * ==========================================================================
 */
#include <stdio.h>
#include <string.h>

void solve_uva272(const char *input, char *output) {
    int in_quote = 0;
    int out_idx = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '\"') {
            if (!in_quote) {
                output[out_idx++] = '`';
                output[out_idx++] = '`';
                in_quote = 1;
            } else {
                output[out_idx++] = '\'';
                output[out_idx++] = '\'';
                in_quote = 0;
            }
        } else {
            output[out_idx++] = input[i];
        }
    }
    output[out_idx] = '\0';
}

int main(void) {
    const char *in = "\"To be or not to be\"";
    char out[128];
    solve_uva272(in, out);
    int ok = (strcmp(out, "``To be or not to be''") == 0);
    printf("%s: UVa 272 - TeX Quotes\n", ok ? "PASS" : "FAIL");

    /*
     * UVa Submission:
     * int ch, in_quote = 0;
     * while ((ch = getchar()) != EOF) {
     *     if (ch == '\"') {
     *         if (!in_quote) { printf("``"); in_quote = 1; }
     *         else { printf("''"); in_quote = 0; }
     *     } else { putchar(ch); }
     * }
     */
    return ok ? 0 : 1;
}
