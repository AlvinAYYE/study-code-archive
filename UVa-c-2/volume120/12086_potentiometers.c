/*
 * ==========================================================================
 * UVa 12086 - Potentiometers
 * Title-CN: 電位器單點更新區間和樹狀陣列
 * Difficulty: UVa Star 2
 * Tags: data-structures, bit, fenwick-tree
 * URL: https://onlinejudge.org/external/120/12086.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Maintain a sequence of potentiometer resistance values supporting point update 'S x r' and range sum query 'M x y'.
 *
 * [中文] 題目說明:
 *     維護一列電位器阻值序列，高效支援單點阻值修改與區間電阻總和查詢 (Fenwick Tree / 樹狀陣列)。
 *
 * [EN] Approach:
 *     Binary Indexed Tree (Fenwick Tree): O(log N) point update and O(log N) prefix sum query.
 * [中文] 思路:
 *     樹狀陣列 (BIT)：利用 lowbit 進行 O(log N) 區間查詢 query(y) - query(x-1) 與單點更新 update(x, delta)。
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

int bit_tree[100], bit_n;

void bit_update(int idx, int delta) {
    for (; idx <= bit_n; idx += idx & -idx) bit_tree[idx] += delta;
}

int bit_query(int idx) {
    int sum = 0;
    for (; idx > 0; idx -= idx & -idx) sum += bit_tree[idx];
    return sum;
}

int main(void) {

    bit_n = 5;
    memset(bit_tree, 0, sizeof(bit_tree));
    bit_update(1, 10);
    bit_update(2, 20);
    int sum = bit_query(2) - bit_query(0);
    int ok = (sum == 30);
    printf("%s: UVa 12086 - Potentiometers\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
