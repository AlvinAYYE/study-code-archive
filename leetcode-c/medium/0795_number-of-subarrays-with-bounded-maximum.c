/*
 * Title-CN: 最大值落在指定範圍內的子陣列數
 * LeetCode 795. Number of Subarrays with Bounded Maximum
 *
 * 題意翻譯：給定整數陣列 nums，以及整數 left、right。請計算有多少個非空連續
 * 子陣列，其最大值介於 left 和 right 之間（包含兩端）。
 *
 * 範例 1：nums = [2,1,4,3]、left = 2、right = 3，輸出 3。符合的子陣列是 [2]、
 *         [2,1]、[3]。
 * 範例 2：nums = [2,9,2,5,6]、left = 2、right = 8，輸出 7。
 *
 * 限制：1 <= nums.length <= 10^4；0 <= nums[i] <= 10^9；0 <= left <= right <= 10^9。
 *
 * 解題思路：先定義「最大值不超過 limit 的子陣列數」。從左到右掃描時，若目前值
 * <= limit，所有以它結尾、且從最近一個超標值之後開始的子陣列都有效；若超標，
 * 有效連續長度歸零。於是每個位置把目前有效長度加進總數。要求最大值在 [left,right]
 * 之間，就用「最大值 <= right 的數量」減去「最大值 < left 的數量」。時間 O(n)，
 * 空間 O(1)。
 *
 * LeetCode C 介面：回傳符合條件的子陣列數；main() 僅供本機測試。
 */

#include <assert.h>

static int countWithMaximumAtMost(int *nums, int numsSize, int limit) {
    int endingHere = 0;
    int total = 0;
    int i;

    for (i = 0; i < numsSize; ++i) {
        if (nums[i] <= limit) {
            ++endingHere;
            total += endingHere;
        } else {
            endingHere = 0;
        }
    }
    return total;
}

int numSubarrayBoundedMax(int *nums, int numsSize, int left, int right) {
    return countWithMaximumAtMost(nums, numsSize, right) -
           countWithMaximumAtMost(nums, numsSize, left - 1);
}

int main(void) {
    int example1[] = {2, 1, 4, 3};
    int example2[] = {2, 9, 2, 5, 6};
    int example3[] = {1, 1, 1};
    assert(numSubarrayBoundedMax(example1, 4, 2, 3) == 3);
    assert(numSubarrayBoundedMax(example2, 5, 2, 8) == 7);
    assert(numSubarrayBoundedMax(example3, 3, 1, 1) == 6);
    return 0;
}
