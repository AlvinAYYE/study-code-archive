/*
 * ==========================================================================
 * UVa 673 - Parentheses Balance
 * Title-CN: 括號平衡匹配驗證 (堆疊)
 * Difficulty: UVa Star 1
 * Tags: stack, string
 * URL: https://onlinejudge.org/external/6/673.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Verify whether parentheses '(' ')' and brackets '[' ']' in string are properly balanced and nested.
 *
 * [中文] 題目說明:
 *     以堆疊判定字串中的小括號 () 與中括號 [] 是否合法成對平衡且巢狀嵌套。
 *
 * [EN] Approach:
 *     Stack simulation: push open brackets; on close bracket check stack non-empty and matching top.
 * [中文] 思路:
 *     遇到左括號壓入堆疊；遇到右括號檢查堆疊是否為空且棧頂是否為對應的左括號，最後檢查堆疊是否為空。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva673(const char *s) {
    char stack[150];
    int top = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '(' || s[i] == '[') {
            stack[top++] = s[i];
        } else if (s[i] == ')') {
            if (top == 0 || stack[--top] != '(') return 0;
        } else if (s[i] == ']') {
            if (top == 0 || stack[--top] != '[') return 0;
        }
    }
    return top == 0;
}

int main(void) {

    int ok = solve_uva673("([])") && !solve_uva673("([)]");
    printf("%s: UVa 673 - Parentheses Balance\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
