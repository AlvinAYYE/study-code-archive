/*
 * LeetCode 0398. Random Pick Index（隨機挑選索引）
 * Difficulty: Medium
 * 題意：給定整數陣列 nums，建立物件後，pick(target) 要在所有值等於 target 的索引中等機率隨機回傳一個。target 保證存在。
 * 範例：
 *   1. 輸入：nums = [1,2,3,3,3]。pick(3) 可回傳 2、3 或 4，且三個索引機率相同；pick(1) 一定回傳 0。
 * 限制：
 *   - 1 <= nums.length <= 2 * 10^4
 *   - -2^31 <= nums[i] <= 2^31 - 1
 *   - target 一定出現在 nums
 *   - pick 呼叫不超過 10^4 次
 * 解法：
 *   1. 掃描整個陣列，只處理值等於 target 的位置。
 *   2. 用水塘抽樣：看到第 k 個符合位置時，以 1/k 的機率用它取代目前答案。
 *   3. 掃描結束後，每個符合位置都有相同機率成為最後答案，且不需要預先保存所有索引。
 *   4. 物件保存原陣列副本和自己的亂數狀態，避免依賴全域亂數狀態。
 * 複雜度：建立時間 O(n)，每次 pick 時間 O(n)，額外空間 O(n) 保存輸入副本。
 */
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/* ---- community solution ---- */
typedef struct {
    int *nums;
    int numsSize;
    uint32_t randomState;
} Solution;

static uint32_t nextRandom(Solution *obj) {
    uint32_t value = obj->randomState;
    value ^= value << 13;
    value ^= value >> 17;
    value ^= value << 5;
    obj->randomState = value;
    return value;
}

static uint32_t randomBelow(Solution *obj, uint32_t bound) {
    uint32_t threshold = (uint32_t)(0u - bound) % bound;
    uint32_t value;
    do {
        value = nextRandom(obj);
    } while (value < threshold);
    return value % bound;
}

Solution* solutionCreate(int* nums, int numsSize) {
    Solution *obj = (Solution *)malloc(sizeof(*obj));
    if (obj == NULL) {
        return NULL;
    }
    obj->nums = (int *)malloc(sizeof(int) * (size_t)numsSize);
    if (obj->nums == NULL) {
        free(obj);
        return NULL;
    }
    memcpy(obj->nums, nums, sizeof(int) * (size_t)numsSize);
    obj->numsSize = numsSize;
    obj->randomState = 0x9E3779B9u;
    return obj;
}

int solutionPick(Solution* obj, int target) {
    int selectedIndex = -1;
    uint32_t matchesSeen = 0;
    for (int i = 0; i < obj->numsSize; i++) {
        if (obj->nums[i] == target) {
            matchesSeen++;
            if (randomBelow(obj, matchesSeen) == 0) {
                selectedIndex = i;
            }
        }
    }
    return selectedIndex;
}

void solutionFree(Solution* obj) {
    if (obj != NULL) {
        free(obj->nums);
        free(obj);
    }
}

/* ---- generated tests ---- */
int main(void) {
    int nums[] = {1, 2, 3, 3, 3};
    Solution *obj = solutionCreate(nums, 5);
    if (obj == NULL) {
        return 1;
    }

    bool passed = solutionPick(obj, 1) == 0;
    for (int i = 0; i < 100; i++) {
        int index = solutionPick(obj, 3);
        if (index < 2 || index > 4 || nums[index] != 3) {
            passed = false;
            break;
        }
    }
    solutionFree(obj);
    printf("%s: 0398 RandomPickIndex local tests\n", passed ? "PASS" : "FAIL");
    return passed ? 0 : 1;
}
