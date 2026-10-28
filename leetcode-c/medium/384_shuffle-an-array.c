/*
 * LeetCode 384. Shuffle an Array
 * Title-CN: 打亂陣列
 *
 * 題目翻譯：建立一個物件保存整數陣列 nums，提供 reset() 還原並回傳原始排列，
 * 以及 shuffle() 回傳隨機排列。shuffle 的每種可能排列都必須等機率出現。
 *
 * 操作範例：以 [1,2,3] 建立物件；shuffle() 可回傳 [3,1,2]；reset() 回傳 [1,2,3]；
 * 再次 shuffle() 也可回傳另一種排列，例如 [1,3,2]。隨機結果每次可不同。
 *
 * 限制：陣列長度 1 到 50；-10^6 <= nums[i] <= 10^6；元素互不相同；reset 與 shuffle
 * 的總呼叫次數最多 10^4。
 *
 * 解題思路：保留一份永不修改的原始陣列，以及一份作為 shuffle 結果的工作陣列。
 * 1. 建立物件時複製輸入到 original。
 * 2. reset 直接回傳 original，因此不會受先前的 shuffle 影響。
 * 3. shuffle 先把 original 複製到工作陣列，再從尾端往前走；每次均勻選一個尚未固定的位置交換。
 *    Fisher–Yates 洗牌中，每個排列都對應到一組等機率選擇，所以排列機率相同。
 *
 * 複雜度：建立 O(n)；reset O(1) 回傳內部陣列；shuffle O(n)；空間 O(n)。
 *
 * LeetCode C API：
 * Solution *solutionCreate(int *nums, int numsSize);
 * int *solutionReset(Solution *obj, int *retSize);
 * int *solutionShuffle(Solution *obj, int *retSize);
 * void solutionFree(Solution *obj);
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int *original;
    int *working;
    int size;
    uint32_t randomState;
} Solution;

static uint32_t nextShuffleRandom(Solution *obj) {
    uint32_t x = obj->randomState;
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    obj->randomState = x;
    return x;
}

static uint32_t shuffleRandomBelow(Solution *obj, uint32_t bound) {
    uint32_t range = UINT32_MAX;
    uint32_t limit = range - range % bound;
    uint32_t value;
    do {
        value = nextShuffleRandom(obj) - 1;
    } while (value >= limit);
    return value % bound;
}

Solution *solutionCreate(int *nums, int numsSize) {
    if (nums == NULL || numsSize <= 0) return NULL;

    Solution *obj = (Solution *)calloc(1, sizeof *obj);
    if (obj == NULL) return NULL;

    obj->original = (int *)malloc((size_t)numsSize * sizeof *obj->original);
    obj->working = (int *)malloc((size_t)numsSize * sizeof *obj->working);
    if (obj->original == NULL || obj->working == NULL) {
        free(obj->original);
        free(obj->working);
        free(obj);
        return NULL;
    }

    memcpy(obj->original, nums, (size_t)numsSize * sizeof *nums);
    memcpy(obj->working, nums, (size_t)numsSize * sizeof *nums);
    obj->size = numsSize;
    obj->randomState = (uint32_t)time(NULL) ^ (uint32_t)(uintptr_t)obj ^ UINT32_C(0x9e3779b9);
    if (obj->randomState == 0) obj->randomState = UINT32_C(0x6d2b79f5);
    return obj;
}

int *solutionReset(Solution *obj, int *retSize) {
    if (retSize != NULL) *retSize = (obj == NULL) ? 0 : obj->size;
    return (obj == NULL) ? NULL : obj->original;
}

int *solutionShuffle(Solution *obj, int *retSize) {
    if (retSize != NULL) *retSize = (obj == NULL) ? 0 : obj->size;
    if (obj == NULL) return NULL;

    memcpy(obj->working, obj->original, (size_t)obj->size * sizeof *obj->working);
    for (int i = obj->size - 1; i > 0; --i) {
        int selected = (int)shuffleRandomBelow(obj, (uint32_t)(i + 1));
        int temporary = obj->working[i];
        obj->working[i] = obj->working[selected];
        obj->working[selected] = temporary;
    }
    return obj->working;
}

void solutionFree(Solution *obj) {
    if (obj == NULL) return;
    free(obj->original);
    free(obj->working);
    free(obj);
}

static int isPermutationOfInput(const int *values, const int *input, int size) {
    int seen[50] = {0};
    for (int i = 0; i < size; ++i) {
        int found = 0;
        for (int j = 0; j < size; ++j) {
            if (values[i] == input[j] && !seen[j]) {
                seen[j] = 1;
                found = 1;
                break;
            }
        }
        if (!found) return 0;
    }
    return 1;
}

static int arrayEquals(const int *left, const int *right, int size) {
    for (int i = 0; i < size; ++i) {
        if (left[i] != right[i]) return 0;
    }
    return 1;
}

int main(void) {
    const int input[] = {1, 2, 3};
    Solution *solution = solutionCreate((int *)input, 3);
    if (solution == NULL) return 1;

    int resultSize = 0;
    int passed = 1;
    for (int i = 0; i < 100; ++i) {
        int *shuffled = solutionShuffle(solution, &resultSize);
        if (resultSize != 3 || !isPermutationOfInput(shuffled, input, 3)) passed = 0;
    }

    int *reset = solutionReset(solution, &resultSize);
    passed = passed && resultSize == 3 && arrayEquals(reset, input, 3);
    solutionShuffle(solution, &resultSize);
    reset = solutionReset(solution, &resultSize);
    passed = passed && arrayEquals(reset, input, 3);

    solutionFree(solution);
    puts(passed ? "PASS: 384 shuffle-an-array" : "FAIL: 384 shuffle-an-array");
    return passed ? 0 : 1;
}
