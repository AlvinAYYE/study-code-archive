/*
 * LeetCode 2347. Best Poker Hand
 * Title-CN: 最佳撲克牌型
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/best-poker-hand/
 *
 * [中文] 題目說明
 *     給定 5 張牌的點數 ranks 和花色 suits。依照由好到差的順序，牌型為：
 *     Flush（五張花色相同）、Three of a Kind（三張點數相同）、Pair
 *    （兩張點數相同）、High Card（以上都不符合）。請回傳能組成的最佳牌型；
 *     回傳字串大小寫必須完全符合題目。
 *
 * [中文] 範例
 *     1. ranks = [13,2,3,1,9]、suits = [a,a,a,a,a]，輸出 Flush。
 *     2. ranks = [4,4,2,4,4]、suits = [d,a,a,b,c]，輸出 Three of a Kind。
 *     3. ranks = [10,10,2,12,9]、suits = [a,b,c,a,d]，輸出 Pair。
 *
 * [中文] 限制
 *     - ranks 與 suits 長度都是 5；1 <= ranks[i] <= 13。
 *     - 花色是 a 到 d；不會有兩張牌點數和花色都相同。
 *
 * [中文] 解題步驟
 *     1. 檢查五張牌的花色是否全相同；若是，Flush 優先級最高，立即回傳。
 *     2. 統計每種點數出現次數；若有點數至少出現 3 次，回傳 Three of a Kind。
 *     3. 否則若有點數至少出現 2 次，回傳 Pair；否則回傳 High Card。
 *     4. 牌數固定為 5，時間 O(1)，額外空間 O(1)。
 *
 * LeetCode C 函式簽名：
 *     char* bestHand(int* ranks, int ranksSize, char* suits, int suitsSize)
 */
#include <stdio.h>

char *bestHand(int *ranks, int ranksSize, char *suits, int suitsSize) {
    int count[14] = {0};
    int flush = 1, hasTriple = 0, hasPair = 0, i;
    (void)suitsSize;
    for (i = 0; i < ranksSize; ++i) {
        ++count[ranks[i]];
        if (suits[i] != suits[0]) flush = 0;
    }
    if (flush) return "Flush";
    for (i = 1; i <= 13; ++i) {
        if (count[i] >= 3) hasTriple = 1;
        if (count[i] >= 2) hasPair = 1;
    }
    if (hasTriple) return "Three of a Kind";
    if (hasPair) return "Pair";
    return "High Card";
}

int main(void) {
    int ok = 1;
    int r1[] = {13, 2, 3, 1, 9}, r2[] = {4, 4, 2, 4, 4}, r3[] = {10, 10, 2, 12, 9};
    ok = ok && bestHand(r1, 5, "aaaaa", 5)[0] == 'F';
    ok = ok && bestHand(r2, 5, "daabc", 5)[0] == 'T';
    ok = ok && bestHand(r3, 5, "abcad", 5)[0] == 'P';
    ok = ok && bestHand(r3, 5, "abcde", 5)[0] == 'P';
    printf("%s: 2347 best-poker-hand\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
