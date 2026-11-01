/*
 * ==========================================================================
 * UVa 12459 - Bees' ancestors
 * Title-CN: 蜜蜂的祖先
 * Difficulty: Easy
 * Tags: Math, Fibonacci
 * URL: https://onlinejudge.org/external/124/12459.pdf
 * ==========================================================================
 * [EN] Problem:
 *     A male bee has only 1 parent (mother), while a female bee has 2 parents (father and mother). Find the number of ancestors of a male bee in the n-th generation back.
 *
 * [中文] 題目概述:
 *     雄蜂只有 1 個親代（母親），雌蜂有 2 個親代（父親與母親）。求一隻雄蜂在倒數第 n 代祖先的總數。
 *
 * [EN] Approach:
 *     The sequence of total ancestors in generation n corresponds to the Fibonacci sequence: F(1)=1, F(2)=2, F(3)=3, F(4)=5, ...
 * [中文] 解題思路:
 *     第 n 代祖先數恰好為費氏數列：F(1)=1, F(2)=2, F(3)=3, F(4)=5, ...
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

long long bee_ancestors(int n) {
    if (n <= 1) return 1;
    long long a = 1, b = 2;
    for (int i = 2; i <= n; i++) {
        long long next = a + b;
        a = b;
        b = next;
    }
    return a;
}

int main(void) {

    int ok = (bee_ancestors(1) == 1) && (bee_ancestors(2) == 2) && (bee_ancestors(3) == 3);
    printf("%s: UVa 12459 - Bees' ancestors\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
