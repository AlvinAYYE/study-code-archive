/*
 * ==========================================================================
 * UVa 11111 - Generalized Matrioshkas
 * Title-CN: 廣義俄羅斯套娃 (堆疊配對與容量驗證)
 * Difficulty: Medium
 * Tags: Stack, Data Structures
 * URL: https://onlinejudge.org/external/111/11111.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Verify if a sequence of negative (open) and positive (close) integers represents a valid set of generalized nested matrioshkas.
 *
 * [中文] 題目說明:
 *     驗證正負整數序列是否為合法嵌套的俄羅斯套娃（負數為開套娃，正數為封套娃，內部直接包含的套娃尺寸和嚴格小於外層）。
 *
 * [EN] Approach:
 *     Use stack of pairs (size, inner_sum). Match -x with +x. Check that inner_sum < x at closure, then add x to parent's inner_sum.
 * [中文] 思路:
 *     使用堆疊維護 (尺寸, 內層尺寸總和)。負數入棧，遇到對應正數時檢查內層和嚴格小於外層尺寸，並累加至上一層父套娃。
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

bool is_valid_matrioshka(int n, const int *seq) {
    int stack_size[50], stack_inner[50], top = 0;
    for (int i = 0; i < n; i++) {
        int v = seq[i];
        if (v < 0) {
            stack_size[top] = -v;
            stack_inner[top] = 0;
            top++;
        } else {
            if (top == 0 || stack_size[top - 1] != v) return false;
            if (stack_inner[top - 1] >= v) return false;
            top--;
            if (top > 0) stack_inner[top - 1] += v;
        }
    }
    return (top == 0);
}

int main(void) {

    int seq1[] = {-9, -3, 3, -4, 4, 9}; // 3 + 4 = 7 < 9 -> valid
    int ok = is_valid_matrioshka(6, seq1);
    printf("%s: UVa 11111 - Generalized Matrioshkas\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
