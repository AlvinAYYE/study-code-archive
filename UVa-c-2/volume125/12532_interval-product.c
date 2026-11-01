/*
 * ==========================================================================
 * UVa 12532 - Interval Product
 * Title-CN: 區間乘積正負號線段樹 / 樹狀陣列
 * Difficulty: UVa Star 2
 * Tags: data-structures, segment-tree
 * URL: https://onlinejudge.org/external/125/12532.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Support point update 'C I V' and range product sign query 'P I J' (+, -, or 0) on an array of integers.
 *
 * [中文] 題目概述:
 *     維護整數陣列，支援單點修改數值與區間乘積正負號查詢 (輸出 '+', '-' 或 '0')。
 *
 * [EN] Approach:
 *     Map elements to sign (+1, -1, 0). Maintain Segment Tree or BIT of zeroes and negative numbers.
 * [中文] 解題思路:
 *     將每個數壓縮為正負符號 (+1, -1, 0)：若區間內含 0 則乘積為 0；否則由負數個數之奇偶性決定為 '-' 或 '+'。
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

char solve_uva12532_query(int *arr, int l, int r) {
    int neg = 0;
    for (int i = l; i <= r; i++) {
        if (arr[i] == 0) return '0';
        if (arr[i] < 0) neg++;
    }
    return (neg % 2 == 1) ? '-' : '+';
}

int main(void) {

    int a[] = {1, -2, 3, -4, 5};
    char s1 = solve_uva12532_query(a, 0, 4); // 2 negatives -> +
    char s2 = solve_uva12532_query(a, 0, 2); // 1 negative -> -
    int ok = (s1 == '+' && s2 == '-');
    printf("%s: UVa 12532 - Interval Product\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
