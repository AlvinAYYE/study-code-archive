/*
 * ==========================================================================
 * UVa 1594 - Ducci Sequence
 * Title-CN: 杜奇序列 (相鄰差循環收斂)
 * Difficulty: Easy
 * Tags: Simulation, Array
 * URL: https://onlinejudge.org/external/15/1594.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Repeatedly transform n-tuple (a1..an) into (|a1-a2|, |a2-a3|, ..., |an-a1|). Determine if it reaches all zeros (ZERO) or enters a cycle (LOOP).
 *
 * [中文] 題目說明:
 *     反覆將 n 元組轉換為相鄰項差值絕對值數組，判斷是在 1000 步內變為全 0 (ZERO) 還是進入非零循環 (LOOP)。
 *
 * [EN] Approach:
 *     Simulate step by step up to 1000 iterations. Check if all elements are zero at each step.
 * [中文] 思路:
 *     模擬最多 1000 步的相鄰差值迭代，每步檢查是否所有元素均為 0，若達到則輸出 ZERO 否則 LOOP。
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

bool is_ducci_zero(int n, int *a) {
    for (int step = 0; step < 1000; step++) {
        bool all_z = true;
        for (int i = 0; i < n; i++) if (a[i] != 0) all_z = false;
        if (all_z) return true;
        int first = a[0];
        for (int i = 0; i < n - 1; i++) a[i] = abs(a[i] - a[i + 1]);
        a[n - 1] = abs(a[n - 1] - first);
    }
    return false;
}

int main(void) {

    int a[] = {8, 11, 2, 7};
    int ok = is_ducci_zero(4, a);
    printf("%s: UVa 1594 - Ducci Sequence\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
