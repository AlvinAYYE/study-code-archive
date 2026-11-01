/*
 * ==========================================================================
 * UVa 11236 - Grocery store
 * Title-CN: 雜貨店四件商品總價與總乘積巧合
 * Difficulty: Medium
 * Tags: Math, Brute Force, Pruning
 * URL: https://onlinejudge.org/external/112/11236.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find all combinations of 4 item prices a <= b <= c <= d in cents such that a+b+c+d == a*b*c*d / 10^6.
 *
 * [中文] 題目描述:
 *     求 4 個商品價格（分）使得四者之和等於四者相乘除以 10^6（即以元為單位的總和等於總乘積）。
 *
 * [EN] Approach:
 *     Triple loop for a, b, c with strict bounds. Solve for d directly: d = (10^6 * S) / (P - 10^6). Verify d >= c and valid.
 *
 * [中文] 解題思維:
 *     三重循環枚舉 a <= b <= c，由等式解出 d = (10^6 * S) / (P - 10^6)，檢查 d 是否整除且 d >= c 且總價 <= 2000。
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

int count_grocery_combinations(void) {
    int count = 0;
    for (long long a = 1; a <= 2000; a++) {
        if (a * 4 > 2000) break;
        if (a * a * a * a > 2000000000LL) break;
        for (long long b = a; b <= 2000 - a; b++) {
            if (a + b * 3 > 2000) break;
            for (long long c = b; c <= 2000 - a - b; c++) {
                long long p = a * b * c;
                long long s = a + b + c;
                if (p <= 1000000LL) continue;
                if ((1000000LL * s) % (p - 1000000LL) != 0) continue;
                long long d = (1000000LL * s) / (p - 1000000LL);
                if (d < c) continue;
                if (s + d > 2000) continue;
                if (s + d == (p * d) / 1000000LL) {
                    count++;
                }
            }
        }
    }
    return count;
}

int main(void) {
    int c = count_grocery_combinations();
    // UVa 11236 has exactly 949 solutions
    int ok = (c == 949);
    printf("%s: UVa 11236 - Grocery store\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
