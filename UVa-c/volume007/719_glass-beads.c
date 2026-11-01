/*
 * ==========================================================================
 * UVa 719 - Glass Beads
 * Title-CN: 玻璃珠項鍊 (最小循環表示法)
 * Difficulty: Medium
 * Tags: String, Minimum Representation
 * URL: https://onlinejudge.org/external/7/719.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the 1-based starting position of the lexicographically smallest cyclic shift of a circular string.
 *
 * [中文] 題目描述:
 *     求環形字串所有循環同構中字典序最小的起始切割位置（最小循環表示法，Booth 演算法）。
 *
 * [EN] Approach:
 *     Dual pointers Booth's algorithm in O(N) or doubled string comparison.
 *
 * [中文] 解題思維:
 *     經典最小表示法：雙指針 i, j, k 比較 s[i+k] 與 s[j+k]，跳躍淘汰較大者，O(N) 找出最小循環位置。
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

int min_cyclic_shift(const char *s) {
    int n = strlen(s);
    char ss[100];
    strcpy(ss, s); strcat(ss, s);
    int i = 0, j = 1, k = 0;
    while (i < n && j < n && k < n) {
        int diff = ss[i + k] - ss[j + k];
        if (diff == 0) k++;
        else {
            if (diff > 0) i += k + 1;
            else j += k + 1;
            if (i == j) j++;
            k = 0;
        }
    }
    return (i < j ? i : j) + 1;
}

int main(void) {

    int pos = min_cyclic_shift("helloworld");
    int ok = (pos > 0 && pos <= 10);
    printf("%s: UVa 719 - Glass Beads\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
