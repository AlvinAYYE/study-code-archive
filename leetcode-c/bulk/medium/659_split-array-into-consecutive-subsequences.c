/*
 * LeetCode 0659. Split Array into Consecutive Subsequences（拆分陣列為連續子序列）
 * Difficulty: Medium
 * 題意：給定已排序整數陣列 nums，判斷能否把所有數字分成一個或多個連續遞增子序列，且每個子序列至少長度為 3。每個陣列元素都必須使用一次。
 * 範例：
 *   1. 輸入：nums = [1,2,3,3,4,5]；輸出：true。可拆成 [1,2,3] 和 [3,4,5]。
 *   2. 輸入：nums = [1,2,3,3,4,4,5,5]；輸出：true。可拆成 [1,2,3,4,5] 和 [3,4,5]。
 *   3. 輸入：nums = [1,2,3,4,4,5]；輸出：false。
 * 限制：
 *   - 1 <= nums.length <= 10^4
 *   - -1000 <= nums[i] <= 1000
 *   - nums 已依非遞減順序排列
 * 解法：
 *   1. 先統計每個數字還有幾個可用次數，另用 need[x] 記錄有幾條已建立的子序列正等著接 x。
 *   2. 依序處理每個 x：若有子序列需要 x，優先把 x 接上去，避免舊子序列被留下太短。
 *   3. 若沒有人需要 x，就嘗試用 x、x+1、x+2 開一條新序列；三個數都要有剩餘次數。
 *   4. 若兩種方式都不行，代表無法拆分；所有數字都成功使用後回傳 true。
 * 複雜度：時間 O(n)，額外空間 O(1)（值域固定為 -1000 到 1000）。
 */
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/* ---- community solution ---- */
bool isPossible(int* nums, int numsSize) {
    int frequency[2005] = {0};
    int needNext[2005] = {0};
    const int offset = 1000;

    for (int i = 0; i < numsSize; i++) {
        frequency[nums[i] + offset]++;
    }

    for (int i = 0; i < numsSize; i++) {
        int index = nums[i] + offset;
        if (frequency[index] == 0) {
            continue;
        }
        frequency[index]--;

        if (needNext[index] > 0) {
            // 先延長已有序列，避免它最後短於 3。
            needNext[index]--;
            needNext[index + 1]++;
        } else if (frequency[index + 1] > 0 &&
                   frequency[index + 2] > 0) {
            // 沒有舊序列可接，就用三個連續數字開新序列。
            frequency[index + 1]--;
            frequency[index + 2]--;
            // 已用完 x、x+1、x+2；下一個需要的是 x+3。
            needNext[index + 3]++;
        } else {
            return false;
        }
    }
    return true;
}

/* ---- generated tests ---- */
int main(void) {
    int numsOne[] = {1, 2, 3, 3, 4, 5};
    int numsTwo[] = {1, 2, 3, 3, 4, 4, 5, 5};
    int numsThree[] = {1, 2, 3, 4, 4, 5};
    bool passed = isPossible(numsOne, 6) &&
                  isPossible(numsTwo, 8) &&
                  !isPossible(numsThree, 6);
    printf("%s: 0659 isPossible tests=3\n", passed ? "PASS" : "FAIL");
    return passed ? 0 : 1;
}
