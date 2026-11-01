/*
 * ==========================================================================
 * UVa 325 - Identifying Legal Pascal Real Constants
 * Title-CN: 判斷合法的 Pascal 實數常數
 * Difficulty: Medium
 * Tags: String, Parser, Regex
 * URL: https://onlinejudge.org/external/3/325.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine whether a given string is a syntactically valid Pascal real number constant.
 *
 * [中文] 題目描述:
 *     判斷給定字串是否為語法正確的 Pascal 實數常數（必須包含小數點且前後均有數字，或包含指數 E/e 且指數為整數）。
 *
 * [EN] Approach:
 *     Trim whitespace, parse optional sign, digits, decimal part (must have digits before and after '.'), and optional exponent 'e'/'E' with optional sign and digits.
 *
 * [中文] 解題思維:
 *     解析符號、前導數字、小數點（小數點前後皆必須有數字）以及可選的指數部分（E/e 及其整數指數）。
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

int is_legal_pascal_real(const char *str) {
    while (*str == ' ') str++;
    int len = (int)strlen(str);
    while (len > 0 && (str[len - 1] == ' ' || str[len - 1] == '\r' || str[len - 1] == '\n')) len--;
    if (len == 0) return 0;

    int i = 0;
    if (str[i] == '+' || str[i] == '-') i++;
    if (i >= len || !isdigit(str[i])) return 0;

    int digits_before_dot = 0;
    while (i < len && isdigit(str[i])) { digits_before_dot++; i++; }

    int has_dot = 0, digits_after_dot = 0;
    if (i < len && str[i] == '.') {
        has_dot = 1;
        i++;
        while (i < len && isdigit(str[i])) { digits_after_dot++; i++; }
        if (digits_after_dot == 0) return 0; // must have digits after dot
    }

    int has_exp = 0;
    if (i < len && (str[i] == 'e' || str[i] == 'E')) {
        has_exp = 1;
        i++;
        if (i < len && (str[i] == '+' || str[i] == '-')) i++;
        int exp_digits = 0;
        while (i < len && isdigit(str[i])) { exp_digits++; i++; }
        if (exp_digits == 0) return 0;
    }

    if (i != len) return 0;
    // Must have either decimal point or exponent to be a real constant
    return (has_dot || has_exp);
}

int main(void) {

    int ok = is_legal_pascal_real("1.2") &&
             is_legal_pascal_real("1e2") &&
             is_legal_pascal_real("-1.0e-3") &&
             !is_legal_pascal_real("1.e2") &&
             !is_legal_pascal_real(".2") &&
             !is_legal_pascal_real("123");
    printf("%s: UVa 325 - Identifying Legal Pascal Real Constants\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
