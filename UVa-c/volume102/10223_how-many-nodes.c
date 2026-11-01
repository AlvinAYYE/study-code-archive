/*
 * ==========================================================================
 * UVa 10223 - How many nodes ?
 * Title-CN: 多少個節點？ (卡特蘭數逆查)
 * Difficulty: Easy
 * Tags: Math, Catalan Numbers
 * URL: https://onlinejudge.org/external/102/10223.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given total number of distinct binary trees C_n, determine the number of nodes n.
 *
 * [中文] 題目說明:
 *     給定形態互不相同的二元樹數量 C_n，求其節點數 n（即卡特蘭數逆運算）。
 *
 * [EN] Approach:
 *     Precompute Catalan numbers C_1 to C_20: C_0 = 1, C_{n} = sum(C_i * C_{n-1-i}). Look up target value.
 * [中文] 思路:
 *     預先計算前 20 項卡特蘭數，查表返回使 C_n 等於輸入值的 n。
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

int find_catalan_nodes(long long c_val) {
    long long c[25] = {0};
    c[0] = 1;
    for (int i = 1; i <= 20; i++) {
        for (int j = 0; j < i; j++) {
            c[i] += c[j] * c[i - 1 - j];
        }
        if (c[i] == c_val) return i;
    }
    return -1;
}

int main(void) {

    int ok = (find_catalan_nodes(1) == 1) && (find_catalan_nodes(2) == 2) && (find_catalan_nodes(5) == 3);
    printf("%s: UVa 10223 - How many nodes ?\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
