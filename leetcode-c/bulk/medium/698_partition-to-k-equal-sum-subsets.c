/*
 * LeetCode 0698. Partition to K Equal Sum Subsets（劃分為 k 個等和子集合）
 * 題意：把 nums 的每個元素各用一次，分成 k 個非空子集合；若每組總和相同，回傳 true。
 * 範例：[4,3,2,3,5,2,1], k=4 -> true，可分成 [5]、[1,4]、[2,3]、[2,3]。
 * 限制：1 <= k <= numsSize <= 16；1 <= nums[i] <= 10^4；每個值最多出現 4 次。
 * 解法：位元遮罩代表已選元素。dp[mask] 記錄這些元素填到目前一組的總和；
 *       每次加入未使用元素，達到 target 後餘數歸零，開始填下一組。
 * 複雜度：時間 O(n * 2^n)，空間 O(2^n)。
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* ---- community solution ---- */
bool canPartitionKSubsets(int* nums, int numsSize, int k) {
    int total = 0;
    for (int i = 0; i < numsSize; i++) {
        total += nums[i];
    }
    if (total % k != 0) {
        return false;
    }

    int target = total / k;
    int stateCount = 1 << numsSize;
    int *filled = (int *)malloc(sizeof(int) * (size_t)stateCount);
    if (filled == NULL) {
        return false;
    }
    for (int mask = 0; mask < stateCount; mask++) {
        filled[mask] = -1;
    }
    filled[0] = 0;

    for (int mask = 0; mask < stateCount; mask++) {
        if (filled[mask] < 0) {
            continue;
        }
        for (int i = 0; i < numsSize; i++) {
            int bit = 1 << i;
            if ((mask & bit) != 0 || filled[mask] + nums[i] > target) {
                continue;
            }
            int nextMask = mask | bit;
            if (filled[nextMask] < 0) {
                filled[nextMask] = (filled[mask] + nums[i]) % target;
            }
        }
    }

    bool possible = filled[stateCount - 1] == 0;
    free(filled);
    return possible;
}

/* ---- generated tests ---- */
int main(void) {
    int first[] = {4, 3, 2, 3, 5, 2, 1};
    int second[] = {1, 2, 3, 4};
    int third[] = {2, 2, 2, 2, 2, 2};
    bool passed = canPartitionKSubsets(first, 7, 4) &&
                  !canPartitionKSubsets(second, 4, 3) &&
                  canPartitionKSubsets(third, 6, 3);
    printf("%s: 0698 canPartitionKSubsets tests=3\n",
           passed ? "PASS" : "FAIL");
    return passed ? 0 : 1;
}
