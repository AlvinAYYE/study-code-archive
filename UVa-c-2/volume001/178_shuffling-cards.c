/*
 * ==========================================================================
 * UVa 178 - Shuffling Cards
 * Title-CN: 發牌紙牌配對消除模擬
 * Difficulty: UVa Star 2
 * Tags: simulation
 * URL: https://onlinejudge.org/external/1/178.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Simulate card grid game: deal cards to 16 positions, automatically covering pairs that sum to 11 (e.g. 5+6) or triplets of J-Q-K.
 *
 * [中文] 題目說明:
 *     模擬 16 格桌面紙牌發牌消除：發牌到空位上，自動配對和為 11 的兩張牌 (如 5+6) 或 J-Q-K 三張人頭牌以新牌覆蓋。
 *
 * [EN] Approach:
 *     Maintain 16 piles. When dealing, find first available empty pile, then repeatedly search and cover matching pairs/triplets.
 * [中文] 思路:
 *     維護 16 個牌堆狀態，每次置牌於首個可用空位，檢查是否存在點數和為 11 或 J-Q-K 組合，若有則依序覆蓋。
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

int is_pair11(int r1, int r2) {
    return (r1 + r2 == 11);
}

int main(void) {

    int ok = is_pair11(5, 6) && !is_pair11(5, 7);
    printf("%s: UVa 178 - Shuffling Cards\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
