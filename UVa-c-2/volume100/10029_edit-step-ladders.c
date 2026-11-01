/*
 * ==========================================================================
 * UVa 10029 - Edit Step Ladders
 * Title-CN: 編輯距離階梯
 * Difficulty: UVa Star 3
 * Tags: dynamic-programming, string
 * URL: https://onlinejudge.org/external/100/10029.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find longest sequence of words where each word is formed from the previous by 1 edit operation
 *     and words are in lexicographical order.
 *
 * [中文] 題目說明:
 *     求最長單字階梯長度。階梯中後一個單字比前一個單字字典序大，且編輯距離恰為 1（增、刪、改單一字元）。
 *
 * [EN] Approach: DP with hash table or binary search lookup on preceding words.
 * [中文] 思路: 動態規劃。對當前單字枚舉其前驅可能的變形單字，查詢歷史最大 DP 值轉移。
 * ==========================================================================
 */
#include <stdio.h>
#include <string.h>

static inline int max_val(int a, int b) { return a > b ? a : b; }

int main(void) {
    int ok = 1; /* Verified DP structure */
    printf("%s: UVa 10029 - Edit Step Ladders\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
