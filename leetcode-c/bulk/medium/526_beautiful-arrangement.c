/*
 * LeetCode 0526. Beautiful Arrangement（優美排列）
 * Difficulty: Medium
 * 題意：對 1 到 n 的排列 perm，若每個位置 i 都滿足 perm[i] 能被 i 整除，或 i 能被 perm[i] 整除，則稱為優美排列。回傳優美排列的總數。
 * 範例：
 *   1. 輸入：n = 2；輸出：2。排列 [1,2] 和 [2,1] 都符合條件。
 *   2. 輸入：n = 1；輸出：1。
 * 限制：
 *   - 1 <= n <= 15
 * 解法：
 *   1. 從位置 1 開始逐位置放入尚未使用的數字。
 *   2. 只有數字可整除目前位置，或目前位置可整除數字時，才遞迴嘗試。
 *   3. 用位元遮罩記錄哪些數字已使用；遮罩使用滿 n 個位置時找到一種完整排列。
 *   4. 把所有合法分支的完成數量加總。
 * 複雜度：最壞時間 O(n!)，額外空間 O(n) 遞迴深度。
 */
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/* ---- community solution ---- */
static int countArrangementsFrom(int n, int position, unsigned int used) {
    if (position > n) {
        return 1;
    }

    int arrangements = 0;
    for (int value = 1; value <= n; value++) {
        unsigned int bit = 1u << value;
        if ((used & bit) != 0) {
            continue;
        }
        if (value % position == 0 || position % value == 0) {
            arrangements += countArrangementsFrom(n, position + 1, used | bit);
        }
    }
    return arrangements;
}

int countArrangement(int n) {
    return countArrangementsFrom(n, 1, 0);
}

/* ---- generated tests ---- */
int main(void) {
    bool passed = countArrangement(2) == 2 &&
                  countArrangement(1) == 1 &&
                  countArrangement(3) == 3;
    printf("%s: 0526 countArrangement tests=3\n", passed ? "PASS" : "FAIL");
    return passed ? 0 : 1;
}
