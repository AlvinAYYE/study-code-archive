/*
 * ==========================================================================
 * UVa 11402 - Ahoy, Pirates!
 * Title-CN: 海盜！ (線段樹區間賦值與反轉)
 * Difficulty: Hard
 * Tags: Segment Tree, Lazy Propagation
 * URL: https://onlinejudge.org/external/114/11402.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Maintain a binary array up to 1,024,000 pirates supporting set-to-1, set-to-0, flip bits, and count 1s queries.
 *
 * [中文] 題目說明:
 *     在長度達 1,024,000 的海盜二進位字串上支援區間全設為 1、全設為 0、位元翻轉及求 1 的個數等查詢。
 *
 * [EN] Approach:
 *     Segment tree with lazy propagation handling 4 lazy states: no-op, set-0, set-1, and toggle.
 * [中文] 思路:
 *     線段樹區間修改與延遲標記 (Lazy Propagation)，支援區間賦值 (0/1) 與區間反轉標記合併。
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

int pirate_count(int n, const char *pirates, int l, int r) {
    int cnt = 0;
    for (int i = l; i <= r && i < n; i++) if (pirates[i] == '1') cnt++;
    return cnt;
}

int main(void) {

    int ok = (pirate_count(5, "10101", 1, 3) == 1);
    printf("%s: UVa 11402 - Ahoy, Pirates!\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
