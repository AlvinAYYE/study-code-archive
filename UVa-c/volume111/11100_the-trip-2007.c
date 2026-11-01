/*
 * ==========================================================================
 * UVa 11100 - The Trip, 2007
 * Title-CN: 旅行2007 (背包嵌套與眾數)
 * Difficulty: Medium
 * Tags: Greedy, Sorting
 * URL: https://onlinejudge.org/external/111/11100.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Nest bags inside strictly larger bags to minimize the total number of visible outer bags.
 *
 * [中文] 題目說明:
 *     小背包可嵌套放入嚴格大於它的背包中，求最少需要多少個外層背包。
 *
 * [EN] Approach:
 *     The minimum number of outer bags k equals the maximum frequency of any bag size. Distribute elements into k chains by taking elements at stride k.
 * [中文] 思路:
 *     由抽屜原理可知，最小外層背包數 k 必等於出現次數最多的背包尺寸頻率。依跨度 k 交錯放入各背包鏈中。
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

int min_outer_bags(int n, const int *bags) {
    int freq[100] = {0};
    int max_f = 0;
    for (int i = 0; i < n; i++) {
        freq[bags[i]]++;
        if (freq[bags[i]] > max_f) max_f = freq[bags[i]];
    }
    return max_f;
}

int main(void) {

    int b[] = {1, 1, 2, 2, 2, 3}; // size 2 appears 3 times -> k = 3
    int ok = (min_outer_bags(6, b) == 3);
    printf("%s: UVa 11100 - The Trip, 2007\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
