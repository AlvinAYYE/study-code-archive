/*
 * ==========================================================================
 * UVa 10559 - Blocks
 * Title-CN: 消除方塊 (區間 DP)
 * Difficulty: Hard
 * Tags: Dynamic Programming, Interval DP
 * URL: https://onlinejudge.org/external/105/10559.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the maximum points attainable by repeatedly removing contiguous blocks of the same color (earning k^2 points for length k).
 *
 * [中文] 題目描述:
 *     每次消除相鄰相同顏色的方塊可獲得長度平方的分數，求消除所有方塊能獲得的最大分數總和。
 *
 * [EN] Approach:
 *     Interval DP state dp[i][j][k]: max score for subarray [i..j] with k additional blocks matching color[j] concatenated to the right.
 *
 * [中文] 解題思維:
 *     經典區間動態規劃：dp[i][j][k] 表示子區間 [i..j] 且右側已有 k 個與 color[j] 同色方塊時的最大分數。
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

static int dp10559[205][205][205];
static int color_len[205], color_val[205];

static int memo_blocks(int i, int j, int k) {
    if (i > j) return 0;
    if (dp10559[i][j][k] != -1) return dp10559[i][j][k];

    // Option 1: remove block j and attached k blocks
    int res = memo_blocks(i, j - 1, 0) + (color_len[j] + k) * (color_len[j] + k);

    // Option 2: merge with matching color block p
    for (int p = i; p < j; p++) {
        if (color_val[p] == color_val[j]) {
            int cand = memo_blocks(p + 1, j - 1, 0) + memo_blocks(i, p, k + color_len[j]);
            if (cand > res) res = cand;
        }
    }
    return dp10559[i][j][k] = res;
}

int max_blocks_score(int n, int *boxes) {
    int m = 0;
    for (int i = 0; i < n; ) {
        int j = i;
        while (j < n && boxes[j] == boxes[i]) j++;
        color_val[m] = boxes[i];
        color_len[m] = j - i;
        m++;
        i = j;
    }
    memset(dp10559, -1, sizeof(dp10559));
    return memo_blocks(0, m - 1, 0);
}

int main(void) {

    int b[] = {1, 2, 2, 2, 1}; // removing 2,2,2 gives 9, then 1,1 gives 4 -> 13
    int res = max_blocks_score(5, b);
    int ok = (res == 13);
    printf("%s: UVa 10559 - Blocks\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
