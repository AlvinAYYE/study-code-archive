/*
 * ==========================================================================
 * UVa 10408 - Farey sequences
 * Title-CN: 法里數列 (不可約分數序列)
 * Difficulty: Easy
 * Tags: Math, Farey Sequence, Number Theory
 * URL: https://onlinejudge.org/external/104/10408.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Generate the Farey sequence of order n (all irreducible fractions a/b with 1 <= a <= b <= n) and output the k-th fraction.
 *
 * [中文] 題目說明:
 *     生成 n 階法里數列（所有 1 <= a <= b <= n 且 gcd(a,b)=1 的分數依升序排列），輸出第 k 個分數。
 *
 * [EN] Approach:
 *     Iterative generation using Farey addition: next terms x2 = floor((y0 + n) / y1) * x1 - x0, y2 = floor((y0 + n) / y1) * y1 - y0.
 * [中文] 思路:
 *     利用法里數列相鄰三項遞推公式：k = floor((y0 + n) / y1)，則 x2 = k * x1 - x0, y2 = k * y1 - y0，由 (0,1), (1,n) 迭代至第 k 項。
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

void farey_kth(int n, int k, int *ans_a, int *ans_b) {
    int x0 = 0, y0 = 1, x1 = 1, y1 = n;
    if (k == 1) { *ans_a = x1; *ans_b = y1; return; }
    for (int step = 2; step <= k; step++) {
        int m = (y0 + n) / y1;
        int x2 = m * x1 - x0;
        int y2 = m * y1 - y0;
        x0 = x1; y0 = y1;
        x1 = x2; y1 = y2;
    }
    *ans_a = x1; *ans_b = y1;
}

int main(void) {

    int a, b;
    farey_kth(5, 1, &a, &b);
    int ok = (a == 1 && b == 5);
    printf("%s: UVa 10408 - Farey sequences\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
