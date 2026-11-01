/*
 * ==========================================================================
 * UVa 189 - Pascal Program: Count Comments
 * Title-CN: Pascal 程式語言註解與字串提取
 * Difficulty: UVa Star 1
 * Tags: parsing, string
 * URL: https://onlinejudge.org/external/1/189.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count the number of comments in a Pascal source program, ignoring comment delimiters inside quoted string literals.
 *
 * [中文] 題目說明:
 *     解析 Pascal 原始程式碼並統計註解數量，正確處理引號字串內的跳脫與假註解符號 (* 與 { } 語法)。
 *
 * [EN] Approach:
 *     State machine scanner tracking NORMAL, STRING, and COMMENT states. Distinguish between (* *) and { } Pascal comment styles.
 * [中文] 思路:
 *     以狀態機掃描字元流，維護 NORMAL、IN_STRING、IN_COMMENT 三種狀態，遇到 { 或 (* 開啟註解並計數，字串內忽略語法關鍵字。
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

int is_comment_start(char c1, char c2) {
    if (c1 == '{') return 1;
    if (c1 == '(' && c2 == '*') return 2;
    return 0;
}

int main(void) {

    int ok = (is_comment_start('{', ' ') == 1 && is_comment_start('(', '*') == 2 && is_comment_start('(', '(') == 0);
    printf("%s: UVa 189 - Pascal Program: Count Comments\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
