/*
 * ==========================================================================
 * UVa 11878 - Homework Checker
 * Title-CN: 作業檢查員
 * Difficulty: Easy
 * Tags: String, Parsing, Math
 * URL: https://onlinejudge.org/external/118/11878.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count how many arithmetic equations like 'a+b=c' or 'a-b=c' are graded correctly when answers marked '?' are ignored.
 *
 * [中文] 題目概述:
 *     檢查給定類似 'a+b=c' 或 'a-b=c' 的算式，統計其中計算正確的數量（答案為 '?' 者不計）。
 *
 * [EN] Approach:
 *     Parse equations with sscanf, check if answer is '?', otherwise verify if a + b == c or a - b == c.
 * [中文] 解題思路:
 *     使用 sscanf 解析算式，若答案為 '?' 則跳過，否則驗證 a + b == c 或 a - b == c 是否成立。
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

bool check_equation(const char *eq) {
    int a, b, c;
    char op, ans_str[20];
    if (sscanf(eq, "%d%c%d=%s", &a, &op, &b, ans_str) == 4) {
        if (strcmp(ans_str, "?") == 0) return false;
        c = atoi(ans_str);
        if (op == '+' && a + b == c) return true;
        if (op == '-' && a - b == c) return true;
    }
    return false;
}

int main(void) {

    int ok = check_equation("2+3=5") && !check_equation("5-2=?") && !check_equation("1+1=3");
    printf("%s: UVa 11878 - Homework Checker\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
