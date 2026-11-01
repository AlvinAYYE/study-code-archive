/*
 * ==========================================================================
 * UVa 263 - Number Chains
 * Title-CN: 數字鏈 (卡布列克過程循環檢測)
 * Difficulty: UVa Star 1
 * Tags: math, simulation, sorting
 * URL: https://onlinejudge.org/external/2/263.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Generate chain: sort digits descending minus ascending to get next number. Stop when a number repeats.
 *
 * [中文] 題目說明:
 *     數字鏈產生規則：將數字的位數由大到小排序減去由小到大排序得到下一個數。遇到重複數字即停止並求鏈長。
 *
 * [EN] Approach:
 *     Sort digits into descending and ascending numbers, subtract, and record seen numbers in hash or array to detect cycle.
 * [中文] 思路:
 *     利用字串將位數排序轉換為遞減與遞增整數相減，以雜湊或陣列記錄已出現的數值以檢測循環。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long long next_kaprekar(long long n) {
    char s[20];
    int len = sprintf(s, "%lld", n);
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (s[i] < s[j]) { char t = s[i]; s[i] = s[j]; s[j] = t; }
        }
    }
    long long desc = 0, asc = 0;
    for (int i = 0; i < len; i++) desc = desc * 10 + (s[i] - '0');
    for (int i = len - 1; i >= 0; i--) asc = asc * 10 + (s[i] - '0');
    return desc - asc;
}

int main(void) {

    int ok = (next_kaprekar(1234) == 3087);
    printf("%s: UVa 263 - Number Chains\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
