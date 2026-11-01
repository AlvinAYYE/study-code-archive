/*
 * ==========================================================================
 * UVa 580 - Critical Mass
 * Title-CN: 臨界質量 (禁忌模式計數DP)
 * Difficulty: Medium
 * Tags: DP, Combinatorics
 * URL: https://onlinejudge.org/external/5/580.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the number of stacks of n uranium (U) and lead (L) cubes that contain at least 3 consecutive uranium cubes (dangerous).
 *
 * [中文] 題目說明:
 *     求長度為 n 由鈾 (U) 與鉛 (L) 方塊構成的堆疊中，包含至少 3 個連續鈾方塊的排列數。
 *
 * [EN] Approach:
 *     Calculate safe stacks safe[n] (no 3 consecutive U): safe[n] = safe[n-1] + safe[n-2] + safe[n-3]. Dangerous = 2^n - safe[n].
 * [中文] 思路:
 *     先求安全堆疊數 safe[n]（無連續 3 個 U）：safe[n] = safe[n-1] + safe[n-2] + safe[n-3]。危險數即為 2^n - safe[n]。
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

long long dangerous_stacks(int n) {
    if (n < 3) return 0;
    long long safe[35];
    safe[0] = 1; safe[1] = 2; safe[2] = 4;
    for (int i = 3; i <= n; i++) {
        safe[i] = safe[i - 1] + safe[i - 2] + safe[i - 3];
    }
    long long total = 1LL << n;
    return total - safe[n];
}

int main(void) {

    int ok = (dangerous_stacks(3) == 1) && (dangerous_stacks(4) == 3);
    printf("%s: UVa 580 - Critical Mass\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
