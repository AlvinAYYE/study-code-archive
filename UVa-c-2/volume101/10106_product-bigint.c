/*
 * ==========================================================================
 * UVa 10106 - Product
 * Title-CN: 高精度大數乘法
 * Difficulty: UVa Star 1
 * Tags: math, big-integer
 * URL: https://onlinejudge.org/external/101/10106.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Multiply two non-negative integers up to 250 digits each.
 *
 * [中文] 題目說明:
 *     精確計算兩個長達 250 位數的非負大整數乘積。
 *
 * [EN] Approach:
 *     Standard O(N*M) grade-school multiplication: res[i+j] += a[i] * b[j] with carry propagation.
 * [中文] 思路:
 *     直式乘法模擬：res[i + j] += a[i] * b[j]，外層雙重迴圈處理累計並處理進位，倒序輸出結果。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void solve_uva10106(const char *s1, const char *s2, char *res) {
    int l1 = (int)strlen(s1), l2 = (int)strlen(s2);
    int p[600] = {0};
    for (int i = 0; i < l1; i++) {
        for (int j = 0; j < l2; j++) {
            p[i + j] += (s1[l1 - 1 - i] - '0') * (s2[l2 - 1 - j] - '0');
        }
    }
    int carry = 0;
    for (int i = 0; i < l1 + l2 || carry; i++) {
        int tot = p[i] + carry;
        p[i] = tot % 10;
        carry = tot / 10;
    }
    int top = l1 + l2 + 5;
    while (top > 0 && p[top] == 0) top--;
    int idx = 0;
    for (int i = top; i >= 0; i--) res[idx++] = p[i] + '0';
    res[idx] = '\0';
}

int main(void) {

    char res[50];
    solve_uva10106("12", "12", res);
    int ok = (strcmp(res, "144") == 0);
    printf("%s: UVa 10106 - Product\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
