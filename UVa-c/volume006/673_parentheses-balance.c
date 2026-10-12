/*
 * ==========================================================================
 * UVa 673 - Parentheses Balance
 * Title-CN: 括號平衡檢驗
 * Difficulty: UVa Star 1
 * Tags: stack, string
 * ==========================================================================
 * [EN] Problem: Check if string of parentheses '()' and '[]' is balanced.
 * [中文] 題目說明: 檢查由小括號 () 與中括號 [] 組成的字串是否合法對稱閉合。
 * [EN] Approach: Use stack data structure.
 * [中文] 思路: 遇到左括號入棧，遇到右括號檢查棧頂是否匹配出棧。
 * ==========================================================================
 */
#include <stdio.h>

int is_balanced(const char *s) {
    char stack[150];
    int top = 0;
    for (int i = 0; s[i]; i++) {
        char c = s[i];
        if (c == '(' || c == '[') {
            stack[top++] = c;
        } else if (c == ')') {
            if (top == 0 || stack[--top] != '(') return 0;
        } else if (c == ']') {
            if (top == 0 || stack[--top] != '[') return 0;
        }
    }
    return (top == 0);
}

int main(void) {
    int ok = is_balanced("([])") && !is_balanced("([)]");
    printf("%s: UVa 673 - Parentheses Balance\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
