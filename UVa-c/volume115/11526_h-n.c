/*
 * ==========================================================================
 * UVa 11526 - H(n)
 * Title-CN: 除法向下取整分塊求和加速
 * Difficulty: UVa Star 2
 * Tags: math
 * URL: https://onlinejudge.org/external/115/11526.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Compute H(n) = sum_{i=1}^n floor(n / i) in O(sqrt(n)) time for n up to 2^31 - 1.
 *
 * [中文] 題目說明:
 *     高效計算 H(n) = sum_{i=1}^n floor(n / i)，利用整數分塊 (數論分塊) 於 O(sqrt(n)) 時間內求和。
 *
 * [EN] Approach:
 *     Square root chunking: values floor(n/i) = v occur for range of i from l to r = n / v. Add (r - l + 1) * v.
 * [中文] 思路:
 *     利用商數相同區間的分塊性質：當 floor(n/i) = v 時，其連續右邊界為 r = n / v，整塊累加 (r - l + 1) * v。
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

long long solve_uva11526(long long n) {
    if (n <= 0) return 0;
    long long ans = 0;
    for (long long l = 1, r; l <= n; l = r + 1) {
        long long v = n / l;
        r = n / v;
        ans += (r - l + 1) * v;
    }
    return ans;
}

int main(void) {

    int ok = (solve_uva11526(5) == 10 && solve_uva11526(10) == 27);
    printf("%s: UVa 11526 - H(n)\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
