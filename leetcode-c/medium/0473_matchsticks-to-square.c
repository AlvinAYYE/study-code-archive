/*
 * Title-CN: 火柴拼正方形
 * LeetCode 473. Matchsticks to Square
 *
 * 題意翻譯：給定每根火柴的長度，判斷能否把所有火柴都用上，分成四組，
 * 讓四組長度總和相同。每根火柴不能折斷，也不能重複使用。
 *
 * 範例：[1,1,2,2,2] 回傳 true，四邊都能湊成 2；[3,3,3,3,4] 回傳 false。
 *
 * 限制：火柴數量為 1 到 15；每根長度為 1 到 10^8。
 *
 * 解題思路：總長度必須能被 4 整除，目標邊長就是總長度除以 4。先將火柴由長
 * 到短排序，再用回溯把每根火柴放進四邊之一。若某邊加上火柴後超過目標就跳過；
 * 若一條空邊放入火柴仍無法完成，其他空邊的嘗試只是對稱重複，可以直接停止。
 *
 * 複雜度：回溯最壞 O(4^n)，排序 O(n log n)；遞迴空間 O(n)。n <= 15。
 * LeetCode 介面：保留 makesquare；main() 僅供本機測試。
 */

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

static int compareDescending(const void *left, const void *right) {
    int a = *(const int *)left;
    int b = *(const int *)right;
    return (a < b) - (a > b);
}

static bool placeNext(int *sticks, int count, int index, int target, int sides[4]) {
    if (index == count) return true;

    int length = sticks[index];
    for (int side = 0; side < 4; ++side) {
        if (sides[side] + length > target) continue;
        sides[side] += length;
        if (placeNext(sticks, count, index + 1, target, sides)) return true;
        sides[side] -= length;

        /* 空邊完全對稱；試過一條失敗，其他空邊也不必再試。 */
        if (sides[side] == 0) break;
    }
    return false;
}

bool makesquare(int *matchsticks, int matchsticksSize) {
    if (matchsticksSize < 4) return false;
    int total = 0;
    for (int i = 0; i < matchsticksSize; ++i) total += matchsticks[i];
    if (total % 4 != 0) return false;

    int target = total / 4;
    qsort(matchsticks, (size_t)matchsticksSize, sizeof(*matchsticks), compareDescending);
    if (matchsticks[0] > target) return false;

    int sides[4] = {0, 0, 0, 0};
    return placeNext(matchsticks, matchsticksSize, 0, target, sides);
}

int main(void) {
    int possible[] = {1, 1, 2, 2, 2};
    int impossible[] = {3, 3, 3, 3, 4};
    int tooFew[] = {1, 1, 1};
    assert(makesquare(possible, 5));
    assert(!makesquare(impossible, 5));
    assert(!makesquare(tooFew, 3));
    return 0;
}
