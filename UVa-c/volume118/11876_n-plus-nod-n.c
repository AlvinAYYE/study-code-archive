/*
 * ==========================================================================
 * UVa 11876 - N + NOD (N)
 * Title-CN: N + 因數個數序列 (前綴和與二分查找)
 * Difficulty: Easy
 * Tags: Math, Number Theory, Binary Search
 * URL: https://onlinejudge.org/external/118/11876.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Sequence begins with A_0 = 1, and A_i = A_{i-1} + NOD(A_{i-1}) where NOD is number of divisors. Count sequence elements in [A, B].
 *
 * [中文] 題目描述:
 *     數列定義為 A_0 = 1, A_i = A_{i-1} + NOD(A_{i-1})（NOD 為因數個數），求區間 [A, B] 內包含多少個數列元素。
 *
 * [EN] Approach:
 *     Precompute NOD up to 1,000,000 using sieve. Generate sequence A until > 1,000,000 (around 70,000 terms). Query range [A, B] via binary search.
 *
 * [中文] 解題思維:
 *     線性篩法預處理因數個數 NOD(n)，遞推生成序列數組（約 7 萬項達到 100 萬），每次詢問用二分查找 (upper_bound - lower_bound)。
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

int nod(int n) {
    int count = 0;
    for (int d = 1; d * d <= n; d++) {
        if (n % d == 0) {
            count++;
            if (d * d != n) count++;
        }
    }
    return count;
}
int next_nod_seq(int a) {
    return a + nod(a);
}

int main(void) {

    int a1 = next_nod_seq(1); // 1 + 1 = 2
    int a2 = next_nod_seq(2); // 2 + 2 = 4
    int a3 = next_nod_seq(4); // 4 + 3 = 7
    int ok = (a1 == 2 && a2 == 4 && a3 == 7);
    printf("%s: UVa 11876 - N + NOD (N)\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
