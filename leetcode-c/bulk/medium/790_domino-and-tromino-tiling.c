/*
 * LeetCode 0790. Domino and Tromino Tiling（骨牌與 L 形磚鋪板）
 * 題意：用可旋轉的 2x1 長方形骨牌與 L 形三格 tromino，完整鋪滿 2*n 棋盤；求不同鋪法數，答案取模 10^9+7。
 * 範例：n=3 -> 5；n=1 -> 1。
 * 限制：1 <= n <= 1000。
 * 解法：令 dp[i] 為鋪滿 2*i 棋盤的方法數。考慮最右側形狀可得 dp[i]=2*dp[i-1]+dp[i-3]，並用 long long 中間計算後取模。
 * 複雜度：時間 O(n)，空間 O(n)。
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MODULUS 1000000007

/* ---- community solution ---- */
int numTilings(int n) {
    int *ways = (int *)calloc((size_t)n + 1, sizeof(int));
    if (ways == NULL) {
        return 0;
    }
    ways[0] = 1;
    ways[1] = 1;
    if (n >= 2) {
        ways[2] = 2;
    }
    for (int width = 3; width <= n; width++) {
        ways[width] = (int)((2LL * ways[width - 1] + ways[width - 3]) % MODULUS);
    }
    int answer = ways[n];
    free(ways);
    return answer;
}

/* ---- generated tests ---- */
int main(void) {
    bool passed = numTilings(1) == 1 && numTilings(2) == 2 &&
                  numTilings(3) == 5 && numTilings(4) == 11 &&
                  numTilings(5) == 24;
    printf("%s: 0790 numTilings tests=5\n", passed ? "PASS" : "FAIL");
    return passed ? 0 : 1;
}
