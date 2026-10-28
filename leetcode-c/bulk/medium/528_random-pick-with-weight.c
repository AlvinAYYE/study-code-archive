/*
 * LeetCode 0528. Random Pick with Weight（依權重隨機挑選）
 * Difficulty: Medium
 * 題意：給定正整數權重陣列 w。每次呼叫 pickIndex 時回傳一個索引 i，且被選中的機率為 w[i] 除以所有權重總和。
 * 範例：
 *   1. 輸入：w = [1]；pickIndex 一定回傳 0。
 *   2. 輸入：w = [1,3]；索引 0 的機率為 1/4，索引 1 的機率為 3/4。
 * 限制：
 *   - 1 <= w.length <= 10^4
 *   - 1 <= w[i] <= 10^5
 *   - pickIndex 呼叫不超過 10^4 次
 * 解法：
 *   1. 建立累積權重陣列。例如權重 [1,3,2] 對應前綴 [1,4,6]。
 *   2. 在 1 到總權重之間等機率抽一個整數 ticket。
 *   3. 用二分搜尋找第一個累積權重大於或等於 ticket 的索引。
 *   4. 每個索引涵蓋的 ticket 數量恰好等於它的權重，因此選取機率符合題目要求。
 * 複雜度：建立時間 O(n)，每次 pickIndex 時間 O(log n)，額外空間 O(n)。
 */
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/* ---- community solution ---- */
typedef struct {
    long long *prefix;
    int size;
    long long total;
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

Solution* solutionCreate(int* w, int wSize) {
    Solution *obj = (Solution *)malloc(sizeof(*obj));
    if (obj == NULL) {
        return NULL;
    }
    obj->prefix = (long long *)malloc(sizeof(long long) * (size_t)wSize);
    if (obj->prefix == NULL) {
        free(obj);
        return NULL;
    }

    obj->size = wSize;
    obj->total = 0;
    obj->randomState = 0xC8013EA4u;
    for (int i = 0; i < wSize; i++) {
        obj->total += w[i];
        obj->prefix[i] = obj->total;
    }
    return obj;
}

int solutionPickIndex(Solution* obj) {
    long long ticket = (long long)randomBelow(obj, (uint32_t)obj->total) + 1;
    int left = 0;
    int right = obj->size;

    // 找第一個累積權重至少涵蓋 ticket 的位置。
    while (left < right) {
        int middle = left + (right - left) / 2;
        if (obj->prefix[middle] >= ticket) {
            right = middle;
        } else {
            left = middle + 1;
        }
    }
    return left;
}

void solutionFree(Solution* obj) {
    if (obj != NULL) {
        free(obj->prefix);
        free(obj);
    }
}

/* ---- generated tests ---- */
int main(void) {
    int oneWeight[] = {1};
    Solution *one = solutionCreate(oneWeight, 1);
    bool passed = one != NULL && solutionPickIndex(one) == 0;
    solutionFree(one);

    int weights[] = {1, 3};
    Solution *obj = solutionCreate(weights, 2);
    passed = passed && obj != NULL;
    for (int i = 0; passed && i < 100; i++) {
        int index = solutionPickIndex(obj);
        if (index < 0 || index > 1) {
            passed = false;
        }
    }
    solutionFree(obj);
    printf("%s: 0528 RandomPickWeight local tests\n", passed ? "PASS" : "FAIL");
    return passed ? 0 : 1;
}
