/*
 * Title-CN: 森林中的兔子
 * LeetCode 781. Rabbits in Forest
 *
 * 題意翻譯：森林裡有一些兔子。你問每隻兔子「有幾隻其他兔子和你顏色相同？」
 * answers[i] 是第 i 隻兔子的回答。請根據這些回答，求森林中兔子數量的最小可能值。
 * 不同顏色的兔子可以給出相同回答。
 *
 * 範例 1：answers = [1,1,2]，輸出 5。兩隻回答 1 的兔子可以同色；回答 2 的兔子
 *         需要另有兩隻同色兔子，因此最少是 2 + 3 = 5 隻。
 * 範例 2：answers = [10,10,10]，輸出 11。每隻回答 10 代表自己那組共有 11 隻；
 *         三隻回答可以屬於同一組。
 *
 * 限制：1 <= answers.length <= 1000；0 <= answers[i] <= 1000。
 *
 * 解題思路：回答 y 的一組兔子共有 y + 1 隻（包含回答者）。若有 c 隻兔子回答 y，
 * 它們至少要分成 ceil(c / (y+1)) 組；每組都必須補足到 y+1 隻，即使最後一組只有
 * 部分兔子提供了回答。先統計每個回答的次數，再把組數乘上組大小加進答案。時間
 * O(n + R)，空間 O(R)，R 為回答值的範圍。
 *
 * LeetCode C 介面：回傳兔子數量的最小值；main() 僅供本機測試。
 */

#include <assert.h>

int numRabbits(int *answers, int answersSize) {
    int frequency[1001] = {0};
    int minimumCount = 0;
    int i;

    for (i = 0; i < answersSize; ++i) ++frequency[answers[i]];
    for (i = 0; i <= 1000; ++i) {
        if (frequency[i] > 0) {
            int groupSize = i + 1;
            int groups = (frequency[i] + groupSize - 1) / groupSize;
            minimumCount += groups * groupSize;
        }
    }
    return minimumCount;
}

int main(void) {
    int example1[] = {1, 1, 2};
    int example2[] = {10, 10, 10};
    int example3[] = {0, 0, 1, 1, 1};
    assert(numRabbits(example1, 3) == 5);
    assert(numRabbits(example2, 3) == 11);
    assert(numRabbits(example3, 5) == 6);
    return 0;
}
