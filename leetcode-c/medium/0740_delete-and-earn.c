/*
 * Title-CN: 刪除並獲得點數
 * LeetCode 740. Delete and Earn
 *
 * 題意翻譯：給定整數陣列 nums。每次選一個數字 x，就得到 x 分，並刪除陣列中
 * 所有值為 x - 1 和 x + 1 的數字。可以重複選擇，請回傳最多能得到幾分。
 *
 * 範例 1：nums = [3,4,2]，輸出 6。選 4 後刪除 3，再選 2，總分 4 + 2 = 6。
 * 範例 2：nums = [2,2,3,3,3,4]，輸出 9。選三個 3 得 9 分，值為 2、4 的數字被刪除。
 *
 * 限制：1 <= nums.length <= 2 * 10^4；1 <= nums[i] <= 10^4。
 *
 * 解題思路：把相同數字合併。若數字 x 出現 count 次，選它的總分就是 x * count；
 * 一旦選了 x，就不能選 x-1 或 x+1，因此問題變成「相鄰位置不能同時選」：
 * 1. points[x] 累加所有 x 的分數。
 * 2. 從 1 掃到最大數，保存 take（選目前數字的最佳分數）和 skip（不選的最佳分數）。
 * 3. 新 take = 舊 skip + points[x]；新 skip = 舊 take、舊 skip 的較大值。
 * 這和打家劫舍的選擇完全相同。時間 O(n + M)，空間 O(M)，M 是最大數值。
 *
 * LeetCode C 介面：回傳最大點數；main() 僅供本機測試。
 */

#include <assert.h>
#include <stdlib.h>

int deleteAndEarn(int *nums, int numsSize) {
    int maximum = 0;
    int *points;
    int take = 0;
    int skip = 0;
    int i;

    for (i = 0; i < numsSize; ++i) {
        if (nums[i] > maximum) maximum = nums[i];
    }
    points = calloc((size_t)maximum + 1U, sizeof(*points));
    if (points == NULL) return 0;
    for (i = 0; i < numsSize; ++i) points[nums[i]] += nums[i];

    for (i = 1; i <= maximum; ++i) {
        int nextTake = skip + points[i];
        int nextSkip = take > skip ? take : skip;
        take = nextTake;
        skip = nextSkip;
    }

    free(points);
    return take > skip ? take : skip;
}

int main(void) {
    int example1[] = {3, 4, 2};
    int example2[] = {2, 2, 3, 3, 3, 4};
    int example3[] = {1};
    assert(deleteAndEarn(example1, 3) == 6);
    assert(deleteAndEarn(example2, 6) == 9);
    assert(deleteAndEarn(example3, 1) == 1);
    assert(deleteAndEarn(NULL, 0) == 0);
    return 0;
}
